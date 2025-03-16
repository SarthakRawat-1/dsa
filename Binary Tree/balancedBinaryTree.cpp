// Problem Statement :- https://leetcode.com/problems/balanced-binary-tree/description/

#include <iostream>
#include <vector>
#include <queue>

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

    // Function to check if a binary tree is balanced.
    bool isBalanced(TreeNode* root) {
        // A tree is balanced if the height difference
        // between left and right subtrees is less than 2
        return dfsHeight(root) != -1;
    }

    // Helper function to calculate the height of the tree.
    int dfsHeight(TreeNode* root) {
        // Base case: if the current node is NULL,
        // the height of the subtree is 0.
        if (root == NULL) {
            return 0;
        }

        // Recursively calculate the height of the left subtree.
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced, propagate this information.
        if (leftHeight == -1) {
            return -1;
        }

        // Recursively calculate the height of the right subtree.
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced, propagate this information.
        if (rightHeight == -1) {
            return -1;
        }

        // Check if the current node is unbalanced.
        // If the height difference is greater than 1,
        // return -1 to indicate an unbalanced subtree.
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the height of the current subtree,
        // which is 1 + max height of its left and right subtrees.
        return max(leftHeight, rightHeight) + 1;
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

    cout << solution.isBalanced(root) << endl;

    return 0;
}