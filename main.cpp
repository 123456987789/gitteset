/*
 * Filename: main.cpp
 * Author: LucianY
 * Brief: ExactTime类测试
 */

#include <iostream>

#include "exact_time.hpp"

int
main() {
  Ly::ExactTime exact_time = Ly::ExactTime::currentTime();
  std::cout << "当前时间：" << exact_time.toString() << std::endl;
  return 0;
}
