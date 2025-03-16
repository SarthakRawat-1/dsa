#include <iostream>
using namespace std;

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base case 1: If n is 0, return 0 as F(0) = 0
    if (n == 0) {
        return 0;
    }
    
    // Base case 2: If n is 1, return 1 as F(1) = 1
    if (n == 1) {
        return 1;
    }

    // Could have also combined these two bases as :-
    // if (n <= 1) return n;

    // Could have also declared another base case for n = 2, it also returns 1. But it is redundant.

    // Recursive case: F(n) = F(n - 1) + F(n - 2)
    // We recursively calculate the previous two Fibonacci numbers and add them
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number F(" << n << ") is: " << fibonacci(n) << endl;

    return 0;
}
