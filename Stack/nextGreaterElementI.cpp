// Problem Statement :- https://leetcode.com/problems/next-greater-element-i/description/

// First, refer nextGreaterElement.cpp

#include <bits/stdc++.h>
using namespace std;

// Method 1 :- With Unordered Map
// Function to find the next greater elements for nums2 in nums1
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // Map to store the next greater element for each number in nums2
    unordered_map<int, int> nge;
    // Stack to process elements in nums2
    stack<int> st;

    // Process nums2 in reverse order
    for (int i = nums2.size() - 1; i >= 0; --i) {
        // Remove elements from the stack that are smaller than or equal to nums2[i]
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        // If stack is not empty, the top element is the next greater element
        nge[nums2[i]] = st.empty() ? -1 : st.top();
        // Push the current element onto the stack
        st.push(nums2[i]);
    }

    // Build the result for nums1 based on the map
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nge[num]);
    }
    return result;
}

// Method 2 :- With Vector
// Function to find the next greater elements for nums2 in nums1
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     // Vector to store the next greater element for each number in nums2
//     vector<int> nge(nums2.size(), -1);
//     // Stack to process elements in nums2
//     stack<int> st;

//     // Process nums2 in reverse order
//     for (int i = nums2.size() - 1; i >= 0; --i) {
//         // Remove elements from the stack that are smaller than or equal to nums2[i]
//         while (!st.empty() && nums2[st.top()] <= nums2[i]) {
//             st.pop();
//         }
//         // If stack is not empty, the top element is the next greater element
//         if (!st.empty()) {
//             nge[i] = nums2[st.top()];
//         }
//         // Push the current index onto the stack
//         st.push(i);
//     }

//     // Build the result for nums1 based on the vector
//     vector<int> result;
//     for (int num : nums1) {
//         auto it = find(nums2.begin(), nums2.end(), num);
//         if (it != nums2.end()) {
//             int index = distance(nums2.begin(), it);
//             result.push_back(nge[index]);
//         }
//     }
//     return result;
// }

// Driver function to test the implementation
int main() {
    // Input arrays
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    // Get the result
    vector<int> result = nextGreaterElement(nums1, nums2);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
