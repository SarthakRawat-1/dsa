// Problem Statement :-

// Consider :- "  -4123abc"
// We will declare an ans variable (initialized to 0) to store the resultant integer.
// First we have to trim the leading white spaces (using a while loop), then check sign, which will obviously be the starting of the number, so after removing whitespaces it'll come at index 0 (we have negative here, we can use a sign variable to store -1 and if it's positive we can store 1 in it. At the end, multiply ans variable with this).
// Then we have to traverse the string till we reach an alphabet (break here) or end of the string. And when we encounter digits, we have to store it in ans variable.
// But we can't directly multiply this, as we are increasing a digit, we first have to multiply the previous ans variable with 10 to put a zero at the end, and then add the char (also have to covnert char to int) to the result. So, ans = ans * 10 + (char - '0')

#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    // Step 1: Check if the input string is empty, if so return 0
    if (s.length() == 0) return 0;

    int i = 0; // Initialize a pointer 'i' to iterate through the string

    // Step 2: Skip leading whitespace characters
    // Keep moving 'i' forward while the current character is a space
    while (i < s.size() && s[i] == ' ') {
        i++;
    }

    // Step 3: Remove leading whitespaces by creating a substring from the first non-whitespace character
    // Trim the string to start from the first non-space character
    s = s.substr(i);

    // Step 4: Initialize the sign variable to store whether the number is positive (1) or negative (-1)
    int sign = 1;  // By default, assume positive sign
    long ans = 0;  // This will store the resultant number as we process it

    // Step 5: Check for sign of the number
    // If the first character is a minus ('-'), set sign to -1 for negative numbers
    if (s[0] == '-') sign = -1;

    // Step 6: Set up boundaries for overflow checks
    int MAX = INT_MAX; // Max value for a 32-bit integer
    int MIN = INT_MIN; // Min value for a 32-bit integer

    // Step 7: Move the pointer past the sign character if it's '+' or '-'
    // If the first character is '+' or '-', start parsing digits from index 1
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    // Step 8: Process each character of the string until we encounter a non-digit or reach the end of the string
    while (i < s.length()) {
        // If the current character is not a digit or is a whitespace, break the loop
        if (s[0] == ' ' || !isdigit(s[i])) break;

        // Step 9: Update 'ans' with the current digit
        // Multiply previous 'ans' by 10 to shift digits and add the new digit after converting the char to int
        ans = ans * 10 + s[i] - '0';

        // Step 10: Overflow checks
        // If the result is too large (overflow) for negative numbers, return the minimum possible integer
        if (sign == -1 && -1 * ans < MIN) return MIN;
        // If the result is too large (overflow) for positive numbers, return the maximum possible integer
        if (sign == 1 && ans > MAX) return MAX;

        // Step 11: Move to the next character in the string
        i++;
    }

    // Step 12: Return the final result (multiply by sign to handle negative numbers)
    return (int)(sign * ans);
}

int main() {
    string s1 = "abc 123";
    string s2 = "1234";
    string s3 = "   456";

    cout << myAtoi(s1) << endl;
    cout << myAtoi(s2) << endl;
    cout << myAtoi(s3) << endl;

    return 0;
}
