// Problem Statement :- https://leetcode.com/problems/generate-parentheses/description/

// Ofc number of opening brackets (already placed) should always be greater than or equal to number of closing brackets (already placed) at any position in a well formed parenthesis
// Then simply we will make recursion tree, we will first add only left parenthesis and then subsequently we will explore the two paths of adding left or right parenthesis.
// Ofc max left parenthesis = n and max right parenthesis = n, we can't add more than that. We will continue this till we reach those branches which have placed both left adn right parenthesis completely.
// 

#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive helper function to generate all valid combinations of parentheses.
 *
 * @param n      - Total number of pairs of parentheses required.
 * @param left   - Number of '(' used so far.
 * @param right  - Number of ')' used so far.
 * @param ans    - Vector to store all valid combinations.
 * @param temp   - Temporary string that builds the current combination.
 */
void parenth(int n, int left, int right, vector<string> &ans, string &temp) {
    // Base Case: If total characters used equals 2 * n, the current string is a valid combination
    if (left + right == 2 * n) {
        ans.push_back(temp);  // Add the valid combination to the result
        return;
    }

    // If we can still add a '(', do it (i.e., left < n)
    if (left < n) {
        temp.push_back('(');                      // Add '(' to the current string
        parenth(n, left + 1, right, ans, temp);   // Recurse with one more '(' used
        temp.pop_back();                          // Backtrack: remove the last added '('
    }

    // We can only add ')' if right < left (to ensure it's valid)
    if (right < left) {
        temp.push_back(')');                      // Add ')' to the current string
        parenth(n, left, right + 1, ans, temp);   // Recurse with one more ')' used
        temp.pop_back();                          // Backtrack: remove the last added ')'
    }
}

/*
 * Main function to initiate generation of all valid parentheses combinations.
 *
 * @param n - Number of pairs of parentheses.
 * @return  - A vector containing all valid parentheses combinations.
 */
vector<string> generateParenthesis(int n) {
    vector<string> ans;     // Final list to store valid combinations
    string temp;            // Temporary string to build each combination

    parenth(n, 0, 0, ans, temp);  // Start with 0 '(' and 0 ')' used

    return ans;
}

int main() {
    
}