// Problem Statement :- https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03

// Brute Force :- Start i from 0 to end of array using a for loop.
// Find both sum, i.e. both side of split. Then compare it simply.

#include <bits/stdc++.h>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    // Step 1: Get the size of the input array
    int n = nums.size();

    // Step 2: Create a cumulative sum array to store prefix sums
    vector<long long> cumSum(n);
    // Initialize the first element of the cumulative sum array
    cumSum[0] = nums[0];

    // Step 3: Fill the cumulative sum array
    for (int i = 1; i < n; i++) {
        // Each element in cumSum[i] holds the sum of elements from index 0 to i
        cumSum[i] = cumSum[i - 1] + nums[i];
    }

    // Step 4: Initialize a counter to count valid splits
    int split = 0;

    // Step 5: Iterate through the array to check valid splits
    for (int i = 0; i < n - 1; i++) { // Stop at n-1 to ensure non-empty right subarray

        // Calculate the sum of the left subarray (0 to i)
        long long leftSum = cumSum[i];

        // Calculate the sum of the right subarray (i+1 to n-1)
        long long rightSum = cumSum[n - 1] - cumSum[i];

        // Step 6: Check if the split satisfies the condition (leftSum >= rightSum)
        if (leftSum >= rightSum) {
            // Increment the count of valid splits
            split++;
        }
    }

    // Step 7: Return the total number of valid splits found
    return split;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int ways = waysToSplitArray(nums);
    cout << "Number of ways to split the array: " << ways << endl;
    return 0;
}