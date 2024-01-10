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
  MyClass& operator++() {
    ++num_;
    return *this;
  }
  MyClass operator++(int) {
    MyClass temp(*this);
    ++num_;
    return temp;
  }
  MyClass& operator--() {
    --num_;
    return *this;
  }
  MyClass operator--(int) {
    MyClass temp(*this);
    --num_;
    return temp;
  }
  friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "Num: " << obj.num_ << std::endl;
    return os;
  }
private:
  int num_;
};

int main() {
  MyClass a(2), b(3), c(4);
  ++a;
  b++;
  c--;
  MyClass result = a + b - c;
  std::cout << result;
  return 0;
}
