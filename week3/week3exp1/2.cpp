#include <iostream>
using namespace std;
class X
{
  private:
    int a=0;
    int &b;
    const int c;
    
  public:
    X() :a(0),b(a),c(0) {}
    X(int i):a(i),b(a),c(0){}
    X(int i,int j,int k):a(i),b(j),c(k){}
    void setA(int i){a=i;}
    void setC(int k) const{ } 
  
};

int main()
{
  X x1;
  X x2(2);
  X x3(1,2,3);
  x1.setA(3);
  return 0; 
}