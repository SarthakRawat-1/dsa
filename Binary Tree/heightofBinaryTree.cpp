// Problem Statement :- https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

// The farthest node is always going to be a leaf node. So we will first find the leaf nodes and then calculate height for all of them. The max of them will be our answer. 
// For every node, we can ask the maximum height on the left side of it and on the right side of it. Ofc, for the node itself, we will add 1 as it's height.

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

int height(Node* root) {
    // Base case: If the root is NULL, return 0 as the height of an empty tree is 0.
    if (root == NULL) {
        return 0;
    }

    // 1 is the height of node itself. We will add this with the maximum height found, which can be on right or left of that node.
    return 1 + max(height(root->left), height(root->right));
}


int main() {
    // Call the BinaryTree function to create the binary tree starting from the root node.
    Node* root = BinaryTree();

    // Get the height of the binary tree and print it.
    cout << "The height of the binary tree is " << height(root) << endl;

    return 0;
}


// Problem Statement :- https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum depth of the binary tree
int maxDepth(TreeNode* root) {
    // Base case: If the node is null, the depth is 0
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate the depth of the left and right subtrees
    int leftDepth = maxDepth(root->left);   // Depth of the left subtree
    int rightDepth = maxDepth(root->right); // Depth of the right subtree

    // The depth of the current node is 1 + the maximum of leftDepth and rightDepth
    return 1 + max(leftDepth, rightDepth);
}

// Helper function to create a binary tree and test maxDepth
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate the maximum depth of the binary tree
    int depth = maxDepth(root);

    // Print the result
    cout << "Maximum Depth of the Binary Tree: " << depth << endl;

    return 0;
}
