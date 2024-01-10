#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
typedef struct CStashTag 
{ int size;      
  int quantity;  
  int next;      
  unsigned char* storage;  
 } CStash;

void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);
const int increment = 100;
/*
结构体部分的作用
size：每个空间的大小（以字节为单位）
quantity：存储空间的数量
next：下一个空闲空间的索引
storage：用于存储数据的指针
函数部分的作用
initialize：初始化 CStash 结构体
cleanup：释放 CStash 结构体占用的资源
add：向 CStash 结构体中添加元素
fetch：从 CStash 结构体中检索元素
count：计算 CStash 结构体中存储的元素数量
inflate：增加 CStash 结构体的存储空间
*/


int main(int arg, char* argv[]) 
{ // Define variables at the beginning
  // of the block, as in C:
  CStash intStash, stringStash;
  int i;
  char* cp;
  ifstream in;
  string line;
  const int bufsize = 80;
  // Now remember to initialize the variables:
  initialize(&intStash, sizeof(int));
  for(i = 0; i < 100; i++)
    add(&intStash, &i);
  for(i = 0; i < count(&intStash); i++)
    cout << "fetch(&intStash, " << i << ") = "
         << *(int*)fetch(&intStash, i)
         << endl;
  // Holds 80-character strings:
  initialize(&stringStash, sizeof(char)*bufsize);
  in.open("CLibTest.cpp");
  assert(in);
  while(getline(in, line))
      add(&stringStash, line.c_str());
  i = 0;
  while((cp = (char*)fetch(&stringStash,i++))!=0)
       cout << "fetch(&stringStash, " << i << ") = "
              << cp << endl;
  cleanup(&intStash);
  cleanup(&stringStash);
  return 0;  
} 

void initialize(CStash* s, int sz) 
{ s->size = sz;
  s->quantity = 0;
  s->storage = 0;
  s->next = 0;  }
//将自定义结构体初始化


int add(CStash* s, const void* element) 
{ if(s->next >= s->quantity) //Enough space left?
  inflate(s, increment);
      // Copy element into storage,
      // starting at next empty space:
  int startBytes = s->next * s->size;
  unsigned char* e = (unsigned char*)element;
  for(int i = 0; i < s->size; i++)
     s->storage[startBytes + i] = e[i];
  s->next++;
  return(s->next - 1);  // Index number
}
/*
add 函数的作用是向 CStash 结构体中添加元素，参数 s 是指向 CStash 结构体的指针，参数 element 是指向要添加的元素的指针。
该函数首先检查存储空间是否足够，如果不足则调用 inflate 函数增加存储空间。
然后，将要添加的元素从指针 element 所指向的内存中拷贝到 CStash 结构体的 storage 成员变量所指向的内存中，从下一个空闲位置开始存储。
最后，将 next 成员变量增加 1，返回新添加元素的索引号。
*/


void* fetch(CStash* s, int index)
{ // Check index boundaries:
  assert(0 <= index);
  if(index >= s->next)
      return 0; // To indicate the end
  // Produce pointer to desired element:
  return &(s->storage[index * s->size]);
}
/*
fetch 函数的作用是从 CStash 结构体中检索元素，参数 s 是指向 CStash 结构体的指针，参数 index 是要检索的元素的索引号。
该函数首先检查索引号是否越界，如果越界则返回空指针。
否则，计算出要检索的元素的内存地址并返回该地址的指针。
*/


int count(CStash* s)
{ return s->next; /* Elements in CStash */  }
/*
count 函数的作用是计算 CStash 结构体中存储的元素数量
*/


void cleanup(CStash* s)
{  if(s->storage != 0) 
      { cout << "freeing storage" << endl;
        delete []s->storage; }
} 
/*
cleanup 函数的作用是释放 CStash 结构体占用的资源
如果 storage 成员变量不为 nullptr，则释放该指针所指向的内存空间。
*/



void inflate(CStash* s, int increase)
{ assert(increase > 0);
  int newQuantity = s->quantity + increase;
  int newBytes = newQuantity * s->size;
  int oldBytes = s->quantity * s->size;
  unsigned char* b = new unsigned char[newBytes];
  for(int i = 0; i < oldBytes; i++)
     b[i] = s->storage[i]; // Copy old to new
  delete [](s->storage); // Old storage
  s->storage = b; // Point to new memory
  s->quantity = newQuantity;
}
/*
inflate 函数的作用是增加 CStash 结构体的存储空间，参数 s 是指向 CStash 结构体的指针，
参数 increase 是要增加的存储空间的数量。
该函数首先检查增加的空间数量是否大于 0，然后计算出新的存储空间大小并分配新的内存空间。
接着，将旧的数据拷贝到新的内存空间中，并释放旧的内存空间，最后更新 quantity 成员变量。
*/