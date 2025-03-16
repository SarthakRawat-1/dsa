// Problem Statement :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

// Find path of Node 1 and Node 2 in BST, from the root node.
// Then simply find the first common ancestor of these two paths. 
// For eg :- Let's say root node was 50 and we had to find common ancestor of 20 and 40.
// Their paths are as follows :- 50 18 30 28 20 and 50 18 30 40
// FIrst mismatch happens at 28 and 40, so just go before that which becomes 30. 30 is the LCA of 20 and 40.

// But let's say it asks us to not use any vector or array to store these paths i.e. no extra space.
// As it is a BST, we can deduce wehere the two nodes may lie (left or right subtree). In our case, as both 20 and 40 are smaller than 50, so they will be on left subtree which starts from 18, so we come there.
// Now compare 18 with 20 and 40. As both are greater, so we come to right side of 18, which is 30. As 20 is smaller and 40 is bigger, so first mismatch occurs and hence, 30 will be the LCA.

/******************************************************
 * C++ Program to Find the Lowest Common Ancestor (LCA)
 * of Two Nodes in a Binary Search Tree (BST)
 *
 * Problem Statement (from LeetCode):
 * Given a BST and two nodes in the tree, find the lowest common
 * ancestor (LCA) of the two nodes.
 *
 * Approach Overview:
 * ------------------
 * 1. One way to solve the problem is to find the path from the root 
 *    to each of the two nodes and then compare these paths to determine
 *    the first common node. For example:
 *       - For a BST with root 50, and nodes 20 and 40, assume their
 *         paths are:
 *            50 -> 18 -> 30 -> 28 -> 20   and
 *            50 -> 18 -> 30 -> 40
 *         The first mismatch is between 28 and 40, so the previous node,
 *         30, is the LCA.
 *
 * 2. However, since the tree is a BST, we can solve the problem without
 *    extra space by using its inherent ordering:
 *       - If both nodes are smaller than the current node, then both lie
 *         in the left subtree.
 *       - If both nodes are larger than the current node, then both lie
 *         in the right subtree.
 *       - Otherwise, the current node is the split point and is the LCA.
 *
 * The program demonstrates the above approach using recursion.
 ******************************************************/

 #include <iostream>
 using namespace std;
 
 //--------------------------------------------------------------
 // Definition for a binary tree node.
 //--------------------------------------------------------------
 struct TreeNode {
     int val;            // Value stored in the node
     TreeNode *left;     // Pointer to the left child
     TreeNode *right;    // Pointer to the right child
     // Constructor to initialize a node with a given value.
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 //--------------------------------------------------------------
 // Function to insert a value into the BST.
 //--------------------------------------------------------------
 TreeNode* insert(TreeNode* root, int val) {
     // If the tree is empty, create a new node.
     if (root == nullptr) {
         return new TreeNode(val);
     }
     // If the value is less than the current node's value,
     // insert it in the left subtree.
     if (val < root->val) {
         root->left = insert(root->left, val);
     } 
     // Otherwise, insert it in the right subtree.
     else {
         root->right = insert(root->right, val);
     }
     return root;
 }
 
 //--------------------------------------------------------------
 // Function to search for a node with a given value in the BST.
 //--------------------------------------------------------------
 TreeNode* findNode(TreeNode* root, int val) {
     if (root == nullptr) {
         return nullptr;
     }
     // If the current node matches the value, return it.
     if (root->val == val) {
         return root;
     }
     // Traverse left or right based on the value comparison.
     if (val < root->val) {
         return findNode(root->left, val);
     } else {
         return findNode(root->right, val);
     }
 }
 
 //--------------------------------------------------------------
 // Class that contains the solution for finding the LCA.
 //--------------------------------------------------------------
 class Solution {
 public:
     /**
      * Finds the lowest common ancestor (LCA) of two nodes in a BST.
      * 
      * @param root Pointer to the root of the BST.
      * @param p Pointer to the first node.
      * @param q Pointer to the second node.
      * @return Pointer to the LCA node.
      *
      * Explanation:
      * - If both p and q are smaller than the current node, the LCA lies in the left subtree.
      * - If both p and q are greater than the current node, the LCA lies in the right subtree.
      * - Otherwise, the current node is the split point where one node is on one side and the other is on the other side,
      *   so the current node is the LCA.
      */
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // Base condition: if the current node is NULL, return NULL.
         if (root == nullptr) return nullptr;
 
         // If both nodes are smaller than the current node's value, explore the left subtree.
         if (root->val > p->val && root->val > q->val) {
             return lowestCommonAncestor(root->left, p, q);
         }
         // If both nodes are greater than the current node's value, explore the right subtree.
         else if (root->val < p->val && root->val < q->val) {
             return lowestCommonAncestor(root->right, p, q);
         }
         // If neither of the above cases is true, current node is the split point and hence the LCA.
         else {
             return root;
         }
     }
 };
 
 //--------------------------------------------------------------
 // Main Function: Builds the BST, finds two nodes, and computes their LCA.
 //--------------------------------------------------------------
 int main() {
     /*
      * Construct the following BST:
      *
      *           50
      *          /
      *        18
      *          \
      *           30
      *          /  \
      *        28    40
      *       /
      *     20
      *
      * The BST is built by inserting nodes in the following order:
      * 50, 18, 30, 28, 20, 40
      */
     TreeNode* root = nullptr;
     root = insert(root, 50);
     insert(root, 18);
     insert(root, 30);
     insert(root, 28);
     insert(root, 20);
     insert(root, 40);
 
     // Define the values for which we want to find the LCA.
     // In this example, we are finding the LCA of nodes with values 20 and 40.
     int val1 = 20;
     int val2 = 40;
 
     // Retrieve the node pointers from the BST.
     TreeNode* p = findNode(root, val1);
     TreeNode* q = findNode(root, val2);
 
     // Ensure that both nodes are found in the BST.
     if (p == nullptr || q == nullptr) {
         cout << "One of the nodes (" << val1 << " or " << val2 << ") was not found in the BST." << endl;
         return 1;
     }
 
     // Create an instance of the solution class and compute the LCA.
     Solution sol;
     TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
 
     // Display the result.
     if (lca != nullptr) {
         cout << "The Lowest Common Ancestor of nodes " << p->val << " and " << q->val 
              << " is: " << lca->val << endl;
     } else {
         cout << "Lowest Common Ancestor not found." << endl;
     }
 
     return 0;
 }
 