// Problem Statement :- https://www.geeksforgeeks.org/problems/largest-bst/1

// For every node, if it's left subtree is a Bst and it's right subtree is a BST, then tree starting from that node is also BST.
// But besides this, we also need, that node should be more than it's inorder predecessor, i.e. max value in left subtree. And similarly, node should be less than min value in right subtree.
// Then only we can say that tree starting from that node is BST. Then size of this BST will be :- size of left subtree + size of right subtree + 1

// To simplify, we will send both max and min from both left and right subtree to the node. Then we don't have to check, and node can simply take what it wants from which subtree.
// So from every subtree, a node will require :- BST, i.e. whether it's a BST or not, size and min and max element of the BST.
// Remember a single node with no children is a BST with size 1 and min, max both as node value. So it will pass only this to it's parent.
// The node when it receives info from both subtree, can then check if it's a BST or not. And then send this info to it's parent.
// Those 4 info that a subtree has to return, they can be encapsulated in a class. Then we can simply return object of this class.
// Also, besides leaf nodes which are obv, we also have to check for nodes which only have one subtree. In this case, ignore the subtree which doesn't exist.

// Btw at every pt u need not modify each info of that we are returning. We can only modify relevant value. For eg :- If BST is false, for soemone, then don't care about it's size or min max as it can't be a BST and even it's parent can't be a BST.

#include <bits/stdc++.h>
using namespace std;

// Node definition for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Box class to store useful info from every subtree
class Box {
public:
    bool BST;  // Is this subtree a BST?
    int size;  // Size of the BST (if valid)
    int min;   // Minimum value in this subtree
    int max;   // Maximum value in this subtree

    Box(int data) {
        BST = true;        // A single node is always a BST
        size = 1;          // Size is 1
        min = data;        // Min = node value
        max = data;        // Max = node value
    }
};

// Recursive function to compute largest BST size in tree
Box* find(Node* root, int& TotalSize) {
    // Base case: if root is a leaf node (no children)
    if (!root->left && !root->right) {
        TotalSize = max(TotalSize, 1);   // A leaf is a BST of size 1
        Box* head = new Box(root->data); // Create a Box object
        return head;
    }

    // Case 1: Node has only RIGHT child
    else if (!root->left && root->right) {
        Box* head = find(root->right, TotalSize);

        // Valid BST only if right subtree is BST AND root < min of right
        if (head->BST && head->min > root->data) {
            head->size++;               // Increase size by including root
            head->min = root->data;     // Update min value
            TotalSize = max(TotalSize, head->size);
            return head;
        } else {
            head->BST = 0; // Not a BST
            return head;
        }
    }

    // Case 2: Node has only LEFT child
    else if (!root->right && root->left) { // <-- Fixed condition
        Box* head = find(root->left, TotalSize);

        // Valid BST only if left subtree is BST AND root > max of left
        if (head->BST && head->max < root->data) {
            head->size++;               // Increase size by including root
            head->max = root->data;     // Update max value
            TotalSize = max(TotalSize, head->size);
            return head;
        } else {
            head->BST = 0; // Not a BST
            return head;
        }
    }

    // Case 3: Node has BOTH left and right children
    else {
        Box* left = find(root->left, TotalSize);
        Box* right = find(root->right, TotalSize);

        // Condition for root to form a BST:
        // 1. Left and right subtrees must be BST
        // 2. root->data must be greater than left->max
        // 3. root->data must be smaller than right->min
        if (left->BST && right->BST && left->max < root->data && right->min > root->data) {
            Box* head = new Box(root->data);

            // Size of BST = size of left + size of right + 1 (root)
            head->size = left->size + right->size + 1;

            // Update min and max
            head->min = left->min;
            head->max = right->max;

            // Update global answer
            TotalSize = max(TotalSize, head->size);

            return head;
        } else {
            // If not BST, just mark and return
            left->BST = 0;
            return left;
        }
    }
}

// Wrapper function to find largest BST size
int largestBst(Node* root) {
    int TotalSize = 0;
    find(root, TotalSize);
    return TotalSize;
}

int main() {
    // Example Usage:
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout << "Largest BST size: " << largestBst(root) << endl;
}

// You can also simplify it to find handling for 2 cases :- root is null or not. 
// If null, then BST: 1, size = 0, min = INT MAX, and max = INT MIN.If not null, then exact same as when it has two children.
// But in this case when updating head->min and max u have to consider min(root->data, left->min) and max(root->data, right->max).