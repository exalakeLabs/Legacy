# Legacy Software Archive

A curated collection of 43 programming projects, demonstrations, reusable
components, and experiments from the 1990s and early 2000s.

The archive is organized by implementation language:

| Directory | Projects | Contents |
|---|---:|---|
| [`C++/`](C%2B%2B/) | 34 | C++, MFC, COM/ActiveX, Win32, OpenGL, and Borland C++Builder |
| [`C/`](C/) | 5 | C, Win32 C, Windows CE, and C with x86 assembly |
| [`Others/`](Others/) | 4 | Visual Basic, mixed C/C++/IDL CORBA, and historical archives |

These projects are preserved primarily for study and historical reference.
Most target discontinued operating systems, SDKs, compilers, or middleware and
are not expected to build unchanged with a current toolchain.

## Quick start

There is no single root build. Each project is self-contained and usually has
its own `README.md`, legacy IDE project file, or Makefile.

| Goal | Start here |
|---|---|
| Build a project on modern macOS or Linux | [`C++/philsophe/`](C%2B%2B/philsophe/) |
| Study Win32 processes and synchronization | [`C++/Process/`](C%2B%2B/Process/) and [`C++/Proc&Thread/`](C%2B%2B/Proc%26Thread/) |
| Explore COM, DCOM, and ActiveX | [`C++/COMObject/`](C%2B%2B/COMObject/), [`C++/COMClient/`](C%2B%2B/COMClient/), and [`C++/DCOM/`](C%2B%2B/DCOM/) |
| Browse OpenGL demonstrations | [`C++/OpenGLSurefire/`](C%2B%2B/OpenGLSurefire/) and [`C++/texturemapping/`](C%2B%2B/texturemapping/) |
| Study a legacy game codebase | [`C/Wolf3DSrc/`](C/Wolf3DSrc/) |
| Compare historical CORBA implementations | [`Others/CORBA/`](Others/CORBA/) |

## C++ projects

### Windows, MFC, COM, and ActiveX

| Project | Description |
|---|---|
| [`ActiveListBoxTest`](C%2B%2B/ActiveListBoxTest/) | MFC test host for the Visual Basic ActiveListBox control |
| [`CLSIDTest`](C%2B%2B/CLSIDTest/) | COM class/category identifier lookup experiment |
| [`COMClient`](C%2B%2B/COMClient/) | MFC client for the COMObject in-process server |
| [`COMObject`](C%2B%2B/COMObject/) | MFC/COM in-process automation server |
| [`DCOM`](C%2B%2B/DCOM/) | Distributed drawing service, client, and control samples |
| [`DLLTest`](C%2B%2B/DLLTest/) | Borland C++ DLL import/export experiments |
| [`Dialog Wnd`](C%2B%2B/Dialog%20Wnd/) | Small diagnostic dialog/window helper |
| [`dllDialog`](C%2B%2B/dllDialog/) | MFC dialog exported from a Windows DLL |
| [`VisioPlugIn`](C%2B%2B/VisioPlugIn/) | Visio VSL add-on that diagrams network resources |
| [`XFloorWnd`](C%2B%2B/XFloorWnd/) | ActiveX tabbed “floor” navigation control |
| [`XPropertiesWnd`](C%2B%2B/XPropertiesWnd/) | ActiveX property and shell-tree controls |

### Processes, threads, and Win32 APIs

| Project | Description |
|---|---|
| [`CreatePipe`](C%2B%2B/CreatePipe/) | Parent/child process communication through a named pipe |
| [`OldProcWrap`](C%2B%2B/OldProcWrap/) | Legacy process-wrapper experiment |
| [`Proc&Thread`](C%2B%2B/Proc%26Thread/) | Process, thread, wait, and signaling examples |
| [`Process`](C%2B%2B/Process/) | Mutex, semaphore, event, critical-section, and overlapped-I/O samples |
| [`shmemcr`](C%2B%2B/shmemcr/) | Shared-memory creator half of a paired example |
| [`shmemop`](C%2B%2B/shmemop/) | Shared-memory opener half of a paired example |
| [`ThreadTest`](C%2B%2B/ThreadTest/) | Windows thread creation and synchronization test |
| [`Timer`](C%2B%2B/Timer/) | Win32 multimedia timer demonstration |
| [`mapfile`](C%2B%2B/mapfile/) | Memory-mapped file examples |

### Graphics and user interfaces

| Project | Description |
|---|---|
| [`C++Builder`](C%2B%2B/C%2B%2BBuilder/) | Borland C++Builder components, database, bitmap, service, and OpenGL samples |
| [`OpenGLSurefire`](C%2B%2B/OpenGLSurefire/) | OpenGL/GLUT texture and rendering demonstration |
| [`qknots`](C%2B%2B/qknots/) | Quaternion-knot visualization |
| [`RGBtoGLByte`](C%2B%2B/RGBtoGLByte/) | RGB image conversion for OpenGL byte data |
| [`texturemapping`](C%2B%2B/texturemapping/) | Texture mapping, lighting, transparency, Gouraud shading, and antialiasing demos |

