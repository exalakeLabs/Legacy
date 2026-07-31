# Proc&Thread

Windows C++ demos for **processes** and **threads**: child/parent processes, simple thread creation, and variations (TLS, wait structures, etc.). Built with Visual C++ (`.dsp` projects).

## Programs / sources

| File / project | Description |
|----------------|-------------|
| **thread** | Simple thread demo: `CreateThread` runs a counter; main loop waits for Enter and prints the count. Runs until you stop it. |
| **threadWait** | Thread demo using wait (e.g. `WaitForSingleObject`). |
| **threadWaitStruc** | Thread demo with a shared structure for coordination. |
| **threadWaitStrucMulti** | Multi-thread version of the above. |
| **threadTls** | Thread-local storage (TLS) demo. |
| **philosophe.cpp** | Dining-philosophers–style concurrency (concept similar to the **philsophe** project). |
| **child** / **parent** | Child/parent process demos. |
| **proc1** | Single-process demo. |

## Build and run

Open the appropriate `.dsp` in Visual C++ (e.g. `thread.dsp`, `threadWait.dsp`) and build. Run the resulting console executable.
