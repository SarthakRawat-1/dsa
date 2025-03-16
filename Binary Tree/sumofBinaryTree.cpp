// Problem Statement :- https://www.geeksforgeeks.org/problems/sum-of-binary-tree/0

// Method 1 :- Traverse the Bianry tree and find the sum of nodes.
// Method 2 :- We will start from the root node and we will ask the sum of nodes present to the left of it and to the right of it. When we go to it's left child, we will ask the same question for that. Keep doing this for all other nodes. Ofc the node's data itself should also be counted when sending the sum of nodes to the node above it.

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
void Total(Node* root, long int &sum) {
    // Base case: If the current node is NULL, return to the previous call.
    // This indicates that a leaf node has been reached.
    if (root == NULL) {
        return;
    }

    // Increment the count for the current node.
    sum += root->data;

    // Recursively traverse the left subtree.
    Total(root->left, sum);

    // Recursively traverse the right subtree.
    Total(root->right, sum);
}

long int sumBT(Node* root) {
    long int sum = 0; // Initialize the sum to 0.

    // Call the Total function to calculate the sum of nodes in the binary tree.
    Total(root, sum);

    return sum; // Return the calculated sum.
}

// Method 2
long int sumBT(Node* root) {
    // Base case: If the current node is NULL, return to the previous call.
    // This indicates that a leaf node has been reached.
    if (root == NULL) {
        return 0;
    }

    // The sum of subtree rooted at current node is equal to the sum of its left subtree + sum of its right subtree + data of current node.
    return root->data + sumBT(root->left) + sumBT(root->right);
}


int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    cout << "Sum of nodes of the binary tree is :- "; 

    // Call the sumBT function to calculate the sum of nodes in the binary tree.
    cout << sumBT(root) << endl;

    return 0;
}