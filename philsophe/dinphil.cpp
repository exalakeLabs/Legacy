// Cross-platform dining philosophers (version 1)
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace {

constexpr int numPhil = 5;
constexpr int MIN_MS = 100;  // min # of millisec to think and eat

std::mutex cs[numPhil];
char csStat[numPhil + 1];
char pStat[numPhil + 1];

int randomDelayMs() {
  return MIN_MS + std::rand() % 50;
}

void PhilosopherThread(int id) {
  int id2 = (id + 1) % numPhil;
  while (true) {
    // thinking
    std::this_thread::sleep_for(std::chrono::milliseconds(randomDelayMs()));

    // hungry, so picks up chopsticks
    std::unique_lock<std::mutex> left(cs[id], std::defer_lock);
    std::unique_lock<std::mutex> right(cs[id2], std::defer_lock);
    std::lock(left, right);

    csStat[id] = '1';
    csStat[id2] = '1';
    pStat[id] = '1';
    std::cout << csStat << "  " << pStat << std::endl;

    // eating
    std::this_thread::sleep_for(std::chrono::milliseconds(randomDelayMs()));

    // done eating
    pStat[id] = '0';
    csStat[id] = '0';
    csStat[id2] = '0';
    // mutexes released automatically by unique_lock destructors
  }
}

}  // namespace

int main() { 
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  // Init output
  for (int i = 0; i < numPhil; ++i) {
    csStat[i] = '0';
    pStat[i] = '0';
  }
  csStat[numPhil] = '\0';
  pStat[numPhil] = '\0';

  std::cout << "chops  phils" << std::endl;
  std::cout << "busy   eating" << std::endl;
  std::cout << "-----  -----" << std::endl;

  std::vector<std::thread> threads;
  threads.reserve(numPhil);

  // Create philosopher threads
  for (int i = 0; i < numPhil; ++i) {
    threads.emplace_back(PhilosopherThread, i);
  }

  // Wait for all threads to finish execution (these threads run indefinitely)
  for (auto& t : threads) {
    t.join();
  }

  return 0;
}