// Problem Statement :- https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/0

// This can be thought of as a extension of countLeavesinBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;

// Define a Node class to represent each node in the binary tree.
class Node {
    public:
    int data;        // Stores the value of the node.
    Node* left;      // Pointer to the left child of the node.
    Node* right;     // Pointer to the right child of the node.

    // Constructor to initialize a node with a given value.
    Node (int value) {
        data = value;
        left = right = NULL; // Initially, left and right children are set to NULL.
    }
};

// Function to create a binary tree using recursive input.
Node* BinaryTree() {
    int x; 
    cin >> x; // Input the value for the current node.

    // Base case: If the input is -1, do not create a node; return NULL.
    if (x == -1) {
        return NULL;
    }

    // Create a new node with the input value.
    Node* temp = new Node(x);

    // Prompt the user to enter the left child for the current node.
    cout << "Enter the left child of " << x << " :- ";
    // Recursively create the left subtree. If -1 is input, the left pointer will remain NULL.
    temp->left = BinaryTree();

    // Prompt the user to enter the right child for the current node.
    cout << "Enter the right child of " << x << " :- ";
    // Recursively create the right subtree. If -1 is input, the right pointer will remain NULL.
    temp->right = BinaryTree();
    
    // Return the address of the created node to be connected to its parent.
    return temp;
}

int countNonLeafNodes(Node* root) {
    if (root == NULL) return 0; // Base case: If the root is NULL, return 0 as there are no non-leaf nodes in an empty tree.

    // Check if the current node is a leaf node.
    if (root->left == NULL && root->right == NULL) {
        return 0; // If both left and right children are NULL, it's a leaf node, so return 0.
    }

    // Recursively count non-leaf nodes in the left and right subtrees.
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main() {
    // Create a binary tree by calling the BinaryTree function and store the root node in the root variable.
    Node* root = BinaryTree();

    int count = countNonLeafNodes(root);

    // Print the number of non leaf nodes in the binary tree.
    cout << "The number of non leaf nodes in the binary tree is " << count << endl;

    return 0;
}