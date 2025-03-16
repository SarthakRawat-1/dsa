// When two or more functions in the same scope share the same name but have different parameters, it’s called function overloading.
// It is compile time polymorphism, because when we compile the code, the compiler will decide which Overloaded function to call based on the parameters passed.

#include <iostream> 
using namespace std;

class Area {
    public :

    // Returns area of a circle
    int calculateArea(int r) {
        return 3.14 * r * r;
    }
    // Now remember that you can't again make a function here with calculateArea name which has only one int as it's parameter, even if you cahnge the name like, int s. There should be difference of either datatypes and/or number of arguments. 

    // Returns area of rectangle
    int calculateArea(int l, int b) {
        return l * b;
    }
};

int main() {
    Area A1;
    cout << A1.calculateArea(4) << endl; // Only one parameter was passed, so it will call calculateArea(int r)

    Area A2;
    cout << A2.calculateArea(4, 5) << endl; // Two parameters were passed, so it will call calculateArea(int l, int b)
}