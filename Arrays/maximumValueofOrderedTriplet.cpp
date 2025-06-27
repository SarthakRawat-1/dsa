// Problem Statement :- https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/
//                      https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

// We want to maximize nums[i] and nums[k] or in short maximize nums[i] - nums[j]
// Hence, for any given j, we want it. So, for a j, we want the maximum element to the left of it (for i), and maximum to right of it as well (for j).
// Hence, we can preprocess and for any given j, we can already make arrays for storing left max (traverse from left to right and store like prefix sum but here we want max) and right max for that j (same but from right to left).

// This can be further optimized by reducing extra space.
// We want to maximize the nums[i] - nums[j], which can be achieved if nums[i] is max.

#include <bits/stdc++.h>
using namespace std;    

#include <vector>
#include <algorithm>
using namespace std;

// Approach-2: Using prefix and suffix storage
// Time Complexity: O(n)
// Space Complexity: O(n)
long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    
    // Create two helper vectors to store the maximum values to the left and right of each index.
    // leftMax[i] will store the maximum value among all elements to the left of index i.
    // rightMax[i] will store the maximum value among all elements to the right of index i.
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    // Build the leftMax array.
    // For each index i starting from 1, compare the previous leftMax value with the element immediately to the left of i.
    // This effectively propagates the maximum value seen so far from the left.
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
    }

    // Build the rightMax array.
    // For each index i starting from the second last element and moving left,
    // compare the next rightMax value with the element immediately to the right of i.
    // This propagates the maximum value seen so far from the right.
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
    }

    // Initialize result to store the maximum triplet value found.
    long long result = 0;

    // Evaluate each possible middle element (j) in the triplet,
    // ensuring j has valid left and right elements.
    // Calculate the product of the difference (leftMax[j] - nums[j]) and the rightMax[j].
    for (int j = 1; j < n - 1; j++) {
        result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
    }

    return result;
}

// Approach-3: Keeping track of maximum difference and maximum element so far
// Time Complexity: O(n)
// Space Complexity: O(1)
long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    
    // result will store the maximum triplet value.
    long long result = 0;

    // maxDiff stores the maximum difference (maxi - current element) encountered so far.
    long long maxDiff = 0;
    
    // maxi stores the maximum value encountered in the array so far.
    long long maxi = 0;

    // Iterate through each element in the array.
    for (int k = 0; k < n; k++) {
        // For the current element at index k, update the result.
        // The triplet value is the product of maxDiff and the current element.
        result = max(result, maxDiff * nums[k]);

        // Update maxDiff:
        // It is either the existing maxDiff or the difference between the maximum element seen so far (maxi)
        // and the current element, whichever is larger.
        maxDiff = max(maxDiff, maxi - nums[k]);

        // Update maxi with the current element if it is greater than the previous maxi.
        maxi = max(maxi, (long long)nums[k]);
    }

    return result;
}

int main() {
    vector<int> nums = {12, 6, 1, 2, 7};
    cout << maximumTripletValue(nums) << endl;

    return 0;
}