//: C07:Mem2.h 
#ifndef MEM2_H 
#define MEM2_H  
#include <cstring>
#include <iostream>

typedef unsigned char byte; 

class Mem { 
  byte* mem; 
  int size; 
  void ensureMinSize(int minSize); 
public: 
  Mem(int sz = 0); 
  Mem(const Mem& m);            // 添加复制构造函数
  Mem& operator=(const Mem& m); // 添加赋值运算符重载函数
  ~Mem(); 
  int msize() const; 
  byte* pointer(int minSize = 0); 

  // 增加了复制构造函数和赋值运算符重载函数
  Mem::Mem(const Mem& m) {
  size = m.size;
  mem = new byte[size];
  memcpy(mem, m.mem, size);
}

Mem& Mem::operator=(const Mem& m) {
  if (this == &m) return *this; // 防止自我赋值
  delete [] mem;                // 释放原有内存
  size = m.size;                // 复制大小
  mem = new byte[size];         // 分配新内存
  memcpy(mem, m.mem, size);     // 复制内容
  return *this;
}

};

#endif // MEM2_H 
