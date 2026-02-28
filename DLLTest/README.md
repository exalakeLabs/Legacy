# DLLTest

Demos for **building and using a DLL** from C++Builder and Visual C++. Includes a class exported from a DLL and an app that uses it.

## Parts

- **classdll** (VC++) — DLL that exports a simple class (`testdll`) with get/set member; uses `__declspec(dllexport)`/`dllimport`.
- **testdll** — VC++ project that links to the DLL and uses the exported class.
- **Project1** (C++Builder) — C++Builder app (VCL form) that uses the DLL; `DllEntryPoint` in the project source.

## Build and run

1. Build the DLL first (e.g. `classdll.dsp` or `classdll.mak`).
2. Build the test app (`testdll.dsp`) or the C++Builder project (`Project1.bpr`).
3. Run the executable with the DLL on the path (or in the same directory).
