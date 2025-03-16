// Swap Two numbers using XOR operator

// XOR (^) has a unique property where if you XOR a number with itself, the result is always 0.

#include <iostream>
using namespace std;

// Function to swap two numbers using the XOR operator
void swapUsingXOR(int &a, int &b) {
    // Step 1: XOR a and b, and store the result in a
    a = a ^ b; // Now, a holds the result of a XOR b, while b remains unchanged.

    // Step 2: XOR the new value of a (a XOR b) with b and store the result in b
    b = a ^ b; // This step changes b to the original value of a (since a XOR b XOR b = a).

    // Step 3: XOR the new value of a (a XOR b) with the new value of b (original a) and store the result in a
    a = a ^ b; // This step changes a to the original value of b (since a XOR b XOR a = b).
}

int main() {
    int num1 = 5, num2 = 10;

    cout << "Before swapping: " << "num1 = " << num1 << ", num2 = " << num2 << endl;

    swapUsingXOR(num1, num2);

    cout << "After swapping: " << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
