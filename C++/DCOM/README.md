# DCOM

**Distributed COM** sample: a COM object implemented inside an NT service, called from clients on the same or different machines. DrawServ is the service hosting the object; ATLDraw is a client that draws in a window (lines appear on all connected clients); DrawCtl is a control with Connect/Disconnect (machine name parameter).

## Parts

| Project | Description |
|---------|-------------|
| **DrawServ** | NT service that implements the COM drawing object. Register with `DrawServ /RegServer`; start via Control Panel → Services. |
| **ATLDraw** | Client app: Server.Connect from menu, then draw with left mouse; lines are replicated to other clients connected to the same server. View.Color changes color per client. |
| **DrawCtl** | Control version: Connect(machine name), Disconnect. |

## Requirements

- NT 4.0 Beta 2 or later on all machines.
- Copy DrawServ.exe and ATLDraw.exe to each machine; register the server on each. Use DCOMCNFG on clients to set the server location to the machine running the service. See `DCOM.txt` in this folder for full steps.
