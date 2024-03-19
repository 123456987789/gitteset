/*
 * Copyright(C)
 * Filename: exact_time.h
 * Author: LucianY
 * Brief: 精确时间类，精确到微妙
 * Dependencies: C++11
 * Update log:
 *     7) 20201112 V2.2.0
 *         1, 代码优化：去除“数据成员设置函数”。
 *         2, 接口增加：新增构造函数ExactTime(const std::tm&, int, int)。
 */

#ifndef LY_EXACT_TIME_HPP
#define LY_EXACT_TIME_HPP

#include <ctime>
#include <string>

namespace Ly {

//
// \brief: 精确时间类
//
class ExactTime : public std::tm {
public:
  //! 默认构造函数
  ExactTime() : tm_millisec(0), tm_microsec(0) {}

  //! 构造函数（重载）
  ExactTime(const std::tm &_tm, int _tm_millisec, int _tm_microsec)
      : std::tm(_tm), tm_millisec(_tm_millisec), tm_microsec(_tm_microsec) {}

  //! 转换为字符串（此字符串含有':'，不能用于文件名）
  std::string toString() const;

  //! 转换为字符串，可用于文件名
  std::string toStringForFilename() const;

  //! 获取当前时间
  static ExactTime currentTime();

private:
  int tm_millisec; // 毫秒
  int tm_microsec; // 微秒
};

} // namespace Ly
#endif // LY_EXACT_TIME_HPP
