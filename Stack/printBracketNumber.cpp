// Problem Statement :- https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// Function to find bracket numbers in the string
vector<int> bracketNumbers(string S) {
    int count = 0; // Initialize a counter to track the bracket level

    stack<int> st; // Stack to keep track of opening bracket numbers

    vector<int> ans; // Vector to store the resulting bracket numbers

    // Iterate through each character in the string S
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') { // Check if the character is an opening bracket
            count++; // Increment the counter for each opening bracket
            st.push(count); // Push the current count onto the stack
            ans.push_back(count); // Store the current count in the result vector
        } else if (S[i] == ')') { // Check if the character is a closing bracket
            ans.push_back(st.top()); // Get the corresponding opening bracket number from the stack
            st.pop(); // Remove the top element from the stack since it is now matched
        }
    }

    return ans; // Return the vector containing bracket numbers
}

int main() {
    string str = "(aa(bdc))p(dee)"; 
    cout << "The bracket numbers are :- ";

    for (int i = 0; i < bracketNumbers(str).size(); i++) {
        cout << bracketNumbers(str)[i] << " ";
    } 

    return 0;
}
