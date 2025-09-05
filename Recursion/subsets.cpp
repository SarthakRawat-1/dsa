// Problem Statement :- https://leetcode.com/problems/subsets/description/

// We can think of selecting numbers from the array to be in our subsequence, as either accepting that number or rejecting it
// For eg :- {1, 2, 3} we can say 0, 0, 0 i.e. we don't take 1, or 2, or 3 creating empty set.

#include <bits/stdc++.h>
using namespace std;

// Brute Force using Bit Manipulation :- Refer Bit Manipulation Directory for reference
// vector<vector<int>> subsets(vector<int>& nums) {
//     int n = nums.size();                // Get the size of the input array
//     int totalSubsets = 1 << n;          // Calculate the total number of subsets (2^n)
//     vector<vector<int>> result;         // To store the final list of subsets

//     // Iterate over all possible subset combinations (from 0 to 2^n - 1)
//     for (int i = 0; i < totalSubsets; i++) {
//         vector<int> subset;             // Temporary vector to store the current subset
//         // Check each bit of the number i to decide which elements to include
//         for (int j = 0; j < n; j++) {
//             if (i & (1 << j)) {         // If the j-th bit is set in i, include nums[j]
//                 subset.push_back(nums[j]);
//             }
//         }
//         result.push_back(subset);       // Add the current subset to the result
//     }

//     return result;          
// }

// Optimal using Recursion and Backtracking
// Say, we had {1, 2, 3}, we take a empty subset initially {}. Then we give us a choice.
// Should we pick 1 or not. Both give rise to diff branches of recursion tree and depending on that, we add it to the subset.
// We will do this for all the other elements as well sequentially. 
// At every end node of tree i.e. when there are no more elements left to make choices, we add the subset as one of the possible subset of our array/power set.

/*
 * Recursive helper function to generate all subsets of the input array.
 * 
 * @param index  - The current index in the input vector `nums` we're making a decision on.
 * @param nums   - The original input vector of numbers.
 * @param current - The current subset being built (path of decisions so far).
 * @param result  - A 2D vector to store all the generated subsets.
 */
void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if index has reached the end of nums, we've formed one complete subset
    if (index == nums.size()) {
        result.push_back(current);  // Add the current subset to the final result
        return;
    }

    // ----------- Decision 1: Include nums[index] in the current subset -----------

    current.push_back(nums[index]);     // Choose the current element
    generateSubsets(index + 1, nums, current, result); // Recur to process the next element

    // ----------- Decision 2: Exclude nums[index] from the current subset ---------

    current.pop_back();                 // Backtrack: remove the last included element
    generateSubsets(index + 1, nums, current, result); // Recur to process the next element without including nums[index]
}

/*
 * Main function to initiate the subset generation.
 *
 * @param nums - The input vector for which subsets are to be generated.
 * @return     - A 2D vector containing all subsets (the power set).
 */
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;  // To store all generated subsets
    vector<int> current;         // Temporary vector to store the current subset being formed
    generateSubsets(0, nums, current, result);  // Start recursion from index 0
    return result;
}

// For Subset Sum II, first sort the input array first → duplicates come together.
// At each recursion level, when skipping an element, skip over all its duplicates.
void generateSubsetsNoDup(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);  // record subset when end is reached
        return;
    }

    // 1️⃣ Include nums[index]
    current.push_back(nums[index]);
    generateSubsetsNoDup(index + 1, nums, current, result);
    current.pop_back();

    // 2️⃣ Exclude nums[index] 🚫 but skip over duplicates
    int next = index + 1;
    while (next < nums.size() && nums[next] == nums[index]) next++;

    generateSubsetsNoDup(next, nums, current, result);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sort so duplicates are adjacent
    vector<vector<int>> result;
    vector<int> current;
    generateSubsetsNoDup(0, nums, current, result);
    return result;
}

int main() {
    
}

