// Problem Statement :- https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

// This can be thought of as a extension of sizeofBinaryTree.cpp

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

// Method 1
void countLeaf(Node* root, int &count) {
    // Base case: If the current node is NULL, return to the previous call.
    if (!root) {
        return;
    }

    // Check if the current node is a leaf node.
    // A leaf node has no left or right child.
    if (!root->left && !root->right) {
        count++;  // Increment the count for the leaf node.
        return;  // Return to avoid further recursion.
    }

    // Recursively call the function for the left subtree.
    countLeaf(root->left, count);

    // Recursively call the function for the right subtree.
    countLeaf(root->right, count);
}

int countLeaves(Node* root) {
    int count = 0; // Initialize the count to 0.
    countLeaf(root, count); // Call the countLeaf function to count the leaves in the binary tree.

    return count; // Return the count of leaves.
}

// Method 2
int countLeaves(Node* root) {
    // Base case: If the current node is NULL, return 0.
    // This indicates there are no nodes in this subtree.
    if (!root) {
        return 0;
    }

    // Check if the current node is a leaf node.
    // A leaf node has no left or right child.
    if (!root->left && !root->right) {
        return 1;  // Return 1 for the leaf node.
    }

    // Recursively count leaf nodes in the left and right subtrees,
    // and return their sum.
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Create a binary tree by calling the BinaryTree function and store the root node in the root variable.
    Node* root = BinaryTree();

    // Call the countLeaves function to count the number of leaves in the binary tree and store the result in the count variable.
    int count = countLeaves(root);

    // Print the number of leaves in the binary tree.
    cout << "The number of leaves in the binary tree is " << count << endl;

    return 0;
}