// Problem Statement :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;                // Node's value.
    TreeNode *left;         // Pointer to left child.
    TreeNode *right;        // Pointer to right child.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor with value.
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Full constructor.
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // 'curr' is used to traverse the tree.
        TreeNode* curr = root;
        
        // Traverse the tree until we have processed all nodes.
        while (curr != nullptr) {
            // If the current node has a left subtree, we need to rewire connections.
            if (curr->left != nullptr) {
                // Find the rightmost node in the left subtree.
                // This node is the predecessor in pre-order traversal.
                TreeNode* predecessor = curr->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                
                // Connect the original right subtree to the rightmost node.
                // This ensures that the right subtree comes after the left subtree in the flattened list.
                predecessor->right = curr->right;
                
                // Move the left subtree to the right.
                // In the flattened tree, the left child should always be null.
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move on to the next node (which is now at curr->right).
            curr = curr->right;
        }
    }
};

int main() {

}
