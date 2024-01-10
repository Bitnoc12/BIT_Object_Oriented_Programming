#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> my_vector(25); // create a vector of size 25
    for (int i = 0; i < my_vector.size(); i++) {
        my_vector[i] = i * 0.5f; // assign a floating-point number to each element
    }
    // display the vector
    cout << "The vector contains: ";
    for (int i = 0; i < my_vector.size(); i++) {
        cout << my_vector[i] << " ";
    }
    cout << endl;
    return 0;
}