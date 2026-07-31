# visio

**Visio 4.x SDK** sources bundled with the NetInfo VSL (Visio Corporation, 1991–1996). Enables the parent [**VisioPlugIn**](../README.md) DLL to load as a Visio add-on and automate the drawing surface.

## Key files

| File(s) | Purpose |
|---------|---------|
| `Vao.c` / `Vao.h` | Visio ↔ VSL interface (VisioLibMain, callbacks) |
| `Vaddon.cpp` / `Vaddon.h` | Add-on base class |
| `Vdllmain.c`, `Lib.c` | DLL entry and registration |
| `Visio.h`, `V41objs.h`, `Visconst.h` | Object model definitions |
| `Ivisprox.h`, `Ovisprox.h`, `Ivisauto.h` | Automation proxies |
| `Ivisreg.cpp` | Registry helpers |
| `Addsink.cpp` / `Addsink.h` | Visio event advise sink |
| `Helpers.cpp` | Utility routines |

Compiled as part of **NetInfo.dsp**; not a standalone product.
