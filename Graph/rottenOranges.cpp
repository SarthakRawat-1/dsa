// Problem Statement :- https://leetcode.com/problems/rotting-oranges/description/

// This is a multisource BFS question because time is same for all so all rotting oranges will rot their neighbours at the same flow of time, i.e. parallely.
// BSF because DFS ain't reliable for these shortest type ques.
// So, each rotten orange is a source. Start multisource BFS. 
// So, traverse the grid, count no of fresh oranges and if the orange is rotten, insert their (i, j) in index.
// Then pop from front from queue and insert their neighbours into queue (if they are fresh oranges), keep doing this till u have popped and inserted neighbours of all prev sources.
// Then inc minute as one min has passed. Ofc their neighbour are rotten so marke them rotten in grid and then insert their fresh negihbours in queue. Ofc, as oranges rot, keep decreasing fresh oranges
// Ofc when queue becomes empty, we would have gotten ans.
// Btw how do we know till how much should we pop back before a stage of rotten oranges is clear all their neighbour have been rotted and next min starts? Simply find size of queue before inserting any of their neighbours.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P; // To store cell coordinates (row, col)
    
    // Possible 4 directions: up, down, left, right
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();      // number of rows
        int n = grid[0].size();   // number of columns

        queue<P> que;             // queue for BFS (multi-source)
        int freshCount = 0;       // count of fresh oranges

        // Step 1: Traverse the grid
        // - Push all rotten oranges into the queue (multi-source BFS starting points)
        // - Count total fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    que.push({i, j}); // rotten orange (source of infection)
                }
                else if(grid[i][j] == 1) {
                    freshCount++;     // fresh orange
                }
            }
        }
        
        // If no fresh oranges exist initially, no time is needed
        if(freshCount == 0)
            return 0;
        
        // Lambda to check if a cell is valid and contains a fresh orange
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < grid.size() && 
                   y >= 0 && y < grid[x].size() && 
                   grid[x][y] == 1; // must be a fresh orange
        };
        
        // Step 2: Apply Multi-Source BFS
        int time = 0; // keeps track of minutes elapsed
        while(!que.empty()) {
            int n = que.size(); // number of rotten oranges at the current time step
            
            // Process all rotten oranges at this level (same time frame)
            while(n--) {
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;
                
                // Try all 4 directions
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    
                    // If the neighboring cell has a fresh orange, rot it
                    if(isSafe(new_i, new_j)) {
                        grid[new_i][new_j] = 2;    // becomes rotten
                        que.push({new_i, new_j});  // add to queue for next round
                        freshCount--;              // one less fresh orange
                    }
                }
            }
            time++; // one minute passed
        }
        
        // If all fresh oranges are rotten, return time-1 (last level is extra)
        // Otherwise, return -1 (not all oranges can rot)
        return (freshCount==0) ? time-1 : -1;
    }
};

int main() {

}