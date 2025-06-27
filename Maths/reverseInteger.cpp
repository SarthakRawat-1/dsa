// Problem Statement :- https://leetcode.com/problems/reverse-integer/description/

// Extract digits from number from the end one by one and then continue adding digits to them.
// For eg :- 234, extract 4, then extract 2, do 4 * 10 + 3 = 43, then extract 2, do 43 * 10 + 2 = 432

#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    int ans = 0; // To store reversed number
    int rem; // To store the extracted digits

    while (x) {
        rem = x % 10; // Extract the last digit
        x /= 10; // Remove the last digit

        if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0; // Condition to rectify Integer Overflow.

        ans = ans * 10 + rem; // Add the extracted digit to reversed number.
    }

    return ans;
}

int main() {
    int number = 15342364;
    cout << "Reversed Number :- " << reverse(number) << endl;
}