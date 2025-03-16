#include <bits/stdc++.h>
using namespace std;

// Function to return the precedence of operators
// Higher return value indicates higher precedence.
int precedence(char op) {
    switch (op) {
        case '^': return 3;         // Exponent operator has the highest precedence
        case '*': case '/': return 2; // Multiplication and Division have medium precedence
        case '+': case '-': return 1; // Addition and Subtraction have the lowest precedence
        default: return -1;          // Invalid character or parenthesis has no precedence
    }
}

// Function to convert an infix expression (standard mathematical notation)
// to a postfix expression (reverse Polish notation).
string infixToPostfix(const string &exp) {
    stack<char> st;           // Stack to hold operators and parentheses
    string result;            // String to accumulate the final postfix expression

    // Iterate over each character in the infix expression
    for (char c : exp) {
        // Case 1: Operand (e.g., variables, numbers)
        // If character is alphanumeric (a-z, A-Z, 0-9), it's an operand, so we add it to the result.
        if (isalnum(c)) {
            result += c;
        }
        // Case 2: Opening parenthesis '('
        // Push '(' onto the stack to mark the beginning of a subexpression.
        else if (c == '(') {
            st.push(c);
        }
        // Case 3: Closing parenthesis ')'
        // Pop from the stack until '(' is encountered, appending each popped operator to result.
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top(); // Append operator to postfix result
                st.pop();            // Remove operator from stack
            }
            st.pop(); // Pop the '(' from the stack, but don't add it to result
        }
        // Case 4: Operator (e.g., '+', '-', '*', '/', '^')
        else {
            // While the stack is not empty and the precedence of the current operator
            // is less than or equal to the precedence of the operator on the top of the stack,
            // pop the operator from the stack to result.
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                result += st.top(); // Append operator to postfix result
                st.pop();           // Remove operator from stack
            }
            // Push the current operator to the stack
            st.push(c);
        }
    }

    // After reading all characters from the infix expression,
    // pop all remaining operators from the stack and add them to result.
    while (!st.empty()) {
        result += st.top(); // Append remaining operators to postfix result
        st.pop();           // Remove operator from stack
    }

    return result; // Return the final postfix expression
}

int main() {
    // Example infix expression to convert
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    // Convert infix to postfix and print the result
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
