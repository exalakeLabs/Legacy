# TARFILES

**Unix tarballs** of ORB-specific CORBA POS directories from the original book diskette.

On Unix, PC-style 8.3 filenames are awkward; extracting the tarball for your ORB recreates the developers’ original mixed-case tree. Each archive corresponds to one vendor port also present as a flat directory at the CORBA root (e.g. NEO, ORBIX, ORBPLUS).

```bash
# Example (exact filename varies by ORB)
tar xvf ORBIX.tar   # then follow that ORB's README / Makefile
```

Use **either** the extracted tarball **or** the matching top-level ORB folder—not both. See the main [**CORBA** README](../README.md).
