// Problem Statement :- https://leetcode.com/problems/powx-n/description/

// Use Binary Exponentiation. For eg :- If you are given x^8, it can be written as (x * x)^4 
// Generalizing :- pow(x, n) = pow(x * x, n/2) when n is divisble by 2.
// If n is odd, then make it even first. For eg :- x^9 = x * x^8 = x * pow(x, 8) = x * pow(x * x, 4)

// NOTE :- A negative exponent can be written as 1/positive exponent.
// Generalizing :- pow(x, n) = pow(1/x, -n) if n is negative. There is one problem however, if n = INT_MIN then -n will be 1 more than INT_MAX (as range of int 32 is from -2^31 to 2^31 - 1). So it will cause Integer Overflow. 
// To solve this, just use long instead of int.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate x raised to the power n using binary exponentiation
double myPow(double x, long n) {
    // Base case: any number raised to the power of 0 is 1
    if (n == 0) return 1;
    
    // If the exponent is negative, convert it to positive and invert x
    // Generalizing: pow(x, n) = pow(1/x, -n)
    if (n < 0) return myPow(1 / x, -n); // Using long to avoid overflow for INT_MIN case

    // If n is even, apply the binary exponentiation rule
    // Generalizing: pow(x, n) = pow(x * x, n/2) when n is divisible by 2
    if (n % 2 == 0) {
        return myPow(x * x, n / 2);
    } 
    // If n is odd, reduce it to an even exponent
    // Generalizing: pow(x, n) = x * pow(x, n-1)
    else {
        return x * myPow(x * x, (n - 1) / 2); // Reduce n by 1 to make it even
    }
}

int main() {
    double x = 4; 
    long n = 5;   
    cout << "The number " << x << " raised to " << n << " is " << myPow(x, n) << endl;

    return 0;
}
