// Problem Statement :- https://leetcode.com/problems/remove-outermost-parentheses/description/

// Counter based Approach
// We intialize a counter named balance to 0. We will increment it for each '(' and decrement it for each ')' in the string. 
// Initially, the balance is zero, this means that we are either going to start the valid parenthesis or end it. In both these cases, we don't add anything to our answer string.
// If the balance is not zero, we will add the character to our answer string.

#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string result;
    int balance = 0;  // This will act like our stack to track the balance of parentheses

    for (char ch : s) {
        if (ch == '(') {
            // If balance is greater than 0, we're inside a valid primitive, so add '('
            if (balance > 0) {
                result += '(';
            }
            balance++;  // Increment balance for each '('
        } else {
            balance--;  // Decrement balance for each ')'
            // If balance is still greater than 0 after decrementing, we're inside a valid primitive, so add ')'
            if (balance > 0) {
                result += ')';
            }
        }
    }

    return result;
}

int main() {
    // Test case 1: "(()())(())"
    string s1 = "(()())(())";
    cout << "Output for s1: " << removeOuterParentheses(s1) << endl;  // Output: "()()()"

    // Test case 2: "(()())(())(()(()))"
    string s2 = "(()())(())(()(()))";
    cout << "Output for s2: " << removeOuterParentheses(s2) << endl;  // Output: "()()()()(())"

    // Test case 3: "()()"
    string s3 = "()()";
    cout << "Output for s3: " << removeOuterParentheses(s3) << endl;  // Output: ""

    return 0;
}
