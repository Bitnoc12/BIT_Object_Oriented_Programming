#ifndef LinearList_h 
#define LinearList_h 
template<typename T>
class LinearList
{ 
public: 
LinearList() {} 
virtual ~LinearList() {} 
// 求表最⼤容量
virtual int Size() const = 0; 
// 求表⻓度
virtual int Length() const = 0; 
// 在表中搜索给定值x 
virtual int Search(T& x) const = 0; 
// 定位第i个元素
virtual int Locate(int i) const = 0; 
// 取第i个表项的值
virtual bool getData(int i, T& x) const = 0; 
// 修改第i个表项的值
virtual void setData(int i, T& x) = 0; 
// 在第i个表项后插⼊x 
virtual bool Insert(int i, T& x) = 0;
// 删除第i个表项
virtual bool Remove(int i, T& x) = 0; 
// 判表空
virtual bool IsEmpty() const = 0; 
// 判表满
virtual bool IsFull() const = 0; 
// 排序
virtual void Sort() = 0; 
// 输⼊
virtual void input() = 0; 
// 输出
virtual void output() = 0; 
}; 
#endif