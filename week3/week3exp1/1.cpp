#include <iostream>
using namespace std;

// 声明函数
void setDate(void);
void showDate(void);

class Date
{
  void setDate(void);
  void showDate(void);

  public:
    int year;
    int month;
    int day;
};
Date d;

int main()
{
  setDate();
  showDate();
  return 0;
}

void setDate(void){
  cin>>d.year;
  cin>>d.month;
  cin>>d.day;
}

void showDate(void){
  cout<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
}