# ActiveListBoxTest

MFC **dialog-based** application “DialogTester” for hosting and exercising the
Visual Basic [`ActiveListBox`](../../Others/ActiveListBox/) control. Generated
Automation wrapper files (`_activelistbox.cpp` and `_activelistbox.h`) expose
the control to the C++ dialog.

## Build and run

- Visual C++: `DialogTester.dsp` (or the project file in this folder). Build and run the executable.
- Build and register ActiveListBox first, then make the control available to the
  dialog project through the original ActiveX references.
