#include <iostream>
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
};
int Counted::count=0;

int main(){
  Counted c1;
  Counted c2;
  Counted c3;
  return 0;
}