// Problem Statement :- https://leetcode.com/problems/symmetric-tree/description/

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

    bool isMirror(TreeNode* node1, TreeNode* node2) {
        // Base case: If both nodes are NULL, they are symmetric at this point.
        if (node1 == NULL && node2 == NULL) {
            return true;
        }

        // If only one of the nodes is NULL, they are not symmetric.
        if (node1 == NULL || node2 == NULL) {
            return false;
        }

        // Recursive case: 
        // 1. Current node values must match.
        // 2. Left child of node1 must mirror right child of node2.
        // 3. Right child of node1 must mirror left child of node2.
        return (
            (node1->val == node2->val) &&
            isMirror(node1->left, node2->right) &&
            isMirror(node1->right, node2->left)
        );
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true; // An empty tree is symmetric.
        }
        return isMirror(root->left, root->right);
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

    cout << solution.isSymmetric(root) << endl;

    return 0;
}