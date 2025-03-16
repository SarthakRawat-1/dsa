// Problem Statement :- https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

// In questions of grid, when we are asked to find minimum path, we should think of BFS.
// The visited vector here, will also keep track of the state, i.e. whether we reached here with the same k value as before (then don't visit again) or something different.

#include <bits/stdc++.h>
using namespace std;

// Approach-1 - BFS with 3D Visited State
vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<vector<int>> que; // BFS queue: [i, j, remaining_k]
    que.push({0, 0, k});
    
    bool visited[41][41][1601]; // 3D array to track visited states (i, j, remaining_k)
    memset(visited, false, sizeof(visited));
    visited[0][0][k] = true; // Mark start position with k eliminations
    
    int steps = 0; // Track the number of steps taken
    
    while (!que.empty()) {
        int size = que.size();
        // Process all nodes at the current level (BFS layer)
        while (size--) {
            vector<int> curr = que.front();
            que.pop();
            int i = curr[0], j = curr[1], remK = curr[2];
            
            // Check if reached the destination
            if (i == m-1 && j == n-1)
                return steps;
            
            // Explore all four directions
            for (auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                
                // Check if new position is within grid bounds
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                    continue;
                
                // If the next cell is empty (0) and not visited with remainingK
                if (grid[new_i][new_j] == 0 && !visited[new_i][new_j][remK]) {
                    que.push({new_i, new_j, remK});
                    visited[new_i][new_j][remK] = true;
                }
                // If the next cell is an obstacle (1) and can eliminate it
                else if (grid[new_i][new_j] == 1 && remK > 0 && !visited[new_i][new_j][remK-1]) {
                    que.push({new_i, new_j, remK-1});
                    visited[new_i][new_j][remK-1] = true;
                }
            }
        }
        steps++; // Increment steps after processing each BFS layer
    }
    return -1; // Destination unreachable
}

vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    
    // 2D array to track the minimum obstacles encountered to reach each cell
    vector<vector<int>> obs(m, vector<int>(n, INT_MAX));
    obs[0][0] = 0; // Starting with 0 obstacles
    
    queue<vector<int>> que; // BFS queue: [x, y, currentObstacleCount]
    que.push({0, 0, 0});
    
    int steps = 0;
    
    while (!que.empty()) {
        int size = que.size();
        while (size--) {
            auto curr = que.front(); que.pop();
            int x = curr[0], y = curr[1], currObstacle = curr[2];
            
            // Check if destination is reached
            if (x == m-1 && y == n-1)
                return steps;
            
            // Explore all directions
            for (auto& dir : dirs) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    // Calculate new obstacle count
                    int newObstacle = currObstacle + grid[new_x][new_y];
                    
                    // Skip if new obstacle count exceeds k or is not better than previous
                    if (newObstacle >= obs[new_x][new_y] || newObstacle > k)
                        continue;
                    
                    // Update obstacle count and enqueue
                    obs[new_x][new_y] = newObstacle;
                    que.push({new_x, new_y, newObstacle});
                }
            }
        }
        steps++; // Increment steps after each BFS layer
    }
    return -1; // Destination unreachable
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}};
    int k = 1;
    int result = shortestPath(grid, k);
    cout << "Shortest path: " << result << endl;
    return 0;
}