// Problem Statement :- https://leetcode.com/problems/permutations-ii/description/

// The approach to solve this is similar to permutations.cpp
// The difference, let's say we have 1, 1, 2, 2 and we have fixed 1, _, _, _ for the first 1. Then we need not call 1, _, _, _ again to fix for the second 1. 
// Hence, if an element has been fixed already at a position, the same position cannot be used to fix other element (which is same as that element, in our case 1 and 1). 
// Eg :- If we had 1, 1, 2 then only two cases are possible for fixing first position, 1, _, _ and 2, _, _
// For our optimized approach, we can think it like that we only need to swap the element with that element after it, with which it has not been swapped before. So, if we have 1, 1, 2 and we want to fix first position, we can swap 1 by itself resulting in 1, 1, 2 and we can swap 1 by 2 i.e. 2, 1, 1. It will not be worthwhile to swap 1 with other 1 after that, as it will also result in 1, 1, 2.
// Now if we had 2, 1, 1 (from prev eg) and now we want to fix second position, we only have one swap availiable which is 1 with itself resulting in 2, 1, 1.
// Similarly, if we had 1, 1, 2, 2 and we wanted to fix first position, the first option is swapping 1 with itself resulting in 1, 1, 2, 2 and second is swapping 1 with first 2 resulting in 2, 1, 1, 2. Swapping 1 with the second 2 is redundant (as we have already swapped 1 with a 1 before). It results in 2, 1, 2, 1.
// You might think that 2, 1, 1, 2 and 2, 1, 2, 1 are different. But remember that at this point we have only fixed the first position.The rest 3 elements can permutate and will result in 3! permutatiosn for both, covering all scenarios.
// But how do we know that we have already swapped 1 with a 2, so we need not swap it with another 2? We can use a bool vector of size 21 (problem constraints state number can be between -10 and 10) to mark elements which we have already swapped with.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate unique permutations
// Arguments:
// - nums: reference to the vector of integers to permute
// - ans: reference to the vector that stores all unique permutations
// - idx: current index to fix in each recursion step
void solve(vector<int>& nums, vector<vector<int>>& ans, int idx) {
    // Base case: if idx has reached the end of nums, store the permutation in ans
    if (idx == nums.size()) {
        ans.push_back(nums);  // Add the current permutation to results
        return;               // Exit the function
    }

    // Boolean vector to mark numbers already swapped with nums[idx]
    // This prevents duplicate permutations for identical elements
    vector<bool> vis(21, false);  // 21 covers numbers from -10 to 10 after offset by 10

    // Iterate from the current index to end to fix elements at idx
    for (int i = idx; i < nums.size(); i++) {
        // Skip if nums[i] has been swapped with nums[idx] in this position already
        if (!vis[nums[i] + 10]) {  // Offset by 10 to handle -10 to 10 range
            // Mark the number as used in the current recursive level
            vis[nums[i] + 10] = true;

            // Swap nums[i] with nums[idx] to fix nums[i] at idx position
            swap(nums[i], nums[idx]);
            
            // Recursive call to fix the next index
            solve(nums, ans, idx + 1);
            
            // Backtrack: restore the array to its original form before the next iteration
            swap(nums[i], nums[idx]);
        }
    }
}

// Main function to generate unique permutations of a list with duplicates
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;  // Store all unique permutations

    // Begin recursion from the first index
    solve(nums, ans, 0);

    return ans;  // Return the result
}

int main() {
    vector<int> nums = {1, 1, 2};  // Example input

    // Generate all unique permutations of `nums`
    vector<vector<int>> ans = permuteUnique(nums);

    // Print each unique permutation
    for (const auto& permutation : ans) {
        for (int num : permutation) {
            cout << num << " ";  // Print each number in the permutation
        }
        cout << endl;  // New line for each permutation
    }
}
