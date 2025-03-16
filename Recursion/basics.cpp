// Recursion is a programming technique where a function calls itself to solve a smaller instance of the same problem. This is useful when a problem can be broken down into smaller sub-problems, which are essentially similar to the original problem. Each recursive call works on a smaller part of the problem until a base case is reached, which terminates the recursion.
// Base Case is a condition where the function stops calling itself. Without this, the recursion would continue indefinitely and cause a stack overflow.
// Recursive Case is the part of the function where it calls itself with a modified argument, gradually reducing the size of the problem.

// To understand the concept of Stack overflow, we will have to first understand how stack memory actually works.
// Stack memory is a region of memory used for managing function calls, local variables, and control flow. It follows a Last In, First Out (LIFO) structure, meaning the most recent function call or local variable is the first to be removed when the function finishes.
// Each time a function is called, a new stack frame (or activation record) is created. This stack frame contains Local variables, Function arguments, Return address (the address in the code where control returns after the function completes) and Saved state which is information necessary to restore the previous function's state.
// As functions are called, new stack frames are pushed onto the stack. When a function returns, the stack frame is popped, and control returns to the calling function. This process continues until the main program finishes.
// If a recursive function calls itself too many times without reaching a base case, or if the base case is far too deep, it can lead to stack overflow. Each recursive call adds a new frame to the stack, and if the stack exceeds its allocated space, overflow occurs.

#include <iostream>
using namespace std;

void birthday(int n) {
    // This is our base class. It will terminate the recursion when n i.e. number of days become zero.
    if (n == 0) {
        cout << "Happy Birthday!" << endl;
        return;
    }

    // This is our recursive case. It will call itself again with n - 1. It will do this until we reach the base case.
    cout << n << " days left for birthday" << endl;
    birthday(n - 1);
}

int main() {
    // Problem Statement is that we have to print days left for birthday as each day passes and on Birthday, print Happy Birthday.
    int n = 5; // Days left for birthday.

    birthday(n);
}

// It is easier to visualise and understand recursion by making a recursion tree. A recursion tree is a visual representation of the function calls made during a recursive algorithm's execution.
// You can also think of recursion in mathematical terms, something like a factorial, how factorial of 0 is 1 and factorial of 1 is 1 x factorial(0) and factorial of 2 is 2 x factorial(1) and so on. Simialrly, like thsi recursion can be thought of where factorial(0) is our base case.