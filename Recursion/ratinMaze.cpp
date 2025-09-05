// Problem Statement :- https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// If at any cell, we go left, then row is same but column decreases by 1 i.e. net change is by adding (0, -1).
// Similarly, for moving down it is (1, 0), for right (0, 1) and up will be (-1, 0).
// Once we visit a cell, we will mark it 0. To not visit it again.

#include <bits/stdc++.h>
using namespace std;

// Global vector to store all valid paths from source to destination
vector<string> result;

// Function to check if cell (i, j) is within bounds of the grid
bool isSafe(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

// Recursive function to explore all possible paths from (i, j) to (n-1, n-1)
void solve(int i, int j, vector<vector<int>> &m, int n, string path) {
    // If the current cell is out of bounds or is blocked (0), return
    if (!isSafe(i, j, n) || m[i][j] == 0) {
        return;
    }

    // If destination cell (n-1, n-1) is reached, store the current path and return
    if (i == n - 1 && j == n - 1) {
        result.push_back(path);
        return;
    }

    // Mark the current cell as visited by setting it to 0
    m[i][j] = 0;

    // Move Down (D)
    path.push_back('D');
    solve(i + 1, j, m, n, path);
    path.pop_back(); // Backtrack

    // Move Right (R)
    path.push_back('R');
    solve(i, j + 1, m, n, path);
    path.pop_back(); // Backtrack

    // Move Up (U)
    path.push_back('U');
    solve(i - 1, j, m, n, path);
    path.pop_back(); // Backtrack

    // Move Left (L)
    path.push_back('L');
    solve(i, j - 1, m, n, path);
    path.pop_back(); // Backtrack

    // Unmark the current cell while backtracking
    m[i][j] = 1;
}

// Main function to find all paths from (0,0) to (n-1,n-1)
vector<string> findPath(vector<vector<int>> &m, int n) {
    string path = "";

    // Start solving from the top-left corner (0,0)
    solve(0, 0, m, n, path);

    // Return the list of valid paths found
    return result;
}

int main() {

}