// Problem Statement :- https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

// Function to divide two integers without using multiplication, division, and mod operators
int divide(int dividend, int divisor) {
    // If dividend and divisor are the same, return 1 as the result (since x / x = 1).
    if (dividend == divisor) {
        return 1;
    }

    // Initialize the sign as true (positive result).
    bool sign = true;
    
    // Check if the signs of the dividend and divisor are different.
    // If so, the result will be negative, so set sign to false.
    if (dividend >= 0 && divisor < 0) { // One positive, one negative.
        sign = false;
    }
    else if (dividend <= 0 && divisor > 0) { // One negative, one positive.
        sign = false;
    }

    // Take the absolute value of both dividend and divisor.
    // This simplifies the logic for finding the quotient.
    long n = abs(dividend); // n stores absolute value of dividend.
    long d = abs(divisor);  // d stores absolute value of divisor.

    // divisor is updated to its absolute value for the shifting logic.
    divisor = abs(divisor);

    // Initialize quotient to 0, which will store the result.
    long quotient = 0;

    // Loop while the dividend (n) is greater than or equal to the divisor (d).
    // This will allow us to subtract multiples of the divisor from the dividend.
    while (n >= d) {
        int cnt = 0; // Counter for keeping track of how many times the divisor can be doubled.

        // The inner loop shifts the divisor left (which is equivalent to multiplying it by powers of 2)
        // and checks how many times the divisor can be subtracted from the dividend.
        // The condition (d << (cnt + 1)) checks if shifting the divisor by (cnt + 1) bits (i.e., multiplying by 2^(cnt + 1))
        // still results in a value that is less than or equal to the remaining dividend.
        while (n >= (d << (cnt + 1))) {
            cnt++; // Increase the shift counter.
        }

        // Once the largest possible shift is found, we add the corresponding power of 2 to the quotient.
        // This simulates how many times the divisor fits into the dividend.
        quotient += (1 << cnt); // (1 << cnt) is 2^cnt, which is added to the quotient.

        // Subtract the largest shifted divisor from the dividend.
        n -= (d << cnt); // This reduces the dividend by the largest multiple of divisor found in this iteration.
    }

    // Handle overflow cases.
    // If quotient equals (1 << 31) (i.e., 2^31, which is the overflow boundary for 32-bit integers) and the result should be positive,
    // return the maximum integer value (INT_MAX).
    if (quotient == (1 << 31) && sign) {
        return INT_MAX;
    }

    // If quotient equals (1 << 31) and the result should be negative, return the minimum integer value (INT_MIN).
    if (quotient == (1 << 31) && !sign) {
        return INT_MIN;
    }

    // Return the final result. If the sign is positive, return the quotient directly.
    // If the sign is negative, return the negative of the quotient.
    return sign ? quotient : -quotient;
}

int main() {
    int dividend = 34;
    int divisor = 5;
    int quotient = divide(dividend, divisor);
    cout << quotient << endl;
    return 0;
}