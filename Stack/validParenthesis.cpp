// Problem Statement :- https://leetcode.com/problems/valid-parentheses/description/

// Push opening parenthesis/braces/brackets in Stack when they are encountered. When you encounter closing parenthesis/braces/brackets, then check if top element of Stack also has same type of opening parenthesis/braces/brackets. If yes, then pop that from Stack and continue till Stack becomes empty. If they are different, our parenthesis are not valid.

#include <bits/stdc++.h>
using namespace std;

// Function to check if the input string of parentheses is valid
bool isValid(string s) {
    // Stack to store the opening brackets (i.e., '(', '{', '[')
    stack <char> st;

    // Loop through each character in the input string
    for (char &ch : s) {
        // If stack is empty or current character is an opening bracket, push it to the stack
        if (st.empty() || ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);    
        } 
        // If current character is a closing parenthesis ')', check the top of the stack for a matching '('
        else if (ch == ')') {
            // If the top element is '(', pop it from the stack (as it's a valid pair)
            if (st.top() == '(') {
                st.pop();
            } 
            // If the top element is not '(', return false (invalid parentheses)
            else {
                return false;
            }
        } 
        // If current character is a closing curly brace '}', check the top of the stack for a matching '{'
        else if (ch == '}') {
            // If the top element is '{', pop it from the stack (valid pair)
            if (st.top() == '{') {
                st.pop();
            } 
            // If the top element is not '{', return false (invalid parentheses)
            else {
                return false;
            }
        } 
        // If current character is a closing square bracket ']', check the top of the stack for a matching '['
        else if (ch == ']') {
            // If the top element is '[', pop it from the stack (valid pair)
            if (st.top() == '[') {
                st.pop();
            } 
            // If the top element is not '[', return false (invalid parentheses)
            else {
                return false;
            }
        }
    }

    // If the stack is empty after processing all characters, return true (valid parentheses)
    return st.empty();
}

int main() {
    string s = "{{[()()[]]}}";

    cout << isValid(s);
}


// Other approach :- When you encounter an opening bracket of any type, push it's corresponding closing bracket to the Stack
// When you encounter a closing bracket of any type, check if top element of Stack is equal to that. If it is, then pop it from Stack. If not, return false.

#include <bits/stdc++.h>
using namespace std;

// Function to check if the input string of parentheses is valid
bool isValid(string s) {
    // Stack to store the expected closing brackets
    stack <char> st;

    // Loop through each character in the input string
    for (char &ch : s) {
        // If current character is an opening parenthesis '(', push its corresponding closing parenthesis ')' to the stack
        if (ch == '(') {
            st.push(')');
        } 
        // If current character is an opening curly brace '{', push its corresponding closing brace '}' to the stack
        else if (ch == '{') {
            st.push('}');
        } 
        // If current character is an opening square bracket '[', push its corresponding closing bracket ']' to the stack
        else if (ch == '[') {
            st.push(']');
        } 
        // If the current character is a closing bracket:
        // 1. Check if the stack is empty (which means no matching opening bracket) or
        // 2. If the top of the stack does not match the current closing bracket, return false (invalid parentheses)
        else if (st.empty() || st.top() != ch) {
            return false;
        } 
        // If the top of the stack matches the current closing bracket, pop it from the stack
        else {
            st.pop();
        }
    }

    // After processing all characters, if the stack is empty, return true (valid parentheses)
    return st.empty();
}

int main() {
    string s = "{{[()()[]]}}";

    cout << isValid(s);
}