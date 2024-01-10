#include <iostream>
using namespace std;

class IntList
{
  protected:
    struct Node{
      Node * next;
      int data;
    };
    Node * pFirst;
  public:
    IntList() : pFirst(nullptr) {}  // 构造函数
    ~IntList()                      // 析构函数
    {
        Node * p = pFirst;
        while (p != nullptr) {
            Node * q = p->next;
            delete p;
            p = q;
        }
    }
    bool insert(int i, int elem)    // 在第i个位置插入元素
    {
        if (i < 0) {
            return false;
        }
        Node * p = pFirst;
        Node * q = nullptr;
        int j = 0;
        while (p != nullptr && j < i) {
            q = p;
            p = p->next;
            j++;
        }
        if (j != i) {
            return false;
        }
        Node * node = new Node;
        node->data = elem;
        node->next = p;
        if (q == nullptr) {
            pFirst = node;
        } else {
            q->next = node;
        }
        return true;
    }
    bool remove(int i, int &elem)   // 删除第i个位置的元素
    {
        if (i < 0) {
            return false;
        }
        Node * p = pFirst;
        Node * q = nullptr;
        int j = 0;
        while (p != nullptr && j < i) {
            q = p;
            p = p->next;
            j++;
        }
        if (j != i || p == nullptr) {
            return false;
        }
        if (q == nullptr) {
            pFirst = p->next;
        } else {
            q->next = p->next;
        }
        elem = p->data;
        delete p;
        return true;
    }
    int * find(int elem) const      // 查找元素elem
    {
        Node * p = pFirst;
        while (p != nullptr) {
            if (p->data == elem) {
                return &(p->data);
            }
            p = p->next;
        }
        return nullptr;
    }
    int length() const             // 计算链表长度
    {
        Node * p = pFirst;
        int len = 0;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }
    void printList()                // 打印链表
    {
        Node * p = pFirst;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    // 创建一个空链表
    IntList mylist;

    // 向链表中插入一些元素
    mylist.insert(0, 1);
    mylist.insert(1, 3);
    mylist.insert(2, 5);
    mylist.insert(3, 7);

    // 打印链表中的所有元素
    cout << "Elements in the list: ";
    mylist.printList();
    cout << endl;

    // 在链表中查找元素
    int *pElem = mylist.find(3);
    if (pElem != nullptr) {
        cout << "Element found: " << *pElem << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    // 从链表中删除元素
    int elem;
    mylist.remove(1, elem);
    cout << "Element removed: " << elem << endl;

    // 打印链表中的所有元素
    cout << "Elements in the list: ";
    mylist.printList();
    cout << endl;

    // 计算链表的长度
    int len = mylist.length();
    cout << "Length of the list: " << len << endl;

    // 从链表中删除所有元素
    while (mylist.length() > 0) {
        mylist.remove(0, elem);
    }

    // 打印链表中的所有元素
    cout << "Elements in the list: ";
    mylist.printList();
    cout << endl;

    // 销毁链表
    mylist.~IntList();

    return 0;
}