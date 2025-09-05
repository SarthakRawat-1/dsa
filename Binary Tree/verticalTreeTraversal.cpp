// Problem Statement :- https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// First revise Top view of BT.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Step 1: Collect all nodes as tuples: (col, row, value)
        // col = horizontal distance, row = depth
        vector<tuple<int,int,int>> nodes;
        dfs(root, 0, 0, nodes);

        // Step 2: Sort by col, then row, then value
        //   - First key: col (left → right)
        //   - Second key: row (top → bottom)
        //   - Third key: val (ascending, to break ties)
        sort(nodes.begin(), nodes.end());

        // Step 3: Group values column by column
        vector<vector<int>> result;
        int prevCol = INT_MIN;  // track column changes

        for (auto& t : nodes) {
            int col, row, val;
            tie(col, row, val) = t;

            // If we encounter a new column, start a new vector
            if (col != prevCol) {
                result.emplace_back();
                prevCol = col;
            }
            // Add the current node's value to the last column group
            result.back().push_back(val);
        }

        return result;
    }

private:
    // DFS traversal to collect (col, row, value)
    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>>& nodes) {
        if (!node) return;

        // Store current node's position
        nodes.emplace_back(col, row, node->val);

        // Recurse left: row+1, col-1
        dfs(node->left, row + 1, col - 1, nodes);

        // Recurse right: row+1, col+1
        dfs(node->right, row + 1, col + 1, nodes);
    }
};

// Example usage
int main() {
    // Build example tree:
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.verticalTraversal(root);

    // Print the result
    cout << "Vertical Traversal:" << endl;
    for (auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// BFS approach
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Data structure to store nodes:
        //   nodes[x][y] = multiset of values at column x and row y
        // Why?
        //   - Outer map<int,...> keeps columns sorted left to right
        //   - Inner map<int,...> keeps rows sorted top to bottom
        //   - multiset<int> allows multiple nodes at same (x,y),
        //     and automatically keeps their values sorted
        map<int, map<int, multiset<int>>> nodes;

        // BFS queue: stores (node, (col, row))
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});  // root starts at column=0, row=0

        // Level-order traversal (BFS)
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   // column index
            int y = p.second.second;  // row index

            // Insert current node's value into the structure
            nodes[x][y].insert(node->val);

            // Traverse left child → column - 1, row + 1
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }

            // Traverse right child → column + 1, row + 1
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        // Build the result by collecting nodes column by column
        vector<vector<int>> ans;
        for (auto &colPair : nodes) {
            vector<int> col;
            // Traverse rows inside this column
            for (auto &rowPair : colPair.second) {
                // Add all values at (col,row) in sorted order
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(col); // push the finished column into result
        }

        return ans;
    }
};
