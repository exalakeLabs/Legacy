// Cross-platform philosophers demo

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace {

constexpr int NUM_PHILO = 5;
constexpr int NUM_BOUCHEE = 100;

std::mutex critSec;
std::atomic<int> count{0};

void Philosophe(int id) {
  std::cout << "My Philosophe ID is : " << id << std::endl;

  for (int i = 0; i < NUM_BOUCHEE; ++i) {
    std::lock_guard<std::mutex> lock(critSec);
    ++count;
  }
}

}  // namespace

int main() {
  std::vector<std::thread> philosophers;
  philosophers.reserve(NUM_PHILO);

  for (int i = 0; i < NUM_PHILO; ++i) {
    philosophers.emplace_back(Philosophe, i);
  }

  for (auto& t : philosophers) {
    t.join();
  }

  std::cout << "Dinner done... total bites = " << count.load() << std::endl;
  return 0;
}
