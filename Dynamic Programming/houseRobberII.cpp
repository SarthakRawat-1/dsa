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

int main() {
    vector<int> nums = {2, 3, 2};
    int result = rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}