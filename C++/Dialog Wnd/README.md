# Dialog Wnd

Small **diagnostic message-box library** for Windows (Scott Robert Ladd, 1995).

`DiagOutWin()` in `diagwin.cpp` / `diagwin.h` shows user-visible diagnostics with severity levels:

| Level | Behavior |
|-------|----------|
| `DIAG_FATAL` | Message box, then terminates the program |
| `DIAG_ERROR` | “Yes” terminates, “No” continues |
| `DIAG_WARNING` | Warning dialog |
| `DIAG_MSG` | Informational message |

## Usage

Add `diagwin.cpp` to your Visual C++ project and `#include "diagwin.h"`. Call `DiagOutWin(level, "format", ...)` like `printf`.

## Build

No separate project file—compile as part of a host application. Typical host: any Win32 `.dsp` console or GUI app from the same era.
