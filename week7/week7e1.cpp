#include <iostream>
using namespace std;
class A
{
  private:
    int x,y;
  public:
    A(int a,int b):x(a),y(b){cout<<"constructing A..."<<endl;}
    void add(int a,int b) { 
       x+=a;y+=b;
       }
    void display() {
       cout<<"("<<x<<","<<y<<")";
       }
    ~A(){
      cout<<"Destructing A..."<<endl;
      }
};

class B:private A
{
  private:
    int i,j;
    A Aobj;
  public:
    B(int a,int b,int c,int d):A(a,b),i(c),j(d),Aobj(1,1)
    {
      cout<<"Constructing B..."<<endl;
    }
    void add(int x1,int y1,int x2,int y2){
      A::add(x1,y1);
      i+=x1;
      j+=y2;
    }
    void display(){
      A::display();
      Aobj.display();
      cout<<"("<<i<<","<<j<<")"<<endl;
    }
    ~B(){
      cout<<"Destructing B..."<<endl;
    }
};

int main(){
  B b(1,2,3,4);
  b.display();
  b.add(1,3,5,7);
  b.display();
  return 0;
}