// Problem Statement :- https://leetcode.com/problems/3sum/description/

// Brute Force :- Do this with 3 pointers and exhaustive search. Checking all possible combinations.

// Optimized Approach :- Convert this to a 2 sum problem. n1 + n2 + n3 = 0 is equivalent to n1 + n2 = -n3 Now we can just use a two sum approach. 
// So initially, we will fix n1 as first element, and from the array after the first element, we will find n2 and n3, such that n2 + n3 = -n1 which is pretty much a two sum problem.
// Then we will move n2 to second element and from the array after the first element, we will find n2 and n3, and so on..
// In these kind of problems, if we are asked for index of elements, we can't sort. But in this ques, we are only asked for elements, not index. So we will sort the given array first.
// To check for duplicates, we can use the conditions :- arr[i] == arr[i + 1] or arr[j] == arr[j - 1] while using the two sum approach.
// But duplicates can also occur due to same value of n1. Hence, for n1 too, we will skip the duplicates i.e. we won't find n2 and n3 for same value of n1 again. 

// If we were asked for indices, we could have done two sum using twoSum.cpp

#include <bits/stdc++.h>
using namespace std;

// Helper function to find two numbers that sum up to a target, given a fixed number (n1)
void twoSum(vector<int>& nums, int k, vector<vector<int>>& result, int target) {
    // Using the two-pointer technique for a sorted array
    int i = k, j = nums.size() - 1; // Initialize two pointers: 'i' starting at 'k', 'j' at the end of the array

    // Traverse the array until 'i' crosses 'j'
    while (i < j) {
        // Case 1: If the sum of nums[i] and nums[j] is greater than the target, move 'j' left to reduce the sum
        if (nums[i] + nums[j] > target)
            j--;
        // Case 2: If the sum of nums[i] and nums[j] is less than the target, move 'i' right to increase the sum
        else if (nums[i] + nums[j] < target)
            i++;
        else {
            // Case 3: nums[i] + nums[j] equals the target
            // Add the triplet to the result, including -target (which is the fixed element, n1 in this context)
            result.push_back({-target, nums[i], nums[j]});

            // To avoid duplicates, skip over any additional occurrences of nums[i] or nums[j]
            while (i < j && nums[i] == nums[i + 1]) i++; // Move 'i' right if next element is the same
            while (i < j && nums[j] == nums[j - 1]) j--; // Move 'j' left if previous element is the same

            // Move both pointers inward after finding a valid triplet
            i++;
            j--;
        }
    }
}

// Main function to find all unique triplets that sum up to zero
vector<vector<int>> threeSum(vector<int>& nums) {
    // Edge case: If there are fewer than 3 numbers, return an empty result
    if (nums.size() < 3)
        return {};

    vector<vector<int>> result; // Vector to store the final list of unique triplets
    sort(nums.begin(), nums.end()); // Sort the array to make it easier to use two-pointer technique and avoid duplicates

    // Loop through each element to set it as n1, and search for pairs (n2, n3) such that n1 + n2 + n3 = 0
    for (int i = 0; i < nums.size() - 2; i++) { // Stop at nums.size() - 2 to leave space for n2 and n3
        // Skip duplicates for n1 to avoid generating duplicate triplets
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        // Call the twoSum helper to find pairs in the rest of the array that sum to -nums[i] (i.e., -n1)
        twoSum(nums, i + 1, result, -nums[i]);
    }

    return result; // Return the final list of unique triplets
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums);

    // Output the result
    for (const auto& triplet : triplets) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

// Also check out tripletSum.cpp