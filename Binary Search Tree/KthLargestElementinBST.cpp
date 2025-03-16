// Problem Statement :- https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// Again here also we can use inorder traversal, make a vector and find the kth largest element.
// If we don't want to use a vector, we can think in a different way.
// Inorder i.e. LNR gives answer in ascending order. So, RNL will give answer in descending order.
// This way, we can use a variable k initalized with the value of K, and everytime we visit a node (i.e. N in RNL) we will decrease it by 1.

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

void Klargest(Node* root, int& ans, int &K) {
    // Base case: If the current node is NULL, return immediately.
    if (!root) {
        return;
    }

    // Traverse the right subtree first to get the largest elements in descending order (RNL).
    Klargest(root->right, ans, K);

    // Decrement K for every node visited, as we're moving closer to the K-th largest element.
    K--;

    // If K becomes 0, we have reached the K-th largest element. Store its value in 'ans'.
    if (K == 0) {
        ans = root->data; // Capture the K-th largest element
    }

    // If K is less than or equal to 0, there's no need to traverse further.
    if (K <= 0) {
        return;
    }

    // Traverse the left subtree if K is still greater than 0, as we haven't found the K-th largest yet.
    Klargest(root->left, ans, K);
}

int kthLargest(Node* root, int K) {
    int ans;
    Klargest(root, ans, K); 

    return ans;
}

int main() {
    // Input array containing values to be inserted into the BST
    int arr[] = {6, 3, 17, 5, 11, 1, 2, 1, 20, 14};

    Node* root = NULL; // Initialize the root of the BST as NULL

    // Insert each element of the array into the BST
    for (int i = 0; i < 10; i++) {
        root = insert(root, arr[i]); // Call the insert function
    }

    // Find the K-th largest element in the BST
    int K = 4; // K is the number of the largest element we want to find
    cout << kthLargest(root, K);

    return 0; // Indicate successful program execution
}
