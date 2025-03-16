// Operator overloading allows you to redefine the way operators work for user-defined types (like classes and structures).
// For achieveing this we will use the operator keyword. Then the operator (+, -, *, / etc.) can be used as a function name. Inside that we can define how our function will work for that datatype.

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:

    Complex() {
        real = 0;
        imag = 0;    
    }

    Complex(float real, float imag) {
        this->real = real;
        this->imag = imag;
    }

    // Overloading the + operator
    Complex operator + (const Complex& obj) { // We are passing the object as a reference. If we pass the obj parameter by value (i.e., Complex obj), a copy of the entire Complex object would be made. This involves calling the copy constructor of the class and allocating memory for the new object, which can be inefficient, especially for larger objects.
        Complex temp(0, 0); // Creating a new Complex object to store the result.
        temp.real = real /* real here means c1.real which is 3.4 in our example */ + obj.real; // obj.real here means c2.real which is 1.2 in our example. The reason why we can use dot notation to access that and don't have to use a dereferemcomg operator is because the obj is being passed as a reference. This doesn't mean that it is a pointer. A reference is an alias for another object. It is not a pointer, but rather another name for an existing object. You access the members of the object through the reference using the dot (.) operator, just as you would with the original object.
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.4, 2.5), c2(1.2, 3.3);
    Complex c3 = c1 + c2; // Calls the overloaded + operator. Here, c1 is our fucntion calling object which is calling the + fucntion and inside that c2 will go as an argument which we have captured in our Overloaded fucntion as a parameter.
    c3.display();         // Output: 4.6 + 5.8i
    return 0;
}
