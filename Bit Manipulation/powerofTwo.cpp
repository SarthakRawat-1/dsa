// Problem Statement :- https://leetcode.com/problems/power-of-two/description/

// A number n is a power of two if exactly one bit is set in its binary representation.

#include <iostream>
using namespace std;

// Function to check if a number is a power of two using bit manipulation
bool isPowerOfTwo(int n) {
    // If n is less than or equal to 0, it can't be a power of two
    if (n <= 0) {
        return false;
    }
    
    // Bit manipulation trick to check if n is a power of two:
    // A power of two has exactly one bit set to 1.
    // The expression (n & (n - 1)) clears the lowest set bit of n.
    // If this results in 0, then n is a power of two.
    // Example: n = 8 (1000), n - 1 = 7 (0111), n & (n - 1) = 1000 & 0111 = 0
    return (n & (n - 1)) == 0;
}

int main() {
    int n1 = 16;   
    int n2 = 18;   
    int n3 = 1;    
    int n4 = -8;   

    if (isPowerOfTwo(n1)) {
        cout << n1 << " is a power of two.\n";
    } else {
        cout << n1 << " is not a power of two.\n";
    }

    if (isPowerOfTwo(n2)) {
        cout << n2 << " is a power of two.\n";
    } else {
        cout << n2 << " is not a power of two.\n";
    }

    if (isPowerOfTwo(n3)) {
        cout << n3 << " is a power of two.\n";
    } else {
        cout << n3 << " is not a power of two.\n";
    }

    if (isPowerOfTwo(n4)) {
        cout << n4 << " is a power of two.\n";
    } else {
        cout << n4 << " is not a power of two.\n";
    }

    return 0;
}
