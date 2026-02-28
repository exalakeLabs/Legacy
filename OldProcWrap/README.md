# OldProcWrap

Prototype for **wrapping a child process** and monitoring its stdout/stderr. Uses `CreatePipe` to get read/write handles, sets the child’s standard handles in `STARTUPINFO`, and launches the process (e.g. `bsp.exe`); the parent reads from the pipe and can display output or detect error messages. Similar in purpose to **CreatePipe**; this version may use a larger buffer (e.g. 32 KB).

## Build and run

- Visual C++: open the workspace/project in this folder (e.g. `main.cpp`), build.
- Run the executable; it starts the child and displays what it reads from the pipe.
