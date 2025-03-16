// Problem Statement :- https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();    // Number of rows
    int n = mat[0].size(); // Number of columns
    
    // Directions for the four possible movements: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Initialize a queue for BFS and a result matrix
    queue<pair<int, int>> q;
    
    // Step 1: Initialize the result matrix and enqueue all 0s
    vector<vector<int>> dist(m, vector<int>(n, -1)); // -1 indicates unvisited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;  // Distance to itself is 0
                q.push({i, j});   // Enqueue the 0 cell
            }
        }
    }

    // Step 2: Perform BFS
    while (!q.empty()) {
        // Get the current cell from the queue
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); // Remove the front element from the queue
        
        // Explore all four neighbors
        for (auto& dir : directions) {
            int newX = x + dir.first;  // New row position
            int newY = y + dir.second; // New column position
            
            // Check if the new position is within bounds
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                // If the neighbor has not been visited (i.e., distance is still -1)
                if (dist[newX][newY] == -1) {
                    // Update the distance to the neighbor cell
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY}); // Enqueue the neighbor for further exploration
                }
            }
        }
    }

    // Return the result matrix with the shortest distances
    return dist;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);
    
    // Print the result matrix
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
