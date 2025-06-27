// Problem Statement :- https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24

#include <bits/stdc++.h>
using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> res;  // This will store the result indices
    int r = 0;        // 'r' tracks the minimum index that hasn't been added to result yet (to avoid duplicates)
    int n = nums.size(); // Total number of elements in the input vector

    // Traverse each index 'j' of the array
    for (int j = 0; j < n; ++j) {
        if (nums[j] == key) {
            // Found a match for the key at index j
            // Compute the left bound of the k-distant range, ensure we don't revisit indices already considered
            int l = max(r, j - k);

            // Update the right bound (exclusive) to avoid future duplicates
            r = min(n - 1, j + k) + 1;

            // Add all indices from l to r - 1 to the result
            for (int i = l; i < r; ++i) {
                res.push_back(i);
            }
        }
    }
    return res; // Return the final list of k-distant indices
}

int main() {
    
}