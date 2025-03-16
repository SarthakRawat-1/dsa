// Problem Statement :- https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// When you encounter digits, store them in Stack. When you encounter a operator, pop top two elements from Stack and calculate the result. Push the result in Stack again.
// Ofc since these are strings, we have to first convert them to integers. 
// Sometimes result of multiplication can cause overflow, in that case use long long int type.

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    // Stack to store intermediate results of the Reverse Polish Notation (RPN) expression
    stack<int> st;

    // Iterate over each token (string) in the given list of tokens (RPN expression)
    for (string &token : tokens) {
        // Check if the token is an operator (+, -, *, /)
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop the top two elements from the stack to perform the operation
            // 'b' is the first element popped, representing the second operand
            int b = st.top();
            st.pop();
            // 'a' is the second element popped, representing the first operand
            int a = st.top();
            st.pop();

            // Perform the operation based on the token
            if (token == "+") 
                st.push(a + b);  // If token is "+", push the result of a + b
            else if (token == "-") 
                st.push(a - b);  // If token is "-", push the result of a - b
            else if (token == "*") 
                st.push(a * b);  // If token is "*", push the result of a * b
            else if (token == "/") 
                st.push(a / b);  // If token is "/", push the result of a / b (integer division)
        } else {
            // If the token is not an operator, it must be a number
            // Convert the string token to an integer and push it onto the stack
            st.push(stoi(token));
        }
    }

    // The result of the RPN expression will be the only element left in the stack
    return st.top();
}


int main() {
    vector <string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens);
}


// Approach 2 :- Using Unordered Map and Lambda. 
// Instead of declaring if else statements for every operator, we can use unordered map and lambda.
// In unordered map, key will be operator and value will be fucntion which takes two number and return result of that operator on those two numbers. This function we will write using lambda.

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    unordered_map <string, function<int(int, int)>> mp = { // Key is string, Value is function whose return type is int, and it takes two int as arguments.
        {"+", [](int a, int b) {return a + b;}}, // Key is "+", value is a lambda function which takes two integer a and b and returns a + b
        {"-", [](int a, int b) {return a - b;}},
        {"*", [](int a, int b) {return a * b;}},
        {"/", [](int a, int b) {return a / b;}}
    };

    stack<int> st;

    // Iterate over each token (string) in the given list of tokens (RPN expression)
    for (string &token : tokens) {
        // Check if the token is an operator (+, -, *, /)
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop the top two elements from the stack to perform the operation
            // 'b' is the first element popped, representing the second operand
            int b = st.top();
            st.pop();
            // 'a' is the second element popped, representing the first operand
            int a = st.top();
            st.pop();

            int result = mp[token](a, b); // Perform the operation based on the token
            st.push(result);
        } else {
            // If the token is not an operator, it must be a number
            // Convert the string token to an integer and push it onto the stack
            st.push(stoi(token));
        }
    }

    // The result of the RPN expression will be the only element left in the stack
    return st.top();
}

int main() {
    vector <string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens);
}