# C Projects

This directory contains five projects whose primary implementation language is
C. They range from small Win32 utilities to a complete DOS-era game source
archive. None share a common build system.

## Project index

| Project | Target | Kind | Toolchain | Current expectation |
|---|---|---|---|---|
| [`main-puzzle`](main-puzzle/) | Console | Obfuscated-code curiosity | Any permissive C compiler; originally Visual C++ | Small enough to port, but intentionally non-idiomatic |
| [`OCXREG`](OCXREG/) | Win32 | ActiveX registration utility | Visual C++ and Win32/OLE SDK | Requires Windows |
| [`winCE Winsock`](winCE%20Winsock/) | Windows CE | Socket test application | Historical Windows CE SDK | Requires a matching CE SDK/device or emulator |
| [`winsock`](winsock/) | Win32 | Socket client/server sample | Visual C++ and Winsock | Requires Windows and minor modernization |
| [`Wolf3DSrc`](Wolf3DSrc/) | DOS/16-bit x86 | Game-engine source archive | Borland C++ 3.x and x86 assembler | Preservation source; substantial porting required |

## What belongs here

- C is the primary hand-written source language.
- Generated resource files and assembly helpers may accompany a C project.
- Mixed C/C++/IDL collections belong in [`../Others/`](../Others/) rather than
  being split across language directories.

## Build notes

The Windows projects use project formats and APIs from their original era.
Open a project’s local README before attempting a build. In particular:

- `.dsp` files are Visual C++ 5/6 projects.
- Windows CE projects require platform-specific SDK headers and libraries.
- Wolf3DSrc assumes segmented memory models and Borland-specific behavior.
- Generated object, debug-database, incremental-link, and library files are not
  part of the curated source tree.

Return to the [repository guide](../README.md).
