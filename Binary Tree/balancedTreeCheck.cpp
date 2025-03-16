// Problem Statement :- https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

// For every node, we will first find height of left and right subtrees. We will use a valid variable initialized with 1 to check if tree is balanced.
// Whener we find a node which is not balanced, we will simply assign 0 to valid indicating binary tree is not balanced.

#include <bits/stdc++.h>
using namespace std;

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

int height(Node* root, bool* valid) {
    if (root == NULL) {
        return 0; // Base case: Height of an empty tree is 0.
    }

    // Calculate the height of the left subtree.
    int lh = height(root->left, valid);

    // Check if the tree is already unbalanced. If yes, stop further processing.
    if (!(*valid)) return 0;

    // Calculate the height of the right subtree.
    int rh = height(root->right, valid);

    // Check the balance condition.
    if (abs(lh - rh) > 1) {
        *valid = 0; // Mark the tree as unbalanced.
    }

    // Return the height of the current node.
    return 1 + max(lh, rh);
}

// Function to determine if a binary tree is balanced.
bool isBalanced(Node* root) {
    bool valid = 1; // Variable to store whether the tree is balanced. Initialized to true (1).

    // Calculate the height of the tree and check for balance.
    height(root, &valid);

    // Return the value of `valid`. If `valid` is 1, the tree is balanced; otherwise, it is not.
    return valid;
}

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

int main() {
    Node* root1 = BinaryTree(); // Create the first binary tree using recursive input.

    // Check if the created binary tree is balanced.
    if (isBalanced(root1)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
