#include "Cpplib.h"
#include <iostream>
using namespace std;
int main()
{
  Stash doubleStash;
  doubleStash.initialize(sizeof(double));

//取入double值
  for(int i=0;i<25;i++){
    double value=i*1.1;
    doubleStash.add(&value);
  }

// 首先，doubleStash.fetch(i)用于从Stash对象中检索在索引i处存储的值，
// 由于Stash对象的fetch()函数返回的是一个void指针，
// 因此需要将其转换为double类型的指针，这就是static_cast<double*>所完成的转换操作。
  for(int i=0;i<doubleStash.count();i++){
    double* valuePtr=static_cast<double*>(doubleStash.fetch(i));
    cout<<*valuePtr<<" ";
  }
  cout<<endl;

  doubleStash.cleanup();
  return 0;
}