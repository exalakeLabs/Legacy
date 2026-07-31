# VisioPlugIn

MFC **Visio VSL (Visio Solution Library)** add-on named **NetInfo**, generated with the “MFC VAddon VSL Wizard” (Visio Corporation, 1997).

## What it does

The **&Network Resources** add-on (`vNetInfo.cpp`) enumerates Windows networking resources via `CNetworkResourceCollector`, then draws the hierarchy on the active Visio page using `CNetworkResource` shapes (`NetworkResource.cpp`, `NetworkResourceCollector.cpp`).

Requires **Microsoft Visio** (4.x era) with VSL load support and the Visio automation headers in [`visio/`](visio/).

## Layout

| Path | Role |
|------|------|
| `NetInfo.dsp` | Visual C++ 6 project |
| `vNetInfo.cpp` / `vNetInfo.h` | VAddon subclass (Run, About, Load) |
| `NetworkResource*.cpp` | Shape tree for NETRESOURCE hierarchy |
| [`visio/`](visio/) | Visio SDK: VAO, automation proxies, add-in entry points |

## Build and deploy

1. Build `NetInfo.dll` with Visual C++ 6 and MFC.
2. Register/load the VSL per Visio’s add-on documentation for your Visio version.
3. In Visio, run the **Network Resources** add-on to populate the diagram.

Original AppWizard boilerplate: [`ReadMe.txt`](ReadMe.txt).
