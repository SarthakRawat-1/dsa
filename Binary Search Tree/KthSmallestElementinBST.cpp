// Problem Statement :- https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;         // Value of the node
    int size;        // Size of the subtree rooted at this node (for optimization)
    TreeNode* left;  // Pointer to the left child
    TreeNode* right; // Pointer to the right child

    // Constructors
    TreeNode() : val(0), size(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), size(1), left(left), right(right) {
        updateSize(); // Update size during initialization
    }

    // Update the size of the current node based on its children
    void updateSize() {
        size = 1 + (left ? left->size : 0) + (right ? right->size : 0);
    }
};

class Solution {
public:
    // Helper function for standard in-order traversal to find kth smallest
    void inorder(TreeNode* root, int& k, int& result) {
        if (!root) return; // Base case: null node

        inorder(root->left, k, result); // Traverse the left subtree

        k--; // Process the current node
        if (k == 0) {
            result = root->val; // Found kth smallest element
            return;
        }

        inorder(root->right, k, result); // Traverse the right subtree
    }

    // Function to find kth smallest using standard in-order traversal
    int kthSmallest(TreeNode* root, int k) {
        int result = -1; // To store the kth smallest element
        inorder(root, k, result); // Perform in-order traversal
        return result;
    }
};

// Function to insert a value into the BST and update size
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val); // Create a new node if root is null

    if (val < root->val) {
        root->left = insert(root->left, val); // Insert into the left subtree
    } else {
        root->right = insert(root->right, val); // Insert into the right subtree
    }

    root->updateSize(); // Update the size after insertion
    return root;
}

// Main function
int main() {
    // Example input: Construct the BST
    int arr[] = {5, 3, 6, 2, 4, 1};
    TreeNode* root = nullptr;

    // Insert elements into the BST
    for (int val : arr) {
        root = insert(root, val);
    }

    Solution solution;

    // Example 1: Standard in-order traversal approach
    int k = 3;
    cout << "Kth Smallest (Inorder): " << solution.kthSmallest(root, k) << endl;

    return 0;
}
