# fstreamTest

Small console app to exercise C++ **fstream** binary I/O. Writes a struct (`toto`: two ints) 10,000 times to `test.bin` using `ofstream::write`. Note: the sample uses `ios::in` with `open` for a write operation, which is likely a bug; typically you’d use `ios::out` for writing. Useful as a minimal fstream/struct serialization example.

## Build and run

Visual C++ project: `testfstream.dsp`. Build and run; it creates `test.bin` in the current directory.
