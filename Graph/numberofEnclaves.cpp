// Problem Statement :- https://leetcode.com/problems/number-of-enclaves/description/

// Very similar to Surrounded Regions

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

int numEnclaves(vector<vector<int>>& grid) {
    r = grid.size();
    c = grid[0].size();

    queue<pair<int, int>> q;

    // Traverse all boundary cells in one go
    // If a boundary cell contains land (1), mark it as water (0)
    // and push into queue for BFS flood-fill
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {  // boundary check
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; // mark as visited (sunk land)
                }
            }
        }
    }

    // BFS flood-fill: sink all land cells connected to the boundary
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj) && grid[ni][nj] == 1) {
                grid[ni][nj] = 0;   // sink land
                q.push({ni, nj});
            }
        }
    }

    // Count remaining land (enclaves)
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << "Number of Enclaves: " << numEnclaves(grid) << endl;
    return 0;
}
