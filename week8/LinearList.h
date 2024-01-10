#ifndef LinearList_h
#define LinearList_h
template<typename T>
class LinearList
{
  public:
    LinearList() {}
    virtual ~LinearList() {}

    // 求表最大容量
    virtual int Size() const=0;

    // 求表的长度
    virtual int Length() const=0;

    // 在表中搜索给定值x
    virtual int Search(T& x) const=0;

    // 定位第i个元素
    virtual int Locate(int i) const=0;

    // 取第i个项的值
    virtual bool getData(int i,T& x) const=0;

    // 修改第i个表项的值
    virtual void setData(int i,T &x) const=0;

    // 在第i个表项后插入x
    virtual bool Insert(int i,T& x) const=0;

    // 判断空
    virtual bool IsEmpty() const=0;

    // 判断满
    virtual bool IsFull() const=0;

    // 排序
    virtual void Sort()=0;

    // 输入
    virtual void input()=0;

    // 输出
    virtual void output()=0;

};
#endif