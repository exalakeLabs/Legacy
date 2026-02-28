# COMClient

MFC **dialog-based** application that acts as a COM **client**: it uses the Microsoft Foundation Classes and can drive Automation (OLE) objects. Includes an automation proxy class for the main dialog. Use it to test or demonstrate calling COM servers from an MFC app.

## Build and run

- Visual C++: `COMClient.dsp`. Build the executable.
- Run COMClient; use the dialog to invoke COM/Automation objects (customize the dialog and proxy as needed for your server).
