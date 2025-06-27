// Problem Statement :- https://leetcode.com/problems/house-robber-ii/description/

// This is an extension of houseRobber.cpp
// In this, we will for some time not consider the last house. Then we will try to find maximum amount that can be robbed from these houses. This way we will avoid the case when we rob fromm both first and last house. 
// Then, we can simply use the method we used in houseRobber.cpp.
// Similarly one case we can take when we will not take the first house in consideration. We will try to find maximum amount that can be robbed from these houses.
// Max of both of these will our answer.
// This works for both Top down and Bottom up approach

// For Space Optimized approach, we will use prev2, prev and curr1. We will use these to find maximum amount that can be robbed from houses 0 to n - 2.
// Similarly, we will use prev, prev2 and curr2. We will use these to find maximum amount that can be robbed from houses 1 to n - 1. 
// Max of curr1 and curr2 will be our answer.
// We will have to modify base cases for both of the cases, especially for array from 1 to n - 1, as prev2 for it will start with index 1 and prev with index 2 and curr2 with index 3.

#include <bits/stdc++.h>
using namespace std;

// Space Optimized Approach
// Helper function for the Space Optimized Approach
int RobberSpaceOptimized(vector<int>& nums, int start, int end) {
    int n = end - start + 1;

    // Edge case: If there is only one house, rob it.
    if (n == 1) {
        return nums[start];
    }

    // Edge case: If there are two houses, rob the one with more money.
    if (n == 2) {
        return max(nums[start], nums[start + 1]);
    }

    int curr;        // Represents the maximum amount that can be robbed up to the current house.
    int prev = max(nums[start], nums[start + 1]);  // Represents the maximum amount that can be robbed up to the previous house.
    int prev2 = nums[start];                       // Represents the maximum amount that can be robbed up to the house before the previous one.

    // Iterate through the houses starting from the third house.
    for (int i = start + 2; i <= end; i++) {
        // The maximum amount that can be robbed up to the i-th house is the maximum of:
        // 1. Robbing the i-th house and adding it to the maximum amount robbed up to the (i-2)-th house.
        // 2. Skipping the i-th house and taking the maximum amount robbed up to the (i-1)-th house.
        curr = max(nums[i] + prev2, prev);

        // Update the variables for the next iteration.
        prev2 = prev;
        prev = curr;
    }

    // The 'prev' variable will contain the maximum amount that can be robbed from the given range of houses.
    return prev;
}

// Main function for the Space Optimized Approach
int rob(vector<int>& nums) {
    int n = nums.size();

    // Edge case: If there is only one house, rob it.
    if (n == 1) {
        return nums[0];
    }

    // Edge case: If there are two houses, rob the one with more money.
    if (n == 2) {
        return max(nums[0], nums[1]);
    }

    // Case 1: Ignore the last house and solve for houses 0 to n-2.
    int case1 = RobberSpaceOptimized(nums, 0, n - 2);

    // Case 2: Ignore the first house and solve for houses 1 to n-1.
    int case2 = RobberSpaceOptimized(nums, 1, n - 1);

    // The final answer is the maximum of the two cases.
    return max(case1, case2);
}

// Top Down Approach
// Helper function for the Top Down Approach
int RobberTopDown(int index, vector<int>& nums, int start, vector<int>& dp) {
    // Base case: If we are at the first house, we can only rob this house.
    if (index == start) {
        return nums[start];
    }

    // Base case: If we are at the second house, we can rob either the first or the second house.
    if (index == start + 1) {
        return max(nums[start], nums[start + 1]);
    }

    // If the result for the current index is already computed, return it from the DP table.
    if (dp[index - start] != -1) {
        return dp[index - start];
    }

    // Recursive case: Choose the maximum between robbing the current house and skipping the previous house,
    // or skipping the current house and robbing the previous house.
    return dp[index - start] = max(nums[index] + RobberTopDown(index - 2, nums, start, dp), RobberTopDown(index - 1, nums, start, dp));
}

int rob(vector<int>& nums) {
    int n = nums.size();

    // Edge case: If there is only one house, rob it.
    if (n == 1) {
        return nums[0];
    }

    // Edge case: If there are two houses, rob the one with more money.
    if (n == 2) {
        return max(nums[0], nums[1]);
    }

    // Initialize the DP table with -1 to indicate that no results have been computed yet.
    vector<int> dp(n, -1);

    // Case 1: Ignore the last house and solve for houses 0 to n-2.
    int case1 = RobberTopDown(n - 2, nums, 0, dp);

    // Reset the DP table for the next case.
    fill(dp.begin(), dp.end(), -1);

    // Case 2: Ignore the first house and solve for houses 1 to n-1.
    int case2 = RobberTopDown(n - 1, nums, 1, dp);

    // The final answer is the maximum of the two cases.
    return max(case1, case2);
}

// Bottom Up Approach
// Helper function for the Bottom Up Approach
int RobberBottomUp(vector<int>& nums, int start, int end) {
    int n = end - start + 1;

    // Edge case: If there is only one house, rob it.
    if (n == 1) {
        return nums[start];
    }

    // Edge case: If there are two houses, rob the one with more money.
    if (n == 2) {
        return max(nums[start], nums[start + 1]);
    }

    // Initialize the DP table with -1.
    vector<int> dp(n, -1);

    // Base case: The maximum amount that can be robbed from the first house is nums[start].
    dp[0] = nums[start];

    // Base case: The maximum amount that can be robbed from the first two houses is the maximum of nums[start] and nums[start + 1].
    dp[1] = max(nums[start], nums[start + 1]);

    // Fill the DP table iteratively.
    for (int i = 2; i < n; i++) {
        // The maximum amount that can be robbed up to the i-th house is the maximum of:
        // 1. Robbing the i-th house and adding it to the maximum amount robbed up to the (i-2)-th house.
        // 2. Skipping the i-th house and taking the maximum amount robbed up to the (i-1)-th house.
        dp[i] = max(nums[start + i] + dp[i - 2], dp[i - 1]);
    }

    // The last element in the DP table will contain the maximum amount that can be robbed from the given range of houses.
    return dp[n - 1];
}

// Main function for the Bottom Up Approach
int rob(vector<int>& nums) {
    int n = nums.size();

    // Edge case: If there is only one house, rob it.
    if (n == 1) {
        return nums[0];
    }

    // Edge case: If there are two houses, rob the one with more money.
    if (n == 2) {
        return max(nums[0], nums[1]);
    }

    // Case 1: Ignore the last house and solve for houses 0 to n-2.
    int case1 = RobberBottomUp(nums, 0, n - 2);

    // Case 2: Ignore the first house and solve for houses 1 to n-1.
    int case2 = RobberBottomUp(nums, 1, n - 1);

    // The final answer is the maximum of the two cases.
    return max(case1, case2);
}

int main() {
    vector<int> nums = {2, 3, 2};
    int result = rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}