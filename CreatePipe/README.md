# CreatePipe

Win32 demo that uses **anonymous pipes** to capture a child process’s stdout and stderr. Creates a pipe with `CreatePipe`, sets the child’s standard handles in `STARTUPINFO`, and spawns the process (e.g. `bsp.exe`); the parent reads from the pipe and can display or react to output (e.g. error messages).

## Build and run

- Visual C++ project: `OldProcWrap.dsp` / workspace in this folder (named for a related wrapper).
- Build in IDE or via generated makefile.
- Run the resulting executable; it launches the child and displays what it reads from the pipe.

## Related

- **OldProcWrap** — Similar “wrap process and monitor stdout/stderr” idea; see that folder’s README.
