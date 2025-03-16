// Problem Statement :- https://leetcode.com/problems/palindrome-number/description/

// Refer reverseInteger.cpp to understand how to reverse the number. Then check if the original number and reversed number are equal or not.

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    // Negative numbers are not palindromes, and numbers ending in 0
    // are not palindromes unless the number is 0 itself.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int ans = 0; // To store reversed number
    int original = x; // To store the original number
    int rem; // To store the extracted digits

    while (x) {
        rem = x % 10; // Extract the last digit
        x /= 10; // Remove the last digit

        if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0; // Condition to rectify Integer Overflow.

        ans = ans * 10 + rem; // Add the extracted digit to reversed number.
    }

    return ans == original;
}

int main() {
    int number = 12321;
    cout << "Is " << number << " a palindrome? " << isPalindrome(number) << endl;
    return 0;
}