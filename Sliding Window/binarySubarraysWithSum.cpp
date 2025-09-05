// Problem Statement :- https://leetcode.com/problems/binary-subarrays-with-sum/description/

// Once review Subarray Sum Equals K.
// First Optimal Approach uses the exact same logic as that.

// Second Optimal Approach uses Sliding Window.
// Use l and r ptr. Traverse using r pointer, track sum of window.
// If sum is less than goal, expand window. If sum is equal, inc the result by 1 as that subarr is valid and then expand window.
// If sum becomes more than goal then shrink the window from left.

// But here's the thing, when we have found a valid window, and the start of window contains some zeroes, then even if we remove those zeroes, the window will still have sum = goal.
// So, when we find a valid window, find the prefix zeroes, i.e. zeroes at start, and the number of prefix zeroes will also be the number of additional subarrays, resulting in sum = goal.
// Hence, if sum is equal to goal => result += 1 (the window itself) + no of prefix zeroes
// But we won't count prefix zeroes in current window. We will keep them outside of window and track their numbers.
// Role of prefix_zeros
// prefix_zeros represents the number of extra subarrays you can form by excluding consecutive leading zeros from the left of the window.
// It must be kept up to date while shrinking because:
// When window_sum > goal, we shrink until it’s valid.
// While shrinking, we need to distinguish between dropping a 1 (reset zeros) vs dropping 0s (accumulate zeros).
// If you only calculate prefix_zeros after seeing window_sum == goal, you won’t know how many valid subarrays ending at j actually exist — because those zeros may already be outside the current window.

#include <bits/stdc++.h>
using namespace std;

// // First Optimal Approach
// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     unordered_map<int, int> mp;

//     int prefixSum = 0;
//     int result = 0;

//     mp[0] = 1; // Initialize map with 0 count as 1.

//     for (int i = 0; i < nums.size(); i++) {
//         prefixSum += nums[i];

//         if (mp.find(prefixSum - goal) != mp.end()) {
//             result += mp[prefixSum - goal];
//         }

//         mp[prefixSum]++;
//     }

//     return result;
// }


// Second optimal Approach
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int prefix_zeros = 0;   // Tracks how many consecutive zeros are before current window
    int window_sum = 0;     // Current window sum
    int count = 0;          // Result: number of subarrays with sum == goal
    
    int i = 0, j = 0;       // Sliding window pointers
    
    while (j < nums.size()) {
        window_sum += nums[j];   // Expand window by including nums[j]
        
        // Shrink the window from left if sum exceeds goal
        // OR if there are leading zeros (nums[i] == 0)
        while (i < j && (nums[i] == 0 || window_sum > goal)) {
            if (nums[i] == 1) {
                prefix_zeros = 0;   // Reset zero count when we remove a '1'
            } else {
                prefix_zeros += 1;  // Count consecutive zeros removed
            }
            
            window_sum -= nums[i];  // Remove nums[i] from window sum
            i++;                    // Move left pointer forward
        }
        
        // If current window sum equals goal,
        // add subarrays ending at j:
        //   - "1" way if no prefix zeros
        //   - "1 + prefix_zeros" ways if there are prefix zeros
        if (window_sum == goal) {
            count += 1 + prefix_zeros;
        }
        
        j++; // Expand window to the right
    }
    
    return count; // Total subarrays with sum == goal
}

int main() {

}