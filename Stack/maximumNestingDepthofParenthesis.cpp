// Problem Statement :- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

// Stack based approach.
// We will use a variable called result (intilalized to 0) to store nested depth.
// Whenever we encounter an opening parenthesis, we push it in the stack. 
// Whenever we encounter a closing parenthesis, we pop one opening parenthesis from the stack. 
// We increase the result variable based on the size of stack i.e. number of opening parenthesis in the stack.
// Our Stack will always be empty at the end, because it is given in problem statement, that we only have Valid Parenthesis. 

#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    // Step 1: Initialize a stack to store opening parentheses
    stack<char> st;
    
    // Step 2: Initialize a variable to store the maximum depth (result)
    int result = 0;

    // Step 3: Iterate over each character in the string 's'
    for (char ch : s) {
        // Step 4: If the character is an opening parenthesis '('
        if (ch == '(') {
            // Push it onto the stack
            st.push(ch);
            // Update the maximum depth to the size of the stack if the stack size is greater
            result = max(result, (int)st.size()); // st.size() returns returns a value of type size_t, so we are converting it to int
        }
        // Step 5: If the character is a closing parenthesis ')'
        else if (ch == ')') {
            // Pop one opening parenthesis from the stack
            if (!st.empty()) {
                st.pop();
            }
        }
    }

    // Step 6: Return the maximum depth found during the traversal
    return result;
}

int main() {
    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";

    cout << "Max Depth of s1: " << maxDepth(s1) << endl;
    cout << "Max Depth of s2: " << maxDepth(s2) << endl;

    return 0;
}
