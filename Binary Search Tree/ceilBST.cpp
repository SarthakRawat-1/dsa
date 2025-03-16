// Problem Statement :- https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find the ceil of a given number X in the BST
int findCeil(Node* root, int X) {
    // Initialize the ceil as -1 (assuming ceil doesn't exist)
    int ceil = -1;
    
    // Traverse the BST to find the ceil
    while (root) {
        if (root->data == X) {
            // If current node's value is equal to X, then ceil is X itself
            return root->data;
        }
        if (root->data > X) {
            // If current node's value is greater than X, this node could be a candidate for ceil
            ceil = root->data;
            root = root->left; // Move to the left subtree to find a smaller valid candidate
        } else {
            // If current node's value is less than X, move to the right subtree
            root = root->right;
        }
    }
    
    return ceil; // Return the closest candidate, which could be -1 if no ceil found
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    // Example 1: root = [5, 4, 6, 3, N, N, 7, 1], X = 3
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 7);
    
    int X1 = 3;
    cout << "Ceil of " << X1 << " is: " << findCeil(root, X1) << endl;  // Expected output: 3
    
    // Example 2: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6
    root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 8);
    
    int X2 = 6;
    cout << "Ceil of " << X2 << " is: " << findCeil(root, X2) << endl;  // Expected output: 7
    
    return 0;
}
