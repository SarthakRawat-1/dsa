// Problem Statement :- https://leetcode.com/problems/house-robber-iv/description/

// This is an extension of House Robber I and II.
// For Optimal :- We have to find minimum capability, where capability is max from houses robbed.
// We have to minimze the maximum amount or (even questions for maximizing the minimum amount), so we have to use BS on answers.
// The answers in our case, are capabilities. 

#include <bits/stdc++.h>
using namespace std;

// A very large number to denote an impossible path.
const int INF = INT_MAX;

// Recursive helper function to compute the minimum capability.
// Parameters:
// - nums: The list of house money values.
// - i: Current index in the vector.
// - k: Number of houses still needed to be robbed.
// - memo: 2D memoization table where memo[i][k] stores the result for state (i, k).
//
// The function returns the minimized maximum amount of money robbed so far if it's possible
// to rob exactly k houses from index i onward. If it's not possible, INF is returned.
int solve(const vector<int>& nums, int i, int k, vector<vector<int>>& memo) {
    // Base case: if no more houses are needed, return 0 as no further money is added.
    if (k == 0) {
        return 0;
    }
    
    // If we have passed the last house and still need to rob more houses, return INF
    // to indicate that this is an invalid (impossible) path.
    if (i >= nums.size()) {
        return INF;
    }
    
    // If the result for the current state (i, k) is already computed, return it.
    if (memo[i][k] != -1) {
        return memo[i][k];
    }
    
    // Option 1: Rob the current house.
    // When robbing, we update the "capability" as the maximum between the current house's money
    // and the result from robbing the rest (note that we skip the next house to avoid adjacent robberies).
    int take = max(nums[i], solve(nums, i + 2, k - 1, memo));
    
    // Option 2: Skip the current house.
    int not_take = solve(nums, i + 1, k, memo);
    
    // Choose the option with the lower maximum robbed amount.
    memo[i][k] = min(take, not_take);
    return memo[i][k];
}

// Main function for Approach 1.
// This function initializes the memoization table and starts the recursive process from index 0,
// trying to rob exactly k houses.
int minCapabilityBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    // Create a memoization table of size n x (k+1) and initialize with -1.
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    return solve(nums, 0, k, memo);
}

// Helper function that checks if it is possible to rob at least k houses 
// with a given maximum allowed amount 'mid' (capability).
// The function iterates over the houses and, if a house's money value is within
// the allowed capability, it counts that house as robbed and skips the next one.
bool isPossible(const vector<int>& nums, int mid, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        // If the current house can be robbed with the current capability,
        // count it and skip the next house.
        if (nums[i] <= mid) {
            count++;
            i++; // Skip the adjacent house to prevent consecutive robberies.
        }
    }
    // Return true if we managed to rob at least k houses.
    return count >= k;
}

// Main function for Approach 2.
// This function uses binary search to find the minimum capability that allows
// robbing at least k houses.
// It searches between the smallest and largest money values in the input.
int minCapabilityBinarySearch(vector<int>& nums, int k) {
    // Determine the lower bound (l) as the minimum element and the upper bound (r) as the maximum element.
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());
    
    int result = r; // Initialize result with the maximum possible capability.
    
    // Binary search loop to narrow down the minimum feasible capability.
    while (l <= r) {
        int mid = l + (r - l) / 2; // Calculate mid capability.
        
        // Check if it's possible to rob at least k houses with capability 'mid'.
        if (isPossible(nums, mid, k)) {
            result = mid;  // Update result as we found a feasible capability.
            r = mid - 1;   // Try to find a lower capability by searching the left half.
        } else {
            l = mid + 1;   // If not possible, increase capability by searching the right half.
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    cout << minCapabilityBruteForce(nums, k) << endl;
    return 0;
}