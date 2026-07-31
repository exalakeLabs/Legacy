# C++ Projects

This directory contains 34 independent C++ projects. Most are Windows examples
written for Visual C++ 5/6, MFC, COM, or Borland C++Builder. A smaller group
covers algorithms, concurrency, file I/O, and OpenGL.

## Windows components and applications

| Project | Purpose | Main technology | Output |
|---|---|---|---|
| [`ActiveListBoxTest`](ActiveListBoxTest/) | Host and exercise the Visual Basic ActiveListBox control | MFC, ActiveX | Dialog application |
| [`CLSIDTest`](CLSIDTest/) | Inspect and modify COM component categories | Win32 COM | Console utility |
| [`COMClient`](COMClient/) | Invoke an Automation/COM server from MFC | MFC, OLE Automation | Dialog application |
| [`COMObject`](COMObject/) | Expose a minimal message-box COM object | MFC, COM, IDL | In-process COM DLL |
| [`DCOM`](DCOM/) | Share drawing operations through a remote COM service | DCOM, ATL/MFC, NT service | Server and clients |
| [`DLLTest`](DLLTest/) | Demonstrate class export/import across a DLL boundary | Visual C++, C++Builder | DLL and test apps |
| [`Dialog Wnd`](Dialog%20Wnd/) | Display formatted diagnostic messages by severity | Win32 UI | Source library |
| [`dllDialog`](dllDialog/) | Provide an MFC-based dialog DLL skeleton | MFC | Regular DLL |
| [`VisioPlugIn`](VisioPlugIn/) | Draw discovered network resources in Visio | MFC, Visio VSL | Visio add-on DLL |
| [`XFloorWnd`](XFloorWnd/) | Implement tabbed/floor-style navigation | MFC ActiveX | OCX control |
| [`XPropertiesWnd`](XPropertiesWnd/) | Implement property and shell-tree UI controls | MFC ActiveX | OCX control |

## Processes, threads, and operating-system APIs

| Project | Purpose | APIs or concepts | Runtime |
|---|---|---|---|
| [`CreatePipe`](CreatePipe/) | Capture a child process’s standard output/error | `CreatePipe`, `CreateProcess` | Win32 |
| [`OldProcWrap`](OldProcWrap/) | Prototype a monitored child-process wrapper | Pipes and redirected handles | Win32 |
| [`Proc&Thread`](Proc%26Thread/) | Collect small process/thread/TLS/wait examples | Win32 process and thread APIs | Win32 |
| [`Process`](Process/) | Compare synchronization and overlapped-I/O primitives | Mutexes, events, semaphores, critical sections | Win32 |
| [`ThreadTest`](ThreadTest/) | Demonstrate worker creation and joining | `CreateThread`, `WaitForSingleObject` | Win32 |
| [`Timer`](Timer/) | Exercise high-resolution periodic callbacks | Multimedia timers, `winmm` | Win32 |
| [`mapfile`](mapfile/) | Read a file through a mapped view | File-mapping APIs | Win32 |
| [`shmemcr`](shmemcr/) | Create and observe a named shared-memory mapping | File mapping | Win32 |
| [`shmemop`](shmemop/) | Open and write the paired shared-memory mapping | File mapping | Win32 |

## Graphics and visual experiments

| Project | Purpose | Main technology | Notes |
|---|---|---|---|
| [`C++Builder`](C%2B%2BBuilder/) | Collect VCL components and example apps | Borland C++Builder/VCL | Contains several subprojects |
| [`OpenGLSurefire`](OpenGLSurefire/) | Render textured and lit orbiting geometry | OpenGL, GLUT | Includes SGI image assets |
| [`qknots`](qknots/) | Render a quadruple knot as a NURBS curve | OpenGL, GLU, GLUT | Visual C++ project |
| [`RGBtoGLByte`](RGBtoGLByte/) | Preserve the “maiden” colored-geometry demo | OpenGL, GLUT | Folder name does not fully describe the program |
| [`texturemapping`](texturemapping/) | Compare texturing, lighting, shading, and antialiasing | MFC-hosted OpenGL | Multi-demo package |

## Algorithms, containers, and language exercises

| Project | Purpose | Form | Portability |
|---|---|---|---|
| [`Bin Tree`](Bin%20Tree/) | Generic binary-tree implementation | Header library | Old template style; adaptable |
| [`ExceptionTest`](ExceptionTest/) | Minimal exception-testing scaffold | Console app | Requires example code to be useful |
| [`fstreamTest`](fstreamTest/) | Test raw struct writes with `fstream` | Console app | Contains a documented open-mode issue |
| [`LISTS`](LISTS/) | Provide deque/context container templates | Source library | Old compiler conventions |
| [`math`](math/) | Approximate square roots iteratively | Console app | Borland headers need updating |
| [`Matrix`](Matrix/) | Implement and exercise a matrix template | Library and test app | Visual C++ project |
| [`philsophe`](philsophe/) | Compare dining-philosopher concurrency variants | Three console apps | Actively smoke-tested with C++17 |
| [`QSort`](QSort/) | Demonstrate recursive integer quicksort | Console app | Straightforward to port |

## Specialized platform sample

| Project | Purpose | Dependency | Output |
|---|---|---|---|
| [`dvcrpage`](dvcrpage/) | Expose properties for a D-VCR/DirectShow component | Historical DirectShow SDK | Property-page DLL |

## Build status

[`philsophe`](philsophe/) is the only project built in CI and is the recommended
starting point for a current compiler. The remaining projects are curated as
historical samples and generally require their original Windows SDK, IDE, or
third-party dependency.

Moving an entire project under this directory preserves its internal relative
paths. Absolute SDK paths and references to projects in other language
directories may still need manual correction in a legacy IDE.

Return to the [repository guide](../README.md).
