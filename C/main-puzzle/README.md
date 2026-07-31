# main-puzzle

An **IOCCC-style obfuscated C** program preserved as a compiler and code-reading
puzzle. The single recursive `main()` in [`main.c`](main.c) encodes both control
flow and output data in nested conditional expressions. It is intentionally not
an example of maintainable C.

## Build and run

- Visual C++: open `surlecul.dsp`, build, run the console executable.
- A permissive C compiler: compile `main.c` and run the resulting executable.

```sh
cc -o main-puzzle main.c
./main-puzzle
```

Modern compilers may warn about the K&R-style function declaration, implicit
library declarations, and recursive use of `main`. Those constructs are part of
the puzzle’s historical obfuscation.

Pure curiosity—useful as a conversation piece or compiler torture test, not as library code.
