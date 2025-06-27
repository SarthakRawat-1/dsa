// Problem Statement :- https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/

// Observer that as we have to replace zero, the sum will always increase, it can never be decreased.

#include <bits/stdc++.h>
using namespace std;

long long minSum(vector<int> &nums1, vector<int> &nums2) {
    long long sum1 = 0;  // Total sum of nums1 (including adjustments for zeros)
    long long sum2 = 0;  // Total sum of nums2 (including adjustments for zeros)

    long long zero1 = 0; // Count of zeros in nums1
    long long zero2 = 0; // Count of zeros in nums2

    // Calculate sum1 and count zeros in nums1
    for (int &num : nums1) {
        if (num == 0) {
            zero1++;     // Count the zero
            sum1++;      // Assume each 0 is replaced by minimum value 1
        }
        sum1 += num;     // Add original value to sum1
    }

    // Calculate sum2 and count zeros in nums2
    for (int &num : nums2) {
        if (num == 0) {
            zero2++;     // Count the zero
            sum2++;      // Assume each 0 is replaced by minimum value 1
        }
        sum2 += num;     // Add original value to sum2
    }

    // Compare sums and check if it's possible to equalize them
    if (sum1 < sum2) {
        if (zero1 == 0) {
            // No zeros in nums1 to increase its sum -> cannot equalize
            return -1;
        }
    } else if (sum1 > sum2) {
        if (zero2 == 0) {
            // No zeros in nums2 to increase its sum -> cannot equalize
            return -1;
        }
    }

    // Return the maximum of the two sums (they can be made equal)
    return max(sum1, sum2);
}

int main() {
    vector<int> nums1 = {3, 2, 0, 1, 0};
    vector<int> nums2 = {6, 5, 0};
    cout << minSum(nums1, nums2) << endl;
    return 0;
}