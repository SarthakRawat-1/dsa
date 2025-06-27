// Problem Statement :- https://www.geeksforgeeks.org/problems/path-in-matrix3805/1

// Approach: Dynamic Programming
// Language: C++

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum path sum
int maximumPath(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    
    // Initialize result with the maximum value in the first row
    int res = *max_element(mat[0].begin(), mat[0].end());
    
    // Traverse the matrix row by row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Get max value from possible previous row positions
            int up = mat[i - 1][j];
            int left = (j > 0) ? mat[i - 1][j - 1] : 0;
            int right = (j < m - 1) ? mat[i - 1][j + 1] : 0;
            
            // Update current cell with max path sum
            mat[i][j] += max({up, left, right});
            
            // Update result if current cell has a greater value
            res = max(res, mat[i][j]);
        }
    }
    return res;
}

int main() {
  
    // Input matrix
    vector<vector<int>> mat = {{10, 10,  2,  0, 20,  4},
                                { 1,  0,  0, 30,  2,  5},
                                { 0, 10,  4,  0,  2,  0},
                                { 1,  0,  2, 20,  0,  4}};
    
    // Output the maximum path sum
    cout << maximumPath(mat) << endl;
    return 0;
}