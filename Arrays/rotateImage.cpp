// Problem Statement :- https://leetcode.com/problems/rotate-image/description/

// Brute Force Approach :- 
// When we rotate a matrix 90 degrees (clockwise), it's first row will become last column, it's second row will become second last column and so on..
// So if we have 4 x 4 matrix, for first row :- [0][0] becomes [0][3], [0][1] becomes [1][3], [0][2] becomes [2][3] and [0][3] becomes [3][3]
// When we will try to analyze this pattern, we can see that the column in original matrix (second square bracket) is equal to row in rotated matrix (first square bracket). Also row in original matrix and column in rotated matrix is a constant value. And adding these constant values i.e. 0 + 3 we get 3 which is n - 1. You can check that this relation holds for other rows and columns as well.

#include <bits/stdc++.h>
using namespace std;

// Function to rotate the given matrix 90 degrees clockwise
// This uses an auxiliary matrix and does not modify the original matrix.
// vector<vector<int>> rotate(vector<vector<int>> &matrix) {
//     int n = matrix.size();  // Size of the matrix (n x n)
    
//     // Create a new matrix to store the rotated result
//     vector<vector<int>> rotated(n, vector<int>(n, 0));
    
//     // Traverse each cell of the matrix
//     for (int i = 0; i < n; i++) {           // `i` is the row index in the original matrix
//         for (int j = 0; j < n; j++) {       // `j` is the column index in the original matrix
//             // Place the element at `matrix[i][j]` to the rotated position
//             // Mapping rule: rotated[j][n - i - 1] = matrix[i][j];
//             rotated[j][n - i - 1] = matrix[i][j];
            
//             // Explanation of mapping:
//             // - Row `i` of the original matrix becomes column `n - i - 1` in rotated matrix.
//             // - Column `j` of the original matrix becomes row `j` in rotated matrix.
//         }
//     }
//     return rotated;  // Return the rotated matrix
// }


// Optimized Approach :- Try to catch a pattern. You will observe that first column of original matrix is equal to first row of rotated matrix but in reverse order. Second column of original matrix is equal to second row of rotated matrix but in reverse order. And so on.
// So just take transpose of original matrix and reverse each row. 
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(); // Determine the size of the matrix (n x n)
    
    // Step 1: Transpose the matrix
    // Transposing means converting rows to columns and vice versa.
    // For each element matrix[i][j], we swap it with matrix[j][i] where j < i to avoid redundant swaps.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Swap elements at (i, j) and (j, i) to transpose the matrix
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row of the matrix
    // After transposing, reversing each row will achieve the 90-degree clockwise rotation.
    for (int i = 0; i < n; i++) {
        // Reverse the elements in row 'i'
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // For Brute Force Approach
    // vector<vector<int>> rotated = rotate(arr); 

    // For Optimized Approach
    rotate(arr);

    cout << "Rotated Image:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;  
    }

    return 0;
}
