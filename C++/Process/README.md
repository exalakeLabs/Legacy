# Process

Win32 **synchronization and concurrency** demos: semaphores, mutexes, critical sections, events, and file overlap. Multiple small console programs showing how to coordinate threads or processes.

## Programs

| Source | Description |
|--------|-------------|
| **sema.cpp** | Semaphore demo: several threads increment a shared counter using `CreateSemaphore` / `WaitForSingleObject` / `ReleaseSemaphore`. |
| **mutex.cpp** / **mutex2.cpp** | Mutex-based synchronization. |
| **critsec.cpp** | Critical-section demo. |
| **event.cpp** | Event objects for signaling. |
| **fileovlp.cpp** | File overlap (overlapped I/O) demo; project `fileoverlap.dsp`. |
| **prob1.cpp** | Additional concurrency example; project `prob1.dsp`. |

## Build and run

Open the relevant `.dsp` in Visual C++, build, and run the console executable.
