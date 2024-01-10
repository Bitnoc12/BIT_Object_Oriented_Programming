#include <iostream>
#include "header.h"
using namespace std;

void nothing(){
  cout<<"name:nothing/argument list: /return void"<<endl<<endl;
}

char zf(char a,char b){
  cout<<"name:charP/argument list:"<<a<<" "<<b<<"/return char."<<endl<<endl; 
  return 0;
}

int zx(int x,int y){
  cout<<"name:intP/argument list:"<<x<<" "<<y<<"/return int."<<endl<<endl;
  return 0;
}
float fd(float x,float y,float z){
  cout<<"name:floatP/argument list:"<<x<<" "<<y<<" "<<z<<endl<<endl;
  return 0;
}



