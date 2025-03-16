// Problem Statement :- https://www.geeksforgeeks.org/problems/mirror-tree/1

// We will start from root node. We will swap the left and right child. 
// This becomes trivial with recursion, as whenever we will encounter a new node, we will swap it's left and right child.
// Note that we only need to swap the left and right child not left and right half. This is because the left and right child will take their own child with them even after swapping as they are stored in left and right pointers.

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

// Function to convert a binary tree into its mirror.
void mirror(Node* root) {
    // Base case: If the current node is NULL, there's nothing to mirror, so return.
    if (!root) {
        return;
    }

    // Step 1: Temporarily store the left child of the current node.
    Node* temp = root->left;

    // Step 2: Assign the right child of the current node to its left pointer.
    root->left = root->right;

    // Step 3: Assign the stored left child (from Step 1) to the right pointer of the current node.
    root->right = temp;

    // Step 4: Recursively apply the same logic to the left subtree.
    mirror(root->left);

    // Step 5: Recursively apply the same logic to the right subtree.
    mirror(root->right);
    // After the recursion completes, all nodes of the tree will have their left and right children swapped.
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

    // Mirror the first binary tree.
    mirror(root1);

    return 0;
}

