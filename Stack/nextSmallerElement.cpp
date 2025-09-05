// Problem Statement :- https://takeuforward.org/plus/dsa/problems/next-smaller-element

// This problem is similar to finding the next greater element, but instead, we need to find the next smaller element.
// The goal is to determine the closest smaller element to the right for each element in the array.

// Approach :-
// 1. Use a stack to keep track of indices of elements.
// 2. Traverse the array from left to right.
// 3. For each element, check if it is smaller than the element at the top of the stack.
// 4. If it is, update the result for the element at the top of the stack and pop it.
// 5. Continue this process until the stack is empty or the condition fails.
// 6. Push the current index onto the stack.
// 7. At the end, elements remaining in the stack have no smaller element to their right, so their result is -1.

#include <bits/stdc++.h>
using namespace std;

// Function to find the next smaller elements
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    // Initialize result array with -1 for all elements
    vector<int> ans(n, -1);
    // Stack to store indices of elements
    stack<int> st;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Remove elements from the stack that are greater than or equal to the current element
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        // If stack is not empty, the top element is the next smaller element
        if (!st.empty()) {
            ans[i] = arr[st.top()];
        }
        // Push the current index onto the stack
        st.push(i);
    }
    return ans;
}

// Driver function to test the implementation
int main() {
    // Input array
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    // Get the result
    vector<int> result = nextSmallerElement(arr, n);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
