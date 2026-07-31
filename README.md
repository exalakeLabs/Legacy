# Legacy

A curated archive of C/C++ and Windows projects from the 1990s–2000s: demos, tests, sample code, and reusable components. Most projects target **Visual C++ 5/6**, **MFC**, **COM/ActiveX**, **Borland C++Builder**, or legacy **CORBA** ORBs. A few examples (notably **philsophe**) build on modern macOS and Linux with a standard C++17 toolchain.

This repository preserves original source layouts and filenames. Folder names with spaces or special characters (e.g. `Proc&Thread`, `Dialog Wnd`) are intentional—renaming would break `.dsp`, `.bpr`, and `.vbp` project files.

## Quick start

There is **no single root build**. Each top-level folder is an independent project or small collection. Open the folder’s `README.md` for purpose, dependencies, and build steps.

| If you want to… | Start here |
|-----------------|------------|
| Build something on macOS/Linux today | [`philsophe/`](philsophe/) — `make` produces three concurrency demos |
| Explore COM/ActiveX patterns | [`COMObject/`](COMObject/) + [`COMClient/`](COMClient/) |
| Study Win32 synchronization | [`Process/`](Process/), [`Proc&Thread/`](Proc%26Thread/), [`ThreadTest/`](ThreadTest/) |
| Browse the CORBA POS book example | [`CORBA/`](CORBA/) |
| Run OpenGL on macOS (legacy GLUT) | [`OpenGLSurefire/`](OpenGLSurefire/) — requires OpenGL + GLUT frameworks |

## Contents by category

### Concurrency and processes

| Folder | Description |
|--------|-------------|
| [`philsophe/`](philsophe/) | Dining-philosophers demos; cross-platform C++17 |
| [`Proc&Thread/`](Proc%26Thread/) | Process and thread wait/signal examples |
| [`Process/`](Process/) | Semaphores, mutexes, critical sections, events, overlapped I/O |
| [`ThreadTest/`](ThreadTest/) | Thread creation and synchronization tests |
| [`CreatePipe/`](CreatePipe/) | Named-pipe parent/child demo |
| [`OldProcWrap/`](OldProcWrap/) | Legacy process-wrapper sample |

### COM, ActiveX, and DCOM

| Folder | Description |
|--------|-------------|
| [`COMObject/`](COMObject/) | In-process COM server (MFC/ATL-style) |
| [`COMClient/`](COMClient/) | MFC client for COMObject |
| [`CLSIDTest/`](CLSIDTest/) | CLSID lookup and registration tests |
| [`OCXREG/`](OCXREG/) | OCX registration utility |
| [`DCOM/`](DCOM/) | DCOM draw server/client samples (DrawServ, DrawCtl, ATLDraw) |
| [`dllDialog/`](dllDialog/) | Dialog exported from a DLL |
| [`ActiveListBox/`](ActiveListBox/) | VB6 ActiveX control project |
| [`ActiveListBoxTest/`](ActiveListBoxTest/) | MFC host for ActiveX control testing |
| [`XPropertiesWnd/`](XPropertiesWnd/) | Property-sheet / shell-tree ActiveX control |
| [`XFloorWnd/`](XFloorWnd/) | Tabbed “floor” navigation ActiveX control |
| [`RemoteShell OCX/`](RemoteShell%20OCX/) | Remote-shell ActiveX experiment |

### CORBA

| Folder | Description |
|--------|-------------|
| [`CORBA/`](CORBA/) | POS example from *CORBA Fundamentals and Programming* — multiple ORB ports |

### Graphics and OpenGL

| Folder | Description |
|--------|-------------|
| [`OpenGLSurefire/`](OpenGLSurefire/) | OpenGL/GLUT demo (macOS Makefile) |
| [`qknots/`](qknots/) | Quaternion knot visualization |
| [`texturemapping/`](texturemapping/) | OpenGL texture-mapping package demos |
| [`RGBtoGLByte/`](RGBtoGLByte/) | RGB to OpenGL byte conversion utility |
| [`Wolf3DSrc/`](Wolf3DSrc/) | Wolfenstein 3D–era engine sources (Borland C++ 3.x) |

### Win32 system APIs

| Folder | Description |
|--------|-------------|
| [`Timer/`](Timer/) | Multimedia timer (`timeSetEvent`) demo |
| [`mapfile/`](mapfile/) | Memory-mapped file I/O |
| [`shmemcr/`](shmemcr/) / [`shmemop/`](shmemop/) | Shared-memory creator/operator pair |
| [`winsock/`](winsock/) | Winsock sample |
| [`winCE Winsock/`](winCE%20Winsock/) | Windows CE socket test |
| [`Dialog Wnd/`](Dialog%20Wnd/) | Diagnostic message-box helper library |

### Data structures and math

| Folder | Description |
|--------|-------------|
| [`Bin Tree/`](Bin%20Tree/) | Template binary tree header (`Bintree.h`) |
| [`LISTS/`](LISTS/) | Linked-list utilities |
| [`QSort/`](QSort/) | Quicksort demo |
| [`MATH/`](MATH/) | Math routines |
| [`Matrix/`](Matrix/) | Matrix class and test harness |

### C++Builder / Borland

| Folder | Description |
|--------|-------------|
| [`C++Builder/`](C%2B%2BBuilder/) | Components, DB connectivity, OpenGL, bitmap demos |
| [`DLLTest/`](DLLTest/) | DLL export/import tests |
| [`dvcrpage/`](dvcrpage/) | Device-context page demo |

### Tools, tests, and misc

| Folder | Description |
|--------|-------------|
| [`ExceptionTest/`](ExceptionTest/) | C++ exception handling demo |
| [`fstreamTest/`](fstreamTest/) | Standard fstream I/O test |
| [`surlecul/`](surlecul/) | IOCCC-style obfuscated C curiosity |
| [`VisioPlugIn/`](VisioPlugIn/) | Visio VSL add-on: enumerate network resources |
| [`archives/`](archives/) | Historical zip archives (not built from source here) |

## Build expectations

| Toolchain | Typical projects |
|-----------|------------------|
| **Visual C++ 5/6** (`.dsp`, `.dsw`) | Most Win32, MFC, COM samples |
| **Visual Basic 6** (`.vbp`) | ActiveListBox |
| **Borland C++Builder** (`.bpr`, `.bpg`) | C++Builder/, DLLTest, Wolf3DSrc |
| **Borland C++ 3.x** | Wolf3DSrc |
| **Modern clang++/g++** | philsophe (C++17, pthreads) |
| **Legacy CORBA ORB + make** | CORBA/ subdirectories |

Generated IDE folders (`Debug/`, `Release/`, `.ncb`, etc.) may appear in the tree from original development; they are not required to build from source.

## Documentation convention

- **`README.md`** — Primary entry point for each folder (purpose, build, run).
- **`ReadMe.txt` / `README.TXT`** — Original notes preserved from the era of the code; linked or summarized in the Markdown README where relevant.

## CI

GitHub Actions builds the cross-platform [`philsophe`](philsophe/) project on push/PR to `main`. Most Windows-only projects are not compiled in CI; build them locally with the appropriate legacy IDE.

## License

See [`LICENSE`](LICENSE) (LGPL 2.1) for repository-level terms. Individual subprojects may carry their own copyright notices (e.g. CORBA POS example — OMG/Wiley 1996; Scott Robert Ladd components; Visio Corporation SDK headers in VisioPlugIn).

## Archives

Historical material that is not part of the buildable source tree lives under [`archives/`](archives/).
