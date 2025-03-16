// Problem Statement :- https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

// One way is to watch this as rotate matrix by 270 degrees clockwise. We know how to rotate matrix by 90 degrees clockwise from rotateImage.cpp

// Better Approach :-
// To rotate a matrix 90 degrees counterclockwise (anti-clockwise), first transpose the matrix.
// After that reverse each column.

#include <bits/stdc++.h>
using namespace std;

// Function to rotate the matrix by 90 degrees counterclockwise
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();  // Get the size of the matrix (n x n)
    
    // Step 1: Transpose the matrix
    // Transpose means converting rows to columns and vice versa.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap elements at (i, j) and (j, i)
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each column
    // After transposing, reverse each column to achieve 90-degree counterclockwise rotation.
    for (int j = 0; j < n; j++) {
        int start = 0, end = n - 1;
        while (start < end) {
            // Swap elements in the column j from top to bottom
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    rotate(matrix);

    cout << "\nRotated Matrix by 90 degrees counterclockwise:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
