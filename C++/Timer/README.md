# Timer

Win32 **multimedia timer** demo. Uses `timeGetDevCaps`, `timeBeginPeriod`, and `timeSetEvent` to run a periodic callback (e.g. every 1 ms). The callback counts events and prints every 1000th; demonstrates high-resolution periodic timers on Windows.

## Build and run

- Visual C++ project: `timer.dsp`. Link **winmm.lib** (multimedia library).
- Run the console app; it reports timer resolution and then prints a running count. Stop with Ctrl+C.
