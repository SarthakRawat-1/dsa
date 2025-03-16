// Problem Statement :- You are given a matrix and rotate it 90 degrees clockwise k number of times.

// 1 times means 90 degrees clockwise, 2 times means 180 degrees clockwise, 3 times means 270 degrees clockwise and 360 degrees means same matrix again.
// Furthermore, any more times than 4 will result in one of the 4 cases mentioned above (take k mod 4).
// And we already know how to rotate 90 degrees clockwise :- rotateImage.cpp, 180 degrees :- rotateMatrixby180.cpp, 270 degrees :- rotateMatrixby90AntiClockwise.cpp

// Alternatively, you can also write a function to rotate a matrix by 90 degrees clockwise. Then based on the value of k, call that function that many times.

#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
void rotate90(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        int start = 0, end = n - 1;
        while (start < end) {
            swap(matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }
}

// Function to rotate the matrix by 180 degrees clockwise
void rotate180(vector<vector<int>> &matrix) {
    // Rotate by 90 degrees twice
    rotate90(matrix);
    rotate90(matrix);
}

// Function to rotate the matrix by 270 degrees clockwise
void rotate270(vector<vector<int>> &matrix) {
    // Rotate by 90 degrees three times
    rotate90(matrix);
    rotate90(matrix);
    rotate90(matrix);
}

// Function to rotate the matrix by k * 90 degrees clockwise
void rotateMatrix(vector<vector<int>> &matrix, int k) {
    // Rotate the matrix based on k % 4
    int rotations = k % 4;
    
    for (int i = 0; i < rotations; i++) {
        rotate90(matrix);
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k;
    cout << "Enter the number of rotations (k): ";
    cin >> k;

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix, k);

    cout << "\nMatrix after " << k << " rotations:" << endl;
    printMatrix(matrix);

    return 0;
}
