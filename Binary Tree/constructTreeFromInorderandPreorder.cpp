// Problem Statement :- https://www.geeksforgeeks.org/problems/construct-tree-1/1\
// Problem Statement :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// We can't create a unique tree if Postorder and Preorder traversal are given.
// For creating a unique tree, we need inorder traversal with preorder/postorder traversal. Also, all elements of the tree should be unique.
// This is because in inorder traversal, for a specific node, all the nodes to it's left will also be present in the left of inorder traversal and all the nodes to it's right will also be present in the right of inorder traversal respect to position of that node in inorder traversal.
// From Preorder, we can easily find the root element of Binary Tree, as the first element in Preorder traversal will be the root node of binary tree (topmost node).
// Now, using this we can find this element in inorder traversal, all the elements to the left of it in inorder traversal will come in it's left subtree.
// Let's say for a node, we find multiple elements who will go to it's left and multiple who go to it's right. To determine which will be the root of left subtree and right subtree, we can again use preorder traversal and find the leftmost element out of those sets of elements. They will be the root nodes of left and right subtree.
// Or we can say it differently. We will keep looing the preorder traversal, even after getting two sets of element for left and right subtree. Then the next element encountered in preorder traversal, we will find it is present in which set. On the basis of that it will become the root node of that part.
// We will do this recursively.

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------------------------------------
// Node structure for a binary tree node.
// Each node stores an integer value and has pointers to its left and right children.
struct Node {
    int data;      // The value stored in the node
    Node* left;    // Pointer to the left child (subtree)
    Node* right;   // Pointer to the right child (subtree)
    
    // Constructor to initialize a node with a given value.
    // The left and right pointers are initialized to NULL.
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//------------------------------------------------------------------------------
// Function: find
// Purpose: To locate the index of a given value in the inorder array between indices 'is' and 'ie'.
// Parameters:
//    - in[]: The inorder traversal array.
//    - val: The value to search for in the array.
//    - is: The starting index in the inorder array for the search.
//    - ie: The ending index in the inorder array for the search.
// Returns:
//    - The index at which 'val' is found within the range [is, ie].
//    - Returns -1 if the value is not found (though for valid input, this should not occur).
int find(int in[], int val, int is, int ie) {
    // Iterate over the segment of the array from index 'is' to 'ie'
    for (int i = is; i <= ie; i++) {
        // If the current element matches the value we're looking for, return its index
        if (in[i] == val) {
            return i;
        }
    }
    // Return -1 if the value is not found in the provided segment (safeguard)
    return -1;
}

//------------------------------------------------------------------------------
// Function: Tree
// Purpose: Recursively constructs the binary tree using inorder and preorder traversal arrays.
// Parameters:
//    - in[]: The inorder traversal array.
//    - pre[]: The preorder traversal array.
//    - is: Starting index of the current segment in the inorder array.
//    - ie: Ending index of the current segment in the inorder array.
//    - ps: The current index in the preorder array, representing the root of the subtree.
// Returns:
//    - A pointer to the root node of the constructed binary subtree.
Node* Tree(int in[], int pre[], int is, int ie, int ps) {
    // Base case: if the current inorder segment is empty, return NULL (no node to construct)
    if (is > ie) {
        return NULL;
    }

    // Create a new node with the current value from preorder traversal.
    // In preorder, the first element is always the root of the subtree.
    Node* root = new Node(pre[ps]);

    // Find the position of the current root in the inorder traversal.
    // This position divides the inorder array into left and right subtrees.
    int pos = find(in, pre[ps], is, ie);

    // Recursively build the left subtree.
    // In the inorder array, the left subtree elements are from index 'is' to 'pos - 1'.
    // In the preorder array, the next element (ps + 1) is the root of the left subtree.
    root->left = Tree(in, pre, is, pos - 1, ps + 1);

    // Recursively build the right subtree.
    // In the inorder array, the right subtree elements are from index 'pos + 1' to 'ie'.
    // To calculate the starting index in preorder for the right subtree:
    //    - Number of nodes in the left subtree = pos - is.
    //    - Therefore, the root of the right subtree is at index: ps + (pos - is) + 1.
    root->right = Tree(in, pre, pos + 1, ie, ps + pos - is + 1);

    // Return the current root, which now has its left and right subtrees attached.
    return root;
}

//------------------------------------------------------------------------------
// Function: buildTree
// Purpose: Serves as the interface to build the binary tree from inorder and preorder arrays.
// Parameters:
//    - in[]: The inorder traversal array.
//    - pre[]: The preorder traversal array.
//    - n: The number of nodes in the tree (size of the arrays).
// Returns:
//    - A pointer to the root of the reconstructed binary tree.
Node* buildTree(int in[], int pre[], int n) {
    // Initially, the entire inorder array (0 to n-1) and the first element of preorder (index 0)
//   are used to start building the tree.
    return Tree(in, pre, 0, n - 1, 0);
}

int main() {

    int in[] = {4, 2, 5, 1, 6, 3};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, n);

    return 0;
}
