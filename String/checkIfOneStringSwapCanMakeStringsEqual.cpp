// Problem Statement :- https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// bool areAlmostEqual(string s1, string s2) {
//     int n = s1.length();

//     // If both strings are already equal, return true
//     if (s1 == s2) {
//         return true;
//     }

//     int diffs = 0;  // Count the number of differing positions

//     int freq1[26] = {0};  // Frequency array for s1
//     int freq2[26] = {0};  // Frequency array for s2

//     // Iterate through both strings and track differences
//     for (int i = 0; i < n; i++) {
//         if (s1[i] != s2[i]) {
//             diffs++;  // Increment count if characters at index 'i' are different
//         }

//         // If more than 2 differences are found, swapping is not possible
//         if (diffs > 2)
//             return false;

//         // Count frequency of each character in both strings
//         freq1[s1[i] - 'a']++;
//         freq2[s2[i] - 'a']++;
//     }

//     // Check if both strings have the same character frequencies
//     for (int i = 0; i < 26; i++) {
//         if (freq1[i] != freq2[i]) {
//             return false;  // If frequencies do not match, return false
//         }
//     }

//     // If there are exactly 2 differing positions and character counts match, return true
//     return true;
// }

// Optimal Approach - 
bool areAlmostEqual(string s1, string s2) {
    int n = s1.length();

    // If both strings are already equal, return true
    if (s1 == s2) {
        return true;
    }

    int diffs = 0;   // Count the number of differing positions
    int firstIdx = -1, secondIdx = -1;  // Track indices where differences occur

    // Iterate through both strings and track differences
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            diffs++;  // Increment count if characters at index 'i' are different

            // If more than 2 differences, swapping cannot make the strings equal
            if (diffs > 2) {
                return false;
            }

            // Store the first and second differing indices
            if (diffs == 1) {
                firstIdx = i;
            } else {
                secondIdx = i;
            }
        }
    }

    // Ensure that swapping the two differing characters results in equality
    return s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx];
}

int main() {
    string s1 = "bank", s2 = "kanb";
    cout << areAlmostEqual(s1, s2) << endl;  // Output: true
}