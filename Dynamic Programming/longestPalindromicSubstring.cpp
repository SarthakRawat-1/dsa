// Problem Statement :- https://leetcode.com/problems/longest-palindromic-substring/description/

// First we should discuss how to reverse a string. Ofc first emthod is to reverse and then check if it's same.
// Other is two pointer method. Start from first and last element, and check if they are equal. Then move to second first and second last and so on.

// Find all substring. And check if they are palindrome or not.
// We have to use memoization to cache intermediate results.

#include <bits/stdc++.h>
using namespace std;

// 2D DP memoization table
// t[l][r] will store whether substring s[l..r] is a palindrome
// -1 → not yet computed
//  0 → false (not palindrome)
//  1 → true  (is palindrome)
int t[1001][1001];

// Recursive function to check if s[l..r] is a palindrome
bool solve(string &s, int l, int r) {
    // Base case 1: Single character or empty string is always a palindrome
    if (l >= r) 
        return 1;

    // If we have already computed this state, return stored result
    if (t[l][r] != -1) {
        return t[l][r];
    }

    // If characters at both ends match, check inner substring
    if (s[l] == s[r]) {
        // Store and return whether the inside substring is a palindrome
        return t[l][r] = solve(s, l + 1, r - 1);
    }

    // If characters don't match, it's not a palindrome
    return t[l][r] = false;
}

string longestPalindrome(string s) {
    int n = s.length();

    int maxlen = INT_MIN;     // To store the maximum palindrome length found
    int startingIndex = 0;    // To store the starting index of that palindrome

    // Initialize DP table with -1 (uncomputed)
    memset(t, -1, sizeof(t));

    // Try every possible substring s[i..j]
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            // If current substring is palindrome
            if (solve(s, i, j)) {
                
                // Check if it's longer than the previously found one
                if (j - i + 1 > maxlen) {
                    startingIndex = i;           // Update starting position
                    maxlen = j - i + 1;          // Update maximum length
                }
            }
        }
    }

    // Return the longest palindromic substring
    return s.substr(startingIndex, maxlen);
}

int main() {

}