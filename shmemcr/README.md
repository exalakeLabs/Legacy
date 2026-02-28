# shmemcr

Win32 **shared memory** reader. Creates a file-mapping object named `"shmem1"` with `CreateFileMapping` (1 KB), maps it with `MapViewOfFile`, then loops forever reading and printing the string at the start of the view every second. Used as the “reader” half of a pair with **shmemop**.

## Build and run

- Visual C++ project: `shmemcr.dsp`.
- Run **shmemcr** first, then **shmemop** in another process; shmemcr will display what shmemop writes.
