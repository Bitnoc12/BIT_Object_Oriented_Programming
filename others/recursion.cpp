#include <iostream>
using namespace std;
int main(){
  void removeHat(char);
  removeHat('A');
}
void removeHat(char cat){
  for(char c='A';c<cat;c++) cout<<" ";
  if(cat<='Z'){
    cout<<"cat "<<cat<<endl;
    removeHat(cat+1);
  }
  else
    cout<<"VOOM!!!"<<endl;
}