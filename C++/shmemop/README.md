# shmemop

Win32 **shared memory** writer. Opens an existing file-mapping object named `"shmem1"` with `OpenFileMapping` and `MapViewOfFile`, then writes a short sequence of characters into the shared region (e.g. `'a'`…`'c'` at offsets) with 1-second delays. Used as the “writer” half of a pair with **shmemcr**.

## Build and run

- Visual C++ project: `shmemop.dsp`.
- Run **shmemcr** first (creates the mapping), then run **shmemop** to write; shmemcr will print what it reads.
