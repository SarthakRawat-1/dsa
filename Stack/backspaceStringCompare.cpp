// Problem Statement :- https://leetcode.com/problems/backspace-string-compare/description/

// Start iterating on string. Put the characters in Stack one by one. Check if the element is #. If it is #, pop the top element from the Stack and do not put # in the Stack. 

#include <bits/stdc++.h>
using namespace std;

// Function to process the string by simulating backspace operations
string processString(const string &str) {
    stack<char> s;  // Stack to store the processed characters
    
    // Iterate through the string
    for (char ch : str) {
        if (ch != '#') {
            // If the current character is not a backspace, push it to the stack
            s.push(ch);
        } else if (!s.empty()) {
            // If the current character is a backspace and the stack is not empty,
            // pop the top element (simulating a backspace)
            s.pop();
        }
    }
    
    // Build the final processed string from the stack
    string result;
    while (!s.empty()) {
        result += s.top();  // Add each character to the result string
        s.pop();            // Remove it from the stack
    }
    
    // Reverse the string because we retrieved the characters from the stack
    reverse(result.begin(), result.end());
    
    return result;  // Return the final processed string
}

// Function to compare two strings after processing backspaces
bool backspaceCompare(string s, string t) {
    // Process both strings using the processString function
    return processString(s) == processString(t);
}

int main() {
    string s1 = "ab#c";
    string s2 = "ad#c";

    // Compare the two strings after processing backspaces
    if (backspaceCompare(s1, s2)) {
        cout << "The strings are equal after backspacing." << endl;
    } else {
        cout << "The strings are NOT equal after backspacing." << endl;
    }

    return 0;
}
