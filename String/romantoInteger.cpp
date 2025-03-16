// Problem Statement :- https://leetcode.com/problems/roman-to-integer/ 

#include <bits/stdc++.h>
using namespace std;

// Function to map a Roman numeral character to its corresponding integer value
int Number(char c) {
    // Using a switch-case statement to return the value associated with each Roman numeral
    switch (c) {
        case 'I': return 1;    // 'I' represents 1
        case 'V': return 5;    // 'V' represents 5
        case 'X': return 10;   // 'X' represents 10
        case 'L': return 50;   // 'L' represents 50
        case 'C': return 100;  // 'C' represents 100
        case 'D': return 500;  // 'D' represents 500
        case 'M': return 1000; // 'M' represents 1000
    }

    // Default return if an invalid character is encountered (although this shouldn't happen in practice)
    return 0;
}

int romanToInt(string s) {
    // Initialize sum to store the final integer value
    int sum = 0;

    // Initialize index to traverse through the Roman numeral string
    int index = 0;

    // Traverse the string, but stop one character before the end
    // This is because we'll compare each character with the next one
    while (index < s.size() - 1) {
        // Step 1: Compare the current character's value with the next character's value
        if (Number(s[index]) < Number(s[index + 1])) {
            // If the current character has a smaller value than the next character, we subtract its value
            // This handles cases like "IV" (4) or "IX" (9) where a smaller numeral precedes a larger one
            sum -= Number(s[index]);
        } else {
            // Otherwise, add the value of the current character to the sum
            sum += Number(s[index]);
        }

        // Move to the next character
        index++;
    }

    // Step 2: Add the value of the last character
    // The last character has no subsequent character to compare against, so we just add its value
    sum += Number(s[s.size() - 1]);

    // Return the final integer value representing the Roman numeral
    return sum;
}


int main() {
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}