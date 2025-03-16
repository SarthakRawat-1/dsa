// Problem Statement :- https://leetcode.com/problems/4sum/description/

// Convert this to a 2 sum problem. Pretty much like threeSum.cpp
// In this, we will fix two pointers instead of just one and in the array after them, find the two remaining numbers.
// Check for all duplicate cases here as well.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); // Size of the array
    vector<vector<int>> ans; // Vector to store the result

    // Sort the array to facilitate the two-pointer approach and duplicate handling
    sort(nums.begin(), nums.end());

    // Loop to fix the first element (first pointer)
    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first element to avoid duplicate quadruplets
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Loop to fix the second element (second pointer)
        for (int j = i + 1; j < n; j++) {
            // Skip duplicates for the second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Two-pointer technique: initializing pointers for the remaining two elements
            int k = j + 1; // Left pointer starts right after the second pointer
            int l = n - 1; // Right pointer starts at the end of the array

            // Search for pairs with two pointers until they cross each other
            while (k < l) {
                // Calculate the sum of the four elements
                long long sum = nums[i]; // Start with the value of the first element
                sum += nums[j]; // Add the value of the second element
                sum += nums[k]; // Add the value of the left pointer
                sum += nums[l]; // Add the value of the right pointer

                // Case 1: If the sum matches the target, we found a quadruplet
                if (sum == target) {
                    // Store the current quadruplet in the result
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);

                    // Move both pointers inward to look for new pairs
                    k++;
                    l--;

                    // Skip duplicates for the left pointer (third element)
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    // Skip duplicates for the right pointer (fourth element)
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                // Case 2: If the sum is less than the target, increment the left pointer to increase the sum
                else if (sum < target) k++;
                // Case 3: If the sum is greater than the target, decrement the right pointer to decrease the sum
                else l--;
            }
        }
    }

    // Return the list of all unique quadruplets found
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1}; // Input array
    int target = 9; // Target sum
    vector<vector<int>> ans = fourSum(nums, target); // Calculate quadruplets
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}


