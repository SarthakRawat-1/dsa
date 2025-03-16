// Problem Statement :- https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=row-with-max-1s

// Brute Force Approach :- Traverse the matrix as usual using nested loops and for every single row count the number of 1’s. Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index.

// Optimal Approach :- Because each row is sorted, once we find the first occurrence of 1 in a row, all elements to the right will also be 1.This sorted order allows us to use Binary Search to efficiently locate the first 1 in each row.
// We will use cnt_max variable (initialized to 0) to tracks the maximum count of 1’s found in any row so far. We will use index variable (initialized to -1) to track the index of that row which has most 1's.
// For each row i, we want to find the first occurrence of 1. Since the row is sorted, we can find this position quickly with concept of Lower Bound. With this we will get index of first occurence of 1. Using this, we can find the number of 1's in that row.
// Return the index of the row with most 1's at the end.

#include <bits/stdc++.h>
using namespace std;

// Helper function: lowerBound
// This function finds the first occurrence of a number `x` in a sorted array `arr` of size `n`.
// It returns the index of the first element >= `x`, if it exists, or `n` if all elements are < `x`.
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Initialize `ans` to `n` to handle cases where `x` is not found (no 1's in row)

    // Binary search loop
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index

        // Check if `arr[mid]` is greater than or equal to `x`
        if (arr[mid] >= x) {
            ans = mid; // Update `ans` as `mid` may be the first occurrence of `x`
            high = mid - 1; // Search in the left half for an earlier occurrence of `x`
        }
        else {
            low = mid + 1; // Search in the right half as `arr[mid]` is less than `x`
        }
    }

    // Return the index of the first occurrence of `x`, or `n` if `x` was not found
    return ans;
}

// Main function: rowWithMax1s
// This function finds the row with the maximum number of 1's in a binary matrix `matrix` of dimensions `n` x `m`.
// Each row in `matrix` is sorted, allowing us to use `lowerBound` to find the first occurrence of `1` in each row.
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0; // To store the maximum count of 1's found in any row
    int index = -1;  // To store the index of the row with the maximum number of 1's

    // Traverse each row in the matrix
    for (int i = 0; i < n; i++) {
        // Use lowerBound to find the first occurrence of `1` in the current row `matrix[i]`
        int cnt_ones = m - lowerBound(matrix[i], m, 1); // Calculate the number of 1's in the row
        // Check if the current row has more 1's than the current `cnt_max`
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones; // Update `cnt_max` with the new maximum count
            index = i;          // Update `index` with the row index `i` as it has the most 1's so far
        }
    }

    // Return the index of the row with the maximum number of 1's, or -1 if no 1's were found
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << endl;
}
