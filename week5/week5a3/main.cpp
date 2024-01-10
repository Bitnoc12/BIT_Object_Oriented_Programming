#include "secondHeader.h"
#include <iostream>
using namespace std;
namespace ns=MyNamespace;
int main(){
  //calling function with scope resolution
  ns::function1();
  {
    //calling function without scope resolution
    using namespace MyNamespace;
    function2(); 
    function3();
  }
  ns::function4();
  return 0;
}
void MyNamespace::function1(){
  cout<<"Function 1\n";
}void MyNamespace::function2(){
  cout<<"Function 2\n";
}void MyNamespace::function3(){
  cout<<"Function 3\n";
}void MyNamespace::function4(){
  cout<<"Function 4\n";
}