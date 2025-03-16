// Problem Statement :- https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

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

// Function to find the floor of a given number X in the BST
int findFloor(Node* root, int X) {
    // Initialize the floor as -1 (assuming floor doesn't exist)
    int floor = -1;
    
    // Traverse the BST to find the floor
    while (root) {
        if (root->data == X) {
            // If current node's value is equal to X, then floor is X itself
            return root->data;
        }
        if (root->data < X) {
            // If current node's value is smaller than X, this node could be a candidate for floor
            floor = root->data;
            root = root->right; // Move to the right subtree to find a larger valid candidate
        } else {
            // If current node's value is larger than X, move to the left subtree
            root = root->left;
        }
    }
    
    return floor; // Return the closest candidate, which could be -1 if no floor found
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
    // Example 1: root = [2, 81, 42, 66, 45], X = 87
    Node* root = nullptr;
    root = insert(root, 2);
    root = insert(root, 81);
    root = insert(root, 42);
    root = insert(root, 66);
    root = insert(root, 45);

    int X1 = 87;
    cout << "Floor of " << X1 << " is: " << findFloor(root, X1) << endl;  // Expected output: 87
    
    // Example 2: root = [6, 8, 7, 9], X = 11
    root = nullptr;
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 9);

    int X2 = 11;
    cout << "Floor of " << X2 << " is: " << findFloor(root, X2) << endl;  // Expected output: 9
    
    // Example 3: root = [6, 8, 7, 9], X = 5
    root = nullptr;
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 9);

    int X3 = 5;
    cout << "Floor of " << X3 << " is: " << findFloor(root, X3) << endl;  // Expected output: -1
    
    return 0;
}
