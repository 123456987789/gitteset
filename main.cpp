#include "line.h"

#include <iostream>

int
main() {
  // 下面是调用:

  CxString string1(24); // 这样是OK的, 为CxString预分配24字节的大小的内存
  CxString string2 = 10; // 这样是OK的, 为CxString预分配10字节的大小的内存
  CxString string3; // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”:
                    // 没有合适的默认构造函数可用
  CxString string4("aaaa"); // 这样是OK的
  CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)
  CxString string6 = 'c'; // 这样也是OK的, 其实调用的是CxString(int size),
                          // 且size等于'c'的ascii码
  string1 = 2; // 这样也是OK的, 为CxString预分配2字节的大小的内存
  string2 = 3; // 这样也是OK的, 为CxString预分配3字节的大小的内存
  string3 = string1; // 这样也是OK的, 至少编译是没问题的, 但是如果析构函数里用
  return 0;
}