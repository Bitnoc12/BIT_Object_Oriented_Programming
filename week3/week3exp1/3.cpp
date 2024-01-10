#include <iostream>
#include <memory>
using namespace std;
class Woman;
class Man
{
  public:
    void setWife(weak_ptr<Woman> wife){
      this->wife=wife;
    }
    ~Man(){
      cerr<<"man dead\n";
    }
  private:
    weak_ptr<Woman> wife;
};
class Woman{
  public:
    void setHusband(weak_ptr<Man> man){
      husband=man;
    }
    ~Woman(){
      cerr<<"woman dead\n";
    }
  private:
    weak_ptr<Man> husband;
};
int main(){
  shared_ptr<Man> pman(new Man());
  shared_ptr<Woman> pwoman(new Woman());
  cout<<"man reference counting "<<pman.use_count()<<endl;
  cout<<"woman reference counting "<<pwoman.use_count()<<endl;
  if(pman&&pwoman){
    pman->setWife(pwoman);
    pwoman->setHusband(pman);
  }
  cout<<"man reference counting "<<pman.use_count()<<endl;
  cout<<"woman reference counting "<<pwoman.use_count()<<endl;
  
}
