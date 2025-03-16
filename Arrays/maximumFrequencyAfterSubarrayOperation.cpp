// Problem Statement :- https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

// First, compute the initial count of elements equal to k in the array. This serves as the baseline count before any operations.
// Identify all possible values of x that can be added to a subarray to convert some elements to k.
// These values are derived from the elements of the array as x = k - num for each element num in nums, excluding x = 0 since it does not change the array.
// For each possible value of x, transform the array into a gain/loss array where :-
// +1 is assigned to elements that can be converted to k by adding x.
// -1 is assigned to elements that are already k (since including them in the subarray might reduce the gain).
// 0 is assigned to other elements.
// Track the maximum gain across all possible values of x and add it to the original count of k to get the final result.

#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    int original_count = 0;
    // Calculate the original frequency of k
    for (int num : nums) {
        if (num == k) original_count++;
    }

    unordered_set<int> x_set;
    // Collect all possible x values (k - num) where x != 0
    for (int num : nums) {
        int x = k - num;
        if (x != 0) {
            x_set.insert(x);
        }
    }

    int max_gain = 0; // Track the maximum gain from any subarray operation

    // For each possible x, compute the maximum subarray gain using Kadane's algorithm
    for (int x : x_set) {
        int current_sum = 0;
        int max_subarray = 0;

        for (int num : nums) {
            int val = 0;
            if (num == k) {
                // Including this element in the subarray with x != 0 will turn it into k + x (not k), leading to a loss
                val = -1;
            } else if (num == (k - x)) {
                // This element can be converted to k by adding x, leading to a gain
                val = 1;
            } else {
                // This element is unaffected by adding x, no gain or loss
                val = 0;
            }

            // Kadane's algorithm: decide whether to start a new subarray or extend the current one
            current_sum = max(val, current_sum + val);
            // Update the maximum subarray sum found
            max_subarray = max(max_subarray, current_sum);
        }

        // Update the overall maximum gain across all x values
        if (max_subarray > max_gain) {
            max_gain = max_subarray;
        }
    }

    // The final answer is the original count plus the best gain from one operation
    return original_count + max_gain;
}

int main() {
    vector<int> nums = {1, 2, 4};
    int k = 6;
    cout << maxFrequency(nums, k) << endl;
    return 0;
}