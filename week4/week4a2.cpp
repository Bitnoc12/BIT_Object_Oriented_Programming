#include <iostream>
#include <string>
#include <array>
#include <stack>

int main()
{
  // 创建数组
  std::array<std::string,3> strings={"Hello","World","!"};
  // 创建stack
  std::stack<std::string> stack;
  // 遍历数组并压入
  for(const auto& str:strings){
    stack.push(str);
  }
  // 输出stack
  while(!stack.empty()){
    std::cout<<stack.top();
    stack.pop();
  }
}