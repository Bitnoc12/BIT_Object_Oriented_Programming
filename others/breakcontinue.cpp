#include <iostream>
using namespace std;
int main(){
  char c;
  while(true){
    cin>>c;
    if(c=='q') break;
      else if(c=='n') continue;
    cout<<"It is"<<c<<endl;
  }
}