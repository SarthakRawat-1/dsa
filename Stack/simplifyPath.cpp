// Problem Statement :- https://leetcode.com/problems/simplify-path/description/

// First we will tokenize it i.e. break the string by '/' delimiter.
// If you encounter any token other than ".." or "." or empty i.e. "" in the stack, then simply push it into the stack.
// If you encounter ".", then do nothing to the stack.
// If you encounter "..", then pop the top element from the stack
// At the end, we will construct the final path from the stack. From stack we will get it in reverse order if we append. Hence, we will prepend (or you can just reverse after appending).
// You can also use a Vector instead of a Stack.

#include <bits/stdc++.h>
using namespace std;

// Function to simplify the given Unix-style file path
string simplifyPath(string path) {
    string token = ""; // Temporary string to store each directory/file name or symbol i.e. token
    stringstream ss(path); // Use stringstream to split the path by '/'. Here ss is just a variable name and stringstream is the type.
    stack<string> st; // Stack to store valid directory names for constructing the final path
    
    // Process each token separated by '/' in the path
    while(getline(ss, token, '/')) { 
        
        // If token is empty or ".", skip it as it refers to the current directory
        if(token == "" || token == ".") continue;
        
        // If token is "..", move one directory up by popping from the stack
        if (token != "..") 
            st.push(token); // Valid directory name, add it to the stack
        else if (!st.empty()) 
            st.pop(); // Pop the last directory if available, moving up
    }
    
    string result = ""; // String to store the simplified path
    
    // Construct the final path from the stack
    while(!st.empty()) {
        // Prepend each directory in the stack to the result
        result = "/" + st.top() + result;
        st.pop();
    }
    
    // If result is empty after processing, set it to the root "/"
    if(result.length() == 0) 
        result = "/"; // Minimum root directory must be present in result
    
    return result;
}

int main() {
    // Example usage (add an example path for testing)
    string path = "/a/./b/../../c/";
    cout << simplifyPath(path) << endl; // Output simplified path
}

