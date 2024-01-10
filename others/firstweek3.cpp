#include <iostream>
#include <vector>
using namespace std;
int main(){

  // 初始化vector
  vector<float> f(25);
  for(int i=0;i<f.size();i++)
  {
    // 让25个数字转成float
    f[i]=i*0.5f;
  }
  cout<<"The vector: ";
  
  for(int i=0;i<f.size();i++)
  {
    cout<<f[i]<<" ";
  }
  cout<<endl;
  return 0;
}