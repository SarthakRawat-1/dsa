// Problem Statement :- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.length();  // Get the length of the string

    int result = 0;  // This variable stores the count of valid substrings
    
    vector<int> mp(3, 0); // Frequency array to track occurrences of 'a', 'b', and 'c'
                          // Index 0 -> 'a', Index 1 -> 'b', Index 2 -> 'c'

    int i = 0;  // Left pointer of the sliding window
    int j = 0;  // Right pointer of the sliding window

    // Start expanding the right pointer
    while (j < n) {
        char ch = s[j];   
        mp[ch - 'a']++;  // Increment the count for the current character
        
        // Check if the window contains at least one 'a', one 'b', and one 'c'
        while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
            // If all three characters are present, all substrings ending from (i to n-1)
            // with the current window contribute to the result.
            result += (n - j);

            // Contract the window from the left by moving 'i' forward
            mp[s[i] - 'a']--;  // Reduce the count of the character at index 'i'
            i++;  // Move the left pointer forward
        }

        j++;  // Expand the right pointer
    }

    return result;  // Return the total count of valid substrings
}

int main() {

}