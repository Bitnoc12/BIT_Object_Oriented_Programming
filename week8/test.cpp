#include "LinearList1.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class SeqList : public LinearList<T>
{
public:
    SeqList(int maxSize = 10);  // 构造函数
    ~SeqList() override;  // 析构函数
    int Size() const override;  // 求最大容量
    int Length() const override;  // 求表长度
    int Search(T& x) const override;  // 在表中搜索给定值x
    int Locate(int i) const override;  // 定位第i个元素
    bool getData(int i, T& x) const override;  // 取第i个表项的值
    void setData(int i, T& x) override;  // 修改第i个表项的值
    bool Insert(int i, T& x) override;  // 在第i个表项后插入x
    bool Remove(int i, T& x) override;  // 删除第i个表项
    bool IsEmpty() const override;  // 判表空
    bool IsFull() const override;  // 判表满
    void Sort() override;  // 排序
    void input() override;  // 输入
    void output() override;  // 输出

private:
    T* data;  // 存储线性表的数组
    int maxSize;  // 线性表的最大容量
    int last;  // 线性表的当前长度
};

// 构造函数
template <typename T>
SeqList<T>::SeqList(int maxSize)
{
    this->maxSize = maxSize;
    data = new T[maxSize];
    last = -1;
}

// 析构函数
template <typename T>
SeqList<T>::~SeqList()
{
    delete[] data;
}

// 求最大容量
template <typename T>
int SeqList<T>::Size() const
{
    return maxSize;
}

// 求表长度
template <typename T>
int SeqList<T>::Length() const
{
    return last ;
}

// 在表中搜索给定值x
template <typename T>
int SeqList<T>::Search(T& x) const
{
    for (int i = 0; i <= last; i++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

// 定位第i个元素
template <typename T>
int SeqList<T>::Locate(int i) const
{
    if (i < 1 || i > last + 1) {
        return -1;
    }
    else {
        return i - 1;
    }
}

// 取第i个表项的值
template <typename T>
bool SeqList<T>::getData(int i, T& x) const
{
    if (i < 1 || i > last + 1) {
        return false;
    }
    else {
        x = data[i - 1];
        return true;
    }
}

// 修改第i个表项的值
template <typename T>
void SeqList<T>::setData(int i, T& x)
{
    if (i >= 1 && i <= last + 1) {
        data[i - 1] = x;
    }
}

template <typename T>
bool SeqList<T>::Insert(int i, T& x)
{
if (last == maxSize - 1) {
return false;
}
if (i < 1 || i > last + 2) {
return false;
}
for (int j = last; j >= i - 1; j--) {
data[j + 1] = data[j];
}
data[i - 1] = x;
last++;
return true;
}

// 删除第i个表项
template <typename T>
bool SeqList<T>::Remove(int i, T& x)
{
if (last == -1) {
return false;
}
if (i < 1 || i > last + 1) {
return false;
}
x = data[i - 1];
for (int j = i; j <= last; j++) {
data[j - 1] = data[j];
}
last--;
return true;
}

// 判表空
template <typename T>
bool SeqList<T>::IsEmpty() const
{
return last == -1;
}

// 判表满
template <typename T>
bool SeqList<T>::IsFull() const
{
return last == maxSize - 1;
}

// 排序
template <typename T>
void SeqList<T>::Sort()
{
sort(data, data + last+1);
}

// 输入
template <typename T>
void SeqList<T>::input()
{
cout << "Please enter the length of the linear table:";
cin >> last;
last--;
cout << "Please enter the elements of the linear table:";
for (int i = 0; i <=last; i++) {
cin >> data[i];
}
}

// 输出
template <typename T>
void SeqList<T>::output()
{
cout << "The elements of a linear table are:";
for (int i = 0; i <= last; i++) {
cout << data[i] << " ";
}
cout << endl;
}

int main()
{
SeqList<int> seqList(10);
seqList.input();
seqList.output();
seqList.Sort();
seqList.output();
return 0;
}