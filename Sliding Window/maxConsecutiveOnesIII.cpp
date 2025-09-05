// Problem Statement :- https://leetcode.com/problems/max-consecutive-ones-iii/description/

// Brute Force :- Try every possible subarray (i, j). For each subarray, count how many zeros it contains. If zeros ≤ k → update the answer with length (j - i + 1).
// Optimal Solution :- Find the longest subarray containing at most k zeros. This is because we can flip at most k zeroes. This is the restriction in our problem. Ones are “free”, they only help extend the subarray. 
// Right pointer (right) expands the window rightwards. If we encounter 0, increase counter. But if there are more than k zeroes, then shrink window from left till both become equal.
// Update max length at each iteration and move right pointer.

#include <bits/stdc++.h>
using namespace std;

// // Brute Force
// int longestOnes(vector<int>& nums, int k) {
//     int n = nums.size();
//     int maxLen = 0;

//     // Try every possible starting index
//     for (int i = 0; i < n; i++) {
//         int zeroCount = 0;

//         // Expand subarray from i to j
//         for (int j = i; j < n; j++) {
//             if (nums[j] == 0) {
//                 zeroCount++;  // count zero
//             }

//             // If we exceed k zeros, break out (invalid window)
//             if (zeroCount > k) break;

//             // Update maximum valid subarray length
//             maxLen = max(maxLen, j - i + 1);
//         }
//     }

//     return maxLen;
// }

// Optimal Solution
int longestOnes(vector<int>& A, int K) {
    int start = 0;             // Left boundary of sliding window
    int end = 0;               // Right boundary of sliding window
    int zeroCounter = 0;       // Number of zeros inside current window
    int maxLen = 0;            // Tracks the maximum window length found

    // Traverse until right pointer (end) reaches the end of array
    while (end < A.size()) {
        // Step 1: Expand window by including A[end]
        if (A[end] == 0) {
            zeroCounter++;     // Count zeros in the window
        }

        // Step 2: If window has more than K zeros → shrink from the left
        while (zeroCounter > K) {
            if (A[start] == 0) {
                zeroCounter--; // Remove a zero from the count
            }
            start++;           // Move left boundary rightwards
        }

        // Step 3: Update maximum valid window length
        maxLen = std::max(maxLen, end - start + 1);

        // Step 4: Move right boundary to expand window
        end++;
    }

    return maxLen;
}

int main() {
    
}