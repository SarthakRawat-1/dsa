#include <iostream> 
using namespace std;

// First part is searching for the element which is same as searchInBST.cpp
// After this, there can be three cases.
// First Case :- Leaf Node. If the node to be deleted is a leaf node, we can simply return NULL to it's parent node
// Second Case :- One Child. If the node to be deleted has only one child, we can simply return that child to it's parent node.
// Third Case :- Two Child. If the node to be deleted has two children, we need to replace the node to be deleted, with it 's that children, which will help remain the BST balanced.
// For eg :- Let's say 15 is deleted, it had two children 10 (it further has 7 and 12 (it also has 11 and 14 as child) as child) and 18 (it further has 17 and 19 as child), now 15 should be replaced with that children, which will ensure values to left of it will be smaller and values to right of it will be larger.
// But here's the thing, the node which will be replacement for 15, need not be it's immmediate children. It can be any node which is 15's descendant. in our case, 14 and 17 are valid candidates for replacement of 15.
// But how will we find these replacements? Consider 15 again, if we want to select a replacement from it's left side, we know that a valid replacement will be the node which is greatest in the left half (provided it is shorter than starting node of right half, in our case 18, which ofcourse it'll be as it's BST). This we can find, by going to the left half first, and then moving always towards the right children.
// Similarly if we want to find replacement from right side, we know that a valid replacement will be the node which is smallest in the right half (provided it is greater than the starting node of left half, in our case 10, which ofcourse it'll be as it's BST). This we can find, by going to the right half first, and then moving always towards the left children.
// You can use any one of the two methods to find the replacement.

// Note :- There can be an edge case for Third case. Consider we are using the first method i.e. finding replacement from left half. In this case, let's say we went to the node which is the rightmost. But this node, can also have a left child. So, we will have to send it's original parent, it's left child address and then use it as replacement.

// Note :- One more edge is left to handle for Third case. When the root node (to delete) and parent node (parent of replacement element) are same. In this case, if the replacement element has a child, then a branch will break off from the BST, as parent of replacement element has to point to child of replacment element but parent of replacement element is root element also, which means it already has other branch.
// For this case, we can simply ask replacement element to point to starting node of to other half of root node, then delete the element and replacement element replaces it.

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

Node *deleteNode(Node *root, int target) {
    // If the current node is NULL, the target is not found; return NULL
    if (!root) {
        return NULL;
    }

    // If target is smaller, search and delete in the left subtree
    if (root->data > target) {
        root->left = deleteNode(root->left, target); // Update left child after deletion
        return root;
    } 
    // If target is larger, search and delete in the right subtree
    else if (root->data < target) {
        root->right = deleteNode(root->right, target); // Update right child after deletion
        return root;
    } 
    // Current node is the node to delete
    else {
        // Case 1: Leaf Node (no children)
        if (!root->left && !root->right) {
            delete root;   // Free memory
            return NULL;   // Signal parent to remove reference
        }
        // Case 2: Node has only a right child
        else if (!root->left) {
            Node *temp = root->right; // Save right child
            delete root;              // Free current node
            return temp;              // Replace current node with right child
        }
        // Case 2: Node has only a left child
        else if (!root->right) {
            Node *temp = root->left; // Save left child
            delete root;             // Free current node
            return temp;             // Replace current node with left child
        }
        // Case 3: Node has two children
        else {
            // Find the in-order predecessor (max value in left subtree)
            Node *child = root->left;  // Start with left child
            Node *parent = root;       // Track parent of the predecessor

            // Traverse to the rightmost node (max in left subtree)
            while (child->right) {
                parent = child;
                child = child->right;
            }

            // If predecessor is not the immediate left child
            if (root != parent) {
                // Detach predecessor: parent's right adopts predecessor's left subtree
                parent->right = child->left;

                // Predecessor takes root's place
                child->left = root->left;   // Inherit root's left (excluding predecessor)
                child->right = root->right; // Inherit root's right

                delete root;   // Free the node to delete
                return child;  // Predecessor becomes the new subtree root
            } 
            // If predecessor is the immediate left child (no right subtree)
            else {
                // Predecessor (child) takes root's place
                child->right = root->right; // Inherit root's right subtree

                delete root;   // Free the node to delete
                return child;  // Predecessor becomes the new subtree root
            }
        }
        // Case 3 : Node has two children. Simplified approach
        // else {
        //     // Find the in-order predecessor (max value in the left subtree)
        //     Node* predecessor = root->left;
        //     while (predecessor->right) {
        //         predecessor = predecessor->right;
        //     }
        //     // Replace the value of the node to be deleted with the predecessor's value
        //     root->data = predecessor->data;
        //     // Delete the predecessor
        //     root->left = deleteNode(root->left, predecessor->data);
        //     return root;
        // }
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

    // Delete a value from the BST
    int target = 15; // The value to delete
    root = deleteNode(root, target); // Call the delete function

    return 0; // Indicate successful program execution
}
