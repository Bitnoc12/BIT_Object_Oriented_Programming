#include <iostream>

class MyClass {
public:
  MyClass(int num) : num_(num) {}
  MyClass operator+(const MyClass& other) {
    return MyClass(num_ + other.num_);
  }
  MyClass operator-(const MyClass& other) {
    return MyClass(num_ - other.num_);
  }
  void print(std::ostream& os) {
    os << "Num: " << num_ << std::endl;
  }
private:
  int num_;
};

int main() {
  MyClass a(2), b(3), c(4);
  MyClass result = a + b - c;
  result.print(std::cout);
  return 0;
}
