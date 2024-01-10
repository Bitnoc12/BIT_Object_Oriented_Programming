#include <iostream>
using namespace std;

class ClassA;

class ClassB{
    public:
        void method(ClassA& a);
};

class ClassC{
    public:
        void method(ClassA& a);
};

class ClassA{
    private:
        int privateData;
        friend class ClassB;
        friend void ClassC::method(ClassA& a);
    
    public:
        ClassA(int data):privateData(data){}

        int getPrivateData(){
            return privateData;
        }
};

void ClassB::method(ClassA& a){
    cout<<"ClassB::method() called with ClassA object"<<endl;
    cout<<"Accessing ClassA's private data "<<a.privateData<<endl;
}

void ClassC::method(ClassA& a){
    cout<<"ClassC::method() called with ClassA object"<<endl;
    cout<<"Accesing ClassA's private data "<<a.privateData<<endl;
}

int main(){
    ClassA a(46);
    ClassB b;
    ClassC c;

    b.method(a);
    c.method(a);
    return 0;
}

