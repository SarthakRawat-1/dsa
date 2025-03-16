// Problem Statement :- https://leetcode.com/problems/house-robber/description/

// First try to solve it using Recursion.
// For Top Down Approach of solving this, we will try to look from the back. Say, you have :- {7, 3, 2, 8, 2, 1, 10}
// We got 10, we can either steal from it or not. Assume, we steal from this i.e. nums[n] (say), then we can't steal from nums[n - 1] (i.e. 1) but we can steal from nums[n - 2] (i.e. 2).
// Hence, we can say that :- Max amount robbed from houses = (nums[n] + Max amount robbed from n - 2 houses)
// But we can also skip the house at n, in this case :- Max amount robbed from houses = (Max amount robbed from n - 1 houses).
// The max of these two, will be the answer.

// For Bottom Up Approach, we will look from the front as they are our base case (index 0 and index 1).
// Then simply we can find the maximum robbed amount for every house. 
// In the end, the last index of our dp vector will store the maximum robbed amount possible.

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach (Recursive + Memoization)
// This approach uses recursion to solve the problem and stores intermediate results in a DP table to avoid redundant calculations.
int Robber(int index, vector<int> &nums, vector<int> &dp) {
    // Base case: If we are at the first house, we can only rob this house.
    if (index == 0) {
        return nums[0];
    }

    // Base case: If we are at the second house, we can rob either the first or the second house.
    if (index == 1) {
        return max(nums[0], nums[1]);
    }

    // If the result for the current index is already computed, return it from the DP table.
    if (dp[index] != -1) {
        return dp[index];
    }

    // Recursive case: Choose the maximum between robbing the current house and skipping the previous house,
    // or skipping the current house and robbing the previous house.
    return dp[index] = max(nums[index] + Robber(index - 2, nums, dp), Robber(index - 1, nums, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();

    // Initialize the DP table with -1 to indicate that no results have been computed yet.
    vector<int> dp(n, -1);

    // Start the recursion from the last house.
    return Robber(n - 1, nums, dp);
}

// Bottom Up Approach (Iterative + Tabulation)
// This approach solves the problem iteratively by filling up the DP table from the base cases.
// int rob(vector<int>& nums) {
//     int n = nums.size();

//     // Edge case: If there is only one house, rob it.
//     if (n == 1) {
//         return nums[0];
//     }

//     // Edge case: If there are two houses, rob the one with more money.
//     if (n == 2) {
//         return max(nums[0], nums[1]);
//     }

//     // Initialize the DP table with -1.
//     vector<int> dp(n, -1);

//     // Base case: The maximum amount that can be robbed from the first house is nums[0].
//     dp[0] = nums[0];

//     // Base case: The maximum amount that can be robbed from the first two houses is the maximum of nums[0] and nums[1].
//     dp[1] = max(nums[0], nums[1]);

//     // Fill the DP table iteratively.
//     for (int i = 2; i < n; i++) {
//         // The maximum amount that can be robbed up to the i-th house is the maximum of:
//         // 1. Robbing the i-th house and adding it to the maximum amount robbed up to the (i-2)-th house.
//         // 2. Skipping the i-th house and taking the maximum amount robbed up to the (i-1)-th house.
//         dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
//     }

//     // The last element in the DP table will contain the maximum amount that can be robbed from all houses.
//     return dp[n - 1];
// }

// Space Optimized Approach
// This approach optimizes space by using only two variables to store the results of the previous two houses.
// int rob(vector<int>& nums) {
//     int n = nums.size();

//     // Edge case: If there is only one house, rob it.
//     if (n == 1) {
//         return nums[0];
//     }

//     // Edge case: If there are two houses, rob the one with more money.
//     if (n == 2) {
//         return max(nums[0], nums[1]);
//     }

//     int curr;        // Represents the maximum amount that can be robbed up to the current house.
//     int prev = max(nums[0], nums[1]);  // Represents the maximum amount that can be robbed up to the previous house.
//     int prev2 = nums[0];               // Represents the maximum amount that can be robbed up to the house before the previous one.

//     // Iterate through the houses starting from the third house.
//     for (int i = 2; i < n; i++) {
//         // The maximum amount that can be robbed up to the i-th house is the maximum of:
//         // 1. Robbing the i-th house and adding it to the maximum amount robbed up to the (i-2)-th house.
//         // 2. Skipping the i-th house and taking the maximum amount robbed up to the (i-1)-th house.
//         curr = max(nums[i] + prev2, prev);

//         // Update the variables for the next iteration.
//         prev2 = prev;
//         prev = curr;
//     }

//     // The 'curr' variable will contain the maximum amount that can be robbed from all houses.
//     return curr;
// }

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int result = rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}