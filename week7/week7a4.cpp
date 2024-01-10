#include <iostream>
using namespace std;
class A{
  public:
    A(){
      cout<<"Creating A"<<endl;
    }
    ~A(){
      cout<<"Destroying A"<<endl;
    }
};

class B{
  public:
    B(){
      cout<<"Creating B"<<endl;
    }
    ~B(){
      cout<<"Destroying B"<<endl;
    }
};

class C:public A{
  B b;
};

int main(){
  C objc;
}