// Problem Statement :- https://leetcode.com/problems/make-the-string-great/description/

// In ASCII, the difference between uppercase and lowercase letters is 32.
// To convert from uppercase to lowercase, you add 32 to the ASCII value. To convert from lowercase to uppercase, you subtract 32 from the ASCII value.

#include <bits/stdc++.h>
using namespace std;

// Function to remove pairs of adjacent letters that are the same letter but in opposite cases.
string makeGood(string s) {
    // Initialize an empty string to build the result.
    string result = "";

    // Loop through each character in the input string `s`.
    for (char &ch : s) {
        // Check if the `result` string is not empty and if the last character in `result` forms an "opposite case" pair with the current character `ch`.
        // We check this by adding or subtracting 32 from the ASCII value (case difference).
        if (!result.empty() && (result.back() + 32 == ch || result.back() - 32 == ch)) {
            // If an opposite case pair is found, remove the last character from `result`.
            result.pop_back();
        } else {
            // If no opposite case pair is found, add the current character to `result`.
            result.push_back(ch);
        }
    }

    // After processing all characters, return the `result` string,
    return result;
}

int main() {
    string s = "leEeetcode";
    cout << makeGood(s) << endl;
    return 0;
}