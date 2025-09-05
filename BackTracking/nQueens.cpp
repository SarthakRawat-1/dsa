// Problem Statement :- https://leetcode.com/problems/n-queens/description/

// If we can't find a row to place a queen, we won't go to the next row, as we have to place queens in each row.
// Whenever we place a queen,w e can solve the queen being in same row problem quite easily, as every new iteration will ensure that.
// For same column problem, we can take an array to indicate if there are already queens in that column.


#include <bits/stdc++.h>
using namespace std;

// Helper function to check if placing a queen at position (i, j) is safe
bool check(int n, vector<string> &Board, int i, int j) {
    int row = i, col = j;

    // Check upper-left diagonal
    while (row > -1 && col > -1) {
        if (Board[row][col] == 'Q') {
            return 0;  // Queen found in upper-left diagonal => not safe
        }
        row--, col--;
    }

    // Check upper-right diagonal
    row = i, col = j;
    while (row > -1 && col < n) {
        if (Board[row][col] == 'Q') {
            return 0;  // Queen found in upper-right diagonal => not safe
        }
        row--, col++;
    }

    // No conflicting queen found in diagonals => safe
    return 1;
}

// Recursive function to place queens row by row
void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column) {
    // Base case: if all rows are filled, store the current board configuration
    if (row == n) {
        ans.push_back(Board);
        return;
    }

    // Try placing a queen in every column of the current row
    for (int j = 0; j < n; j++) {
        // Place a queen only if the column is free and diagonals are safe
        if (column[j] == 0 && check(n, Board, row, j)) {
            column[j] = 1;              // Mark column as occupied
            Board[row][j] = 'Q';        // Place queen at (row, j)
            
            find(row + 1, n, ans, Board, column);  // Recur for next row

            // Backtrack: remove queen and mark column as free
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

// Main function to solve the N-Queens problem
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;       // Stores all valid board configurations
    vector<string> Board(n);          // 2D board represented as a vector of strings

    // Initialize the board with empty cells '.'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Board[i].push_back('.');
        }
    }

    vector<bool> column(n, 0);  // Track occupied columns (since rows are filled one by one)

    // Start backtracking from row 0
    find(0, n, ans, Board, column);

    return ans;
}


// Optimized Solution

// We can optimize checking for other queens on a diagonal.
// For checking right diagonals, all right diagonal (right diagonal means from right to left) elements have a common property that (row + col) is constant for same right diagonal.
// So simply, we can again create an array whose indices represent the sum of row and col. Whenever we place a queen, we mark the corresponding indice as 1. Now when we want to check if we can place a queen on a block, we will calculate row + col of that block and check in the array.
// Size of array will be 2n - 1
// For left diagonals, it will be col - row, everything else is same. But this might give negative results (and arr can't have negative results), so we will add n - 1 to make positive.


// Recursive function to place queens row by row
void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDig, vector<bool> &RightDig) {
    // Base case: if all rows are filled, store the current board configuration
    if (row == n) {
        ans.push_back(Board);
        return;
    }

    // Try placing a queen in every column of the current row
    for (int j = 0; j < n; j++) {
        // Place a queen only if the column is free and diagonals are safe
        if (column[j] == 0 && LeftDig[n - 1 + j - row] == 0 && RightDig[row + j] == 0) {
            column[j] = 1;              // Mark column as occupied
            Board[row][j] = 'Q';        // Place queen at (row, j)

            LeftDig[n - 1 + j - row] = 1;
            RightDig[row + j] = 1;
            
            find(row + 1, n, ans, Board, column, LeftDig, RightDig);  // Recur for next row

            // Backtrack: remove queen and mark column as free
            column[j] = 0;
            Board[row][j] = '.';
            LeftDig[n - 1 + j - row] = 0;
            RightDig[row + j] = 0;
        }
    }
}

// Main function to solve the N-Queens problem
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;       // Stores all valid board configurations
    vector<string> Board(n);          // 2D board represented as a vector of strings

    // Initialize the board with empty cells '.'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Board[i].push_back('.');
        }
    }

    vector<bool> LeftDig(2 * n - 1, 0);
    vector<bool> RightDig(2 * n - 1, 0);

    vector<bool> column(n, 0);  // Track occupied columns (since rows are filled one by one)

    // Start backtracking from row 0
    find(0, n, ans, Board, column, LeftDig, RightDig);

    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n for the N-Queens problem: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}