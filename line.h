#ifndef __LINE_H__
#define __LINE_H__

#include <string.h>
#include <memory.h>
#include <stdlib.h>

class CxString // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
public:
  char *_pstr;
  int _size;
  CxString(int size) {
    _size = size;                     // string的预设大小
    _pstr = (char *)malloc(size + 1); // 分配string的内存
    memset(_pstr, 0, size + 1);
  }
  CxString(const char *p) {
    int size = strlen(p);
    _pstr = (char *)malloc(size + 1); // 分配string的内存
    strcpy(_pstr, p);                 // 复制字符串
    _size = strlen(_pstr);
  }
  // 析构函数这里不讨论, 省略...
};

#endif
