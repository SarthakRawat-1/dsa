// Problem Statement :- https://leetcode.com/problems/diagonal-traverse/description/

// The idea: elements with the same (row + col) index lie on the same diagonal
// Example: (0,2), (1,1), (2,0) all belong to diagonal "2" (row+col=2)

#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // Handle edge case: empty matrix
    if (mat.empty() || mat[0].empty()) return {};

    int m = mat.size();     // number of rows
    int n = mat[0].size();  // number of columns
    vector<int> result;
    result.reserve(m * n);  // reserve space to avoid resizing overhead

    // The idea: elements with the same (row + col) index lie on the same diagonal
    // Example: (0,2), (1,1), (2,0) all belong to diagonal "2" (row+col=2)
    
    // We need to process all diagonals from d = 0 to d = m+n-2
    for (int d = 0; d < m + n - 1; ++d) {
        // If d is even -> traverse the diagonal from bottom to top (up-right)
        // If d is odd  -> traverse the diagonal from top to bottom (down-left)
        bool up = (d % 2 == 0);

        // r_start: lowest row index possible for this diagonal
        //          (can't go below 0, so take max)
        int r_start = max(0, d - (n - 1));

        // r_end: highest row index possible for this diagonal
        //        (can't exceed m-1, so take min)
        int r_end = min(d, m - 1);

        if (up) {
            // Traverse upward → decreasing row, increasing column
            for (int r = r_end; r >= r_start; --r) {
                int c = d - r;   // column is determined by (row + col = d)
                result.push_back(mat[r][c]);
            }
        } else {
            // Traverse downward → increasing row, decreasing column
            for (int r = r_start; r <= r_end; ++r) {
                int c = d - r;
                result.push_back(mat[r][c]);
            }
        }
    }

    return result;
}

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    // Base case: if matrix is empty, return an empty vector
    if (matrix.size() == 0) return {};
    
    // iIndex = number of rows, jIndex = number of columns
    int iIndex = matrix.size(), jIndex = matrix[0].size();
    
    // Current row (i) and column (j) pointers
    int i = 0, j = 0;
    
    // Direction flag: true = moving up-right, false = moving down-left
    bool isMovingUpRight = true;
    
    // Keeps track of how many elements we have already added
    int count = 1;
    
    // Result vector, pre-allocated to the correct size
    vector<int> result(iIndex * jIndex);
    
    // Place the very first element
    result[0] = matrix[i][j];
    
    // Traverse until we reach the very last cell (bottom-right corner)
    while (i != iIndex - 1 || j != jIndex - 1) {
        if (isMovingUpRight) {  
            // Case 1: currently moving up-right ↗
            if (j == jIndex - 1) { 
                // If we’ve hit the rightmost column, move down
                i++;
                isMovingUpRight = false; // switch direction
            } else if (i == 0) { 
                // If we’ve hit the top row, move right
                j++;
                isMovingUpRight = false; // switch direction
            } else { 
                // Otherwise, keep moving up-right (row--, col++)
                i--;
                j++;
            }
        } else {  
            // Case 2: currently moving down-left ↙
            if (i == iIndex - 1) { 
                // If we’ve hit the bottom row, move right
                j++;
                isMovingUpRight = true; // switch direction
            } else if (j == 0) { 
                // If we’ve hit the leftmost column, move down
                i++;
                isMovingUpRight = true; // switch direction
            } else { 
                // Otherwise, keep moving down-left (row++, col--)
                i++;
                j--;
            }
        }
        
        // After moving, record the current element in the result
        result[count++] = matrix[i][j];
    }
    
    // Return the final traversal order
    return result;
}

int main() {

}