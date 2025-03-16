// Problem Statement :- https://leetcode.com/problems/median-of-two-sorted-arrays/

// Brute Force :- Merge both arrays, then simmply use formula for calcualting median.

// Optimized Approach :- Using Binary Search.
// 


#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is the smaller array to optimize the binary search range
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    
    int m = nums1.size();
    int n = nums2.size();
    
    // Binary search on the smaller array
    int low = 0, high = m;
    
    while(low <= high) {
        // Partitioning nums1 at index Px
        int Px = low + (high - low) / 2;
        // Partitioning nums2 at index Py such that left half contains (m+n+1)/2 elements
        int Py = (m + n + 1) / 2 - Px;
        
        // Handling edge cases where partition index is at 0 or at the end
        int x1  = (Px == 0) ? INT_MIN : nums1[Px - 1];  // Leftmost element of nums1
        int x3  = (Px == m) ? INT_MAX : nums1[Px];      // Rightmost element of nums1

        int x2  = (Py == 0) ? INT_MIN : nums2[Py - 1];  // Leftmost element of nums2
        int x4  = (Py == n) ? INT_MAX : nums2[Py];      // Rightmost element of nums2
        
        // Valid partition check
        if(x1 <= x4 && x2 <= x3) {
            // If total number of elements is even, median is the average of two middle elements
            if((m + n) % 2 == 0)
                return (max(x1, x2) + min(x3, x4)) / 2.0;
            
            // If total number of elements is odd, median is the maximum of left partition
            return max(x1, x2);
        } 
        // If partition is incorrect, adjust binary search range
        else if(x1 > x4) {
            high = Px - 1;  // Move left
        } 
        else {
            low = Px + 1;   // Move right
        }
    }
    
    return -1;  // Edge case (should never reach here)
}
    
    