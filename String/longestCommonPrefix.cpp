// Problem Statement :- https://leetcode.com/problems/longest-common-prefix/description/

// Start with the first string in the array as the initial prefix.
// Iterate through the remaining strings, and compare each string with the current prefix:
// As soon as you encounter a mismatch between the prefix and the string at any position, trim the prefix up to the last matching character. If at any point the prefix becomes an empty string, we can stop early and return "".
// Continue this process for all strings, and you'll end up with the longest common prefix.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    // Edge case: if the input array is empty, return an empty string
    if (strs.empty()) return "";

    // Step 1: Start with the first string in the array as the initial prefix
    string prefix = strs[0];

    // Step 2: Compare the prefix with each string in the array
    for (int i = 1; i < strs.size(); i++) {
        // Compare the current prefix with the current string in the array
        while (strs[i].find(prefix) != 0) { // The find() function checks if 'prefix' is at the start (index 0). In this specific case, we are only interested in the situation where prefix starts at the beginning of strs[i]. That is, find() should return 0. 

            // If the current prefix is not found at the beginning of strs[i], it means that the common prefix is too long or incorrect, and we need to shorten it.
            // To do this, we remove the last character from prefix using the substr() function.
            prefix = prefix.substr(0, prefix.length() - 1);
            // This process repeats until the prefix either matches the start of strs[i] or becomes empty.
            
            // Step 4: If the prefix becomes empty, return an empty string because it means that there is no common prefix among all the strings
            if (prefix.empty()) {
                return "";
            }
        }
    }

    // Step 5: Return the final longest common prefix
    return prefix;
}

int main() {
    // Test Case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs1) << endl; // Output: "fl"

    // Test Case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}
