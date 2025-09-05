// Problem Statement :- https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
//                      https://leetcode.com/problems/surrounded-regions/description/

// Ofc, we can observe that O's at boundary edges can never be converted to X's.
// Creating sets of O is similar to creating Islands in numberofIslands.cpp
// We haev to create O's sets the biggest available, because if we left some O adjacent to the set, it means the set will not be surrounded by X.
// Once, we create the biggest available set, then we can be sure that it is surrounded by X. But there can be a problem, if the set contains O on boundary edges, then it won't be possible.

// We will start traversal from boundary i.e. first visit all boundary edges. This will help identifying O on them.
// Once found O on boundary, we can use them to create the biggest set and we know that this set can't be converted to X i.e. all of these O's can't be converted to X.
// To keep track of such O's we will use an array which denotes which O's can't be changed to X.

// Infact, we will traverse only the boundary edges. Once we travel all four boundary edges and mark which O's can't be visited or in a simple way, which position's remains as O, we can simply fill rest of the board as X.

// We can solve this without using the extra array. We can simply change those O which we know can't be changed to X, as a different sign like E or smth.
// Then while creating answer. We can simply fill all elements besides E as X and convert E back to O.

#include <bits/stdc++.h>
using namespace std;

int r; // Number of rows
int c; // Number of columns

// Directions for exploring up, down, left, right
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1}; 

// Check if (i, j) is within grid boundaries
bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

void solve(vector<vector<char>>& board) {
    r = board.size();         
    c = board[0].size();

    queue<pair<int, int>> q;

    // Traverse first row
    for (int j = 0; j < c; j++) {
        if (board[0][j] == 'O') {
            q.push({0, j});            // Push border 'O' to queue
            board[0][j] = 'E';         // Mark it as escaped
        }
    }

    // Traverse first column
    for (int i = 0; i < r; i++) {
        if (board[i][0] == 'O') {
            q.push({i, 0});
            board[i][0] = 'E';
        }
    }

    // Traverse last row (excluding first cell to avoid duplicate)
    for (int j = 1; j < c; j++) {
        if (board[r - 1][j] == 'O') {
            q.push({r - 1, j});
            board[r - 1][j] = 'E';
        }
    }

    // Traverse last column (excluding first and last cell to avoid duplicate)
    for (int i = 1; i < r - 1; i++) {
        if (board[i][c - 1] == 'O') {
            q.push({i, c - 1});
            board[i][c - 1] = 'E';
        }
    }

    // Or you can do this too
    // Traverse all boundary cells in one go
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {  // boundary check
    //             if (board[i][j] == 'O') {
    //                 q.push({i, j});
    //                 board[i][j] = 'E';   // mark as escaped
    //             }
    //         }
    //     }
    // }


    // BFS: Mark all 'O's connected to border 'O's as 'E'
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj) && board[ni][nj] == 'O') {
                board[ni][nj] = 'E';       // Mark as escaped
                q.push({ni, nj});
            }
        }
    }

    // Final pass to build the answer:
    // 1. Convert remaining 'O' to 'X' (surrounded regions)
    // 2. Convert 'E' back to 'O' (safe regions)
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';         // This 'O' was surrounded
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O';         // Restore escaped 'O'
            }
        }
    }
}

int main() {
    // Example usage:
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solve(board);

    // Print final board
    for (auto row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
