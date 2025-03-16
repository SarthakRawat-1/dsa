// Problem Statement :- https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
// Problem Statement :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// This is very similar to building a tree from inorder and preorder traversals.
// For Postorder traversal, instead of leftmost node being the root node (of tree or of subtrees), the rightmost node will become the root node.
// Rest of the procedure will be quite similar but remember as we are looking for rightmost element, that logic will change accordingly for other statements as well.

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------
// Definition of the Node structure for a binary tree.
// Each node contains an integer value and pointers to its left and right children.
struct Node {
    int data;      // Stores the value of the node.
    Node* left;    // Pointer to the left subtree.
    Node* right;   // Pointer to the right subtree.
    
    // Constructor to initialize a new node with the provided value.
    // Both left and right pointers are initialized to NULL.
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//------------------------------------------------------------------------------
// Utility function to find the index of a given value in the inorder array.
// Parameters:
//   in[] - The inorder traversal array.
//   val  - The value to search for in the inorder array.
//   is   - The starting index (inclusive) of the current subtree in the inorder array.
//   ie   - The ending index (inclusive) of the current subtree in the inorder array.
// Returns:
//   The index of 'val' in the array if found, otherwise returns -1.
int find(int in[], int val, int is, int ie) {
    for (int i = is; i <= ie; i++) {
        if (in[i] == val) {
            return i;  // Return the index when the value is found.
        }
    }
    // In a valid tree, this situation should not occur.
    return -1;
}

//------------------------------------------------------------------------------
// Recursive function to construct a binary tree from inorder and postorder traversals.
// Parameters:
//   in[]   - The inorder traversal array.
//   post[] - The postorder traversal array.
//   is     - The starting index (inclusive) for the current subtree in the inorder array.
//   ie     - The ending index (inclusive) for the current subtree in the inorder array.
//   ps     - The current index in the postorder array which represents the root of the subtree.
// Returns:
//   A pointer to the root node of the constructed subtree.
Node* Tree(int in[], int post[], int is, int ie, int ps) {
    // Base case: if the current inorder range is invalid, return NULL.
    if (is > ie) {
        return NULL;
    }
    
    // Create a new node with the current root value taken from postorder[ps].
    // For postorder traversal, the last element (rightmost) is the root of the current subtree.
    Node* root = new Node(post[ps]);
    
    // Locate the position of the current root in the inorder array.
    // This divides the inorder array into left and right subtrees.
    int pos = find(in, post[ps], is, ie);
    
    // Recursively construct the right subtree.
    // In postorder, the right subtree comes before the left subtree.
    // The new postorder index for the right subtree is (ps - 1).
    // The inorder indices for the right subtree are from (pos + 1) to ie.
    root->right = Tree(in, post, pos + 1, ie, ps - 1);
    
    // Recursively construct the left subtree.
    // To compute the new postorder index for the left subtree, subtract the number of nodes in the right subtree.
    // Number of nodes in the right subtree = (ie - pos)
    // Therefore, the new index for the left subtree becomes: ps - (ie - pos) - 1.
    root->left = Tree(in, post, is, pos - 1, ps - ie + pos - 1);
    
    // Return the constructed subtree rooted at 'root'.
    return root;
}

//------------------------------------------------------------------------------
// Function to build the entire binary tree using inorder and postorder traversals.
// Parameters:
//   in[]   - The inorder traversal array.
//   post[] - The postorder traversal array.
//   n      - The number of nodes in the tree.
// Returns:
//   A pointer to the root node of the constructed binary tree.
Node* buildTree(int in[], int post[], int n) {
    // Start the recursive tree construction.
    // The initial call uses the full range of the inorder array (0 to n-1)
    // and the last index of the postorder array (n-1) as the root.
    return Tree(in, post, 0, n - 1, n - 1);
}

int main() {
    // Example inorder and postorder arrays.
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {4, 8, 5, 2, 6, 7, 3, 1};
    
    // Calculate the number of nodes in the tree.
    int n = sizeof(in) / sizeof(in[0]);
    
    // Build the tree using the provided inorder and postorder arrays.
    Node* root = buildTree(in, post, n);

    return 0;
}
