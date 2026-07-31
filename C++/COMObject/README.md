# COMObject

**In-process COM server** (DLL) that exposes a simple COM object (`CObject1`) with a method `PopMessageBox(CHAR *message, INT hWnd)` that shows a message box. Built with MFC and ATL-style COM (IDL, `Object1.cpp`/`.h`). Use as a minimal COM server to test with **COMClient** or any COM client.

## Build and run

- Visual C++: build the COMObject DLL project. Register the DLL (e.g. `regsvr32 COMObject.dll`).
- From COMClient or another client, create the object and call `PopMessageBox` to see the message box.
