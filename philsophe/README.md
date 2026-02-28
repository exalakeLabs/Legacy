# Philsophe

Cross-platform C++ concurrency demos based on the **dining philosophers** problem. Standard C++17 threads and mutexes; builds on macOS (clang++) and other POSIX systems (g++).

## Example programs

| Program | Description |
|--------|-------------|
| **philosophe** | Simple demo: 5 threads each take 100 “bites” under a single shared mutex, then print total bites. Good intro to `std::thread`, `std::mutex`, and `std::atomic`. **Finishes** and prints a result. |
| **dinphil** | Classic dining philosophers: 5 philosophers, each needs two adjacent “chopsticks” (mutexes) to eat. Uses `std::lock` to acquire both without deadlock. Prints chopstick/philosopher state each time someone eats. **Runs indefinitely.** |
| **dinphil2** | Same idea as dinphil but with 20 philosophers and faster timing. **Runs indefinitely.** |

## dinphil vs dinphil2

| Aspect | dinphil.cpp | dinphil2.cpp |
|--------|-------------|--------------|
| **Philosophers** | 5 (`numPhil`) | 20 (`numPhilosophers`) |
| **Delay range** | 100–150 ms (think/eat) | 0–50 ms |
| **Print order** | After acquiring chopsticks, before eating | During eating (right after updating stats) |
| **Startup** | Header lines and explicit `csStat`/`pStat` init to `'0'` | No header; only null-terminates status strings |
| **Naming** | Mutexes `cs`, neighbor `id2` | Mutexes `chopsticks`, neighbor `right` |

Both use the same deadlock-free pattern: `std::lock(left, right)` to take two chopsticks atomically.

## Build and run

```bash
make          # build all three binaries
make clean    # remove object files and binaries

./philosophe  # 5 threads, 100 bites each, then exits
./dinphil     # 5 philosophers, continuous (Ctrl+C to stop)
./dinphil2    # 20 philosophers, continuous (Ctrl+C to stop)
```

On macOS the Makefile uses `clang++` and defines `PLATFORM_MACOS`; elsewhere it uses `g++`.
