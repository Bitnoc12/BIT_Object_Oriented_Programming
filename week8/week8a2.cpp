#include <iostream>
using namespace std;
 
class Shape{
  public:
    virtual void draw() = 0;
};

class Circle:public Shape{
  public:
    void draw(){
      cout<<"Drawing a circle"<<endl;
    }
};

class Square:public Shape{
  public:
    void draw(){
      cout<<"Drawing a square"<<endl;
    }
};

class Triangle:public Shape{
  public:
    void draw(){
      cout<<"Drawing a triangle"<<endl;
    }
};

int main(){
  // error:
  // Shape* shape = new Shape();
  // shape->draw();

  Shape* shapes[3];
  shapes[0]=new Circle();
  shapes[1]=new Square();
  shapes[2]=new Triangle();

  for(int i=0;i<3;i++){
    shapes[i]->draw();
  }

  delete shapes[0];
  delete shapes[1];
  delete shapes[2];

  return 0;
}