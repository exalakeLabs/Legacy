# winCE Winsock

**Windows CE** Winsock test harness. `SOCKTEST.C` and companion resources exercise socket APIs on embedded Windows CE targets.

## Build

- Use a **Windows CE SDK** and cross-compiler from the CE era.
- Run `MAKEIT.BAT` (or the equivalent CE build script) with CE platform tools on the PATH.
- Deploy to a CE device or emulator with network support.

Not buildable with desktop Visual C++ alone. See [`winsock/`](../winsock/) for the desktop Winsock counterpart.
