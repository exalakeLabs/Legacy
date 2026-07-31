# Linux port status

The original Borland/DOS sources remain as the historical reference. New
portable code lives under `src/portable` and uses fixed-width types from
`include/wolf3d/port.h`.

## Build

SDL3 and CMake are required for the interactive target:

```sh
cmake -S . -B build -DWOLF3D_ENABLE_SANITIZERS=ON
cmake --build build
ctest --test-dir build --output-on-failure
./build/wolf3d-port --data-dir /path/to/legal/wl6/data
./build/wolf3d-port --smoke-test
```

The asset and portability tests have no external dependencies and can also be
run with `make test`.

## Implemented foundation

- C11/CMake build with optional ASan and UBSan.
- Explicit DOS-compatible integer widths and little-endian readers.
- Bounds-checked Huffman, Carmack, and RLEW decompression.
- A chunky 320x200 indexed framebuffer with VGA palette conversion.
- SDL3 window, nearest-neighbor presentation, events, and a 70 Hz fixed-step
  timing scaffold.
- Case-tolerant DOS data-file discovery and `--data-dir` support.
- `.WL1`/`.WL6` graphics archive loading and planar `TITLEPIC` presentation.
- Versioned, pointer-free text configuration and XDG path discovery.
- Headless tests and initial Linux desktop packaging metadata.

## Still required for a playable game

- Connect the remaining original cache-manager chunk types to the portable decompressors.
- Translate `WL_DR_A.ASM` and scaler generation to framebuffer-based C.
- Map SDL keyboard, mouse, and gamepad state onto the original `IN_*` API.
- Mix digitized sounds and connect an OPL2 emulator to the `SD_*` API.
- Define a pointer-free save-game schema and optional DOS save importer.
- Replace the demonstration screen in `main.c` with the original game loop.

Retail game data is deliberately not bundled. The historical license in
`README/LICENSE.DOC` must be reviewed before distributing a derivative.
