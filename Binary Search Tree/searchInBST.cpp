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

// Function to search for a target value in the BST
bool search(Node* root, int target) {
    // Base case: If the root is NULL, the target is not found in the tree
    if (root == NULL) {
        return false;
    }

    // If the current node's data matches the target, return true
    if (root->data == target) {
        return true;
    }

    // If the target is smaller than the current node's data,
    // search in the left subtree
    if (root->data > target) {
        return search(root->left, target);
    } 
    // Otherwise, search in the right subtree
    else {
        return search(root->right, target);
    }
}

int main() {
    // Input array containing values to be inserted into the BST
    int arr[] = {6, 3, 17, 5, 11, 1, 2, 1, 20, 14};

    Node* root = NULL; // Initialize the root of the BST as NULL

    // Insert each element of the array into the BST
    for (int i = 0; i < 10; i++) {
        root = insert(root, arr[i]); // Call the insert function
    }

    cout << search(root, 11);

    return 0; // Indicate successful program execution
}
