#include <iostream>
using namespace std;
class IntArray {
public:
    static const int ARRAY_SIZE = 10;
    static int sCount;
    IntArray() :mSum(0){
      ++sCount;
      for(int i=0;i<ARRAY_SIZE;++i){
        mArray[i]=i+1;
        mSum+=mArray[i];
      }
    }
    inline void print() const{
      cout<<"Values in the array:\n";
      for(int i=0;i<ARRAY_SIZE;i++){
        cout<<mArray[i]<<" ";
      }
      cout<<"\nStatic data member count: "<<sCount<<"\n";
      printCount();
    }
    static void printCount(){
      cout<<"Static data member count: "<<sCount<<"\n";
    }
private:
    int mArray[ARRAY_SIZE];
    int mSum;
};

int IntArray::sCount = 0;

int main() {
    IntArray arr1;
    arr1.print();
    cout<<"\nCreating a second object...\n\n";
    IntArray arr2;
    arr2.print();
    return 0;
}
