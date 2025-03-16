// Problem Statement :- https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include <bits/stdc++.h>
using namespace std;

// Function to find the transpose of the matrix
void transposeMatrix(vector<vector<int>>& mat, int N) {
    // Loop through each element of the upper triangular matrix (excluding the diagonal)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Swap mat[i][j] and mat[j][i] to transpose
            swap(mat[i][j], mat[j][i]);
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& mat, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input size of the matrix
    int N;
    cin >> N;

    // Declare the matrix of size N x N
    vector<vector<int>> mat(N, vector<int>(N));

    // Input the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    // Call the function to transpose the matrix
    transposeMatrix(mat, N);

    // Output the transposed matrix
    printMatrix(mat, N);

    return 0;
}
