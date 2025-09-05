// Problem Statement :- https://leetcode.com/problems/count-complete-tree-nodes/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to calculate the height of the leftmost path
    int leftHeight(TreeNode* root) {
        if(!root)   // Base case: if root is null, height = 0
            return 0;
        
        int lh = 0;
        TreeNode* temp = root;
        while(temp) {         // Traverse only through left child nodes
            temp = temp->left;
            lh++;
        }
        return lh;            // Return the height of the leftmost path
    }

    // Function to calculate the height of the rightmost path
    int rightHeight(TreeNode* root) {
        if(!root)   // Base case: if root is null, height = 0
            return 0;
        
        int rh = 0;
        TreeNode* temp = root;
        while(temp) {         // Traverse only through right child nodes
            temp = temp->right;
            rh++;
        }
        return rh;            // Return the height of the rightmost path
    }

    // Function to count total number of nodes in a complete binary tree
    int countNodes(TreeNode* root) {
        if(!root)   // Base case: empty tree has 0 nodes
            return 0;
        
        // Compute leftmost and rightmost heights
        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // If both heights are equal, it's a perfect binary tree
        // Number of nodes in perfect binary tree of height h = (2^h - 1)
        if(lh == rh) {
            return pow(2, lh) - 1;
        }
        
        // Otherwise, recursively count nodes in left and right subtrees
        // and add 1 for the root
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Helper function to create a binary tree for testing
TreeNode* createTestTree() {
    /*
        Example Tree:
                 1
               /   \
              2     3
             / \   /
            4   5 6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}

int main() {
    // Create test tree
    TreeNode* root = createTestTree();
    
    Solution sol;
    int totalNodes = sol.countNodes(root);

    cout << "Total number of nodes in the complete binary tree: " 
         << totalNodes << endl;

    return 0;
}
