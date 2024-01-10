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

class B:public A{
  public:
    B(){
      cout<<"Creating B"<<endl;
    }
    ~B(){
      cout<<"Destroying B"<<endl;
    }
};

class C:public B{
  public:
    C(){
      cout<<"Creating C"<<endl;
    }
    ~C(){
      cout<<"Destroying C"<<endl;
    }
};

int main(){
  C objC;
  return 0;
}