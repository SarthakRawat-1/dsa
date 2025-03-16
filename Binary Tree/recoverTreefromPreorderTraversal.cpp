// Problem Statement :- https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

// 

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructor to initialize a node with a given value.
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    // Total length of the traversal string. This variable is used globally within the class.
    int n;

    // Helper function to recursively build the tree.
    // Parameters:
    // - traversal: The preorder traversal string containing digits and dashes.
    // - i: The current index in the string (passed by reference so that updates propagate to recursive calls).
    // - depth: The expected depth (level) of the node to be created in this call.
    //
    // Returns:
    // - A pointer to the constructed TreeNode, or NULL if the expected node isn't present.
    TreeNode* solve(const string& traversal, int& i, int depth) {
        // If we've reached the end of the string, there's nothing left to process.
        if (i >= n)
            return NULL;

        // j will be used to count the number of consecutive '-' characters,
        // which indicate the depth (level) of the next node in the tree.
        int j = i;
        while (j < n && traversal[j] == '-') {
            j++;
        }
        
        // The number of dashes (i.e., depth indicator) is calculated by the difference.
        int dash = j - i;

        // If the number of dashes does not match the expected depth, 
        // then this part of the string does not belong to the current subtree.
        if (depth != dash) {
            return NULL;
        }

        // Move the index past the dashes to the start of the node's numeric value.
        i += dash;

        // Parse the numeric value for the current node.
        int value = 0;
        while (i < n && isdigit(traversal[i])) {
            value = value * 10 + (traversal[i] - '0');  // Construct the integer value digit by digit.
            i++;
        }

        // Create a new TreeNode with the parsed value.
        TreeNode* root = new TreeNode(value);

        // Recursively attempt to build the left subtree.
        // The left child is always at the next depth level (depth + 1).
        root->left = solve(traversal, i, depth + 1);

        // Recursively attempt to build the right subtree.
        // The right child is also expected at depth + 1.
        root->right = solve(traversal, i, depth + 1);

        // Return the constructed subtree rooted at 'root'.
        return root;
    }

    // Main function to recover the binary tree from the preorder traversal string.
    // It initializes the necessary variables and kicks off the recursive tree construction.
    TreeNode* recoverFromPreorder(string traversal) {
        // Record the total length of the input string.
        n = traversal.length();
        // Initialize the starting index for the recursive calls.
        int i = 0;
        // Start the recursion with an expected depth of 0 (root level).
        return solve(traversal, i, 0);
    }
};
    
// Helper function to print the tree in a structured way (pre-order with indentation).
void printTree(TreeNode* root, int depth = 0) {
    if (root == NULL)
        return;
    // Print indentation based on the current depth.
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    cout << root->val << "\n";
    // Recursively print the left and right subtrees.
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

int main() {
    // Example traversal string.
    // This represents the tree: 
    //       1
    //      / \
    //     2   5
    //    / \  / \
    //   3   4 6  7
    string traversal = "1-2--3--4-5--6--7";
    
    // Create a Solution object.
    Solution solution;
    
    // Recover the tree from the given traversal string.
    TreeNode* root = solution.recoverFromPreorder(traversal);
    
    // Print the recovered tree.
    cout << "Recovered Tree (Pre-order with indentation):\n";
    printTree(root);
    
    // Note: In a complete application, you should free the allocated memory for the tree nodes.
    // For simplicity, memory deallocation is omitted here.
    
    return 0;
}