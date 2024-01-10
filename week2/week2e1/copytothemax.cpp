#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc,char* argv[]){
  {
    // 传入两个参数
    if(argc<=2){
      cout<<"Wrong command parameter!"<<endl;
      exit(1);
    }
    string hang;
    ifstream first_file(argv[1]);
    ofstream second_file(argv[2]);

    // 确保文件能透过读写方式打开
    if(first_file.is_open()==false||second_file.is_open()==false){
      cout<<"Error while opening file!"<<endl;
      exit(2);
    }

    // copytothemax
    while(getline(first_file, hang))
      second_file<<hang<<endl;
    
    cout<<"copied completely"<<endl;

    return 0;
  }
}