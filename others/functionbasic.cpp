#include <iostream>
using namespace std;

int main(){
  cout<<"Give three numbers:"<<endl;
  int x,y,z;
  cin>>x>>y>>z;
  int addition(int,int,int);
  cout<<addition(x,y,z)<<endl;
}

int addition(int x,int y,int z){
  return(x+y+z);
}