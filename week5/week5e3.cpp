#include <iostream>
#include <cstring>
using namespace std;

class KeepString{
  private:
    char *m_str;
  public:
    KeepString(const char *str){
      // 分配内存
      m_str=new char[strlen(str)+1];
      strcpy(m_str,str);
    }
    ~KeepString(){
      delete[] m_str;
    }
    const char* GetString() const{
      return m_str;
    }
};

int main()
{
  KeepString KS("Internal String");
  const char *p=KS.GetString();
  cout<<p<<endl; //output is:Internal String
}