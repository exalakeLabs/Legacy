# GENCPP

**Generic C++** porting layer for the CORBA POS example. Subdirectories mirror the example architecture:

| Subdir | Purpose |
|--------|---------|
| **UTIL** | Shared utilities |
| **PNS** | Product naming service |
| **POS** | Point-of-sale terminal |
| **CENTRAL** | Central server |
| **STORE** | Store server |

Use this tree as a starting point when adapting the book example to a C++ ORB that is not one of the pre-built vendor ports. Build with the Makefiles in each subfolder once your ORB’s IDL compiler and runtime are configured.

See the main [**CORBA** README](../README.md) and [`README.TXT`](../README.TXT) for copyright and overall layout.
