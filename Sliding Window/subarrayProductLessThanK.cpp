// Problem Statement :- https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // If k is less than or equal to 1, no product of positive integers can be less than k
    if (k <= 1)
        return 0;

    int n = nums.size();
    int count = 0;      // To store the total number of valid subarrays
    int left = 0;       // Left boundary of the sliding window
    int right = 0;      // Right boundary of the sliding window
    int prod = 1;       // Product of elements within the current window

    // Iterate through the array using the right pointer
    while (right < n) {
        prod *= nums[right];  // Include nums[right] in the current product

        // If the product becomes equal to or greater than k, 
        // move the left pointer to reduce the product
        while (prod >= k) {
            prod /= nums[left];  // Remove nums[left] from the product
            left++;              // Shrink the window from the left
        }

        // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
        // So, number of such subarrays = (right - left + 1)
        count += (right - left + 1);

        right++;  // Move to the next element
    }

    return count;  // Return the total count of valid subarrays
}

int main() {

}