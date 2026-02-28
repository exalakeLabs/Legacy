# VisioPlugIn

MFC **DLL** project named “NetInfo”: network-information or similar functionality, intended to integrate with or extend Visio (e.g. as a plug-in or helper). The DLL exports the `CNetInfoApp` class and standard MFC DLL entry points. See `visio` subfolder for Visio-specific code if present.

## Build and run

- Visual C++: build the NetInfo DLL project.
- Deploy/load the DLL in the environment where Visio (or the target app) can load it; registration and load steps depend on your Visio integration design.