### Algorithms, containers, and language experiments

| Project | Description |
|---|---|
| [`Bin Tree`](C%2B%2B/Bin%20Tree/) | Header-only template binary tree |
| [`ExceptionTest`](C%2B%2B/ExceptionTest/) | C++ exception-handling experiment |
| [`fstreamTest`](C%2B%2B/fstreamTest/) | Standard stream and file-I/O test |
| [`LISTS`](C%2B%2B/LISTS/) | Linked-list implementation and test |
| [`math`](C%2B%2B/math/) | Small numerical routine experiment |
| [`Matrix`](C%2B%2B/Matrix/) | Matrix class and test harness |
| [`philsophe`](C%2B%2B/philsophe/) | Modern C++17 dining-philosophers concurrency demos |
| [`QSort`](C%2B%2B/QSort/) | Quicksort implementation and test |

### Platform-specific samples

| Project | Description |
|---|---|
| [`dvcrpage`](C%2B%2B/dvcrpage/) | Borland C++Builder device-context page sample |

## C projects

| Project | Description |
|---|---|
| [`main-puzzle`](C/main-puzzle/) | IOCCC-style obfuscated recursive C program |
| [`OCXREG`](C/OCXREG/) | Command-line utility for registering OCX controls |
| [`winCE Winsock`](C/winCE%20Winsock/) | Windows CE socket test |
| [`winsock`](C/winsock/) | Classic Win32 Winsock client/server sample |
| [`Wolf3DSrc`](C/Wolf3DSrc/) | Wolfenstein 3D–era C and x86 assembly sources for Borland C++ 3.x |

## Other and mixed-language projects

| Project | Language or format | Description |
|---|---|---|
| [`ActiveListBox`](Others/ActiveListBox/) | Visual Basic 6 | ActiveX list-box control |
| [`CORBA`](Others/CORBA/) | C, C++, IDL, and build scripts | Point-of-sale example ported across multiple historical CORBA ORBs |
| [`RemoteShell OCX`](Others/RemoteShell%20OCX/) | Visual Basic 6 / packaged OCX | Remote-shell ActiveX control and test application |
| [`archives`](Others/archives/) | ZIP archives | Original historical packages retained for reference |

## Toolchains and compatibility

| Toolchain or dependency | Typical projects |
|---|---|
| Visual C++ 5/6 (`.dsp`, `.dsw`) | Most MFC, Win32, COM, and OpenGL projects |
| Visual Basic 6 (`.vbp`, `.frm`, `.ctl`) | ActiveListBox and RemoteShell OCX |
| Borland C++Builder (`.bpr`, `.bpg`, `.dfm`) | C++Builder, DLLTest, and dvcrpage |
| Borland C++ 3.x and an x86 assembler | Wolf3DSrc |
| Legacy CORBA ORB and IDL compiler | CORBA subprojects |
| Modern Clang or GCC with C++17 threads | philsophe |

Legacy Visual Studio files often contain relative paths and assumptions about
SDK installation directories. Moving a complete project folder into its
language category preserves paths internal to that folder, but machine-specific
toolchain paths may still require adjustment.

## Building the modern C++ example

The dining-philosophers project is the only project exercised by continuous
integration:

```sh
cd "C++/philsophe"
make clean all
./philosophe
```

The other projects should be built from inside their individual directories
with the compiler or IDE documented in their local README.

## Repository conventions

- `README.md` provides modern navigation and build notes.
- `ReadMe.txt`, `README.TXT`, and similar files preserve original documentation.
- Original filenames and project-internal layouts are retained where practical.
- Generated compiler and linker artifacts are excluded by the root `.gitignore`.
- Historical binaries already committed to the archive remain available for
  research, even when files with the same extensions are now ignored.

## Continuous integration

The GitHub Actions smoke test builds and runs
[`C++/philsophe`](C%2B%2B/philsophe/) on Ubuntu. Windows-only and
middleware-dependent projects are not compiled in CI.

## License and third-party notices

Repository-level terms are in [`LICENSE`](LICENSE) (LGPL 2.1). Some imported
examples and SDK materials include their own notices, including the CORBA POS
example, third-party C++ components, and historical Visio SDK headers. Review
the documentation and source headers within a project before redistributing it.

## Archive status

This repository favors preservation over modernization. A successful build may
require a virtual machine, an older Windows SDK, original middleware, or small
source changes for modern compiler compatibility. Contributions that improve
documentation, portability, or reproducibility should preserve the intent and
history of the original examples.
