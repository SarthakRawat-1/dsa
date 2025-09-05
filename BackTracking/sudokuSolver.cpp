// Problem Statement :- https://leetcode.com/problems/sudoku-solver/

// Checking same values in same row and samecol is easy but in same block might be a bit problematic.
// So all elements in 0, 1 or 2nd row, they should start checking from 0th row for theri block and 3, 4, 5 should from 3rd row.
// For col too similar. For directly finding this, u can use this formula :- (i / 3) * 3 and (j / 3) * 3
// Eg :- 0 / 3 = 0 and 0 * 3 = 0, 5 / 3 = 1 and 1 * 3 = 3

#include <bits/stdc++.h>
using namespace std;

// Function to check whether a given number can be placed at board[i][j]
bool check(int num, vector<vector<char>> &board, int i, int j) {
    char c = '0' + num;  // Convert number to character (since board stores chars)

    // Check the entire row
    for (int col = 0; col < 9; col++) {
        if (board[i][col] == c) {
            return false; // Number already exists in this row
        }
    }

    // Check the entire column
    for (int row = 0; row < 9; row++) {
        if (board[row][j] == c) {
            return false; // Number already exists in this column
        }
    }

    // Check the 3x3 sub-grid
    // Formula: top-left corner of the block = (i / 3) * 3, (j / 3) * 3
    int row = i / 3 * 3;
    int col = j / 3 * 3;

    for (int a = row; a < row + 3; a++) {
        for (int b = col; b < col + 3; b++) {
            if (board[a][b] == c) {
                return false; // Number already exists in this 3x3 block
            }
        }
    }

    return true; // Safe to place the number
}

// Recursive function to solve the Sudoku using backtracking
bool find(int i, int j, vector<vector<char>>& board) {
    // Base case: reached past the last row → Sudoku solved
    if (i == 9) {
        return true;
    }

    // If column index exceeds 8, move to next row
    if (j == 9) {
        return find(i + 1, 0, board);
    }

    // Skip filled cells, move to next column
    if (board[i][j] != '.') {
        return find(i, j + 1, board);
    }

    // Try placing digits 1 to 9 in current empty cell
    for (int num = 1; num <= 9; num++) {
        if (check(num, board, i, j)) {
            board[i][j] = '0' + num; // Place number

            // Recurse to next cell
            if (find(i, j + 1, board)) {
                return true;
            }

            // Backtrack → reset cell if placement fails
            board[i][j] = '.';
        }
    }

    return false; // No valid number found, backtrack
}

// Main function to solve the Sudoku
void solveSudoku(vector<vector<char>>& board) {
    find(0, 0, board);
}

int main() {

}