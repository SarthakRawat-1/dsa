#include <bits/stdc++.h>
using namespace std;

//----------------------------
// Definition of the Node class
//----------------------------
class Node {
public:
    int data;       // The value stored in the node.
    int height;     // The height of the node in the AVL tree.
    Node *left;     // Pointer to the left child.
    Node *right;    // Pointer to the right child.

    // Constructor to initialize a new node with the given value.
    // By default, a new node has height 1 (leaf node) and no children.
    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

//----------------------------
// Utility function: getheight
//----------------------------
// Returns the height of the given node.
// If the node is NULL (i.e., no node), it returns 0.
int getheight(Node* root) {
    if (!root) {
        return 0;
    }
    return root->height;
}

//----------------------------
// Utility function: getbalance
//----------------------------
// Computes and returns the balance factor of the node.
// Balance factor is defined as the difference between the height of the left subtree and the right subtree.
// A positive value indicates left-heavy, a negative value indicates right-heavy.
int getbalance(Node* root) {
    return getheight(root->left) - getheight(root->right);
}

//----------------------------
// Function: rightRotation
//----------------------------
// Performs a right rotation on the subtree rooted with 'root'.
// Right rotation is used to rebalance a left-heavy subtree.
// Steps:
//   1. Let 'child' be the left child of the current root.
//   2. Temporarily store 'child's right subtree (childRight).
//   3. Make the current root the right child of 'child'.
//   4. Attach 'childRight' as the left subtree of the current root.
//   5. Update heights of both 'root' and 'child'.
//   6. Return the new root of this subtree (which is 'child').
Node* rightRotation(Node* root) {
    Node* child = root->left;         // The left child becomes the new root.
    Node* childRight = child->right;    // Temporarily hold the right subtree of child.

    child->right = root;              // Make the old root a right child of child.
    root->left = childRight;          // Attach the stored subtree as the left child of the old root.

    // Update heights: height is 1 plus the maximum height of the two children.
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;                     // New root of the rotated subtree.
}

//----------------------------
// Function: leftRotation
//----------------------------
// Performs a left rotation on the subtree rooted with 'root'.
// Left rotation is used to rebalance a right-heavy subtree.
// Steps:
//   1. Let 'child' be the right child of the current root.
//   2. Temporarily store 'child's left subtree (childLeft).
//   3. Make the current root the left child of 'child'.
//   4. Attach 'childLeft' as the right subtree of the current root.
//   5. Update heights of both 'root' and 'child'.
//   6. Return the new root of this subtree (which is 'child').
Node* leftRotation(Node* root) {
    Node* child = root->right;        // The right child becomes the new root.
    Node* childLeft = child->left;      // Temporarily hold the left subtree of child.

    child->left = root;               // Make the old root a left child of child.
    root->right = childLeft;          // Attach the stored subtree as the right child of the old root.

    // Update heights: height is 1 plus the maximum height of the two children.
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));

    return child;                     // New root of the rotated subtree.
}

//----------------------------
// Function: insert
//----------------------------
// Recursively inserts a new key into the AVL tree rooted at 'root'.
// After the standard BST insertion, the function checks for any imbalance and performs rotations if needed.
// Steps:
//   1. If the current node is NULL, create and return a new node with the key.
//   2. If key is less than current node's data, insert it into the left subtree.
//   3. If key is greater than current node's data, insert it into the right subtree.
//   4. If key already exists, do nothing (avoid duplicates) and return the current node.
//   5. Update the height of the current node.
//   6. Compute the balance factor to check if the node has become unbalanced.
//   7. If unbalanced, there are four cases to consider and apply the appropriate rotation:
//         a) Left Left Case: Perform a right rotation.
//         b) Right Right Case: Perform a left rotation.
//         c) Left Right Case: Perform a left rotation on the left child, then a right rotation on the current node.
//         d) Right Left Case: Perform a right rotation on the right child, then a left rotation on the current node.
//   8. Return the node pointer (which might be updated after rotations).
Node* insert(Node* root, int key) {
    // Standard BST insertion
    if (!root) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed in this AVL tree.
        return root;
    }
    
    // Update the height of the ancestor node.
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Calculate the balance factor to check whether this node became unbalanced.
    int balance = getbalance(root);

    // If node is left-heavy and the key was inserted in left subtree (Left Left Case)
    if (balance > 1 && key < root->left->data) {
        return rightRotation(root);
    }
    // If node is right-heavy and the key was inserted in right subtree (Right Right Case)
    else if (balance < -1 && root->right->data < key) {
        return leftRotation(root);
    }
    // Left Right Case: key inserted into the right subtree of left child.
    else if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);  // First left rotate the left child.
        return rightRotation(root);               // Then right rotate the current node.
    }
    // Right Left Case: key inserted into the left subtree of right child.
    else if (balance < -1 && root->right->data > key) {
        root->right = rightRotation(root->right); // First right rotate the right child.
        return leftRotation(root);                // Then left rotate the current node.
    }

    // Return the (potentially unchanged) node pointer.
    return root;
}

//----------------------------
// Function: preorder
//----------------------------
// Performs a preorder traversal of the AVL tree (Root, Left, Right).
// It prints the data of each node in the traversal order.
void preorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root->data << " ";  // Process the root.
    preorder(root->left);       // Recursively traverse the left subtree.
    preorder(root->right);      // Recursively traverse the right subtree.
}

//----------------------------
// Function: inorder
//----------------------------
// Performs an inorder traversal of the AVL tree (Left, Root, Right).
// Inorder traversal of a BST yields the nodes in sorted order.
void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);        // Recursively traverse the left subtree.
    cout << root->data << " ";  // Process the root.
    inorder(root->right);       // Recursively traverse the right subtree.
}

//----------------------------
// Function: main
//----------------------------
// Demonstrates usage of the AVL tree by inserting multiple keys
// and then printing the preorder and inorder traversals.
int main() {
    Node *root = NULL;  // Initialize the tree as empty.

    // Insert nodes into the AVL tree.
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    // Output the AVL tree traversals.
    cout << "Preorder :- " << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder :- " << endl;
    inorder(root);
    cout << endl;

    return 0;
}
