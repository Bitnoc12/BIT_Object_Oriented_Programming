#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
    Employee(string name, int id, int level, double baseSalary): 
        name(name), id(id), level(level), baseSalary(baseSalary){};
    virtual void calcSalary() = 0; // 纯虚函数
    virtual void promote() = 0; // 纯虚函数
    void display(){
        cout << "姓名：" << name << "，编号：" << id << "，级别：" << level 
             << "，月薪：" << salary << endl;
    }
protected:
    string name;
    int id;
    int level;
    double baseSalary;
    double salary;
};

class Manager: public Employee{
public:
    Manager(string name, int id, int level, double baseSalary): 
        Employee(name, id, level, baseSalary){};
    void calcSalary(){
        salary = 8000;
    }
    void promote(){
        level = 4;
    }
};

class Technician: public Employee{
public:
    Technician(string name, int id, int level, double baseSalary, int hours): 
        Employee(name, id, level, baseSalary), hours(hours){};
    void calcSalary(){
        salary = hours * 100;
    }
    void promote(){
        level = 3;
    }
private:
    int hours;
};

class Salesman: public Employee{
public:
    Salesman(string name, int id, int level, double baseSalary, double sales): 
        Employee(name, id, level, baseSalary), sales(sales){};
    void calcSalary(){
        salary = baseSalary + sales * 0.04;
    }
    void promote(){
        // 销售员不升级
    }
private:
    double sales;
};

class SalesManager: public Employee{
public:
    SalesManager(string name, int id, int level, double baseSalary, double sales, double commission): 
        Employee(name, id, level, baseSalary), sales(sales), commission(commission){};
    void calcSalary(){
        salary = baseSalary + sales * commission * 0.001;
    }
    void promote(){
        level = 3;
    }
private:
    double sales;
    double commission;
};

int main(){
    Manager m("张三", 1001, 1, 8000);
    m.promote();
    m.calcSalary();
    m.display();

    Technician t("李四", 1002, 1, 100, 80);
    t.promote();
    t.calcSalary();
    t.display();

    Salesman s("王五", 1003, 1, 3000, 20000);
    s.promote();
    s.calcSalary();
    s.display();

    SalesManager sm("赵六", 1004, 1, 5000, 100000, 5);
    sm.promote();
    sm.calcSalary();
    sm.display();

    return 0;
}
