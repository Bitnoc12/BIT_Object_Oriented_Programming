#include <iostream>
using namespace std;
template <typename T>
// max函数模板
T max(T* s,int n){
  T temp=0;
  for(int i=0;i<n;i++){
    if(s[i]>temp){
      temp=s[i];
    }
  }
  return temp;
}
// char类型函数模块专门化
template < >
char max<char>(char* s,int n){
   char temp=0;
  for(int i=0;i<n;i++){
    if(s[i]>temp){
      temp=s[i];
    }
  }
  return temp;
}

int main(){

  int a[]={1,2,3,4,5};
  cout<<max(a,sizeof(a)/sizeof(a[0]))<<endl;

  float b[]={1.2,2.1,1.1,0.9,3,6};
  cout<<max(b,sizeof(b)/sizeof(b[0]))<<endl;

  double c[]={1.009,2.09095,3.66667,5.992948,2938.3334384};
  cout<<max(c,sizeof(c)/sizeof(c[0]))<<endl;

  char d[]={'z','C','a','A'};
  cout<<max(d,sizeof(d)/sizeof(d[0]))<<endl;
}