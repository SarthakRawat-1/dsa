// Problem Statement :- https://leetcode.com/problems/search-a-2d-matrix-ii/description/

// Binary Search can be applied on a 2D array if it is sorted both rowwise and columnwise and but not across rows.

// Approach 1 :- Same as in binarySearchin2DArray.cpp

// Approach 2 :- Here you can't directly use Binary Search, as when you convert the 2D array to 1D array, it will not be sorted.
// Start from frist element in first row, if it is lesser than target, the desired number can appear both below and to the right of that. This can lead to confusion in choosing direction to move in.
// Hence, start from the last element in first row. If it is greater than target, then we have to move to left of that, if it is lesser, we have to move downwards. Simiarly, whenever you move and arrive on a new element, you have to check this condition.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Get the dimensions of the matrix.
    int N = matrix.size();       // Number of rows
    int M = matrix[0].size();    // Number of columns

    int row = 0, col = M - 1;   // Start from the last element in the first row.

    while (row < N && col >= 0) {
        if (matrix[row][col] == target) {
            return true;         // Target found, return true.
        } else if (matrix[row][col] < target) {
            row++;               // If the current element is smaller than the target, move downwards.
        } else {
            col--;               // If the current element is larger than the target, move to the left.
        }
    }

    return false;                // Target not found, return false.
}

int main() {
    // Example 1: Basic test case
    vector<vector<int>> matrix1 = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};;
    int target1 = 9;
    cout << "Result: " << (searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;

    return 0;
}