// Problem Statement :- https://leetcode.com/problems/zero-array-transformation-i/description/

// Zero Array Transforamtion I
// The given solution is using a difference array to count the number of decrement operations allowed at each index.
// Normally, the difference array is initialized based on the original array (D[0] = A[0], D[i] = A[i] - A[i-1]).
// However, in this case, we are not given an initial transformation state for nums, meaning we start with no decrements applied.
// Since the goal is to check whether we can reduce all elements of nums to zero, we don't need an initial value in diff. We simply track the range updates (+1 at l and -1 at r+1), hence diff is initialized to all zeros.
// Instead of adding a value X in a range [l, r], here we are marking where decrements start and stop:
// diff[l]++ → Start applying decrements from index l
// diff[r+1]-- → Stop applying decrements after index r
// After processing all queries, computing the prefix sum of diff gives the number of times each element in nums can be decremented.
// After processing all queries, the prefix sum of diff at index i gives the total number of decrements allowed for nums[i].
// If prefixSum < nums[i] at any index, it means we cannot fully reduce nums[i] to zero, so we return false.

// Zero Array Transforamtion II
// It introduces val to query. Refer differenceArrayTechnique.cpp for detail.
// For finding minimum queries, we can first use Difference Array technique for only first query. If it suffices, we end there.
// If it doesn't, we take first two queries and so on.
// Or we can use Binary search to to determine the smallest number of queries required.

#include <bits/stdc++.h>
using namespace std;

// Zero Array Transformation I
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    // Create a difference array of size n+1 initialized to 0.
    // This will be used to record the "decrement operations" applied at each index.
    vector<int> diff(n + 1, 0);
    
    // Process each query to update the difference array.
    // For each query [l, r], we add 1 at index l and subtract 1 at index r+1.
    // This effectively marks the range where a decrement can be applied.
    for (const auto &q : queries) {
        int l = q[0], r = q[1];
        diff[l]++;        // Start of the range: add a decrement operation.
        diff[r + 1]--;    // End of the range: subtract the effect beyond r.
    }
    
    // Use the difference array to calculate the prefix sum.
    // The prefix sum at index i indicates the maximum number of times 
    // nums[i] can be decremented by processing all queries.
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += diff[i];
        // If the allowed decrement (prefixSum) is less than nums[i],
        // then it's impossible to reduce nums[i] to zero.
        if (prefixSum < nums[i])
            return false;
    }
    
    // If all elements can be decremented enough times to reach 0,
    // return true.
    return true;
}

// Zero Array Transformation II
// ----------------------------------------------------------------------------
// Helper Function: checkWithDifferenceArrayTeq
//
// This function applies the first (k+1) queries to the array using a difference
// array technique and then checks if the resulting array has every element ≤ 0.
// Each query is of the form {l, r, x} which means "subtract x from every element 
// in the range [l, r]". The difference array technique allows us to apply a range
// update in O(1) time per query and then compute the effect on each element in O(n).
//
// Parameters:
//   nums    - The original array of integers.
//   queries - A vector of queries, where each query is a vector<int> of size 3.
//             Format: {l, r, x}.
//   k       - The index (0-indexed) of the last query to apply. Queries [0..k] 
//             will be applied.
// Returns:
//   true if after applying the first (k+1) queries every element in nums becomes
//   non-positive (i.e. ≤ 0), otherwise false.
bool checkWithDifferenceArrayTeq(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
    int n = nums.size();
    // Create a difference array with initial value 0 at every index.
    vector<int> diff(n, 0);
    
    // Process each query from index 0 to k (inclusive)
    // Each query applies an update over a range [l, r]:
    // - Add x at the starting index l.
    // - Subtract x at index r+1 (if within bounds) to stop the effect after index r.
    for (int i = 0; i <= k; i++) {
        int l = queries[i][0];  // Start index of the query
        int r = queries[i][1];  // End index of the query
        int x = queries[i][2];  // Value to subtract from each element in the range
        
        diff[l] += x;
        if (r + 1 < n)
            diff[r + 1] -= x;
    }
    
    // Build the actual update array by computing the cumulative sum of the diff array.
    // This cumulative sum represents the total subtraction applied at each index.
    int cumSum = 0;
    for (int i = 0; i < n; i++) {
        cumSum += diff[i];
        diff[i] = cumSum;
        
        // Check if the updated value at index i is still positive.
        // If nums[i] minus the total subtraction is > 0, then the query set was
        // insufficient to make this element non-positive.
        if (nums[i] - diff[i] > 0) {
            return false;
        }
    }
    
    // If all elements become ≤ 0, return true.
    return true;
}

// ----------------------------------------------------------------------------
// Approach 1: Linear Search
//
// This function determines the minimum number of queries needed (applied in the 
// given order) such that after applying them, all elements in the array become 
// non-positive. It iterates through each query sequentially and uses the helper 
// function above to check if the condition is met.
//
// Parameters:
//   nums    - The original array of integers.
//   queries - A vector of queries, each formatted as {l, r, x}.
// Returns:
//   The minimum number of queries required to turn all numbers ≤ 0.
//   Returns 0 if the array is already non-positive.
//   Returns -1 if even after applying all queries, some element remains positive.
int minZeroArrayLinear(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int Q = queries.size();
    
    // Early check: if the array is already all non-positive, no queries are needed.
    if (all_of(nums.begin(), nums.end(), [](int x) { return x <= 0; })) {
        return 0;
    }
    
    // Try applying queries one by one.
    // For each i from 0 to Q-1, check if applying queries [0..i] makes all elements non-positive.
    for (int i = 0; i < Q; i++) {
        if (checkWithDifferenceArrayTeq(nums, queries, i)) {
            // Since i is 0-indexed, i+1 queries have been applied.
            return i + 1;
        }
    }
    
    // Return -1 if even applying all queries does not make every element non-positive.
    return -1;
}

// ----------------------------------------------------------------------------
// Approach 2: Binary Search Optimization
//
// This function also determines the minimum number of queries required to make
// all elements in the array non-positive. Instead of checking every prefix of 
// queries, it uses binary search to efficiently find the minimum required number.
//
// Parameters:
//   nums    - The original array of integers.
//   queries - A vector of queries, each formatted as {l, r, x}.
// Returns:
//   The minimum number of queries needed such that every element becomes ≤ 0.
//   Returns 0 if the array is already non-positive.
//   Returns -1 if the condition is never met.
int minZeroArrayBinary(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int Q = queries.size();
    
    // Early check: if the array is already all non-positive, no queries are needed.
    if (all_of(nums.begin(), nums.end(), [](int x) { return x <= 0; })) {
        return 0;
    }
    
    // Binary search initialization over the query indices.
    int l = 0, r = Q - 1;
    int answer = -1;  // This will store the minimum number of queries required.
    
    while (l <= r) {
        int mid = l + (r - l) / 2;  // Check the middle point (number of queries to try)
        
        // If applying the first (mid+1) queries makes all numbers non-positive,
        // then mid+1 queries might be sufficient.
        if (checkWithDifferenceArrayTeq(nums, queries, mid)) {
            answer = mid + 1;  // Store the potential answer (convert 0-indexed to count)
            r = mid - 1;       // Try to find a solution using fewer queries.
        } else {
            // If mid queries are not enough, then we need more queries.
            l = mid + 1;
        }
    }
    
    return answer;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{1, 3}, {0, 1}, {2, 4}};

    bool result = isZeroArray(nums, queries);
    cout << (result ? "True" : "False") << endl;

    return 0;   
}