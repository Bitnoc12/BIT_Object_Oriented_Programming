#include <iostream>
#include <vector>
using namespace std;

class Counted{
  private:
    int id;
    static int count;
  public:
    Counted():id(count++){
      cout<<"Creating Counted #"<<id<<endl;
    }
    ~Counted(){
      cout<<"Destroying Counted #"<<id<<endl;
    }
    void f() const{
      cout<<"Counted #"<<id<<" says hi!"<<endl;
    }
};
int Counted::count=0;

int main(){
  vector<Counted*> vec;
  // fill in vector with pointer to new counter objects
  for(int i=0;i<5;i++){
    vec.push_back(new Counted());
  }
  // print
  for(auto ptr:vec){
    ptr->f();
  }
  // Delete 
  for(auto ptr:vec){
    delete ptr;
  }

  return 0;
}