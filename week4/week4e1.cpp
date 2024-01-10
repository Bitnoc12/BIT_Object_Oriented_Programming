#include <iostream>
#include <string.h>
using namespace std;

class Foo
{
  public:
    Foo();
    explicit Foo(int k);
    Foo(int k,char ch);
    Foo(const Foo &f);
    Foo(Foo &&f);
    ~Foo();
    Foo operator+(const Foo &f) const;
    Foo & operator=(const Foo &f);
    Foo & operator=(Foo &&f);
    void showObject() const;

  private:
    int n;
    char * pc;
    static int ct;
};

int Foo::ct=0;
Foo::Foo()
{
  cout<<"Enter foo()\n";
  ++ct;
  n=0;
  pc=nullptr;
  showObject();
  cout<<"Leave Foo()\n";
}

Foo::Foo(int k): n(k)
{
  cout<<"Enter Foo(k)\n";
  ++ct;
  pc=new char[n];
  memset(pc,'/0',n);
  showObject();
  cout<<"Leave Foo(k)\n";
}

Foo::Foo(int k,char ch):n(k)
{
  cout<<"Enter Foo(k,ch)\n";
  ++ct;
  pc=new char[n];
  for(int i=0;i<n;i++) 
    pc[i]=ch;
  showObject();
  cout<<"Leave Foo(k,ch)\n";
}

Foo::Foo(const Foo &f):n(f.n)
{
  cout<<"Enter Foo(const&)\n";
  ++ct;
  pc=new char[n];
  for(int i=0;i<n;i++)
    pc[i]=f.pc[i];
  showObject();
  cout<<"Leabve Foo(const &)\n";
}

Foo::Foo(Foo &&f):n(f.n)
{
  cout<<"Enter Foo(&&)\n";
  ++ct;
  pc=f.pc;
  f.pc=nullptr;
  f.n=0;
  showObject();
  f.showObject();
  cout<<"Leave Foo(&&)\n";
}

Foo::~Foo()
{
  cout<<"Enter ~Foo()\n";
  showObject();
  --ct;
  delete[] pc;
  cout<<"Leave ~Foo()\n";
}

Foo & Foo::operator=(const Foo &f)
{
  cout<<"Enter operator=(const &)\n";
  showObject();
  f.showObject();
  if(this==&f) return *this;
  delete[] pc;
  n=f.n;
  pc=new char[n];
  for(int i=0;i<n;i++) 
    pc[i]=f.pc[i];
  showObject();
  f.showObject();
  cout<<"Leave operator=(const &)\n";
  return *this;
}

Foo & Foo::operator=(Foo &&f)
{
  cout<<"Enter operator=(&&)\n";
  showObject();
  f.showObject();
  if(this == &f) return *this;
  delete[] pc;
  n=f.n;
  pc=f.pc;
  f.n=0;
  f.pc=nullptr;
  showObject();
  f.showObject();
  cout<<"Leave operator=(&&)\n";
  return *this;
}

Foo Foo::operator+(const Foo &f) const
{
  cout<<"Enter operator+(const &)\n";
  showObject();
  f.showObject();
  Foo temp=Foo(n+f.n);
  for(int i=0;i<n;i++)
    temp.pc[i]=pc[i];
  for(int i=n;i<temp.n;i++)
    temp.pc[i]=f.pc[i-n];
  cout<<"\t temp: ";
  temp.showObject();
  cout<<"Leave operator+(const &)\n";
  return temp;
}

void Foo::showObject() const
{
  cout<<"\t this="<<this<<",ct="<<ct;
  cout<<",pc=("<<n<<","<<(void *)pc<<",";
  if(n==0){
    cout<<"(object empty)";
  }
  else{
    for(int i=0;i<n;i++)
      cout<<pc[i];
      cout<<")"<<endl;
  }
}

int main()
{
  Foo one(10,'x');
  cout<<"object one:\n";
  one.showObject();
  cout<<endl;

  Foo two(one);
  cout<<"two object:\n";
  two.showObject();
  cout<<endl;

  Foo three=one + one;
  cout<<"object one:\n";
  one.showObject();
  cout<<"object three:\n";
  three.showObject();
  cout<<endl;

  Foo four;
  cout<<"four=one\n";
  four=one;
  cout<<"now object four:\n";
  four.showObject();
  cout<<endl;

  cout<<"four=one + two \n";
  four=one+two;
  cout<<"now object four:\n";
  four.showObject();
  cout<<endl;
  cout<<"four=move(one)\n";
  four=std::move(one);
  cout<<"now object four:\n";
  four.showObject();
  cout<<"and object one:\n";
  one.showObject();
  cout<<endl;
  return 0;
}