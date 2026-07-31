# Other and Mixed-Language Collections

This directory holds projects that do not fit cleanly into the C or C++
categories. It includes Visual Basic ActiveX work, a multi-language CORBA
reference suite, and packaged historical archives.

## Project index

| Project | Languages or format | Represents | Build expectation |
|---|---|---|---|
| [`ActiveListBox`](ActiveListBox/) | Visual Basic 6 (`.vbp`, `.ctl`) | An ActiveX list-box control project | Open with VB6; test with [`../C++/ActiveListBoxTest`](../C%2B%2B/ActiveListBoxTest/) |
| [`CORBA`](CORBA/) | C, C++, IDL, shell/batch, make | A point-of-sale example ported to numerous 1990s CORBA ORBs | Requires one of the matching historical ORBs and its IDL compiler |
| [`RemoteShell OCX`](RemoteShell%20OCX/) | Visual Basic 6 host plus packaged OCX | An rsh/rexec-style remote-command ActiveX control and test form | Requires Windows, VB6 runtime, and a suitably configured remote service |
| [`archives`](archives/) | ZIP packages | Windows Developer Journal reader submissions retained in original packaging | Extract for inspection; not part of a repository build |

## Why these are separate

- `ActiveListBox` and `RemoteShell OCX` are Visual Basic/ActiveX artifacts, not
  C or C++ source projects.
- `CORBA` deliberately contains parallel C, C++, and IDL implementations. Its
  comparison value would be lost if those trees were separated by language.
- `archives` preserves original packages rather than normalized source trees.

## Safety and compatibility

The remote-shell control relies on obsolete and insecure rsh/rexec protocols;
it should only be studied or tested in an isolated historical environment.
Packaged binaries and archives should be treated as untrusted legacy artifacts.
The CORBA examples require vendor middleware that may no longer be available.

Return to the [repository guide](../README.md).
