#ifndef SequenceList_h
#define SequenceList_h

#include "LinearList.h"

template<typename T>
class SequenceList : public LinearList<T>
{
public:
    // 构造函数
    SequenceList(int MaxListSize = 10);
    // 析构函数
    ~SequenceList();
    // 求表最大容量
    int Size() const;
    // 求表的长度
    int Length() const;
    // 在表中搜索给定值x
    int Search(T& x) const;
    // 定位第i个元素
    int Locate(int i) const;
    // 取第i个项的值
    bool getData(int i, T& x) const;
    // 修改第i个表项的值
    void setData(int i, T& x);
    // 在第i个表项后插入x
    bool Insert(int i, T& x);
    // 判断空
    bool IsEmpty() const;
    // 判断满
    bool IsFull() const;
    // 排序
    void Sort();
    // 输入
    void input();
    // 输出
    void output();

private:
    T* element; // 存储线性表元素的一维数组
    int MaxSize; // 线性表最大长度
    int len; // 线性表当前长度
};

template<typename T>
SequenceList<T>::SequenceList(int MaxListSize)
{
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    len = 0;
}

template<typename T>
SequenceList<T>::~SequenceList()
{
    delete[] element;
}

template<typename T>
int SequenceList<T>::Size() const
{
    return MaxSize;
}

template<typename T>
int SequenceList<T>::Length() const
{
    return len;
}

template<typename T>
int SequenceList<T>::Search(T& x) const
{
    for (int i = 0; i < len; i++)
    {
        if (element[i] == x)
        {
            return i;
        }
    }
    return -1;
}

template<typename T>
int SequenceList<T>::Locate(int i) const
{
    if (i < 1 || i > len)
    {
        return -1;
    }
    return i - 1;
}

template<typename T>
bool SequenceList<T>::getData(int i, T& x) const
{
    if (i < 1 || i > len)
    {
        return false;
    }
    x = element[i - 1];
    return true;
}

template<typename T>
void SequenceList<T>::setData(int i, T& x)
{
    if (i < 1 || i > len)
    {
        return;
    }
    element[i - 1] = x;
}

template<typename T>
bool SequenceList<T>::Insert(int i, T& x)
{
    if (len == MaxSize || i < 1 || i > len + 1)
    {
        return false;
    }
    for (int j = len; j >= i; j--)
    {
        element[j] = element[j - 1];
    }
    element[i - 1] = x;
    len++;
    return true;
}

template<typename T>
bool SequenceList<T>::IsEmpty() const
{
    return len == 0;
}

template<typename T>
bool SequenceList<T>::IsFull() const
{
return len == MaxSize;
}

template<typename T>
void SequenceList<T>::Sort()
{
for (int i = 0; i < len - 1; i++)
{
for (int j = i + 1; j < len; j++)
{
if (element[i] > element[j])
{
T temp = element[i];
element[i] = element[j];
element[j] = temp;
}
}
}
}

template<typename T>
void SequenceList<T>::input()
{
std::cout << "请输入线性表的长度: ";
std::cin >> len;
std::cout << "请输入线性表的元素: ";
for (int i = 0; i < len; i++)
{
std::cin >> element[i];
}
}

template<typename T>
void SequenceList<T>::output()
{
std::cout << "线性表的元素为: ";
for (int i = 0; i < len; i++)
{
std::cout << element[i] << " ";
}
std::cout << std::endl;
}

#endif