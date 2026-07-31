# OCXREG

Console utility to **register or unregister an OCX** (ActiveX control) by calling `DllRegisterServer` or `DllUnregisterServer` from the given DLL. Uses OLE (`OleInitialize`/`OleUninitialize`) and `LoadLibrary`/`GetProcAddress`.

## Usage

```text
ocxreg <control.ocx> <install|uninstall>
```

Example: `ocxreg myctrl.ocx install` or `ocxreg myctrl.ocx uninstall`. Build with Visual C++ (`OCXREG.C` / `OCXREG.DSP`); link with OLE libraries.
