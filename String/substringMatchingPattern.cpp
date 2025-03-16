// Problem Statement :- https://leetcode.com/problems/substring-matching-pattern/description/

// Split the Pattern into Prefix and Suffix :-
// Locate the position of the '*' in the pattern string.
// Divide the pattern into two parts :- Prefix: Substring before '*'. Suffix: Substring after '*'.

// Search for Matching Segments :-
// Find occurrences of the prefix in the main string.
// After locating the prefix, check for the suffix starting from the end of the prefix, allowing any number of characters in between.

// Handle Edge Cases :-
// If '*' is at the start of the pattern, the suffix can appear anywhere.
// If '*' is at the end of the pattern, the prefix can appear anywhere.
// Ensure at least one valid match exists by examining overlapping possibilities.

#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    // Find the position of '*'
    int starPos = p.find('*');

    // Split the pattern into prefix and suffix
    string prefix = p.substr(0, starPos);
    string suffix = p.substr(starPos + 1);

    // Check if the string starts with the prefix
    int prefixPos = s.find(prefix);
    if (prefixPos == -1) {
        return false; // Prefix not found
    }

    // Iterate through occurrences of prefix
    while (prefixPos != -1) {
        // Check if suffix matches after the prefix
        int suffixPos = s.find(suffix, prefixPos + prefix.size());
        if (suffixPos != -1 && suffixPos >= prefixPos + prefix.size()) {
            return true; // Found a valid match
        }

        // Look for the next occurrence of the prefix
        prefixPos = s.find(prefix, prefixPos + 1);
    }

    return false;
}

int main() {
    // Test cases
    cout << boolalpha; // Print true/false instead of 1/0
    cout << isMatch("leetcode", "ee*e") << endl; // true
    cout << isMatch("car", "c*v") << endl;       // false
    cout << isMatch("luck", "u*") << endl;      // true

    return 0;
}
