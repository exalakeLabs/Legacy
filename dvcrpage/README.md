# dvcrpage

**DirectShow** (or legacy filter) **property page** for a “DVcrControl” (D-VCR control). Implements `CDVcrControlProperties` as a property page (CreateInstance, MainThreadProc, etc.). Uses DirectShow SDK headers (e.g. `XPrtDefs.h`). Copyright 1992–1999 Microsoft Corporation. For building filter graphs or driver UIs that expose VCR-style properties.

## Build and run

Visual C++ project: `dvcrpage.dsp`. Requires DirectShow (or legacy SDK) includes and libs. Register the resulting DLL as a filter/property page in the filter graph or host app.
