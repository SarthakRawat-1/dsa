// Problem Statement :- https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

// Here also we can use the concept of range in which a certain node should appear. The root should appear in range 0 to INT_MAX.
// It's left should appear in range 0 to root data, and right should appear in range root data to INT_MAX.
// Similarly, doing this for all other. For leaf nodes too, we can find, that what their child's range should be (they don't exist right now).
// Finding that range, if we find the difference between the upper bound and lower bound of range is 1, then that side (left or right) of the leaf node is a dead end.
// Both side should be dead end for a node to be dead end.

 #include <iostream>
 #include <climits>
 using namespace std;
 
 //--------------------------------------------------------------
 // Definition for a Binary Search Tree (BST) node.
 //--------------------------------------------------------------
 struct Node {
     int data;       // Value stored in the node
     Node *left;     // Pointer to the left child
     Node *right;    // Pointer to the right child
 
     // Constructor to initialize a node with a given value.
     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 };
 
 //--------------------------------------------------------------
 // Function to insert a key into the BST.
 // This helps build the BST for testing.
 //--------------------------------------------------------------
 Node* insert(Node* root, int key) {
     // If the tree is empty, create a new node.
     if (root == nullptr) {
         return new Node(key);
     }
     // If key is less than the current node's data,
     // insert it into the left subtree.
     if (key < root->data) {
         root->left = insert(root->left, key);
     }
     // If key is greater than the current node's data,
     // insert it into the right subtree.
     else if (key > root->data) {
         root->right = insert(root->right, key);
     }
     return root;
 }
 
 //--------------------------------------------------------------
 // Recursive function to check for a dead end in the BST.
 // Parameters:
 //   - root: pointer to the current node.
 //   - lower: the lower bound of allowed values in this subtree.
 //   - upper: the upper bound of allowed values in this subtree.
 // Returns true if a dead end is found in the subtree; otherwise, false.
 //--------------------------------------------------------------
 bool Dead(Node* root, int lower, int upper) {
     // Base case: if the current node is NULL, there is no dead end here.
     if (root == nullptr) {
         return false;
     }
 
     // If the current node is a leaf node (no children)
     if (root->left == nullptr && root->right == nullptr) {
         // Check if the leaf node represents a dead end.
         // If the difference between the node's value and the lower bound is 1,
         // and the difference between the upper bound and the node's value is 1,
         // then no further node can be inserted in this branch.
         if (root->data - lower == 1 && upper - root->data == 1) {
             return true;
         } else {
             return false;
         }
     }
 
     // Recursively check in the left subtree:
     // The allowed range for the left child becomes [lower, root->data]
     // and in the right subtree:
     // The allowed range becomes [root->data, upper].
     return Dead(root->left, lower, root->data) || Dead(root->right, root->data, upper);
 }
 
 //--------------------------------------------------------------
 // Wrapper function to check if the BST contains any dead end.
 // Initializes the allowed range from 0 to INT_MAX.
 //--------------------------------------------------------------
 bool isDeadEnd(Node *root) {
     return Dead(root, 0, INT_MAX);
 }
 
 //--------------------------------------------------------------
 // Main function to demonstrate the solution.
 //--------------------------------------------------------------
 int main() {
     /*
      * Construct the following BST:
      *
      *          8
      *        /   \
      *       5     11
      *      / \
      *     2   7
      *      \
      *       3
      *
      * In this BST, the leaf node with value 3 forms a dead end because:
      * - The allowed range for the node with value 2 is [lower, 2]
      *   (here lower becomes 0 for the root's left subtree) so for node 3:
      *   lower = 2 and upper = 4 (since 2 is the parent and parent's left limit)
      *   Here, 3 - 2 == 1 and 4 - 3 == 1, thus no further insertion is possible.
      */
     Node* root = nullptr;
     root = insert(root, 8);
     insert(root, 5);
     insert(root, 11);
     insert(root, 2);
     insert(root, 7);
     insert(root, 3);
 
     // Check if the BST contains a dead end.
     if (isDeadEnd(root)) {
         cout << "The BST contains a dead end." << endl;
     } else {
         cout << "The BST does not contain a dead end." << endl;
     }
 
     return 0;
 }
 