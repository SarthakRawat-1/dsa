// Problem Statement :- 

// This is very similar to Subset II and combinationSum.cpp
// Now you have to 

#include <bits/stdc++.h>
using namespace std;

// Recursive helper function
void solve(int index, int target, vector<int>& candidates, 
           vector<int>& current, vector<vector<int>>& result) {
    
    // ✅ Base case: Found a valid combination
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    // ❌ Base case: Out of bounds or sum exceeded
    if (index == candidates.size() || target < 0) {
        return;
    }

    // ---------------- Choice 1: Include candidates[index] ----------------
    current.push_back(candidates[index]);
    // Move to next index (since each element can only be used once)
    solve(index + 1, target - candidates[index], candidates, current, result);
    // Backtrack: remove last chosen element
    current.pop_back();

    // ---------------- Choice 2: Exclude candidates[index] ----------------
    // Skip over all duplicates of candidates[index] to avoid repeated combinations
    int next = index + 1;
    while (next < candidates.size() && candidates[next] == candidates[index]) 
        next++;

    // Explore further by excluding this value entirely
    solve(next, target, candidates, current, result);
}

// Main function to start the backtracking
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // Sort to bring duplicates together (important for skipping)
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;
    solve(0, target, candidates, current, result);
    return result;
}

int main() {
    // Example usage
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);

    // Print results
    for (auto &comb : ans) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }
}