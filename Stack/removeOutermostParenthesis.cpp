// Problem Statement :- https://leetcode.com/problems/remove-outermost-parentheses/description/

// Stack Based Approach
// Whenever the stack is empty, we add the current character to the stack, but don't add it to answer string.
// If the stack is not empty, push it to the stack and add the element to answer if it is an opening parenthesis. For closing parenthesis pop an element from stack and add closing parenthesis to answer string.
// Consider this eg :- ((()))(()())
// Intially stack is empty, so we push the first charcter i.e. ( into stack. Then moving onto the next character, we again enocunter ( but this time stack is not empty, so add this to stack and answer string. Do the same for the next character which is (
// Now we have encountered ), in this case, pop one character from stack which will obviously be ( and add this ) for the answer string. Do the same for the next ) string.
// Now we only have one ( left in the stack. And we have encountered a ) again. This time when you pop, the stack will become empty, hence, we don't add this ) to answer string.
// As the stack is empty now, the next primitive decomposition can be processed.

#include <bits/stdc++.h>
#include <stack>
using namespace std;

string removeOuterParentheses(string s) {
    string result;       // This will hold the final answer after removing outermost parentheses
    stack<char> st;      // Stack to track the balance of parentheses

    // Traverse each character in the input string
    for (char ch : s) {
        if (ch == '(') {
            // If stack is not empty, it means we are inside a primitive string
            // So, we add the current '(' to the result (it is not the outermost one)
            if (!st.empty()) {
                result += '(';
            }
            // Push the current '(' into the stack to keep track of the balance
            st.push('(');
        } else {
            // For closing parenthesis ')':
            // First, pop the matching opening parenthesis '(' from the stack
            st.pop();

            // If the stack is not empty after popping, it means we are still inside
            // a primitive string, so we add the current ')' to the result
            if (!st.empty()) {
                result += ')';
            }
        }
    }

    // Return the result after processing all characters
    return result;
}


int main() {
    string s1 = "(()())(())";
    cout << "Output for s1: " << removeOuterParentheses(s1) << endl; // Output: "()()()"

    string s2 = "(()())(())(()(()))";
    cout << "Output for s2: " << removeOuterParentheses(s2) << endl; // Output: "()()()()(())"

    string s3 = "()()";
    cout << "Output for s3: " << removeOuterParentheses(s3) << endl; // Output: ""

    return 0;
}
