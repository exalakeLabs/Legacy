"""Generate the 100-million-value Parquet dataset used by qs.py."""

from __future__ import annotations

import argparse
import random
from pathlib import Path

import pyarrow as pa
import pyarrow.parquet as pq


VALUE_COUNT = 100_000_000
ROW_GROUP_SIZE = 1_000_000
COLUMN_NAME = "value"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "output",
        nargs="?",
        type=Path,
        default=Path(__file__).with_name("quicksort_100m.parquet"),
    )
    parser.add_argument("--seed", type=int, default=42)
    args = parser.parse_args()

    random_source = random.Random(args.seed)
    schema = pa.schema([(COLUMN_NAME, pa.int64())])

    with pq.ParquetWriter(
        args.output,
        schema,
        compression="zstd",
    ) as parquet_file:
        remaining = VALUE_COUNT
        while remaining:
            row_count = min(ROW_GROUP_SIZE, remaining)
            value_buffer = pa.py_buffer(
                random_source.randbytes(row_count * 8)
            )
            values = pa.Array.from_buffers(
                pa.int64(),
                row_count,
                [None, value_buffer],
            )
            parquet_file.write_batch(
                pa.record_batch([values], schema=schema),
            )
            remaining -= row_count

    print(f"Created {args.output} with {VALUE_COUNT:,} signed 64-bit values")


if __name__ == "__main__":
    main()
