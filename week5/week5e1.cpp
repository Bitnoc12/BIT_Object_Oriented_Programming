#include <iostream>

using namespace std;

void Sort(int num[],int size);
void Show(int num[],int size,bool ac);

int main()
{
  int num[10]={10,2,33,4,51,26,7,48,9,120};
  int size=sizeof(num)/sizeof(num[0]);
  Sort(num,size);
  Show(num,size,true);
  cout<<"\n";
  Show(num,size,false);
  return 0;
}

void Sort(int num[],int size)
{
  for(int i=0;i<size-1;i++)
    for(int j=0;j<size-i-1;j++){
      if(num[j]>num[j+1]){
        int temp=num[j];
        num[j]=num[j+1];
        num[j+1]=temp;
      }
    }
}

void Show(int num[],int size,bool ac)
{
  if(ac){
    for(int i=0;i<size;i++){
      cout<<num[i]<<" ";
    }
  }
  else{
    for(int i=size-1;i>=0;i--)
    {
      cout<<num[i]<<" ";
    }
  }
}