// Problem Statement :- https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

// Again, we will find inorder traversal of the BST. Then we can simply compare the difference of each value with the immediate next value in traversal. Thus, we can find the minimum difference.

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
    void minDist(TreeNode* root, int& prev, int& ans) {
        // Base case: If the current node is null, return.
        if (root == nullptr) {
            return;
        }

        // Recursively traverse the left subtree (in-order traversal).
        minDist(root->left, prev, ans);

        // If 'prev' is not the sentinel value (INT_MIN), compute the difference
        // between the current node's value and the previous node's value.
        if (prev != INT_MIN) {
            ans = min(ans, root->val - prev);
        }

        // Update 'prev' to the current node's value for the next comparison.
        prev = root->val;

        // Recursively traverse the right subtree (in-order traversal).
        minDist(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        // Initialize 'prev' to INT_MIN to indicate no previous node initially.
        int prev = INT_MIN;

        // Initialize 'ans' to INT_MAX to track the minimum difference.
        int ans = INT_MAX;

        // Call the helper function to perform in-order traversal and compute the result.
        minDist(root, prev, ans);

        // Return the minimum difference found.
        return ans;
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

    // Calculate and print the minimum distance between BST nodes
    cout << "Minimum distance between BST nodes: " << solution.minDiffInBST(root) << endl;
    
    return 0;
}
