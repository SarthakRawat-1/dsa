// Problem Statement :- https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

// Total numbers of substring in a string of length n is :- 1 + 2 + ... + n
// We also know that if a string is homogenous, all of it's substrings will also be homogenous. Eg :- "aaaa" is homogenous so all the 10 susbtrings of this will be homogenous.
// Hence, we just have to find those substrings in which each character is same and then find it's length.

#include <bits/stdc++.h>
using namespace std;

// Constant for modulo operation to handle large numbers, as required by the problem constraints.
// Have to specify int here because if we directly use this value in calcualting result expression,this numebr will be interpreted as a double. Therefore, the result of the modulo operation is incorrect and can cause unexpected behavior or errors.
int MOD = 1e9 + 7;

int countHomogenous(string s) {
    int n = s.length();  // Length of the input string

    int result = 0;      // This will store the total count of homogenous substrings
    int length = 0;      // This tracks the length of each sequence of identical characters

    // Traverse the string character by character
    for (int i = 0; i < n; i++) {
        // Check if the current character is the same as the previous one
        if (i > 0 && s[i] == s[i - 1]) {
            // If yes, increment the length of the current homogenous substring
            length++;
        } else {
            // Otherwise, reset length to 1 as we start a new sequence
            length = 1;
        }

        // Add the length to result. Each position contributes its sequence count (1 to `length`).
        result = (result + length) % MOD;
    }

    // Return the total count of homogenous substrings, modulo MOD to avoid overflow.
    return result;
}

int main() {
    string s = "abbcccaa";
    int result = countHomogenous(s);
    cout << "Total count of homogenous substrings: " << result << endl;

    return 0;
}
