#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  //确保文件一打开 
  if(!fin.is_open()){
    cerr<<"Error:failed to open the text1 file"<<endl;
    return 1;
  }
  // 确保文件二打开
  if(!fout.is_open()){
    cerr<<"Error:failed to open the text2 file"<<endl;
    return 1;
  }

  string line;
  while(getline(fin,line)){
    fout<<line<<endl;
  }

  fin.close();
  fout.close();

  cout<<"The File is copied completely."<<endl;

  return 0;
}