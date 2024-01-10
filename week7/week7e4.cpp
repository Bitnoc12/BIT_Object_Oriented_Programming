#include <iostream>
using namespace std;
class A{
  public:
    A(){
      cout<<"A::A() called.\n";
    }
    virtual ~A(){
      cout<<"A::~A() called.\n";
    }
};
class B:public A{
  public:
    B(int i){
      cout<<"B::B() called.\n";
      buf=new char[i];
    }
    virtual ~B(){
      delete []buf;
      cout<<"B::B~B() called.\n";
    }
  private:
    char *buf;
};
void fun(A *a){
  cout<<"May you succeed!"<<endl;
  delete a;
}
int main(){
  A*p=new B(15);
  fun(p);
  return 0;
}