# mapfile

Win32 demo: **memory-mapped file** read. Prompts for a filename, opens the file with `CreateFile`, creates a read-only file mapping with `CreateFileMapping`, and maps the whole file with `MapViewOfFile`. Then it prints the mapped content as text and unmaps/closes. Shows how to read a file via a single mapping without explicit read loops.

## Build and run

- Visual C++ project: `mapfile.dsp`.
- Run the executable, enter a valid file path when prompted; the program dumps the file contents to the console.
