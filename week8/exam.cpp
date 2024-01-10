#include <iostream>
using namespace std;
class blah{
public:
 static int a;
 int b;
 blah(int x) {
 b=x;
 a=b+1;
 }
};
int blah::a = 0;
void main(void)
{
 blah b1(5);
 blah b2(12);
 cout << "b1.a is " << b1.a << endl;
 cout << "b1.b is " << b1.b << endl;
 cout << "b2.a is " << b2.a << endl;
 cout << "b2.b is " << b2.b << endl;
}