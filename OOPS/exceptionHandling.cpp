#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        // This might not throw an exception because modern OS overcommit memory. This means that the operating system promises more memory to applications than it can actually provide. It only checks if there's enough memory available when the program actually tries to use that memory (e.g., by writing to it).
        // This won't work properly because error related to array size being too large (size of array is too large) is a compile-time error, not a runtime exception. So it can't be caught by a try catch block.
        int *p = new int[1000000000000000];
        cout << "Memory allocation is successful.";
        delete []p;
    }
    catch (const bad_alloc &e) {
        // bad_alloc exception specifically for memory allocation failure
        cout << "Memory allocation failed: " << e.what() << endl;
    }
    // We can write this because exception is a class, in this case, the exception is thrown by compiler which is an object of type exception.
    catch (const exception &e) {
        // With this, we can find the type of exception.
        // This is a generic exception handler for  catches exceptions of type std::exception or any class derived from std::exception (like std::bad_alloc, std::runtime_error, etc.).
        cout << "Exception occured :- " << e.what() << endl;
    }
}

// The exception class has some already defined Children classes for some errors like bad_alloc. This is why we could catch the error in our example, even without using a throw statement because that error was predefined.
// You can also make your own exception class by inheriting from the exception class.