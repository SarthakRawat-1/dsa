// Problem Statement :- https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
// Valid operators in this context are '+', '-', '*', '/', '^'
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix expression to infix expression
string postfixToInfix(const string& postfix) {
    stack<string> st; // Stack to store intermediate infix expressions

    // Traverse through each character in the postfix expression from left to right
    for (char c : postfix) {
        
        // Case 1: Operand (e.g., variables or numbers)
        // If the character is an operand, push it onto the stack as a string
        if (isalnum(c)) {
            st.push(string(1, c)); // Convert char to string and push to stack
        }
        // Case 2: Operator
        // If the character is an operator, pop two elements from the stack
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();

            // Form a new infix expression by placing the operator between the two operands
            string infix = "(" + operand1 + c + operand2 + ")";

            // Push the resulting infix expression back onto the stack
            st.push(infix);
        }
    }

    // After processing all characters, the stack will contain only one element,
    // which is the fully converted infix expression.
    return st.top();
}

int main() {
    // Example postfix expression to convert
    string postfix = "AB+C*DE/-";
    cout << "Postfix expression: " << postfix << endl;
    
    // Convert postfix to infix and print the result
    cout << "Infix expression: " << postfixToInfix(postfix) << endl;
    
    return 0;
}
