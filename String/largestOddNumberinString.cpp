// Problem Statement :- https://leetcode.com/problems/largest-odd-number-in-string/description/

// We know that for any odd number, the digit at it's 0th place will be odd i.e. 1/3/5/7/9
// Hence, for largest odd number in a string, we have to find that odd digit, which is coming further to the right (i.e. towards the end of string), then we can simply take all digits before it and this odd digit, and it'll be our largest odd number.

#include <bits/stdc++.h>
using namespace std;

// Function to find the largest odd number in the given string
string largestOddNumber(string num) {
    int n = num.length(); // Get the length of the input string

    // Traverse the string from the end (right to left)
    // We are looking for the first odd digit starting from the last position
    for (int i = n - 1; i >= 0; i--) {
        // Convert num[i] from char to int by subtracting '0'
        // Check if the digit is odd
        if ((num[i] - '0') % 2 != 0) {
            // If an odd digit is found, return the substring from the start to this digit (inclusive)
            // This is because the largest odd number will include all digits before it and this odd digit
            return num.substr(0, i + 1);
        }
    }

    // If no odd digit is found, return an empty string (no odd number possible)
    return "";
}

int main() {
    string num = "12345";

    cout << "The largest odd number in given string is :- " << largestOddNumber(num) << endl;
}

// NOTE :- Even if you directly do num[i] % 2 != 0, the code will still work fine. This is because of how ASCII values work. The numeric characters '0', '1', '2', ... '9' have consecutive values from 48 to 57. Even though num[i] is a character, the modulus operation (% 2) works because the ASCII values of odd digits (like '1', '3', '5', etc.) have odd ASCII values, while even digits (like '0', '2', '4', etc.) have even ASCII values.