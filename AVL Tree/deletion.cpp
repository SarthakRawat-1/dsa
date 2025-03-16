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
// Function: deleteNode
//----------------------------
// Deletes a node with the given key from the AVL tree rooted at 'root'.
// This function follows the standard BST deletion procedure and then rebalances the tree if needed.
// Steps:
//   1. If the tree is empty, return NULL.
//   2. Traverse the tree to find the node with the matching key:
//       a. If key is smaller than root's data, recurse into the left subtree.
//       b. If key is greater than root's data, recurse into the right subtree.
//   3. When the node with the key is found:
//       a. If it is a leaf (no children), delete it and return NULL.
//       b. If it has one child, delete it and return its child.
//       c. If it has two children:
//            i. Find the inorder successor (the smallest node in the right subtree).
//           ii. Copy the inorder successor's data to the current node.
//          iii. Delete the inorder successor from the right subtree.
//   4. Update the height of the current node after deletion.
//   5. Calculate the balance factor of the current node.
//   6. If the node is unbalanced, perform the appropriate rotation(s):
//       a. Left Left Case: Right rotation.
//       b. Left Right Case: Left rotation on left child then right rotation.
//       c. Right Right Case: Left rotation.
//       d. Right Left Case: Right rotation on right child then left rotation.
//   7. Return the (possibly new) root of the subtree.
Node* deleteNode(Node* root, int key) {
    // Base case: if the tree is empty, return NULL.
    if (!root) {
        return NULL;
    }

    // Recurse down the tree to locate the node to be deleted.
    if (key < root->data) {
        // If key is less, it lies in the left subtree.
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        // If key is greater, it lies in the right subtree.
        root->right = deleteNode(root->right, key);
    } else {
        // Node with the matching key found.

        // Case 1: Node with no children (leaf node).
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // Case 2: Node with only one child.
        else if (root->left && !root->right) {
            Node* temp = root->left; // Save pointer to left child.
            delete root;
            return temp;
        }
        else if (root->right && !root->left) {
            Node* temp = root->right; // Save pointer to right child.
            delete root;
            return temp;
        }
        // Case 3: Node with two children.
        else {
            // Find the inorder successor (smallest node in right subtree).
            Node* curr = root->right;
            while(curr->left) {
                curr = curr->left;
            }
            // Copy the inorder successor's data to the current node.
            root->data = curr->data;
            // Delete the inorder successor from the right subtree.
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // Update the height of the current node after deletion.
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // Calculate the balance factor to check if the node became unbalanced.
    int balance = getbalance(root);

    // If the node is left-heavy.
    if (balance > 1) {
        // Check if the left subtree is balanced or left-heavy.
        if (getbalance(root->left) >= 0) {
            // Left Left Case: perform a right rotation.
            return rightRotation(root);
        } else {
            // Left Right Case: perform a left rotation on left child, then right rotation on current node.
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    // If the node is right-heavy.
    else if (balance < -1) {
        // Check if the right subtree is balanced or right-heavy.
        if (getbalance(root->right) <= 0) {
            // Right Right Case: perform a left rotation.
            return leftRotation(root);
        } else {
            // Right Left Case: perform a right rotation on right child, then left rotation on current node.
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    
    // Return the (possibly updated) node pointer.
    return root;
}

int main() {   
    return 0;
}