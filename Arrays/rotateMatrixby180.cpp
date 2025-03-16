// Problem Statement :- https://www.geeksforgeeks.org/problems/c-matrix-rotation-by-180-degree0745/0

// Rotating a matrix by 180 degrees clockwise or counterclockwise will produce the same output.

// One way is to rotate the matrix by 90 degrees clockwise and then rotate the matrix by 90 degrees clockwise again. This will give us the same result as rotating by 180 degrees clockwise.

// Better way :- Observe a pattern. The first row in original matrix will be the last row in rotated matrix but in reverse order. Second row in original matrix will be second last row in rotated matrix but in reverse order and so on. 
// For swapping first row to last row, second row to second last row and so on, we can just reverse each column.
// After this, reversing each row we can do it quite easily. Refer rotateImage.cpp

#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

// Function to rotate the matrix by 180 degrees
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(); // Get the size of the matrix (assuming n x n matrix)

    // Step 1: Reverse each column
    // This step brings the top rows to the bottom and vice versa.
    // For each column (j), we start from the top (start) and the bottom (end),
    // and swap their values to reverse the order of each column.
    for (int j = 0; j < n; j++) {
        int start = 0, end = n - 1;
        while (start < end) {
            // Swap elements from top to bottom in the current column `j`
            swap(matrix[start][j], matrix[end][j]);
            start++;
            end--;
        }
    }

    // Step 2: Reverse each row
    // After reversing columns, each row must be reversed to achieve 180-degree rotation.
    // This step ensures that each element is moved to its exact 180-degree rotated position.
    for (int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while (start < end) {
            // Swap elements in the current row `i` from left to right
            swap(matrix[i][start], matrix[i][end]);
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

    // Rotate the matrix by 180 degrees
    rotate(matrix);

    cout << "\nRotated Matrix by 180 degrees:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
