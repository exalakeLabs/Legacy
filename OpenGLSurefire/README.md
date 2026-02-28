# OpenGLSurefire

**OpenGL/GLUT** demo: “Surefire” — a central sphere (or cube/ring) with orbiting spheres, textured and lit. Uses `sgi.h`/`sgi.cpp` for SGI-style helpers. Builds on macOS (GLUT) and other platforms with GLUT. Subdirs `64`, `128`, `256` may hold resolution-specific assets or builds.

## Build and run

```bash
make          # build surefire
./surefire    # run the demo
```

Requires OpenGL and GLUT. Use the Makefile in this directory.
