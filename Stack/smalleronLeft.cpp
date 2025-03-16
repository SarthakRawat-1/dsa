// Problem Statement :- https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/0

// This problem is similar to finding the next smaller element, but instead, we need to find the smallest element on the left.
// The goal is to determine the closest smaller element to the left for each element in the array.

// Approach :-
// 1. Use a stack to keep track of elements.
// 2. Traverse the array from left to right.
// 3. For each element, check if it is greater than or equal to the element at the top of the stack.
// 4. If it is, remove elements from the stack until we find a smaller element or the stack is empty.
// 5. If the stack is not empty, the top element is the smallest element to the left.
// 6. Push the current element onto the stack.
// 7. At the end, elements that have no smaller element to their left are set to -1.

#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest element on the left for each element
vector<int> leftSmaller(int n, int a[]) {
    // Initialize result array with -1 for all elements
    vector<int> ans(n, -1);
    // Stack to store elements
    stack<int> st;

    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {
        // Remove elements from the stack that are greater than or equal to the current element
        while (!st.empty() && st.top() >= a[i]) {
            st.pop();
        }
        // If stack is not empty, the top element is the smallest element on the left
        if (!st.empty()) {
            ans[i] = st.top();
        }
        // Push the current element onto the stack
        st.push(a[i]);
    }
    return ans;
}

// Driver function to test the implementation
int main() {
    // Input array
    int a[] = {4, 8, 5, 2, 25};
    int n = sizeof(a) / sizeof(a[0]);

    // Get the result
    vector<int> result = leftSmaller(n, a);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
