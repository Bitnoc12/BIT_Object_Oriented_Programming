#include <iostream>
using namespace std;
class Test
{
  public:
    Test();
    int getInt(){
      return num;
    }
    float getFloat(){
      return f1;
    }
    ~Test();
  private:
    int num;
    float f1;
};
Test::Test(){
  cout<<"Initializing default"<<endl;
  num=0;
  f1=0.0;
}
Test::~Test(){
  cout<<"Destructor is active"<<endl;
}
int main(){
  Test array[2];
  cout<<array[1].getInt()<<" "<<array[1].getFloat()<<endl;
  return 0;
}