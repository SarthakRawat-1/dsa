#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case: If n is 0 or 1, factorial is 1
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case: n! = n * (n - 1)!
    return n * factorial(n - 1); 
}

int main() {
    int num;

    cout << "Enter a number to find its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is " << factorial(num) << endl;
    }

    return 0;
}
