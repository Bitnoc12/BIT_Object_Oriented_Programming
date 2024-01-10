#include <iostream>

using namespace std;

class CSmart{
  private:
    static int count;
  public:
    CSmart(){
      count++;
    }
    ~CSmart(){
      count--;
    }
    static int getCount(){
      return count;
    }
};
int CSmart::count = 0;

void DoSomething()
{
  CSmart s;
}

CSmart s1;

int main(){
  CSmart s2;
  cout<<CSmart::getCount()<<" objects"<<endl;
  DoSomething();
  CSmart *s3=new CSmart;
  cout<<CSmart::getCount()<<" objects"<<endl;
  delete s3;
  cout<<CSmart::getCount()<<" objects"<<endl;
  return 0;
}