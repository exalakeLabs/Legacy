# RemoteShell OCX

**ActiveX control** that acts like **rsh/rexec**: log on to a Unix host and run a remote command, with results returned via events. For use from VB or any ActiveX container. Supports sync/async (`Async` property), `ConnectionType` (rsh vs rexec), and properties: `Command`, `Host`, `Username`, `LocalUsername`, `Password`. Events: `ReceiveData`, `AsyncComplete`, `Error`.

## Requirements

- VB 6.0 runtime for the control host.
- Unix server configured for rsh/rexec for the chosen user.

## Usage

Register the OCX, then place the control in a form and set Host, Username, Command, etc.; call `Process` and handle `ReceiveData` (and optionally `AsyncComplete`/`Error`). See `readme.txt` in this folder for full property/method/event details.

## Historical and security note

The folder contains a packaged control and executables rather than the control’s
implementation source. The rsh/rexec protocols transmit or trust credentials in
ways that are unsuitable for modern networks. Treat the binaries as untrusted
legacy artifacts and only inspect them in an isolated environment.
