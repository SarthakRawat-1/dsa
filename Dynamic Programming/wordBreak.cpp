// Problem Statement :- https://leetcode.com/problems/word-break/description/

// Simply try breaking a word from s from the start at diff lengths. If the broken word is in dictionary, continue by trying to break the rest of the word similarly.

#include <bits/stdc++.h>
using namespace std;

int n;                         // Length of the input string
unordered_set<string> st;      // Stores the dictionary words for O(1) lookup
int dp[300];                   // Memoization array: -1 = unvisited, 0 = false, 1 = true

// Recursive function to check if s[idx..end] can be segmented
bool solve(int idx, string &s) {
    // ✅ Base case: if we've reached the end, the string is fully segmented
    if (idx >= n) {
        return dp[idx] = true;
    }

    // ✅ If we've already solved for this index, return the cached result
    if (dp[idx] != -1) {
        return dp[idx];
    }

    // Try all possible substring lengths starting from idx
    for (int l = 1; l <= n - idx; l++) {
        // Take substring s[idx .. idx+l-1]
        string temp = s.substr(idx, l);

        // If substring exists in dictionary AND the rest of the string can also be segmented
        if (st.find(temp) != st.end() && solve(idx + l, s)) {
            return dp[idx] = true;   // ✅ Store result and return true
        }
    }

    // If no segmentation worked, mark as false
    return dp[idx] = false;
}

// Main function called by the problem
bool wordBreak(string s, vector<string>& wordDict) {
    n = s.length();                  // Store length of the string
    memset(dp, -1, sizeof(dp));      // Initialize dp array with -1 (unvisited)

    // Insert all words into unordered_set for fast lookup
    for (string &word : wordDict) {
        st.insert(word);
    }

    // Start recursion from index 0
    return solve(0, s);
}

int main() {

}