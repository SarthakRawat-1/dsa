// Problem Statement :- https://leetcode.com/problems/number-of-islands/description/

// Pick a 1 i.e. land. Now it needs to find all adjacent 1's (even diagonally) connecting to which it can form an island. Similarly, these newly added 1's will also check for the same.
// Start rowwise, when you find a 1, try to find adjacent 1's continuosly to make a single isalnd.
// Once that island is found, continue where you left off i.e. rowwise, now when you fidn another 1, check if it's already part of an island or not.
// If it is skip that.

// For finding islands, we can again use a queue if we want to solve it using BFS>
// When we encounter 1, add it to queue, pop from queue, add adjacent 1's to queue, but we also have to have a visisted array to keep track of 1's that are part of some island.
// Ofc, wehn queue is empty we will know that island is completed and we need to start traversing rowwise again to find new 1's.

// We can optimize this to solve without visited array.
// When we visit a 1, we know that we have toe tiher check if it's part of visisted array or add it to queue.
// The first 1 encountered doesn't have to be checked, so start with adding it to queue and then change it from 1 to 0 permanently. Do this for the rest of 1's too.
// Now, we can simply ignore already visited 1's as during their processign they were turned to 0.

#include <bits/stdc++.h>
using namespace std;

// Global variables to store number of rows and columns in the grid
int r;
int c;

// Arrays to represent all 8 directions (including diagonals)
// This is for GFG versions which consider 8 directions. Leetcode considers only 4 directions like in covidSpread.cpp
int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

// Function to check whether the (i, j) position is within bounds
bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

// Function to count the number of islands in the grid
int numIslands(vector<vector<char>>& grid) {
    r = grid.size();         // Number of rows
    c = grid[0].size();      // Number of columns

    queue<pair<int, int>> q; // Queue for BFS
    int count = 0;           // Island counter

    // Traverse each cell in the grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            // If a land cell ('1') is found
            if (grid[i][j] == '1') {
                count++; // Start of a new island

                // Begin BFS from this cell
                q.push({i, j});
                grid[i][j] = '0'; // Mark it visited by turning it to '0'

                // Explore all connected land cells using BFS
                while (!q.empty()) {
                    int newi = q.front().first;
                    int newj = q.front().second;
                    q.pop();

                    // Check all 8 directions
                    for (int k = 0; k < 8; k++) {
                        int ni = newi + row[k];
                        int nj = newj + col[k];

                        // If neighbor is valid and is land ('1')
                        if (valid(ni, nj) && grid[ni][nj] == '1') {
                            grid[ni][nj] = '0';  // Mark it as visited
                            q.push({ni, nj});    // Add it to queue for further BFS
                        }
                    }
                }
            }
        }
    }

    // Return the total number of islands found
    return count;
}

int main() {
    // Sample test (for demonstration)
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '1', '0', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '1'}
    };

    cout << "Number of Islands (8-directional): " << numIslands(grid) << endl;

    return 0;
}
