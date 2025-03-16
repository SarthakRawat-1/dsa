#include <iostream> 
using namespace std;

// Class definition for a node in the Binary Search Tree (BST)
class Node {
    public: 
    int data;        // Data value stored in the node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) {
        data = value;        // Set the node's data
        left = right = NULL; // Initialize both children as NULL
    }
};

// Function to insert a new value into the BST
Node* insert(Node* root, int target) {
    // If the root is NULL, create a new node and return it as the root
    if (root == NULL) {
        Node *temp = new Node(target); // Allocate memory for the new node
        return temp;
    }

    // If the target value is smaller than the current node's data,
    // insert it into the left subtree
    if (target < root->data) {
        root->left = insert(root->left, target);
    } 
    // Otherwise, insert it into the right subtree
    else {
        root->right = insert(root->right, target);
    }

    return root; // Return the root after insertion
}

// Function to perform in-order traversal of the BST
void inorder (Node *root) {
    if (root == NULL) {
        return; // Base case: If the node is NULL, return
    }

    // Recursively visit the left subtree
    inorder(root->left);

    // Print the value of the current node
    cout << root->data << " ";

    // Recursively visit the right subtree
    inorder(root->right);
}

int main() {
    // Input array containing values to be inserted into the BST
    int arr[] = {6, 3, 17, 5, 11, 1, 2, 1, 20, 14};

    Node* root = NULL; // Initialize the root of the BST as NULL

    // Insert each element of the array into the BST
    for (int i = 0; i < 10; i++) {
        root = insert(root, arr[i]); // Call the insert function
    }

    // Perform in-order traversal of the BST and print the elements
    // In-order traversal will print the elements in sorted order
    inorder(root);

    return 0; // Indicate successful program execution
}
