# BCBComponent-NTServices

**Windows NT administration** VCL components for Delphi 2/3/4 and C++Builder 1/3:

| Component | Purpose |
|-----------|---------|
| **TNTService** | Add, delete, control, and configure NT services |
| **TNTEventLog** | Read/write event log entries (TStringList-like API) |
| **TNTUserMan** | User and group management |
| **TNTShare** | Share management and connected-user monitoring |
| **TNTFileSecurity** | NTFS file ACL assignment |
| **TNTRegSecurity** | Registry security |

## Install

| IDE | Steps |
|-----|-------|
| **Delphi 4** | Open `NTSet.bpg`; compile and install `NT.bpl` |
| **Delphi 3** | Open `NT.DPK`, compile, install; set library path to NT.DPL directory |
| **Delphi 2** | Component → Install; add `NTReg.dcu`, `RegEdtrs.dcu` |
| **C++Builder 3** | Open `library.bpg`, compile all; copy `ntrtl.bpl` to system BPL path |

Demo projects under `examples/` (NTServ, UserMan, etc.) require the package installed first.

Full per-version notes: [`readme.txt`](readme.txt) (original). See the parent [**C++Builder** README](../README.md).
