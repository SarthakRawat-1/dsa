// Problem Statement :- https://www.geeksforgeeks.org/problems/size-of-binary-tree/0

// Method 1 :- Just traverse the binary tree and count the number of nodes present in it. 
// Method 2 :- We will start from the root node and we will ask the number of nodes present to the left of it and to the right of it. When we go to it's left child, we will ask the same question for that. Keep doing this for all other nodes. Ofc the node itself should also be counted when sending the number of nodes to the node above it.

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
void Total(Node* root, int &count) {
    // Base case: If the current node is NULL, return to the previous call.
    // This indicates that a leaf node has been reached.
    if (root == NULL) {
        return;
    }

    // Increment the count for the current node.
    count++;

    // Recursively traverse the left subtree.
    Total(root->left, count);

    // Recursively traverse the right subtree.
    Total(root->right, count);
}

int getSize(Node* root) {
    int count = 0; // Initialize the count to 0.

    Total(root, count); // Call the Total function to count the number of nodes in the binary tree.

    return count; // Return the count, which represents the size of the binary tree.
}

// Method 2
int getSize(Node* root) {
    // Base case: If the current node is NULL, return 0.
    // This indicates there are no nodes in this subtree.
    if (root == NULL) {
        return 0;
    }

    // The size of the subtree rooted at the current node is:
    // 1 (for the current node itself) + size of the left subtree + size of the right subtree.
    return (1 + getSize(root->left) + getSize(root->right));
}


int main() {
    // Call the BinaryTree function to create the binary tree starting from the root node.
    Node* root = BinaryTree();

    // Get the size of the binary tree and print it.
    cout << "The size of the binary tree is " << getSize(root) << endl;

    return 0;
}