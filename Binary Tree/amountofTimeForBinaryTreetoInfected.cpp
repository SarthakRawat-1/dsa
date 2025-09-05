// Problem Statement :- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     * Convert the binary tree into an undirected graph
     * Each node is connected to its parent and children.
     */
    void convert(TreeNode* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) return;

        // Connect current node with its parent
        if (parent != -1) {
            adj[current->val].push_back(parent);
        }

        // Connect current node with its children
        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        } 
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }

        // Recursive calls for left and right child
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    /*
     * Perform BFS from the 'start' node to simulate infection spread
     */
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);  // Build adjacency list

        queue<int> que;
        que.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                // Traverse all neighbors
                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++; // Each BFS level = 1 minute
        }

        return minutes - 1; // Subtract 1 because last increment is extra
    }
};

/*
 * Helper function to build a simple test tree
 *
 * Example Tree:
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   5   6
 */
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    // Build sample tree
    TreeNode* root = buildTestTree();

    Solution sol;
    int start = 3;  // Infection starts from node 3
    int timeTaken = sol.amountOfTime(root, start);

    cout << "Amount of time to infect entire tree = " << timeTaken << " minutes" << endl;

    return 0;
}
