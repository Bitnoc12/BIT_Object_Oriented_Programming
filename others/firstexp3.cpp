#include <iostream>
using namespace std;
int main()
{
  int myMax(int x,int y);
  int a,b;
  cout<<"Please enter a and b:"<<endl;
  cin>>a>>b;
  cout<<"Max="<<myMax(a,b)<<endl;
  return 0;
}

int myMax(int x,int y)
{
  return (x>y?x:y);
}