// Problem Statement :- https://www.geeksforgeeks.org/problems/get-min-at-pop/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

// Function to push elements of the array into the stack
// The stack stores the minimum element at each level as we push elements
stack<int> _push(int arr[], int n) {
    stack<int> st;  // Stack to store the minimum elements

    // Iterate through the array and push elements into the stack
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // If it's the first element, simply push it into the stack
            st.push(arr[i]);
        } else {
            // For subsequent elements, push the minimum between the current element
            // and the top element of the stack (which stores the minimum so far)
            st.push(min(arr[i], st.top()));
        }
    }

    return st;  // Return the stack with minimum elements stored at each level
}

// Function to print the minimum at each pop from the stack
void _getMinAtPop(stack<int> st) {
    // Continue popping elements until the stack is empty
    while (!st.empty()) {
        // Print the top of the stack (which contains the current minimum)
        cout << st.top() << " ";
        // Pop the top element
        st.pop();
    }
    cout << endl;  // Print a new line after all elements have been printed
}

int main() {
    int arr[] = {1, 2, 3, 4, 99, 87, 45, 67, 21};

    stack <int> st = _push(arr, 9);
    _getMinAtPop(st);

    return 0;
}