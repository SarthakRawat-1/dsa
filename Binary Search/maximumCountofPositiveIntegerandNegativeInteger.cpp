// Problem Statement :- https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

#include <bits/stdc++.h>

using namespace std;

int maximumCount(vector<int>& nums) {
    int n = nums.size();  // Get the size of the array
    int low = 0, high = n - 1;

    int firstZero = n, firstPositive = n;  // Initialize positions of first zero and first positive number

    // First binary search to find the index of the first zero or positive number
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate the middle index to avoid integer overflow
        
        if (nums[mid] >= 0) {  // If nums[mid] is zero or positive
            firstZero = mid;  // Update firstZero to the current mid position
            high = mid - 1;   // Search in the left half for an earlier occurrence
        } else {  
            low = mid + 1;  // Move to the right half since all previous elements are negative
        }
    }

    low = 0, high = n - 1;  // Reset low and high for the second binary search

    // Second binary search to find the index of the first strictly positive number
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > 0) {  // If nums[mid] is strictly positive
            firstPositive = mid;  // Update firstPositive to the current mid position
            high = mid - 1;  // Search in the left half for an earlier occurrence
        } else {  
            low = mid + 1;  // Move to the right half since all previous elements are non-positive
        }
    }

    int negativeCount = firstZero;  // Count of negative numbers is the first occurrence of zero
    int positiveCount = n - firstPositive;  // Count of positive numbers is total size minus first positive index

    return max(negativeCount, positiveCount);  // Return the larger count
}

// Approach 2 :- Using STL
// int maximumCount(vector<int>& nums) {
//     int n = nums.size();

//     // Find the first index of a non-negative number (firstZero)
//     int firstZero = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    
//     // Find the first index of a positive number (firstPositive)
//     int firstPositive = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();

//     int negativeCount = firstZero;  
//     int positiveCount = n - firstPositive; 

//     return max(negativeCount, positiveCount);
// }

int main() {
    vector<int> nums = {-2, -1, -1, 1, 2, 3};

    cout << maximumCount(nums) << endl;

    return 0;
}