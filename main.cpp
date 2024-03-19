#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> atomicCounter(0);

void
incrementCounter() {
  for (int i = 0; i < 10000; ++i) {
    atomicCounter.fetch_add(1);
  }
}

int
main() {
  std::thread t1(incrementCounter);
  std::thread t2(incrementCounter);

  t1.join();
  t2.join();

  std::cout << "Final Counter Value: " << atomicCounter.load() << std::endl;

  return 0;
}