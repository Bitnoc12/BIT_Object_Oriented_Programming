#include <iostream>
using namespace std;

// classB的前项声明
class ClassB;

class ClassA{
  public:
    void method(ClassB* b){
      cout<<"ClassA::method() called with ClassB object pointer"<<endl;
    }
};

class ClassB{
  public:
    void method(ClassA* a){
      cout<<"ClassB::method() called with ClassA object pointer"<<endl;
    }
};

int main()
{
  ClassA a;
  ClassB b;
  a.method(&b);
  b.method(&a);
  return 0;
}