# DrawServ

**NT service** that hosts the DCOM drawing object. Implements the COM server (IDL in `DrawServ.idl`); when running, clients (ATLDraw or DrawCtl) connect and receive drawing updates. Register with `DrawServ /RegServer`; start and stop via Control Panel → Services. See parent **DCOM** README for full setup and DCOMCNFG configuration.

## Build and run

Build with Visual C++ (`DrawServ.dsp` / `DrawServ.mak`). Copy the executable to each machine; on the server machine run `DrawServ /RegServer` then start the service.
