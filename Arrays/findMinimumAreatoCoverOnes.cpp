// Problem Statement :- https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

// Basically find boundaries.

#include <bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int minRow = m;
    int maxRow = -1;
    int minCol = n;
    int maxCol = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
}

int main() {

}