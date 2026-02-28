# ThreadTest

Win32 **thread** demo: creates a worker thread (`ClientThread`) via `CreateThread`, passes an index, and the main thread waits for it with `WaitForSingleObject`. The worker prints its thread ID and “Done processing.” Simple example of thread creation and join on Windows.

## Build and run

- Visual C++: `TestThreads.dsp`. Build and run the console app.
