#include <iostream>
#include <ctime> //use for compare the two functions speed
using namespace std;

inline int f1(int x){
  return x*2;
}

int f2(int x){
  return x*2;
}

int main(){
  const int num=10000000;
  //execution time of f1
  int result;
  clock_t start_time=clock();
  for(int i=0;i<num;i++){
    result=f1(i);
  }
  clock_t end_time=clock();
  cout<<"f1 execution time: "
      <<double(end_time-start_time)/CLOCKS_PER_SEC
      <<" seconds\n";

  start_time=clock();
  for(int i=0;i<num;i++){
    result=f2(i);
  }
  end_time=clock();
  cout<<"f2 execution time: "
      <<double(end_time-start_time)/CLOCKS_PER_SEC
      <<" seconds\n";
  return 0;
}

