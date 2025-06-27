// Constructor is a special function which is invoked automatically at the time of object creation. It's name will be same as the Class name. It doesn't havea ny return type. It is used to intiialize values.
// You can make multiple Constructors. 
// A default constructor is a constructor that either takes no parameters or has all of its parameters with default values. It is automatically provided by the compiler if no other constructor is defined. If you define any constructor yourself, and by any it means ANY CONSTRUCTOR, the compiler will no longer generate a default constructor unless you explicitly define one. Its purpose is to initialize the object with default values.
// A parameterized constructor is a constructor that takes one or more parameters. It allows passing specific values to initialize the object when it is created. This is useful when you want to initialize an object with custom data rather than default values.
// When we have more than one constructors for the same class, it is called Constructor Overloading. this keyword is especially important in Constructor OVerloading.
// The this pointer can be used to explicitly access the data members of the current object. This is especially useful when member variable names are the same as parameter names in a constructor or member function.

#include <iostream>
using namespace std;

class Customer {
    string name;
    int account_number;
    int balance;
    // Obv Constructor can also be used to write additional logic like if you need a resource let's say a file. You can write logic for this here.

    public: 

    // This is Default Constructor
    Customer() {
        name = "Sarthak";
        account_number = 21;
        balance = 999999;
    }

    // This is Parameterized Constructor. Now that we have defined a Parameterized Constructor using string a, int b, int c i.e. first parameter as string and rest two as int. We can't define other COnstructors using this same combination even if the name of the parameters are different.
    Customer(string a, int b, int c) {
        // Here we didn't needed this keyword as parameter names are a, b and c while data members are name, account_number and balance.
        name = a;
        account_number = b;
        balance = c;
    }

    Customer(string name, int account_number) {
        this->name = name;
        this->account_number = account_number;
        balance = 0; 
    }

    // Copy Constructor with shallow copy as it is taking a reference. Before using this comment the inline Constructor.
    Customer (Customer &B) {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }

    // This is an example of an inline constructor.
    // Before running this, do comment out the Constructor just after the default COnstructor becuase both are taking the same arguements.
    inline Customer(string a, int b, int c): name(a), account_number(b), balance(c) {}

    void display() {
        cout << name << " " << account_number << " " << balance << endl;
    }
};

int main() {
    Customer A1;
    Customer A2("Shogun", 22, 9999999);
    Customer A3("Kingun", 23);

    // Copy Constructor creates a new object as a copy of an existing object. It is used to initialize an object by copying the data members from another object of the same class
    // If you do not define any constructor, the C++ compiler provides a default copy constructor that performs a shallow copy of the object's data members.
    Customer A4(A3);
    Customer A5 = A3; // This also works

    A1.display();
    A2.display();
    A3.display();
    A4.display();
}

// Let's say you defined multiple objects of same class like :- Customer A1, A2, A3. In this case, Constructor will be called for A1 first, then A2 and then A3.
