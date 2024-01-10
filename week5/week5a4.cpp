#include <iostream>
using namespace std;
class MyClass{
  private:
    double *ptr;
  public:
    MyClass(double value):ptr(new double(value)){}
    ~MyClass(){
      cout<<"Destructor called,value pointed to: "<<*ptr<<"\n";
      *ptr=-1;
      delete ptr;
      ptr=nullptr;
    }
    MyClass(const MyClass &other):ptr(new double(*other.ptr)) {}
};

void foo(MyClass obj){
  cout<<"Inside foo\n";
}

int main()
{
  MyClass obj(10.32);
  foo(obj);
  cout<<"Back in main\n";
  return 0;
}