#include <iostream>
using namespace std;
class A{
  private:
    int x;
  public:
    A(int a):x(a){cout<<"Constructing A..."<<x<<endl;}
    int fun() {
      return x;
    }
    ~A() {
      cout<<"Destructing A..."<<endl;
    }
};
class B:public virtual A{
  private:
    int y;
    A Aobj;
  public:
    B(int a,int b,int c):A(a),y(c),Aobj(c){
      cout<<"Constructing A..."<<endl;
    }
    int fun(){
      A::fun();
      Aobj.fun();
      return ++y;
    }
    void display(){
      cout<<A::fun()<<"\t"<<Aobj.fun()<<"\t"<<fun()<<endl;
    }
    ~B() {
      cout<<"Destructing B..."<<endl;
    }
};
class C:public B{
  public:
    C(int a,int b,int c):B(a,b,c),A(0){
      cout<<"Constructing C..."<<endl;
    }
};
class D:public C,public virtual A{
  public:
    D(int a,int b,int c):C(a,b,c),A(c){
      cout<<"contructing D..."<<endl;
    }
    ~D(){
      cout<<"Destructing D..."<<endl;
    }
};

int main(){
  D d(7,8,9);
  d.fun();
  d.display();
  return 0;
}