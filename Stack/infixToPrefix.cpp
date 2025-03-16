// Problem Statement :- https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3; // Highest precedence
    else if (c == '*' || c == '/') return 2; // Medium precedence
    else if (c == '+' || c == '-') return 1; // Lowest precedence
    else return -1; // Invalid operator
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string infix) {
    // Reverse the infix expression to facilitate conversion to prefix
    reverse(infix.begin(), infix.end());

    stack<char> operators; // Stack to store operators
    string result; // String to build the prefix expression

    // Traverse the reversed infix expression
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Case 1: If character is an operand (alphanumeric), add it to result
        if (isalnum(c)) {
            result += c; // Append operand to the result
        }
        // Case 2: If character is '(', treat it as ')' for the reversed expression
        else if (c == ')') {
            operators.push(c); // Push ')' to the stack
        }
        // Case 3: If character is ')', pop until '(' is encountered
        else if (c == '(') {
            // Pop from stack to result until ')' is found
            while (!operators.empty() && operators.top() != ')') {
                result += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the ')' from stack
        }
        // Case 4: If character is an operator
        else if (isOperator(c)) {
            // Pop operators from the stack to the result while they have higher or equal precedence
            while (!operators.empty() && precedence(c) < precedence(operators.top())) {
                result += operators.top();
                operators.pop();
            }
            // Push the current operator onto the stack
            operators.push(c);
        }
    }

    // Pop all the remaining operators from the stack to the result
    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }

    // The result is in reverse order due to the initial reversal, so reverse it back
    reverse(result.begin(), result.end());

    return result; // Return the final prefix expression
}

int main() {
    // Example infix expression to convert
    string infix = "(A+B)*C-D";
    cout << "Infix expression: " << infix << endl;
    
    // Convert infix to prefix and print the result
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
