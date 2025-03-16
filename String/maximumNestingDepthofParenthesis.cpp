// Problem Statement :- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

// Counter based Approach
// We can intialize a counter to store the count of opening brackets. We will increment it for each '(' and decrement it for each ')' in the string.
// We will also use a result variable to store nested depth. Whenever we are updating the counter, we will store max(counter, result) in result. 

#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int counter = 0; // Keeps track of open parentheses
    int result = 0;  // Stores the maximum nesting depth

    // Step 2: Traverse each character in the string 's'
    for (char c : s) {
        // Step 3: If the current character is '(', increment the counter
        if (c == '(') {
            counter++; // One more opening parenthesis is encountered
            result = max(result, counter); // Update result with the max depth so far
        } 
        // Step 4: If the current character is ')', decrement the counter
        else if (c == ')') {
            counter--; // One closing parenthesis reduces the current depth
        }
    }

    // Step 5: Return the maximum depth found
    return result;
}

int main() {
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Max depth of '" << s1 << "': " << maxDepth(s1) << endl; // Expected: 3

    string s2 = "(1)+((2))+(((3)))";
    cout << "Max depth of '" << s2 << "': " << maxDepth(s2) << endl; // Expected: 3

    string s3 = "1+(2*3)/(2-1)";
    cout << "Max depth of '" << s3 << "': " << maxDepth(s3) << endl; // Expected: 1

    string s4 = "1";
    cout << "Max depth of '" << s4 << "': " << maxDepth(s4) << endl; // Expected: 0

    return 0;
}
