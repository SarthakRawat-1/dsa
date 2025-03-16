#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwo(int n) {
    // If the number is less than 1, it can't be a power of two
    // Since powers of two are positive and greater than or equal to 1.
    if (n < 1) {
        return false;  // Return false for non-positive numbers
    }

    // Iterate while n is not equal to 1
    // The goal is to divide n by 2 repeatedly until we get 1, if possible
    while (n != 1) {
        // If n is odd, it can't be a power of two (except 1 itself, which is handled separately)
        // Any power of two is always even (except 1).
        if (n % 2 == 1) {
            return false;  // If n is odd, return false since it is not divisible by 2
        }

        // Divide n by 2 to check if it's further divisible
        n = n / 2;
    }

    // If we reach here, it means n was divided down to 1, so it's a power of two
    return true;  // Return true since n is a power of two
}


int main() {
    int n1 = 16;
    int n2 = 18;

    cout << isPowerOfTwo(n1) << endl;
    cout << isPowerOfTwo(n2) << endl;
}
