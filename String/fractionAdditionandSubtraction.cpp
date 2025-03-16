// Problem Statement :- https://leetcode.com/problems/fraction-addition-and-subtraction/description/

// Just parse the string normally using a pointer.
// We will take two variables, numerator (initialized to 0) and denominator (initialized to 1).
// Consider :- 1/3 - 1/2 We parse and first we get 1/3, so we will add 1/3 to 0/1 and we will get 1/3 as result. So update numerator to 1 and denominator to 3.
// Then we parse -1/2, so we add that to 1/3. But how do we add?
// We add them as (3 x -1) + (2 x 1) / 3 x 2 We can solve the numerator and denominator separately.WWWWWWWWWsssssssss  

#include <bits/stdc++.h>
using namespace std;

// Fucntion to calculate gcd, if the gcd() fucntion is not being recognized by compiler.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

string fractionAddition(string expression) {
    // Initialize result variables: numerator starts at 0 and denominator at 1 (neutral element for fractions)
    int numerator = 0, denominator = 1;

    // Index to iterate through the expression
    int i = 0;
    int n = expression.length();

    // Process each fraction in the expression one by one
    while(i < n) {
        int curr_numerator = 0;   // To store the current fraction's numerator
        int curr_denominator = 0; // To store the current fraction's denominator

        // Determine if the current fraction is negative by checking the sign
        bool isNeg = (expression[i] == '-');

        // If there's a '+' or '-' sign, advance the pointer to the numeric part
        if (expression[i] == '-' || expression[i] == '+') {
            i++;
        }

        // Parse the numerator of the current fraction
        while (i < n && isdigit(expression[i])) {
            int val = expression[i] - '0';        // Convert char to int
            curr_numerator = curr_numerator * 10 + val; // Build multi-digit numbers
            i++;
        }

        // Move past the '/' character to reach the denominator
        i++;

        // If the fraction is negative, make the numerator negative
        if (isNeg) {
            curr_numerator *= -1;
        }

        // Parse the denominator of the current fraction
        while (i < n && isdigit(expression[i])) {
            int val = expression[i] - '0';
            curr_denominator = curr_denominator * 10 + val;
            i++;
        }

        // Calculate the new numerator and denominator by adding the fraction
        // We use cross-multiplication to combine the fractions
        numerator = numerator * curr_denominator + curr_numerator * denominator;
        denominator *= curr_denominator;
    }

    // gcd() fucntion is available in C++17 or later.
    // Simplify the fraction using the greatest common divisor (GCD)
    int gcdVal = gcd(abs(numerator), abs(denominator));
    numerator /= gcdVal;
    denominator /= gcdVal;

    // Handle case where denominator is negative, by putting the negative sign on numerator instead.
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Return the simplified fraction as a string
    return to_string(numerator) + "/" + to_string(denominator);
}

// Main function to test the fraction addition
int main() {
    string expression = "1/3-1/2"; // Example input
    cout << fractionAddition(expression) << endl; // Expected output: "-1/6"
}
