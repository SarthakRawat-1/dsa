// Problem Statement :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Approach :- Generate all possible letter combinations using **backtracking**.
// First, we need a mapping from digits to the corresponding letters.

#include <bits/stdc++.h>
using namespace std;

vector<string> result; // Global vector to store all possible combinations

// Recursive backtracking function
void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
    // Base Case: if we have formed a combination of length == digits length
    if (idx >= digits.length()) {
        result.push_back(temp); // store the formed combination
        return;
    }

    // Current digit we are processing
    char ch = digits[idx];
    string str = mp[ch]; // Get mapped letters for this digit

    // Try each letter corresponding to current digit
    for (int i = 0; i < str.length(); i++) {
        temp.push_back(str[i]);             // Choose a letter
        solve(idx + 1, digits, temp, mp);   // Recurse for next digit
        temp.pop_back();                    // Backtrack (undo the choice)
    }
}

// Main function to be called
vector<string> letterCombinations(string digits) {
    // Edge case: if input string is empty, return empty list
    if (digits.length() == 0) {
        return {};
    }

    // Mapping from digits to corresponding letters (like on phone keypad)
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    string temp = ""; // Temporary string to build each combination
    solve(0, digits, temp, mp); // Start recursion from index 0

    return result; // Return all stored combinations
}

int main() {
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);

    // Print result for testing
    for (auto &s : combinations) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
