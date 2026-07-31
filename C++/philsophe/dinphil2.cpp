// Cross-platform dining philosophers (version 2)

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace {

constexpr int numPhilosophers = 20;

std::mutex chopsticks[numPhilosophers];
char csStat[numPhilosophers + 1];
char pStat[numPhilosophers + 1];

int randomDelayMs() {
  return std::rand() % 50;
}

void PhilosopherThread(int id) {
  while (true) {
    // thinking
    std::this_thread::sleep_for(std::chrono::milliseconds(randomDelayMs()));

    // hungry, so picks up chopsticks
    int right = (id + 1) % numPhilosophers;
    std::unique_lock<std::mutex> left(chopsticks[id], std::defer_lock);
    std::unique_lock<std::mutex> rightLock(chopsticks[right], std::defer_lock);
    std::lock(left, rightLock);

    csStat[id] = '1';
    csStat[right] = '1';
    pStat[id] = '1';

    // eating
    std::cout << csStat << "  " << pStat << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(randomDelayMs()));

    // done eating
    pStat[id] = '0';
    csStat[id] = '0';
    csStat[right] = '0';
    // mutexes released automatically by unique_lock destructors
  }
}

}  // namespace

int main() {
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  csStat[numPhilosophers] = '\0';
  pStat[numPhilosophers] = '\0';

  // Create the philosopher threads
  std::vector<std::thread> threads;
  threads.reserve(numPhilosophers);

  for (int i = 0; i < numPhilosophers; ++i) {
    threads.emplace_back(PhilosopherThread, i);
  }

  // Wait for all threads to finish execution (threads run indefinitely)
  for (auto& t : threads) {
    t.join();
  }

  return 0;
}
