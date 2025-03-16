// Problem Statement :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

/******************************************************
 * C++ Program to Construct a Binary Tree from Preorder 
 * and Postorder Traversals
 *
 * This program demonstrates two approaches:
 * 
 * 1. Approach-1 (Brute Force):
 *    - Uses a recursive helper that scans the postorder 
 *      array to locate the boundary for the left subtree.
 *    - Time Complexity: O(n^2) in worst-case scenarios.
 *    - Space Complexity: O(n) due to recursion stack.
 *
 * 2. Approach-2 (Optimized using unordered_map):
 *    - Pre-computes a map for quick lookup of indices in 
 *      the postorder array.
 *    - Time Complexity: O(n) because each lookup is O(1).
 *    - Space Complexity: O(n) for the map and recursion stack.
 *
 * The program constructs the tree and prints its inorder
 * traversal as a simple verification step.
 ******************************************************/

 #include <iostream>
 #include <vector>
 #include <unordered_map>
 using namespace std;
 
 // Definition for a binary tree node.
 struct TreeNode {
     int val;                // Value stored in the node
     TreeNode *left;         // Pointer to the left child
     TreeNode *right;        // Pointer to the right child
     // Constructor to initialize a node with a given value.
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 //--------------------------------------------------------------
 // Approach-1: Brute Force
 //--------------------------------------------------------------
//  class Solution {
//  public:
//      /**
//       * Recursive helper function to build the binary tree.
//       * @param prestart Starting index in the preorder vector for the current subtree.
//       * @param poststart Starting index in the postorder vector for the current subtree.
//       * @param preend Ending index in the preorder vector for the current subtree.
//       * @param preorder Vector containing the preorder traversal.
//       * @param postorder Vector containing the postorder traversal.
//       * @return Pointer to the constructed subtree's root.
//       */
//      TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder) {
//          // If the current range is invalid, return NULL.
//          if (prestart > preend) {
//              return NULL;
//          }
 
//          // Create a new node with the current value from preorder.
//          TreeNode* root = new TreeNode(preorder[prestart]);
 
//          // If there's only one node, it's a leaf, so return it.
//          if (prestart == preend) {
//              return root;
//          }
 
//          // The next element in preorder is the root of the left subtree.
//          int nextNode = preorder[prestart + 1];
 
//          // Find the index of nextNode in the postorder array.
//          int j = poststart;
//          while (postorder[j] != nextNode) {
//              j++;
//          }
 
//          // Calculate the number of nodes in the left subtree.
//          int num = j - poststart + 1;
 
//          // Recursively construct the left subtree.
//          root->left = solve(prestart + 1, poststart, prestart + num, preorder, postorder);
//          // Recursively construct the right subtree.
//          root->right = solve(prestart + num + 1, j + 1, preend, preorder, postorder);
 
//          return root;
//      }
 
//      /**
//       * Constructs the binary tree from given preorder and postorder traversals.
//       * @param preorder Vector containing preorder traversal.
//       * @param postorder Vector containing postorder traversal.
//       * @return Pointer to the root of the constructed binary tree.
//       */
//      TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//          int n = preorder.size();
//          return solve(0, 0, n - 1, preorder, postorder);
//      }
//  };
 
 //--------------------------------------------------------------
 // Approach-2: Optimized Using unordered_map
 //--------------------------------------------------------------
 class Solution {
 public:
     /**
      * Recursive helper function to build the binary tree with optimization.
      * @param prestart Starting index in the preorder vector for the current subtree.
      * @param poststart Starting index in the postorder vector for the current subtree.
      * @param preend Ending index in the preorder vector for the current subtree.
      * @param preorder Vector containing the preorder traversal.
      * @param postorder Vector containing the postorder traversal.
      * @param mp Map for quick lookup of indices in the postorder array.
      * @return Pointer to the constructed subtree's root.
      */
     TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder,
                     unordered_map<int, int>& mp) {
         // If the current range is invalid, return NULL.
         if (prestart > preend) {
             return NULL;
         }
 
         // Create a new node with the current value from preorder.
         TreeNode* root = new TreeNode(preorder[prestart]);
 
         // If the node is a leaf, return it.
         if (prestart == preend) {
             return root;
         }
 
         // The next element in preorder is the root of the left subtree.
         int nextNode = preorder[prestart + 1];
 
         // Get the index of nextNode in the postorder array using the map.
         int j = mp[nextNode];
 
         // Calculate the number of nodes in the left subtree.
         int num = j - poststart + 1;
 
         // Recursively construct the left subtree.
         root->left = solve(prestart + 1, poststart, prestart + num, preorder, postorder, mp);
         // Recursively construct the right subtree.
         root->right = solve(prestart + num + 1, j + 1, preend, preorder, postorder, mp);
 
         return root;
     }
 
     /**
      * Constructs the binary tree from given preorder and postorder traversals.
      * @param preorder Vector containing preorder traversal.
      * @param postorder Vector containing postorder traversal.
      * @return Pointer to the root of the constructed binary tree.
      */
     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         int n = preorder.size();
         unordered_map<int, int> mp;  // Map to store value-to-index mapping for postorder.
         for (int i = 0; i < n; i++) {
             mp[postorder[i]] = i;
         }
         return solve(0, 0, n - 1, preorder, postorder, mp);
     }
 };
 
 //--------------------------------------------------------------
 // Utility Function: Inorder Traversal
 //--------------------------------------------------------------
 /**
  * Performs an inorder traversal of the binary tree.
  * @param root Pointer to the root of the tree.
  */
 void inorderTraversal(TreeNode* root) {
     if (root == nullptr) {
         return;
     }
     inorderTraversal(root->left);
     cout << root->val << " ";
     inorderTraversal(root->right);
 }
 
 //--------------------------------------------------------------
 // Main Function
 //--------------------------------------------------------------
 int main() {
     // Example input:
     // Preorder and Postorder traversals for a full binary tree.
     vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
     vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

     cout << "Constructing tree using Approach-2 (Optimized using unordered_map):" << endl;
     Solution sol2;
     TreeNode* root2 = sol2.constructFromPrePost(preorder, postorder);
     cout << "Inorder traversal of the constructed tree: ";
     inorderTraversal(root2);
     cout << endl;
 
     return 0;
 }
 