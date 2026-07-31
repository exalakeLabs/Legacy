# CORBA

CORBA **POS (Point of Sale) example** from the book *CORBA Fundamentals and Programming* (Jon Siegel et al., 1996). Contains implementations for multiple ORBs plus generic C and C++ porting layers. Used for teaching CORBA and comparing ORB vendors.

Copyright and permissions are in [`README.TXT`](README.TXT) (OMG / John Wiley & Sons, 1996).

## Layout

| Directory | Role |
|-----------|------|
| [`IDL/`](IDL/) | Standard IDL definitions shared across ORBs |
| [`GENC/`](GENC/) | Generic **C** skeleton for porting to C ORBs |
| [`GENCPP/`](GENCPP/) | Generic **C++** skeleton (UTIL, PNS, POS, CENTRAL, STORE) |
| [`NEO/`](NEO/) | NEO ORB port |
| [`ORBIX/`](ORBIX/) | Iona Orbix port (IDL, LAUNCHER, Makefiles) |
| [`ORBPLUS/`](ORBPLUS/) | ORBPlus port |
| [`EXPERSFT/`](EXPERSFT/) | Expersoft ORB port |
| [`SOM/`](SOM/) | IBM SOM (System Object Model) port |
| [`DAIS/`](DAIS/) | DAIS ORB port |
| [`DST/`](DST/) | DST ORB / reference port |
| [`OBJBRKR/`](OBJBRKR/) | Object Broker port |
| [`TARFILES/`](TARFILES/) | Unix tarballs with long mixed-case filenames |

Smalltalk sources from the book are generic and were not duplicated on the original diskette.

## PC vs Unix

- **PC (DOS/Windows/NT):** Use the directory named for your ORB. Filenames may be 8.3 uppercase; local README or scripts restore book-correct names.
- **Unix:** Extract the matching tarball from [`TARFILES/`](TARFILES/) to recreate the original directory tree, then follow that ORB’s Makefile.

Code is duplicated between ORB directories and TARFILES—use one or the other, not both.

## Build

Each ORB directory includes its own Makefile(s) and README. Steps depend entirely on which ORB you have installed. See the book or vendor documentation for compile and run order (typically IDL → skeletons → servers → client).

Updated sources were historically available from [omg.org](https://www.omg.org).
