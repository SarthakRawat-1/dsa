// Problem Statement :- https://www.geeksforgeeks.org/problems/odd-or-even3618/1

// A number is even if the LSB is 0, and odd if the LSB is 1.

#include <iostream>
using namespace std;

// Function to determine whether a number is odd or even using bit manipulation
string checkOddOrEven(int n) {
    // Bitwise AND of n with 1 checks the least significant bit (LSB)
    // If LSB is 1, the number is odd; if LSB is 0, the number is even
    if (n & 1) {
        return "odd";  // LSB is 1, so the number is odd
    } else {
        return "even"; // LSB is 0, so the number is even
    }
}

int main() {
    int n1 = 15;  
    int n2 = 44;  

    cout << n1 << " is " << checkOddOrEven(n1) << endl;

    cout << n2 << " is " << checkOddOrEven(n2) << endl;

    return 0;
}
