// Problem Statement :-

// Use a boolean flag or step counter to determine whether to include a cell in result or not. 

#include <bits/stdc++.h>
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>>& grid) {
    // Initialize the answer vector to store the zigzag traversal.
    vector<int> ans;

    // Get the dimensions of the grid.
    int n = grid.size();    // Number of rows in the grid.
    int m = grid[0].size(); // Number of columns in the grid.

    // Initialize row and column pointers.
    int row = 0, col = 0;

    // Flags to control traversal direction.
    bool flag = true;   // Controls whether to add the current element to the answer.
    bool left = true;   // If true, move rightward; if false, move leftward.
    bool right = false; // Redundant, could be removed as it is unused.

    // Iterate while row and column indices are within grid bounds.
    while (row < n && col < m) {
        // If the flag is true, add the current element to the answer vector.
        if (flag) {
            ans.push_back(grid[row][col]);
            flag = false; // Toggle flag after adding an element.
        } else {
            flag = true;  // Toggle flag for the next iteration.
        }

        // Handle movement when traversing left to right.
        if (left) {
            if (col == m - 1) { // If at the last column, move to the next row.
                row++;
                left = false;   // Switch direction to right-to-left.
            } else {
                col++;          // Move to the next column.
            }
        } 
        // Handle movement when traversing right to left.
        else {
            if (col == 0) {     // If at the first column, move to the next row.
                row++;
                left = true;    // Switch direction to left-to-right.
            } else {
                col--;          // Move to the previous column.
            }
        }
    }

    // Return the result of the zigzag traversal.
    return ans;
}

// Optimized Approach
vector<int> zigzagTraversal(vector<vector<int>>& grid) 
{
    // Initialize the answer vector to store the zigzag traversal.
    vector<int> ans;

    // Outer loop to iterate over each row of the grid.
    for (int r = 0; r < grid.size(); r++) 
    {
        // Check if the row index is even.
        if (r % 2 == 0) 
        {
            // Traverse left-to-right for even-indexed rows.
            for (int c = 0; c < grid[0].size(); c++) 
            {
                // Check if the column index is even.
                if (c % 2 == 0) 
                {
                    ans.push_back(grid[r][c]); // Add the element to the result.
                    // Note: Instead of incrementing `c` by 1, we could optimize using `c += 2` to directly skip odd-indexed columns.
                }
            }
        } 
        else 
        {
            // Traverse right-to-left for odd-indexed rows.
            for (int c = grid[0].size() - 1; c >= 0; c--) 
            {
                // Check if the column index is odd.
                if (c % 2 == 1) 
                {
                    ans.push_back(grid[r][c]); // Add the element to the result.
                    // Note: Another approach could calculate the starting element for odd-indexed rows (e.g., the last odd column) to optimize traversal.
                }
            }
        }
    }

    // Return the zigzag traversal result.
    return ans;
}


int main() {
    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> ans = zigzagTraversal(grid);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}