// Problem Statement :- https://leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
using namespace std;

// Helper function for backtracking
void backtrack(int start, int k, int target, vector<int>& current, vector<vector<int>>& result) {
    // ✅ Base case: if we've picked exactly k numbers AND they sum up to target
    if (k == 0 && target == 0) {
        result.push_back(current);   // save the valid combination
        return;
    }

    // ❌ Pruning condition:
    // If we’ve already picked k numbers but sum != target
    // OR if sum exceeded target, stop exploring this branch
    if (k == 0 || target < 0) return;

    // Try all possible numbers from "start" to 9
    for (int i = start; i <= 9; i++) {
        // (Optional pruning: if i > target, break here since numbers only get bigger)

        // Choose number i
        current.push_back(i);

        // Explore further with:
        // - next number must be greater than i → ensure uniqueness
        // - one less pick (k - 1)
        // - reduced target (target - i)
        backtrack(i + 1, k - 1, target - i, current, result);

        // Undo the choice (backtrack)
        current.pop_back();
    }
}

// Main function
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;   // stores all valid combinations
    vector<int> current;          // temporary combination being built
    backtrack(1, k, n, current, result);  // start from 1 → 9
    return result;
}

// Alternatively, this is just Subset problem with target variable tracking.
// The appraoch is to take {1, 2, 3, 4, 5, 6, 7, 8, 9} as the input vector and find possible subsets of this whose size is k and sum = target.
void generateSubsets(int index, int k, int target,
                        vector<int>& nums, vector<int>& current,
                        vector<vector<int>>& result) {
    // Base case: checked all numbers
    if (index == nums.size()) {
        if (current.size() == k && target == 0) {
            result.push_back(current);
        }
        return;
    }

    // Case 1: Include nums[index]
    current.push_back(nums[index]);
    generateSubsets(index + 1, k, target - nums[index], nums, current, result);
    current.pop_back();

    // Case 2: Exclude nums[index]
    generateSubsets(index + 1, k, target, nums, current, result);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(0, k, n, nums, current, result);
    return result;
}

int main() {}

