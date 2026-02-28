# DrawCtl

**Control** version of the DCOM client: exposes **Connect** (takes machine name) and **Disconnect** so a host app can connect to the DrawServ COM object on a given computer. Use when embedding the drawing client inside another application. See parent **DCOM** README for server setup.

## Build and run

Build with Visual C++ (DrawCtl project). Register or embed the control in a container; call Connect with the server machine name, then draw as in ATLDraw.
