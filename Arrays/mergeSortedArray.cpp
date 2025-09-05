// Problem Statement :- https://leetcode.com/problems/merge-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // i → index of the last element in nums1's initial "valid" part (length m)
    int i = m - 1;

    // j → index of the last element in nums2 (length n)
    int j = n - 1;

    // k → index of the last position in nums1's total allocated size (m + n)
    // nums1 already has space for all elements (m original + n extra zeros)
    int k = m + n - 1;

    // Merge nums1 and nums2 from the back to the front
    // Reason: avoids overwriting elements in nums1 that we haven't processed yet
    while (j >= 0) { // Keep going until all elements from nums2 are placed
        // Case 1: nums1[i] is larger than nums2[j] → place nums1[i] at nums1[k]
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--]; // Copy and move both i and k backwards
        }
        // Case 2: nums2[j] is larger or equal → place nums2[j] at nums1[k]
        else {
            nums1[k--] = nums2[j--]; // Copy and move both j and k backwards
        }
    }

    // Note: No need to copy remaining nums1 elements because they are already in place
    // If any elements from nums2 remain, they'll be handled in the loop above
}

int main() {

}