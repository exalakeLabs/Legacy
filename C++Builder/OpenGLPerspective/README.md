# OpenGLPerspective

C++Builder **OpenGL perspective** demo (`Project1.bpr`). Uses the **TOpenGLPanel** component (from [**C++BuilderComponent**](../C++BuilderComponent/)) on a VCL form to render a 3D scene with adjustable rotation and perspective depth.

## Prerequisites

- C++Builder with OpenGL libraries available.
- **TOpenGLPanel** component package installed (see C++BuilderComponent).

## Build and run

Open `Project1.bpr`, build, and run. The form links `#pragma link "TOpenGLPanel"` and drives `glColor`, transforms, and redraw on user input.

See the parent [**C++Builder** README](../README.md).
