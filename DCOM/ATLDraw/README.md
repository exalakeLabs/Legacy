# ATLDraw

**DCOM client** (ATL/MFC): connects to the DrawServ COM object and draws in a window. Use menu Server.Connect to attach to the server; draw by dragging with the left mouse—lines appear on all connected clients. View.Color sets the drawing color per client. See parent **DCOM** README for registering the server and configuring DCOMCNFG.

## Build and run

Build with Visual C++ (ATLDraw project). Run on client machines; ensure DrawServ is registered and the server location is set in DCOMCNFG.
