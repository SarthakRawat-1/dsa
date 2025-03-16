// Problem Statement :- https://leetcode.com/problems/validate-stack-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// Function to validate if a given stack push/pop sequence is valid
// pushed -> list of integers representing the sequence of elements pushed to the stack
// popped -> list of integers representing the sequence of elements popped from the stack
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    // Stack to simulate the push and pop operations
    stack<int> st;

    // Size of the pushed and popped sequences (both should be the same length)
    int m = pushed.size();

    // Two pointers: i to iterate over 'pushed' and j to iterate over 'popped'
    int i = 0, j = 0;

    // Loop to process all elements in the 'pushed' array
    while (i < m && j < m) {
        // Push the current element from 'pushed' to the stack
        st.push(pushed[i]);

        // While the stack is not empty and the top of the stack matches the current element in 'popped'
        // This simulates popping the elements in the same sequence as in 'popped'
        while (!st.empty() && st.top() == popped[j]) {
            st.pop(); // Pop the element from the stack
            j++;      // Move to the next element in 'popped'
        }

        // Move to the next element in 'pushed'
        i++;
    }

    // After the loop, the stack should be empty if the push/pop sequence is valid
    // If the stack is not empty, it means the sequence cannot be valid
    return st.empty();
}

int main() {
    vector <int> pushed = {1, 2, 3, 4, 5};
    vector <int> popped = {4, 5, 3, 2, 1};

    cout << validateStackSequences(pushed, popped);
}