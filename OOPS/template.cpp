// Templates allow functions or classes to work with any data type. When you define a template, the actual function or class implementation is not generated until the template is instantiated with a specific type.
// It is compile time polymorphism, because when we compile the code, the compiler generates the appropriate version of the function or class for each unique type used with the template.

#include <iostream>
using namespace std;

// Function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Add integers: " << add(3, 4) << endl;        // Output: 7
    cout << "Add floats: " << add(2.5, 3.5) << endl;      // Output: 6
    return 0;
}
