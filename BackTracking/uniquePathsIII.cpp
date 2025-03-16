// Problem Statement :- https://leetcode.com/problems/unique-paths-iii/description/

// We will keep count of the non obstacles (including the start i.e. 1), in a variable. We will find this using a for loop. In the same for loop, we will also find the starting point. 
// We will decrease nonObstacle one by one as we step on a non obstacle.
// Whenever, we reach target i.e. 2, we will check if that variable ahs become zero or not.
// We will also have to mark our visited cells somehow. We can do this using another data structure or just modify this cell with some other character. In our case, we will mark them with -1. This way, we can tell ourselves not to go back to the same path where we came from, if there are still valid non obstacles to move to.
// Once we find the target, we will have to backtrack (and make the cells 0) all the way to the starting point.

#include <bits/stdc++.h>
using namespace std;

int m, n;
int result;
int nonObstacles;

// Possible directions to move (right, left, down, up)
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void backTrack(vector<vector<int>>& grid, int count, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) { // Boundary and condition checks
        return;
    }

    if (grid[i][j] == 2) { // If you reach the target, check if you have reached all the non obstacles
        if (count == nonObstacles) {
            result += 1;
        }
        return;
    }

    grid[i][j] = -1; // Mark the cell as visited

    for (vector<int> & dir : directions) { // For all possible directions, call the backtrack function
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        backTrack(grid, count + 1, new_i, new_j);
    }

    grid[i][j] = 0; // Backtrack : Restore the cell to unvisited
}

int uniquePathsIII(vector<vector<int>>& grid) {
    m = grid.size(); // Number of rows in the grid
    n = grid[0].size(); // Number of columns in the grid

    result = 0; // To count the number of paths possible
    nonObstacles = 0; // To count the number of non obstacles

    int start_x = 0, start_y = 0; // To store the coordinates of starting point

    // Find the number of non obstacles i.e. 0 and set the starting point i.e. where grid value is 1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                nonObstacles++;
            } else if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            }
        }
    }

    nonObstacles += 1; // As start_x and start_y is 1, which is also a non obstacle.
    int count = 0; // To count the number of non obstacles encountered while we are trying to reach the target.

    backTrack(grid, count, start_x, start_y); // Call the backtrack function for the starting point, initiating our process.

    return result;
}

int main() {
    // Define a sample grid for testing
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    // Call uniquePathsIII with the sample grid
    int totalPaths = uniquePathsIII(grid);

    // Print the result
    cout << "Total unique paths from start to target: " << totalPaths << endl;

    return 0;
}
