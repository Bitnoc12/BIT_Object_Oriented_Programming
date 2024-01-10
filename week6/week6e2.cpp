#include <iostream>
#include <iomanip>

using namespace std;

class Date{
  private:
    int year;
    int month;
    int day;

    bool isLeapYear(){
      // 判断闰年
      return(year%400==0)||(year%4==0&&year%100!=0);  
    }
    // 返回每个月的天数
    int daysInMonth(){
      switch(month){
        case 2:
          // 根据闰年来返回天数
          if(isLeapYear()){
            return 29;
          }
          else{
            return 28;
          }
        case 4:
        case 6:
        case 9:
        case 11:
          return 30;
        default:
          return 31;
      }
    }

  public:
    // 构造日期
    Date(int year=2000,int month=1,int day=1){
      // 用this指针访问private的变量
      this->year=year;
      this->month=month;
      this->day=day;
    }

    // 动态更改以及设计年月日
    void setYear(int year){
      this->year=year;
    }
    void setMonth(int month){
      this->month=month;
    }
    void setDay(int day){
      this->day=day;
    }

    void print(){
      // setfill设置空的字符填充为0
      // setw则是设置字符的宽度
      cout<<setfill('0')<<setw(4)<<year<<"-"<<setw(2)<<month<<"-"<<setw(2)<<day<<endl;
    }
    
    // 天数++，从天，月，年嵌套进行进位处理
    void operator++(){
      day++;
      if(day>daysInMonth()){
        day=1;
        month++;
        if(month>12){
          month=1;
          year++;
        }
      }
    }

    //通过循环来进行增加任意天数，通过设置好的自增运算符重载实现此运算符重载 
    void operator+=(int days){
      for(int i=0;i<days;i++){
        ++(*this);
      }
    }
    bool operator==(const Date& other){
      return year==other.year&&month==other.month&&day==other.day;
    }


};

int main(){
  Date d1;
  Date d2(2023,3,31);

  d1.print();
  d2.print();

  ++d1;
  d1.print();

  d1+=365;
  d1.print();

  cout<<(d1==d2)<<endl;

  return 0;
}