// Problem Statement :- https://leetcode.com/problems/count-the-number-of-good-subarrays/

#include <bits/stdc++.h>
using namespace std;

long long countGood(vector<int>& nums, int k) {
    int n = nums.size();  // Size of the input array
    int i = 0;  // Left pointer for the sliding window
    int j = 0;  // Right pointer for the sliding window

    long long result = 0;  // To store the final result, i.e., the number of good subarrays

    unordered_map<int, int> mp;  // A map to store the frequency of elements in the current window

    long long pairs = 0;  // A counter to store the number of valid pairs (x, y) where nums[x] == nums[y]

    // Traverse the array using the right pointer `j`
    while(j < n) {
        // Count how many times nums[j] has appeared before in the window
        // If nums[j] has appeared previously, it forms pairs with all its previous occurrences.
        pairs += mp[nums[j]];  // Adds the frequency of nums[j] as it counts valid pairs

        // Increment the frequency of nums[j] in the map, since we're now including nums[j] in the window
        mp[nums[j]]++;

        // Once we have enough pairs (i.e., `pairs >= k`), start shrinking the window from the left
        // to maintain the condition of having at least `k` pairs
        while(pairs >= k) {
            // Add to the result the number of subarrays that end at position `j` and start anywhere from `i` to `n-1`
            // Every subarray with start index `i` to `n-1` will form a valid subarray.
            result += (n - j);

            // Shrink the window by moving `i` to the right
            // First, we decrement the frequency of nums[i] because we're excluding nums[i] from the window
            mp[nums[i]]--;
            // Update the number of pairs by subtracting the occurrences of nums[i] since it is no longer in the window
            pairs -= mp[nums[i]];
            // Move the left pointer `i` to the right to reduce the window size
            i++;
        }

        // Move the right pointer `j` to the next element
        j++;
    }

    // Return the total number of good subarrays
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 10;
    cout << countGood(nums, k) << endl;
    return 0;
}