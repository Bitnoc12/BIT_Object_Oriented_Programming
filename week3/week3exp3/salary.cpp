#include <iostream>
using namespace std;
class Salary{
  private:
    double wage,subsidy,rent,waterFee,elecFee;
  public:
    // 空参数构造函数，初始化工资各项数据为0
    Salary() {
      wage=subsidy=rent=waterFee=elecFee=0;
    }
    Salary(double wage,double subsidy,double rent,double waterFee,double elecFee){
      this->wage=wage;
      this->subsidy=subsidy;
      this->rent=rent;
      this->waterFee=waterFee;
      this->elecFee=elecFee;
    }

  // 赋值
  void setWage(double wage){
    this->wage=wage;
  }
  void setSubsidy(double subsidy){
    this->subsidy=subsidy;
  }
  void setRent(double rent){
    this->rent=rent;
  }
  void setWaterFee(double waterFee){
    this->waterFee=waterFee;
  }
  void setElecFee(double elecFee){
    this->elecFee=elecFee;
  }
  // 获取数据
  double getWage(){return wage;}
  double getSubsidy(){return subsidy;}
  double getRent(){return rent;}
  double getWaterFee(){return waterFee;}
  double getElecFee(){return elecFee;}

  // 计算salary并返回
  double getSalary(){
    double salary=wage+subsidy-rent-waterFee-elecFee;
    return salary;
  }

  // 输出各项数据
  void printAll(){
    cout<<"基本工资："<<wage<<
        "\n岗位津贴:"<<subsidy<<
        "\n房租:"<<rent<<
        "\n水费:"<<waterFee<<
        "\n电费:"<<elecFee<<endl;
  }
};

int main(){

  // test1
  Salary t1(2000.80,1500.45,900,500,300);
  t1.printAll();

  double total1=t1.getSalary();
  cout<<"实发工资:"<<total1<<"\n"<<endl;
  cout<<"\n"<<endl;


  // test2
  Salary t2;
  t2.setWage(2680.88);
  t2.setSubsidy(1208);
  t2.setRent(400.66);
  t2.setWaterFee(10);
  t2.setElecFee(400.20);

  double wage=t2.getWage();
  double subsidy=t2.getSubsidy();
  double rent=t2.getRent();
  double waterFee=t2.getWaterFee();
  double elecFee=t2.getElecFee();
  t2.printAll();

  double total2=t2.getSalary();
  cout<<"实发工资："<<total2<<endl;
}

