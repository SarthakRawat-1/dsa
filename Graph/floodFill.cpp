// Problem Statement :- https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS to fill connected pixels with new color
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int newColor,
             vector<pair<int,int>>& directions, int iniColor) {
        
        // Color current pixel
        ans[row][col] = newColor; 
        
        int n = image.size();
        int m = image[0].size(); 
        
        // Explore all 4 directions
        for(auto dir : directions) {
            int nrow = row + dir.first; 
            int ncol = col + dir.second; 
            
            // Check bounds, same initial color, and not yet recolored
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
               image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, directions, iniColor); 
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];     // original color of starting pixel
        vector<vector<int>> ans = image;  // result grid initialized as input image
        
        // Directions: up, right, down, left
        vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        dfs(sr, sc, ans, image, newColor, directions, iniColor); 
        return ans; 
    }
};

// You can also do using BFS, which is better for larger inputs
// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         int iniColor = image[sr][sc];
//         if (iniColor == newColor) return image; // No change needed

//         int n = image.size();
//         int m = image[0].size();
        
//         vector<vector<int>> ans = image;

//         // Directions: up, right, down, left
//         vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};

//         // Queue for BFS, starting from the source pixel
//         queue<pair<int,int>> q;
//         q.push({sr, sc});
//         ans[sr][sc] = newColor;

//         while (!q.empty()) {
//             auto cell = q.front();
//             q.pop();
//             int row = cell.first;
//             int col = cell.second;

//             // Explore all 4 neighbors
//             for (auto dir : directions) {
//                 int nrow = row + dir.first;
//                 int ncol = col + dir.second;

//                 // Check bounds, same initial color, and not already recolored
//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                     ans[nrow][ncol] == iniColor) {
                    
//                     ans[nrow][ncol] = newColor;   // color the pixel
//                     q.push({nrow, ncol});         // add to queue for further expansion
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main() {
    vector<vector<int>> image{
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    
    // sr = 1, sc = 1, newColor = 2
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
    
    // Print result
    for(auto &row : ans){
        for(auto &pixel : row)
            cout << pixel << " ";
        cout << "\n";
    }
    return 0;
}
