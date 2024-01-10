#include <iostream>
using namespace std;
int dog,cat,bird;
void f(int pet){
  cout<<"pet id number:"<<pet<<endl;
}
int main(){
  int i,j;
  cout<<"f():"<<&f<<endl;
  cout<<"dog:"<<&dog<<endl;
  cout<<"cat:"<<&cat<<endl;
  cout<<"bird:"<<&bird<<endl;
  cout<<"i:"<<&i<<endl;
  cout<<"j:"<<&j<<endl;
  int *p=new int;
  cout<<"p:"<<&p<<endl;
  cout<<"&(*p)"<<&(*p)<<endl;
  delete p;
}