from __future__ import annotations

import argparse
import os
import random
from array import array
from ctypes import c_longlong
from multiprocessing import cpu_count, get_context
from pathlib import Path
from typing import Iterable


# Small partitions are faster with insertion sort than with the
# overhead of creating additional queue work.
INSERTION_THRESHOLD = 64
PARQUET_COLUMN = "value"


def _load_parquet(path: str | Path) -> array:
    """Load a null-free int64 Parquet column into a compact array."""
    try:
        import pyarrow.parquet as pq
    except ImportError as error:
        raise RuntimeError(
            "Parquet input requires pyarrow; install Python/requirements.txt"
        ) from error

    parquet_file = pq.ParquetFile(path)

    if PARQUET_COLUMN not in parquet_file.schema_arrow.names:
        raise ValueError(
            f"Parquet dataset must contain a {PARQUET_COLUMN!r} column"
        )

    values = array("q")

    for batch in parquet_file.iter_batches(columns=[PARQUET_COLUMN]):
        column = batch.column(0)

        if column.null_count:
            raise ValueError(
                f"Parquet column {PARQUET_COLUMN!r} cannot contain nulls"
            )

        data_buffer = column.buffers()[1]
        byte_start = column.offset * values.itemsize
        byte_end = byte_start + len(column) * values.itemsize
        values.frombytes(memoryview(data_buffer)[byte_start:byte_end])

    return values


def _median3(x: int, y: int, z: int) -> int:
    """Return the median of three values for a better pivot."""
    if x < y:
        if y < z:
            return y
        return z if x < z else x

    if x < z:
        return x

    return z if y < z else y


def _partition3(a, lo: int, hi: int) -> tuple[int, int]:
    """
    Three-way QuickSort partition.

    Produces:

        [ values < pivot ][ values == pivot ][ values > pivot ]

    Returns the inclusive boundaries of the == pivot section.
    """
    mid = (lo + hi) // 2

    pivot = _median3(
        a[lo],
        a[mid],
        a[hi],
    )

    lt = lo
    i = lo
    gt = hi

    while i <= gt:

        if a[i] < pivot:
            a[lt], a[i] = a[i], a[lt]
            lt += 1
            i += 1

        elif a[i] > pivot:
            a[i], a[gt] = a[gt], a[i]
            gt -= 1

        else:
            i += 1

    return lt, gt


def _insertion_sort(a, lo: int, hi: int) -> None:
    """Sort a small range in place."""
    for i in range(lo + 1, hi + 1):
        value = a[i]
        j = i - 1

        while j >= lo and a[j] > value:
            a[j + 1] = a[j]
            j -= 1

        a[j + 1] = value


def _pin_worker(worker_index: int) -> None:
    """
    Pin each worker to a CPU core when the OS supports sched_setaffinity().

    Linux supports this directly.

    On macOS/Windows the worker processes can still execute simultaneously
    on different cores, but CPU placement is left to the OS scheduler.
    """
    if hasattr(os, "sched_setaffinity"):

        available_cores = sorted(os.sched_getaffinity(0))

        if available_cores:
            core = available_cores[
                worker_index % len(available_cores)
            ]

            os.sched_setaffinity(0, {core})


def _worker(
    shared,
    tasks,
    worker_index: int,
    threshold: int,
) -> None:
    """
    Worker process.

    Each worker repeatedly grabs a QuickSort partition, chooses a pivot,
    partitions it, and puts the resulting partitions back into the queue.
    """
    _pin_worker(worker_index)

    while True:

        task = tasks.get()

        try:
            # Shutdown message
            if task is None:
                return

            lo, hi = task

            if lo >= hi:
                continue

            size = hi - lo + 1

            # Avoid multiprocessing/queue overhead on tiny ranges.
            if size <= threshold:
                _insertion_sort(shared, lo, hi)
                continue

            # This pivot calculation and partition happens inside
            # the worker process and therefore on that CPU core.
            equal_lo, equal_hi = _partition3(
                shared,
                lo,
                hi,
            )

            # These two regions are disjoint, so different processors
            # can safely work on them concurrently.

            left_hi = equal_lo - 1

            if lo < left_hi:
                tasks.put(
                    (lo, left_hi)
                )

            right_lo = equal_hi + 1

            if right_lo < hi:
                tasks.put(
                    (right_lo, hi)
                )

        finally:
            tasks.task_done()


def parallel_quicksort(
    values: Iterable[int],
    workers: int | None = None,
) -> list[int]:
    """
    Parallel QuickSort using multiple processor cores.

    Parameters
    ----------
    values:
        Iterable containing signed 64-bit integers.

    workers:
        Number of worker processes.
        Defaults to the number of logical CPUs.

    Returns
    -------
    list[int]:
        Sorted values.
    """
    values = list(values)

    n = len(values)

    if n < 2:
        return values

    worker_count = workers or cpu_count()

    worker_count = max(
        1,
        min(worker_count, n),
    )

    # "spawn" works on Linux, macOS, and Windows.
    ctx = get_context("spawn")

    # Shared memory. All workers operate on the same underlying array.
    shared = ctx.RawArray(
        c_longlong,
        values,
    )

    # Dynamic queue of QuickSort ranges.
    tasks = ctx.JoinableQueue()

    processes = [
        ctx.Process(
            target=_worker,
            args=(
                shared,
                tasks,
                worker_index,
                INSERTION_THRESHOLD,
            ),
            name=f"quicksort-{worker_index}",
        )
        for worker_index in range(worker_count)
    ]

    # Start worker pool.
    for process in processes:
        process.start()

    # Start with the complete array.
    tasks.put(
        (0, n - 1)
    )

    # Wait until all recursively generated partitions are finished.
    tasks.join()

    # Shut down workers.
    for _ in processes:
        tasks.put(None)

    tasks.join()

    for process in processes:
        process.join()

        if process.exitcode != 0:
            raise RuntimeError(
                f"{process.name} exited "
                f"with code {process.exitcode}"
            )

    return list(shared)


if __name__ == "__main__":

    parser = argparse.ArgumentParser(
        description="Run the parallel quicksort implementation.",
    )
    parser.add_argument(
        "dataset",
        nargs="?",
        help=(
            "optional dataset: a Parquet file with an int64 'value' column, "
            "a binary int64 .bin file, or whitespace-separated text integers"
        ),
    )
    args = parser.parse_args()

    if args.dataset:
        if args.dataset.endswith(".parquet"):
            data = _load_parquet(args.dataset)
        elif args.dataset.endswith(".bin"):
            data = array("q")
            with open(args.dataset, "rb") as dataset_file:
                data.fromfile(
                    dataset_file,
                    os.path.getsize(args.dataset) // data.itemsize,
                )
        else:
            with open(args.dataset, encoding="utf-8") as dataset_file:
                data = [
                    int(value)
                    for value in dataset_file.read().split()
                ]
    else:
        # Create test data when no dataset file is supplied.
        data = [
            random.randint(
                -1_000_000,
                1_000_000,
            )
            for _ in range(200_000)
        ]

    result = parallel_quicksort(data)

    # Verify it because trusting sorting code without checking it
    # is how humans eventually invent corrupted databases.
    expected = sorted(data)

    assert result == expected

    print(
        "Sorted correctly:",
        result == expected,
    )

    print(
        "Available CPU cores:",
        cpu_count(),
    )

    print(
        "First 20:",
        result[:20],
    )
