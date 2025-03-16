// Problem Statement :- https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class for level order traversal.
class Solution {
    public:

    // Function to check if two binary trees are identical.
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        // Base case: If both nodes are NULL, the trees are identical.
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        
        // If only one of the nodes is NULL, the trees are not identical.
        if (node1 == NULL || node2 == NULL) {
            return false;
        }
        
        // Recursive case: Check if the current nodes have the same value
        // and their left and right subtrees are also identical.
        return (
            (node1->val == node2->val) &&                      // Check current node values.
            isSameTree(node1->left, node2->left) &&             // Recursively check left subtrees.
            isSameTree(node1->right, node2->right)              // Recursively check right subtrees.
        );
    }
};

// Utility function to insert nodes in a binary tree (for testing)
TreeNode* buildTree(vector<int> nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);

    return root;
}

// Utility function to print the level order result
void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> treeNodes = {3, 9, 20, -1, -1, 15, 7};

    TreeNode* root = buildTree(treeNodes, 0);

    Solution solution;

    cout << solution.isSameTree(root, root) << endl;

    return 0;
}