/*
 * Copyright(C)
 * Filename: exact_time.cpp
 * Author: LucianY
 * Brief: 精确时间类，精确到微妙
 * Dependencies: C++11
 * Update log:
 *     7) 20201112 V2.2.0
 *         1, 代码优化：去除“数据成员设置函数”。
 *         2, 接口增加：新增构造函数ExactTime(const std::tm&, int, int)。
 */

#include "exact_time.hpp"

#include <chrono>

using namespace std::chrono;

namespace Ly {

std::string
ExactTime::toString() const {
  char temp[35]{0};
  snprintf(temp, 35, "%04d-%02d-%02d %02d:%02d:%02d.%03d%03d",
           (tm_year + 1900) % 10000, tm_mon % 12 + 1, tm_mday % 32,
           tm_hour % 24, tm_min % 60, tm_sec % 60, tm_millisec % 1000,
           tm_microsec % 1000);
  return std::string(temp);
}

std::string
ExactTime::toStringForFilename() const {
  char temp[31]{0};
  snprintf(temp, 31, "%04d%02d%02d_%02d%02d%02d.%03d%03d",
           (tm_year + 1900) % 10000, tm_mon % 12 + 1, tm_mday % 32,
           tm_hour % 24, tm_min % 60, tm_sec % 60, tm_millisec % 1000,
           tm_microsec % 1000);
  return std::string(temp);
}

ExactTime
ExactTime::currentTime() {
  auto duration_since_epoch
      = system_clock::now()
            .time_since_epoch(); // 从1970-01-01 00:00:00到当前时间点的时长
  auto microseconds_since_epoch
      = duration_cast<microseconds>(duration_since_epoch)
            .count(); // 将时长转换为微秒数
  time_t seconds_since_epoch = static_cast<time_t>(
      microseconds_since_epoch / 1000000); // 将时长转换为秒数

  ExactTime exact_time;
#if defined _MSC_VER && _MSC_VER >= 1400
  localtime_s(&exact_time, &seconds_since_epoch);
#elif defined __GNUC__
  localtime_r(&seconds_since_epoch, &exact_time);
#else
#  error "Unknown compiler"
#endif
  exact_time.tm_microsec = static_cast<int>(microseconds_since_epoch % 1000);
  exact_time.tm_millisec
      = static_cast<int>(microseconds_since_epoch / 1000 % 1000);

  return exact_time;
}

} // namespace Ly
