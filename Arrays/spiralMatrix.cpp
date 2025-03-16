// Problem Statement :- https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// Function to traverse the matrix in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;  // This will store the result in spiral order
    if (matrix.empty()) {
        return result;  // If matrix is empty, return empty result
    }

    // Initialize boundary indices
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

    // Loop until all boundaries have been processed
    while (top <= bottom && left <= right) {
        // 1. Traverse from left to right along the top boundary
        // The top row has been processed completely, so we push the elements in order.
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;  // After processing the top row, move the top boundary down to avoid revisiting it

        // 2. Traverse from top to bottom along the right boundary
        // The rightmost column has been processed, so we push elements from top to bottom in that column.
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;  // After processing the rightmost column, move the right boundary left to avoid revisiting it

        // 3. Traverse from right to left along the bottom boundary
        // This step should only be done if there are still rows left.
        // If top <= bottom, the bottom row is still available for processing.
        if (top <= bottom) {
            // Traverse the bottom row from right to left, as we have already traversed the top row.
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;  // After processing the bottom row, move the bottom boundary up to avoid revisiting it
        }

        // 4. Traverse from bottom to top along the left boundary
        // This step should only be done if there are still columns left.
        // If left <= right, the left column is still available for processing.
        if (left <= right) {
            // Traverse the leftmost column from bottom to top.
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;  // After processing the leftmost column, move the left boundary right to avoid revisiting it
        }
    }

    // Return the result vector that contains the elements in spiral order
    return result;
}

int main() {
    // Example 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = spiralOrder(matrix);  // Get the spiral order of the matrix

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

