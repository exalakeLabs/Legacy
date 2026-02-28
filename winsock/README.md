# winsock

**Windows Sockets** sample (Microsoft source). Demonstrates the Winsock API: two instances of the app can connect to each other, and the app can display information about a host. Uses TCP, listen/accept, and dialog-based UI. Original: `wsock.c` / `WSOCK.C`, with `DIALOGS.C`, `strutils.c++`, and resources.

## Build and run

- Use the provided `MAKEFILE` or open the WSOCK project in Visual C++ (resource/project files present). Link with Winsock library (e.g. `wsock32.lib`).
- Run two copies; connect one to the other and exchange data. Use the dialogs to query host info.
