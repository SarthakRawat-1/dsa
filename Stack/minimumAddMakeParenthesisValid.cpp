// Problem Statement :- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

// This can be solved both with Stack, or just with a size variable behaving like a Stack.
// It's Stack approach is very similar to one with validParenthesis.cpp

#include <bits/stdc++.h>
using namespace std;

// Function to compute the minimum number of parentheses to add to make a string valid
int minAddToMakeValid(string s) {
    // Variable to track the number of unmatched '(' parentheses
    int size = 0;
    
    // Variable to count the unmatched ')' parentheses
    int open = 0;

    // Loop through each character of the input string
    for (char &ch : s) {
        // If the current character is '(', increment size (acts like pushing to a stack)
        if (ch == '(') {
            size++;
        } 
        // If the current character is ')' and there is an unmatched '(' to pair with
        else if (size > 0) {
            // Decrease size to indicate one '(' is now matched (popping from stack)
            size--;
        } 
        // If there are no unmatched '(' (size == 0) to match with the current ')', it is an unmatched ')'
        else {
            // Increment open to count the unmatched ')'
            open++;
        }
    }

    // Return the total number of unmatched parentheses:
    // 'open' is the number of unmatched ')' parentheses
    // 'size' is the number of unmatched '(' parentheses
    return open + size;
}

int main() {
    string s = "(((";

    cout << minAddToMakeValid(s);
}