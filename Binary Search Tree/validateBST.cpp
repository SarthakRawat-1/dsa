// Problem Statement :- https://leetcode.com/problems/validate-binary-search-tree/description/

// We know that in a BST, for every node, all the nodes in the left subtree of that node should be smaller than it, and all the nodes in the right subtree of that node should be larger than it.

// One simple way to validate if a given tree is BST or not, is to find it's inorder traversal. If it's inorder traversal comes out to be ascending, the given tree is BST.
// For this, we can simply store the results of inorder traversal in a vector, and check if the vector is in ascending order.
// If we want to optimize this further, we can do it by not using vector. As, we have to check if vector is in ascending order or not, we have to simply compare each value with it's previous value during every iteration of traversal.

#include <iostream>
#include <limits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool BST(TreeNode* root, long& prev) {
        if (root == nullptr) {
            return true;
        }

        // Check left subtree
        if (!BST(root->left, prev)) {
            return false;
        }

        // Check current node value
        if (root->val <= prev) {
            return false;
        }

        // Update previous value
        prev = root->val;

        // Check right subtree
        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN; // Use LONG_MIN to handle edge cases
        return BST(root, prev);
    }

};

// Helper function to create a tree node
TreeNode* createNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(val, left, right);
}

int main() {
    // Create a sample binary tree
    // Example: 
    //      2
    //     / \
    //    1   3
    TreeNode* root = createNode(2, createNode(1), createNode(3));

    Solution solution;
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
