// Problem Statement :- https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/

#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s) {
    int n = s.length(); // Get the length of the input string

    string result = ""; // Initialize an empty string to store the result

    // Push the first character to the result string as it’s always allowed
    result.push_back(s[0]);
    int freq = 1; // Initialize frequency counter for consecutive characters

    // Start iterating from the second character
    for (int i = 1; i < n; i++) {
        // Check if the current character is the same as the last added character in result
        if (s[i] == result.back()) {
            freq++; // Increment frequency counter for consecutive characters
            if (freq < 3) { // Only add the character if frequency is less than 3
                result.push_back(s[i]);
            }
        } else { // Reset frequency if the current character is different
            result.push_back(s[i]); // Add the new character to result
            freq = 1; // Reset frequency counter for the new character
        }
    }

    return result; // Return the final "fancy" string
}

int main() {
    string s = "aaabaaaa"; 
    cout << makeFancyString(s) << endl; 
}
