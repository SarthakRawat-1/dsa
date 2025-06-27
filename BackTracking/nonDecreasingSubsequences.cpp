// Problem Statement :- https://leetcode.com/problems/non-decreasing-subsequences/description/

// We don't want duplicates in answer.


#include <bits/stdc++.h>
using namespace std;

// Global variable to store the size of the input array.
int n;

/*
 * The backtrack function is a recursive function that constructs potential subsequences.
 * Parameters:
 *   - nums: the original array of integers.
 *   - idx: the current index to start processing the nums array.
 *   - curr: the current subsequence built so far.
 *   - result: a reference to the vector that stores all valid non-decreasing subsequences.
 */
void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
    // When the current subsequence has at least 2 elements, add it to the result set.
    if (curr.size() >= 2) {
        result.push_back(curr);
    }

    // Use a set to record elements we've already processed at this recursion level (starting from idx).
    // This helps to avoid adding duplicates at the same recursion level.
    unordered_set<int> st;

    // Loop through the numbers starting from the current index
    for (int i = idx; i < n; i++) {
        // Check two conditions before proceeding:
        // 1. If curr is empty, we can always add an element,
        //    or if not empty, add the element only if it is greater than or equal to the last element.
        //    This ensures the non-decreasing property.
        // 2. Check if the element has already been used in this recursive call (to prevent duplicate subsequences).
        if ((curr.empty() || nums[i] >= curr.back()) && st.find(nums[i]) == st.end()) {
            // Add the current element to the subsequence.
            curr.push_back(nums[i]);
            // Recursively call backtrack with the next index to continue building the subsequence.
            backtrack(nums, i + 1, curr, result);
            // Backtrack: remove the last element added, to explore subsequences without it.
            curr.pop_back();
            // Record the element in the set to indicate that we've handled this particular number at this recursion level.
            st.insert(nums[i]);
        }
    }
}

/*
 * The main function that initializes the process of generating non-decreasing subsequences.
 * It sets up the necessary data structures and invokes the backtracking recursion.
 */
vector<vector<int>> findSubsequences(vector<int>& nums) {
      // Set the global size variable for the input array.
      n = nums.size();
      
      // This vector will store all the valid non-decreasing subsequences.
      vector<vector<int>> result;
      // Temporary vector to keep track of the current subsequence under construction.
      vector<int> curr;

      // Begin the backtracking process starting at index 0.
      backtrack(nums, 0, curr, result);

      // Return the complete list of valid subsequences.
      return result;
}

int main() {
    // Example test-case; users can provide input arrays and invoke findSubsequences to test the functionality.
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> subsequences = findSubsequences(nums);
    for (auto subseq : subsequences) {
        for (int num : subseq) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}