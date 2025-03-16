// Problem Statement :- https://leetcode.com/problems/count-number-of-bad-pairs/description/

#include <bits/stdc++.h>
using namespace std;

/************************************************************
 * Approach-1: Brute Force
 * ------------------------
 * For every pair (i, j) with i < j, we check if the pair is bad (i.e., if
 * j - i != nums[j] - nums[i]). We increment our result if the condition holds.
 *
 * Time Complexity  : O(n^2) - because we check each pair.
 * Space Complexity : O(1) - no extra space apart from loop variables.
 ************************************************************/
long long countBadPairsApproach1(vector<int>& nums) {
    int n = nums.size();
    long long result = 0;
    
    // Iterate over all pairs (i, j) with i < j.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the pair (i, j) does not satisfy the "good pair" condition.
            if (j - i != nums[j] - nums[i]) {
                result++;  // Increment the count of bad pairs.
            }
        }
    }
    
    return result;
}

/************************************************************
 * Approach-2: Using HashMap (Modifying the Array)
 * ------------------------------------------------
 * The idea is to transform each element by subtracting its index:
 *     transformed_value = nums[i] - i.
 * With this transformation, a pair (i, j) is "good" if:
 *     transformed_value[i] == transformed_value[j]
 *
 * For each index j, if we already encountered some indices with the same
 * transformed value, then those form good pairs with j. Since the total pairs
 * up to index j is j (because there are j previous indices), the number of bad
 * pairs for index j is:
 *     bad_pairs_at_j = (number of indices before j) - (number of good pairs)
 *
 * Time Complexity  : O(n) - single pass through the array.
 * Space Complexity : O(n) - extra space for the frequency hashmap.
 ************************************************************/
long long countBadPairsApproach2(vector<int>& nums) {
    int n = nums.size();
    long long result = 0;
    
    // Transform the array in-place: for every index i, subtract i from nums[i]
    for (int i = 0; i < n; i++) {
        nums[i] = nums[i] - i;
    }
    
    unordered_map<int, int> freqMap; // To store frequency of each transformed value.
    
    // Initialize the frequency map with the first element.
    freqMap[nums[0]] = 1;
    
    // Process from the second element to the end.
    for (int j = 1; j < n; j++) {
        // Number of times this transformed value has occurred before index j.
        int countGoodPairs = freqMap[nums[j]];
        
        // Total indices before j is equal to j.
        // Therefore, the number of bad pairs ending at index j is:
        //   (total indices before j) - (number of good pairs for this value)
        int badPairsAtJ = j - countGoodPairs;
        
        // Add the count of bad pairs for the current index to the result.
        result += badPairsAtJ;
        
        // Update the frequency of the current transformed value.
        freqMap[nums[j]]++;
    }
    
    return result;
}

/************************************************************
 * Approach-3: Using HashMap (Without Modifying the Array)
 * ---------------------------------------------------------
 * This approach is similar to Approach-2, but we compute the
 * transformation on the fly rather than modifying the input array.
 *
 * For every index i:
 *   - Compute diff = nums[i] - i.
 *   - The count of good pairs ending at i is given by the number of previous
 *     indices with the same diff, stored in a hashmap.
 *   - The number of total pairs ending at i is i (since indices 0 to i-1 are valid).
 *   - So, the number of bad pairs with i as the second index is i - (number of good pairs).
 *
 * Time Complexity  : O(n) - a single traversal through the array.
 * Space Complexity : O(n) - hashmap used to store frequencies.
 ************************************************************/
long long countBadPairsApproach3(const vector<int>& nums) {
    int n = nums.size();
    long long result = 0;
    
    unordered_map<int, int> freqMap; // Maps each (nums[i]-i) value to its frequency.
    
    // Iterate through the array.
    for (int i = 0; i < n; i++) {
        // Compute the difference (transformation) on the fly.
        int diff = nums[i] - i;
        
        // Total possible pairs with current index i is i (with all previous indices).
        int totalPairsTillI = i;
        
        // Number of good pairs for the current diff.
        int goodPairsSoFar = freqMap[diff];
        
        // The bad pairs with current index i as the second index.
        // (All previous indices minus the ones that would form a good pair)
        result += (totalPairsTillI - goodPairsSoFar);
        
        // Increment the frequency of the current diff.
        freqMap[diff]++;
    }
    
    return result;
}


int main() {
    vector<int> nums = {4, 1, 3, 3};
    
    long long result1 = countBadPairsApproach1(nums);
    // If using Approach-2, you might want to pass a copy of nums because
    // it modifies the input array.
    vector<int> numsCopy = nums;
    long long result2 = countBadPairsApproach2(numsCopy);
    long long result3 = countBadPairsApproach3(nums);
    
    // Output or check the results...
    return 0;
}

