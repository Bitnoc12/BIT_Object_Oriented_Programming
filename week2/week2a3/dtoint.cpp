#include <iostream>
using namespace std;

int func(double);
int(*p)(double);
int main(){
  int x;
  double y;
  cin>>y;
  p=func;
  x=(*p)(y);
  cout<<"整数部分："<<x<<endl;
}

int func(double x){
  return (int)x;
}