#include <iostream>
using namespace std;

// Recursive function to calculate 2 raised to the power of n
int powerOfTwo(int n) {
    // Base case: 2^0 = 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: 2^n = 2 * 2^(n-1)
    return 2 * powerOfTwo(n - 1);
}

int main() {
    int exponent;

    // Input: Asking the user for the exponent n
    cout << "Enter the exponent n to calculate 2^n: ";
    cin >> exponent;

    // If the exponent is negative, we can handle it here. But for now, only positive exponents are supported.
    if (exponent < 0) {
        cout << "Exponent should be non-negative." << endl;
    } else {
        // Output: Calling the recursive function and printing the result
        cout << "2^" << exponent << " = " << powerOfTwo(exponent) << endl;
    }

    return 0;
}
