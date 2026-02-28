# qknots

**OpenGL/GLUT** demo that draws a “quadruple knot” using NURBS (`GLUnurbsObj`). Defines control points and knot vectors, then renders the curve with `gluBeginCurve`/`gluNurbsCurve`/`gluEndCurve`. Includes simple 2D text (raster position) and uses a 500px window.

## Build and run

- Visual C++: `test.dsp`. Requires OpenGL and GLUT libraries.
- Run the executable to view the NURBS knot; ensure the knot vector is consistent with `numPoints` (e.g. 10 points, 14 knots).
