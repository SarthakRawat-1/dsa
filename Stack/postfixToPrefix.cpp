// Problem Statement :- https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

#include <bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert postfix expression to prefix expression
string postfixToPrefix(const string& postfix) {
    stack<string> st; // Stack to store intermediate prefix expressions

    // Traverse the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // Case 1: Operand (e.g., variables or numbers)
        // If the character is an operand, push it onto the stack as a string
        if (isalnum(c)) {
            st.push(string(1, c)); // Convert char to string and push to stack
        }
        // Case 2: Operator
        // If the character is an operator, pop two elements from the stack
        else if (isOperator(c)) {
            // Ensure there are at least two operands in the stack
            if (st.size() < 2) {
                cerr << "Error: Insufficient operands in the stack for operator " << c << endl;
                return ""; // Return empty string in case of error
            }

            // Pop the top two operands from the stack
            string operand2 = st.top(); // Pop first operand (top of the stack)
            st.pop();
            string operand1 = st.top(); // Pop second operand
            st.pop();

            // Form a new prefix expression by placing the operator in front of the operands
            string prefix = c + operand1 + operand2;

            // Push the resulting prefix expression back onto the stack
            st.push(prefix);
        }
    }

    // After processing all characters, the stack will contain only one element,
    // which is the fully converted prefix expression.
    if (st.size() != 1) {
        cerr << "Error: Invalid postfix expression." << endl;
        return ""; // Return empty string in case of error
    }
    return st.top(); // Return the final prefix expression
}

int main() {
    // Example postfix expression to convert
    string postfix = "AB+C*D-";
    cout << "Postfix expression: " << postfix << endl;
    
    // Convert postfix to prefix and print the result
    string prefix = postfixToPrefix(postfix);
    if (!prefix.empty()) {
        cout << "Prefix expression: " << prefix << endl;
    }

    return 0;
}
