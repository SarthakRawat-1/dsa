// Problem Statement :- https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
  ----------
  - Use a sliding window of size k to examine each contiguous segment of blocks.
  - Count the number of white blocks ('W') in each window since these are the ones that would
    need to be repainted.
  - The minimum number of repaints across all windows is the answer.
*/

int minimumRecolors(string blocks, int k) {
    int n = blocks.size();   // Total number of blocks.
    int i = 0, j = 0;        // 'i' is the start index and 'j' is the end index for the sliding window.
    
    int ops = k;             // Initialize operations (repaints) to k, which is the worst-case scenario:
                             // if all k blocks are white, then k repaints are needed.
    int W = 0;               // Counter for the number of white blocks ('W') in the current window.

    // Slide the window over the entire string.
    while (j < n) {
        // If the current block is white, increment the white counter.
        if (blocks[j] == 'W') {
            W++;
        }
        
        // Check if the current window size is exactly k.
        if (j - i + 1 == k) {
            // Update the minimum number of operations needed.
            // This is the minimum white count among all windows of size k.
            ops = min(ops, W);

            // Slide the window:
            // If the block at the start of the window is white,
            // decrement the white counter since it will no longer be in the window.
            if (blocks[i] == 'W') {
                W--;
            }
            // Move the start of the window forward.
            i++;
        }
        // Expand the window by moving the end pointer.
        j++;
    }

    return ops; // Return the minimum number of recolors needed.
}

int main() {
    string blocks = "WBBWWBBWBW";
    int k = 7;  

    int result = minimumRecolors(blocks, k);
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}