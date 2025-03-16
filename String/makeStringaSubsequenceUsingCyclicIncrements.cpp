// Problem Statements :- https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/

#include <iostream>
using namespace std;

// Function to check if string str2 can be made a subsequence of str1
// by incrementing characters of str1 cyclically.
bool canMakeSubsequence(string str1, string str2) {
    // Get the lengths of the strings.
    int m = str1.length(), n = str2.length();

    // Initialize pointers for both strings.
    int i = 0, j = 0;

    // Iterate through both strings.
    while (i < m && j < n) {
        // Check if the characters match directly,
        // or if the character in str1 can be incremented cyclically to match the character in str2.
        if ((str1[i] == str2[j]) || (str1[i] + 1 == str2[j]) || (str1[i] - 25 == str2[j])) {
            // Move to the next character in str2 as a match is found.
            j++;
        }
        // Always move to the next character in str1.
        i++;
    }

    // If all characters in str2 are matched, return true.
    return j == n;
}

int main() {
    // Test case 1: Basic example
    string str1_1 = "abc", str2_1 = "bcd";
    cout << "Can make subsequence: " << (canMakeSubsequence(str1_1, str2_1) ? "Yes" : "No") << endl;

    return 0;
}
