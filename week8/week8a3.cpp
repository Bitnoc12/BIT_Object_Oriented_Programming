#include <iostream>
using namespace std;

class Shape{
  public:
    virtual void draw(){
      cout<<"Drawing a shape"<<endl;
    }
};

class Circle:public Shape{
  public:
    void draw(){
      cout<<"Drawing a circle";
    }
};

void drawShape(Shape s){
  s.draw();
}

void drawShapeByReference(Shape& s){
  s.draw();
}

int main(){
  Circle c;
  drawShape(c);

  drawShapeByReference(c);
  return 0;
}