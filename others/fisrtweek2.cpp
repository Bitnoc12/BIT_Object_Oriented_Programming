#include <iostream>
#include <string>
using namespace std;
int main()
{
  string s;
  //起始设置被空格隔开的词为1以应付第一个词以及最后一个词的漏洞
  int space=1;
  cout<<"Enter a sentence\n"; 
  //吸收字符串  
  getline(cin,s);
  // 循环并计算空格的数量
  for(int i=0;i<s.length();i++)
  {
    if(s[i]==' '){
      space++;
    }
  };
  cout<<" the whitespace-separated words in the sentence:"<<space<<endl;
}