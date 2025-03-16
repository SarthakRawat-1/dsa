// Problem Statement :- https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-postfix-conversion

#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
// Valid operators in this context are '+', '-', '*', '/', '^'
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert prefix expression to postfix expression
string prefixToPostfix(const string& prefix) {
    stack<string> st; // Stack to store intermediate postfix expressions

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // Case 1: Operand (e.g., variables or numbers)
        // If the character is an operand, push it onto the stack as a string
        if (isalnum(c)) {
            st.push(string(1, c)); // Convert char to string and push to stack
        }
        // Case 2: Operator
        // If the character is an operator, pop two elements from the stack
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();

            // Form a new postfix expression by placing the operands in order followed by the operator
            string postfix = operand1 + operand2 + c;

            // Push the resulting postfix expression back onto the stack
            st.push(postfix);
        }
    }

    // After processing all characters, the stack will contain only one element,
    // which is the fully converted postfix expression.
    return st.top();
}

int main() {
    // Example prefix expression to convert
    string prefix = "*+AB-CD";
    cout << "Prefix expression: " << prefix << endl;
    
    // Convert prefix to postfix and print the result
    cout << "Postfix expression: " << prefixToPostfix(prefix) << endl;
    
    return 0;
}
