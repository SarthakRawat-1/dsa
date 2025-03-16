// Problem Statement :- https://leetcode.com/problems/maximum-ascending-subarray-sum/description/

#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// int maxAscendingSum(vector<int>& nums) {
//     int n = nums.size();
//     int maxSum = 0; // Variable to store the maximum ascending sum found

//     // Iterate through the array considering each element as a starting point
//     for(int i = 0; i < n; i++) {
//         int sum = nums[i]; // Initialize sum with the current element
//         int j = i + 1;
        
//         // Expand the subarray while it remains ascending
//         while(j < n && nums[j] > nums[j-1]) {
//             sum += nums[j]; // Add current element to sum
//             j++;
//         }
        
//         // Update maxSum if the current sum is greater
//         maxSum = max(maxSum, sum);
//     }
    
//     return maxSum;
// }

// Approach-2 (Optimal)
int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    
    int maxSum = 0; // Stores the maximum sum encountered
    int sum = nums[0]; // Tracks the current ascending subarray sum

    // Iterate through the array starting from index 1
    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[i-1]) {
            sum += nums[i]; // Continue adding to the current subarray sum
        } else {
            maxSum = max(maxSum, sum); // Store the maximum encountered so far
            sum = nums[i]; // Reset sum to start a new subarray
        }
    }
    
    return max(maxSum, sum); // Ensure the last subarray sum is considered
}

int main() {
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    cout << maxAscendingSum(nums) << endl;
    return 0;
}