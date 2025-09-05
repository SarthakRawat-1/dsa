// Problem Statement :- https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

int m, n;  
typedef pair<int, int> P;  

// Four possible directions (right, left, up, down)
vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    m = mat.size();       // number of rows
    n = mat[0].size();    // number of columns
    
    queue<P> que;         // BFS queue to process cells
    vector<vector<int>> dist(m, vector<int>(n, -1)); // result matrix initialized with -1 (unvisited)
    
    // Step 1: Push all 0-cells into the queue as starting points
    //         and mark their distance as 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;    // distance from 0 to itself = 0
                que.push({i, j}); // enqueue this zero cell
            }
        }
    }
    
    // Lambda function to check matrix bounds (valid index check)
    auto isSafe = [](int& i, int& j, int& m, int& n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    };
    
    // Step 2: Multi-source BFS traversal
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        
        // Explore all four neighbors of current cell
        for (auto &dir : directions) {
            int i = p.first  + dir[0];
            int j = p.second + dir[1];
            
            // Check boundaries
            if (isSafe(i, j, m, n)) {
                // If this neighbor hasn't been visited yet
                if (dist[i][j] == -1) {
                    // Update its distance as current cell's distance + 1
                    dist[i][j] = 1 + dist[p.first][p.second];
                    // Enqueue it for further BFS expansion
                    que.push({i, j});
                }
            }
        }
    }
    
    // Step 3: Return final distance matrix
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
