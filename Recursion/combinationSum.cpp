// Problem Statement :- https://leetcode.com/problems/combination-sum/description/

// This is an extension of subsetSum.cpp
// However we will have to change our base condition a little, because now there can also be zero in set.
// So, now when sum is equal to target, we will continue if there's a zero. As we can also include that zero and sum will remain same.
// Hence, it's better to now find cases for all, explore every branch, even if u get the correct sum. As there might be 0 present. 
// Ofc if sum exceeds then we can terminate as there are no negative numbers. If they are also included, then generate every case, don't abort any branch unless u have decided to choose for all elements.

#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive backtracking function to explore all combinations.
 * 
 * @param index       - Current index in the candidates array.
 * @param candidates  - Input array of candidate numbers.
 * @param target      - Target sum to achieve.
 * @param current     - Current combination being built.
 * @param result      - Final result to store all valid combinations.
 */
void solve(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if target is exactly 0, we found a valid combination
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Base case: if index is out of bounds or target becomes negative
    if (index == candidates.size() || target < 0) {
        return;
    }

    // ---------- Choice 1: Include candidates[index] ----------
    current.push_back(candidates[index]);                   // Choose current element
    solve(index, candidates, target - candidates[index], current, result); // Stay at same index (reuse allowed)
    current.pop_back();                                     // Backtrack

    // ---------- Choice 2: Exclude candidates[index] ----------
    solve(index + 1, candidates, target, current, result);  // Move to next index (don't reuse)
}

/*
 * Main function to initiate combination sum solving.
 */
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    solve(0, candidates, target, current, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    // Output all combinations
    for (auto& combo : result) {
        for (int num : combo)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
