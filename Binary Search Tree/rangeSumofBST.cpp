// Problem Statement :- https://leetcode.com/problems/range-sum-of-bst/description/

// Simply, we can find Inorder Traversal of the BST. Then we can simply find the sum of all the values in the range.

// Use logic of LCAofBST.cpp
// In this the low and high will be like the two nodes and we will compare actual nodes of BST with them.
// For every node, we can check if it lies in the range or not. If not, move left or right accordingly.
// If it is, then add it's value to the sum. And now you can go to both it's left and right subtree one by one to find more nodes.
// If you want to visit the data in ascending order, then you can use directly use Inorder traversal on that node.

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
 // Helper Function: Insert a value into the BST.
 //--------------------------------------------------------------
 TreeNode* insert(TreeNode* root, int val) {
     // If the tree is empty, create a new node and return it.
     if (root == nullptr) {
         return new TreeNode(val);
     }
     // If the value to be inserted is less than the current node's value,
     // insert it into the left subtree.
     if (val < root->val) {
         root->left = insert(root->left, val);
     } 
     // Otherwise, insert it into the right subtree.
     else {
         root->right = insert(root->right, val);
     }
     return root;
 }
 
 //--------------------------------------------------------------
 // Class containing the solution for Range Sum of BST.
 //--------------------------------------------------------------
 class Solution {
 public:
     /**
      * Computes the sum of all node values within the inclusive range [low, high].
      *
      * @param root Pointer to the root of the BST.
      * @param low Lower bound of the range.
      * @param high Upper bound of the range.
      * @return Sum of values of nodes that lie within [low, high].
      *
      * Explanation:
      * - If the current node is NULL, there is nothing to add, so return 0.
      * - If the current node's value is less than low, then all values in the left subtree
      *   are too small (by BST property), so only consider the right subtree.
      * - If the current node's value is greater than high, then all values in the right subtree
      *   are too large, so only consider the left subtree.
      * - If the current node's value is within [low, high], add its value to the sum and
      *   recursively process both left and right subtrees.
      */
     int rangeSumBST(TreeNode* root, int low, int high) {
         // Base case: if the current node is null, return 0.
         if (root == nullptr) {
             return 0;
         }
 
         // If the current node's value is less than low,
         // skip the left subtree and process the right subtree.
         if (root->val < low) {
             return rangeSumBST(root->right, low, high);
         }
         // If the current node's value is greater than high,
         // skip the right subtree and process the left subtree.
         if (root->val > high) {
             return rangeSumBST(root->left, low, high);
         }
 
         // Otherwise, include the current node's value and explore both subtrees.
         return root->val 
              + rangeSumBST(root->left, low, high) 
              + rangeSumBST(root->right, low, high);
     }
 };
 
 //--------------------------------------------------------------
 // Main Function: Builds the BST, calls the solution, and prints the result.
 //--------------------------------------------------------------
 int main() {
     /*
      * Construct the following BST:
      *
      *         10
      *        /  \
      *       5    15
      *      / \     \
      *     3   7     18
      *
      * The BST is built by inserting the following values in order:
      * 10, 5, 15, 3, 7, 18.
      */
     TreeNode* root = nullptr;
     root = insert(root, 10);
     insert(root, 5);
     insert(root, 15);
     insert(root, 3);
     insert(root, 7);
     insert(root, 18);
 
     // Define the range [low, high] for which we need to compute the sum.
     // In this example, we consider the range [7, 15].
     int low = 7;
     int high = 15;
 
     // Create an instance of the solution class.
     Solution sol;
     // Compute the sum of node values within the specified range.
     int sum = sol.rangeSumBST(root, low, high);
 
     // Print the result.
     cout << "The sum of values within the range [" << low << ", " << high << "] is: " << sum << endl;
 
     return 0;
 }
 