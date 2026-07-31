# C++BuilderComponent

Custom **C++Builder design-time package** with OpenGL-enabled VCL controls for embedding hardware-accelerated rendering in forms.

## Components

| Folder | Control | Role |
|--------|---------|------|
| [`OpenGLControl/`](OpenGLControl/) | OpenGLControl | Base OpenGL rendering control |
| [`TOpenGL/`](TOpenGL/) | TOpenGL | OpenGL component variant |
| [`TOpenGLPanel/`](TOpenGLPanel/) | TOpenGLPanel | Panel that hosts an OpenGL context |

**OpenGLPerspective** and other demos link `TOpenGLPanel` after this package is installed.

## Install

Build the component package (`.dpk` / project group in this tree) in C++Builder 1.x–3.x, then **Install** into the IDE component palette. Rebuild any dependent projects (e.g. OpenGLPerspective) against the installed BPL.

See the parent [**C++Builder** README](../README.md).
