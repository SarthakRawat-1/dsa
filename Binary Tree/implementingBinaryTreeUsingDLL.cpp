// In implementingBinaryTreeUsingQueue.cpp, we created nodes of tree level wise. Here, we will first cascadingly create the left child nodes first (of all nodes, even as soon as we make a new node). 
// If we get -1 we won't create the node. Once we have finished making the left child for a parent (if we get -1 we don't have to make a node), we will then make the right child (if -1 is given there as well, then we won't create the right child).

// We will implement this using Doubly Linked List. If a number is not -1, we have to create the node, with the value of node as data and left and right pointers to store address of it's left and right child.
// First we have to fill the left pointers of each node (even those who are being created anew). Once we receive -1, we don;t have to create a node, so we can just store NULL in the pointer.
// Once the left pointer of a node becomes NULL (or if we came at a node which has already made it's left child, we have to now create it's right child), it means it doesn't have a left child, so now we can make it's right child depending on the value. 
// The child should return it's address to the parent.

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

int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    return 0;
}


