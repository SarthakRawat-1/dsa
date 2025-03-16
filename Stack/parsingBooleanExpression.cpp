// Problem Statement :- https://leetcode.com/problems/parsing-a-boolean-expression/description/

// Consider !(&(f, t))
// You can store elements in a Stack till you reach a closing parenthesis. When you encounter a closing parenthesis it means there was an opening parenthesis. So, now pop elements from stack till you get an opening parenthesis (pop that also), and store them in vector (don't store opening parenthesis). The operation to be performed between the obtained elements is present just before the opening parenthesis, i.e. the top of stack.
// For AND operation, we just need to check if any of the expression is f in the vector because AND results in false if any one of the operand is false. Similarly, for OR, we will check if any one is t.
// For NOT operation, there will only be one element in the vector. So, we just return the opposite of that element.
// After we solve one set of parenthesis, we will push the result back to the Stack. After that, continue traversing from where you left off.

#include <bits/stdc++.h>
using namespace std;

// Function to solve a sub-expression based on the operator provided
// Parameters:
//   - op: the operator (!, &, or |)
//   - values: vector containing the boolean values to be operated on ('t' or 'f')
char solveOp(char op, vector<char>& values) {
    // NOT operation: returns the opposite of the only value in `values`
    if (op == '!') 
        return values[0] == 't' ? 'f' : 't';

    // AND operation: returns 'f' if any value in `values` is 'f', otherwise returns 't'
    if (op == '&') 
        return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';

    // OR operation: returns 't' if any value in `values` is 't', otherwise returns 'f'
    if (op == '|') 
        return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';

    return 't'; // Unreachable, placeholder to satisfy return requirements
}

// Main function to parse a boolean expression and evaluate it
bool parseBoolExpr(string s) {
    int n = s.size();       // Size of the input expression
    stack<char> st;         // Stack to store characters as we process them

    // Traverse through each character in the expression
    for (int i = 0; i < n; i++) {
        if (s[i] == ',') continue;  // Ignore commas, as they don't affect the evaluation

        // If closing parenthesis is found, process the current sub-expression
        if (s[i] == ')') {
            vector<char> values;   // To store values within the current parenthesis

            // Pop elements from the stack until we find the matching '('
            while (st.top() != '(') {
                values.push_back(st.top()); // Collect all values between '(' and ')'
                st.pop();
            }
            st.pop();  // Remove '(' from the stack

            char op = st.top();    // Get the operator just before '(' (e.g., !, &, or |)
            st.pop();              // Remove the operator from the stack
            st.push(solveOp(op, values)); // Solve the sub-expression and push the result back
        } else {
            // Push the current character onto the stack if it's not a ')'
            st.push(s[i]);
        }
    }
    // The final result will be the only element left on the stack
    return (st.top() == 't');
}

int main() {
    string s = "&(|(f))"; // Example boolean expression

    cout << parseBoolExpr(s); // Output the result of the parsed boolean expression
}
