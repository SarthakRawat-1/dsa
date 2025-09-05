// Problem Statement :- 

#include <bits/stdc++.h>
using namespace std;

int n;

// Helper function to sort one diagonal of the matrix
void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
    vector<int> vec; // stores all diagonal elements starting from [r][c]

    int i = r;
    int j = c;

    // Step 1: Collect all diagonal elements into vec
    while(i < n && j < n) {
        vec.push_back(grid[i][j]);
        i++;
        j++;
    }

    // Step 2: Sort the diagonal
    // If asc = true → sort in increasing order
    // If asc = false → sort in decreasing order
    if(asc) {
        sort(begin(vec), end(vec));
    } else {
        sort(rbegin(vec), rend(vec));
    }

    // Step 3: Place sorted values back into the diagonal
    i = r;
    j = c;
    for(int &val : vec) {
        grid[i][j] = val;
        i++;
        j++;
    }
}

// Function to sort all diagonals of the matrix
vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    n = grid.size(); // size of the matrix (n x n)

    // 1. Sort all diagonals starting from the first column (bottom-left side)
    //    These diagonals are sorted in **non-increasing order** (descending)
    for(int row = 0; row < n; row++) {
        sortDiagonal(row, 0, grid, false);
    }

    // 2. Sort all diagonals starting from the first row (top-right side),
    //    excluding the first element [0][0] since it’s already handled.
    //    These diagonals are sorted in **non-decreasing order** (ascending)
    for(int col = 1; col < n; col++) {
        sortDiagonal(0, col, grid, true);
    }

    return grid; // return the sorted matrix
}

int main() {}