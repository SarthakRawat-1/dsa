// Problem Statement :- https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// Function to add spaces at specific positions in the string.
// The positions are specified by the 'spaces' vector.
string addSpaces(string s, vector<int>& spaces) {
    int m = s.length(); // Length of the input string.
    int n = spaces.size(); // Number of space positions specified.

    string result = ""; // To store the resulting string with added spaces.

    int j = 0; // Pointer to traverse the 'spaces' vector.

    // Iterate through each character of the string.
    for (int i = 0; i < m; i++) {
        // Check if the current index matches the next position in the 'spaces' vector.
        if (j < n && i == spaces[j]) {
            result += " "; // Add a space to the result string.
            j++; // Move to the next space position.
        }

        // Append the current character to the result string.
        result += s[i];
    }

    return result; // Return the modified string.
}

int main() {
    // Test case 1: Basic example
    string s1 = "leetcode";
    vector<int> spaces1 = {4};
    cout << "Resulting string: '" << addSpaces(s1, spaces1) << "'" << endl;

    return 0;
}