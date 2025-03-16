// Problem Statement :- https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

// Start from root node. Check if root node of both trees are equal. If they are, then check if left half of both trees is equal. After that check if right half of both trees is equal.
// This becomes trivial with recursion, as whenever we will encounter a new node, we will check the same for it's left and right half.

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

// Function to check if two binary trees are identical.
bool isIdentical(Node* r1, Node* r2) {
    // Base case: If both nodes are NULL, they are identical (empty trees).
    if (r1 == NULL && r2 == NULL) {
        return true; // Both trees are empty at this point.
    }

    // If one node is NULL and the other is not, the trees are not identical.
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) {
        return false; // Mismatch in structure detected.
    }

    // If the data at the current nodes does not match, the trees are not identical.
    if (r1->data != r2->data) {
        return false; // Values differ, so trees are not identical.
    }

    // Recursively check the left subtrees and right subtrees of the current nodes.
    // Both left and right subtrees must be identical for the entire trees to be identical.
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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
    Node* root2 = BinaryTree(); // Create the second binary tree using recursive input.

    // Check if the two binary trees are identical.
    if (isIdentical(root1, root2)) {
        cout << "The two trees are identical." << endl;
    } else {
        cout << "The two trees are not identical." << endl;
    }
}