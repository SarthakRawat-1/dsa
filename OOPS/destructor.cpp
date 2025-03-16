// It is an instance member function that is invoked automatically whenever an object is going to be destroyed. It is the last function that is going to be called before an object is destroyed.
// A class can only have one Destructor and it cannot be overlaoded like Constructors.
// Same name as the Class but a ~ is added before the name. No parameters and no return type.
// The purpose of desturctor is to release all the dynamic resources allocated (like using new keyword). It can also be used to close a file or other reosurces which we opnened in Constructor or release locks.
// If you don't explicitly define a destructor, the compiler will generate a default destructor, which will perform the necessary cleanup of class members (such as calling destructors for member objects). However, if you manage dynamic resources (like raw pointers), you should define your own destructor to avoid memory leaks.
// Note :- Destructor is not used to delete objects themselves. The primary purpose of a destructor is to release resources that the object has acquired, such as dynamically allocated memory, file handles, network connections, or other system resources.
// Objects are either deleted by going out fo the scope like local varaibles, which happens for Objects with Automatic Storage Duration. For Dynamic Storage Duration, which means objects created with new, they must be explicitly deleted using delete. The destructor is called during this deletion process to clean up resources.


#include <iostream>
using namespace std;

class Customer {
  string name;
  int *data;  

  public:
  Customer() {
    name = "Sarthak";
    data = new int;
    *data = 10;
  }

 // Destructor
  ~Customer() {
    delete data;
  }
};

int main() {
    Customer A1;
    // Now let's say you had this :-
    Customer *A4 = new Customer;
    // If you just write this, the constructor for it will be called, but not the destructor. So use delete keyword
    delete A4;
}

// Let's say you defined multiple objects of same class like :- Customer A1, A2, A3. In this case, Destructor will be called for A3 first, then A2 and then A1.