// Problem Statement :- https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

// Global variable to store the string length for use in recursion.
int n;

/*
 * Function: isPalindrome
 * ------------------------
 * Checks if a substring of the given string 's' (from index 'start' to index 'end') is a palindrome.
 *
 * Parameters:
 *   s     - The input string.
 *   start - The starting index of the substring.
 *   end   - The ending index of the substring.
 *
 * Returns:
 *   A boolean value indicating whether the substring is a palindrome.
 *
 * Approach:
 *   - Compare the characters from the beginning and the end of the substring.
 *   - Move towards the center until all corresponding characters match.
 *   - If any pair does not match, it returns false.
 *   - If all pairs match, it returns true.
 */
bool isPalindrome(string &s, int start, int end) {
    // Using a two-pointer approach, incrementing from start and decrementing from end.
    while (start < end) {
        // If characters at corresponding positions do not match, it's not a palindrome.
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

/*
 * Function: backtrack
 * -------------------
 * Recursively partitions the string 's' into all possible combinations such that every substring is a palindrome.
 *
 * Parameters:
 *   s      - The input string.
 *   idx    - The current index in the string from where to check for palindromic substrings.
 *   curr   - The current list (vector) of palindromic substrings that form a partition.
 *   result - The main list (vector of vectors) where each valid palindromic partition is stored.
 *
 * Approach:
 *   - The function uses recursion to try every possible end index for a substring starting from 'idx'.
 *   - For each substring from 'idx' to 'i', check if it is a palindrome.
 *   - If it is, add it to the current partition and recursively process the remaining substring (i+1 onwards).
 *   - Once the end of the string is reached (i.e., idx equals n), store the current partition in the result.
 *   - Backtrack to try other possibilities by removing the last added substring.
 */
void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
    // Base case: If we have reached the end of the string, add the current partition to the result.
    if (idx == n) {
        result.push_back(curr);
        return;
    }
    
    // Explore all possible end indices 'i' for the substring starting from 'idx'
    for (int i = idx; i < n; i++) {
        // Check if the current substring [idx, i] is a palindrome.
        if (isPalindrome(s, idx, i)) {
            // If yes, add this substring to the current partition.
            curr.push_back(s.substr(idx, i - idx + 1));
            // Recur for the substring starting from the next position (i + 1).
            backtrack(s, i + 1, curr, result);
            // Backtrack: Remove the last added substring to try another partition possibility.
            curr.pop_back();
        }
    }
}

/*
 * Function: partition
 * -------------------
 * Main function which initiates the partitioning of the input string into all possible palindromic partitions.
 *
 * Parameter:
 *   s - The input string that needs to be partitioned.
 *
 * Returns:
 *   A vector of vectors of strings, where each inner vector represents a valid partition where each substring is a palindrome.
 *
 * Approach:
 *   - The length of the string is stored in a global variable 'n'.
 *   - An empty temporary vector 'curr' is created to store the current partition.
 *   - The backtracking function is called starting from index 0.
 *   - Finally, the complete list of partitions is returned.
 */
vector<vector<string>> partition(string s) {
    n = s.size();
    vector<vector<string>> result; // To store the list of palindromic partitions.
    vector<string> curr;           // Temporary vector to store current partition.
    
    // Start recursive backtracking from index 0.
    backtrack(s, 0, curr, result);
    
    return result;
}

int main() {
    // Example use: You could call partition("aab") and print the results.
    string input = "aab";
    vector<vector<string>> partitions = partition(input);
    
    // Print out all the palindromic partitions.
    for (const auto &part : partitions) {
        for (const auto &str : part)
            cout << str << " ";
        cout << endl;
    }
    
    return 0;
}
