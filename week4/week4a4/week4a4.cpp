#include <iostream>

class Mem {
public:
    // constructor, destructor, and other member functions

    bool moved() const {
        return pointer() != base;
    }
    char* pointer() const {
    return base;
    }
    char* alloc(int n) {
    char* result = curr;
    if (curr + n <= base + sz) {
        curr += n;
        return result;
    } else {
        return nullptr;
    }
    }
private:
    char* base;     // pointer to the allocated memory block
    char* curr;     // pointer to the next available memory location
    int sz;         // size of the allocated memory block
};


int main() {
    Mem m;

    char* p1 = m.alloc(10);     // allocate 10 bytes
    bool b1 = m.moved();        // check whether the pointer has moved

    char* p2 = m.alloc(50);     // allocate 50 more bytes
    bool b2 = m.moved();        // check again

    // print the results
    std::cout << "b1 = " << b1 << std::endl;
    std::cout << "b2 = " << b2 << std::endl;

    return 0;
}
