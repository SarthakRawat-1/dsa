// Problem Statement :- https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Function to find the next greater elements in a circular array (503 - Next Greater Element II)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    // Initialize result array with -1 for all elements
    vector<int> nge(n, -1);
    // Stack to store indices of elements in circular traversal
    stack<int> st;

    // Process elements twice to simulate circular array
    for (int i = 2 * n - 1; i >= 0; --i) {
        // Circular index handling: i % n
        while (!st.empty() && nums[st.top()] <= nums[i % n]) {
            st.pop();
        }
        // Update the result for the current element if the stack is not empty
        if (!st.empty()) {
            nge[i % n] = nums[st.top()];
        }
        // Push the current index onto the stack
        st.push(i % n);
    }
    
    return nge;
}

// Driver function to test the implementation
int main() {
    // Input array
    vector<int> nums = {1, 2, 1};

    // Get the result
    vector<int> result = nextGreaterElements(nums);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
