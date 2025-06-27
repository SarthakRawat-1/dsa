// Problem Statement :- https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    int oddCount = 0; // Keeps track of the number of odd numbers in the current window
    int count    = 0; // Counts how many valid starting points (i) exist for current j such that there are exactly k odd numbers between i and j
    int result   = 0; // Final result: total number of nice subarrays

    int i = 0; // Start of the sliding window
    int j = 0; // End of the sliding window

    // Best example to understand the use of count variable: [2, 1, 2, 1], k = 1 → Output: 6
    while (j < n) {

        // If current number is odd, increment the odd count
        if (nums[j] % 2 != 0) {
            oddCount++;
            count = 0; // Reset count to avoid overcounting — important for cases like [1,1,2,1,1], k = 3
        }

        // Shrink the window from the left as long as we have exactly k odd numbers
        while (oddCount == k) {
            count++; // Every time we move i, we find a new valid subarray ending at j

            // If nums[i] is odd, decrease the odd count because we are moving the window past an odd number
            if (nums[i] % 2 == 1) {
                oddCount--;
            }

            i++; // Move the start of the window forward
        }

        // Add count (number of valid subarrays ending at j) to the result
        result += count;
        j++; // Move to next element
    }

    return result;
}

int main() {

}