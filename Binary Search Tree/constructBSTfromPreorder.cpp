// Problem Statement :- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

// Method 1 :- Preorder Traversal, hence first element in traversal will be root node. Nodes smaller to that will go on left subtree and rest on right subtree because BST.
// Further from the two separated sets, the one which appears on leftmost will be root of left subtree and again division of rest elements will happen in same fashion. Same goes for right subtree.

// Method 2 :- First element root node. After this for the rest of elements, build the BST like we how normally build it.

// Method 3 (Optimized) :- For every node, we can define a range in which the value which is to be inserted as it's left child (or right child) should lie in.
// For eg :- If 30 is root node, and it has left child 15, then right child of 15 should lie in range 15 < x < 30 let's say x is 25.
// Now left child of 25 should lie in range :- 20 < y < 25
// This range can be deduced in following way :-
// For root node of tree, we can say that it can lie between INT_MIN and INT_MAX. Whenever we go to it's left child, we will say that it should now lie between INT_MIN and it's parent node's value. And for right child, it's value should lie between it's parent node value and INT_MAX.
// Keep updating this range for subsequent nodes.
// Now consider Preorder Traversal :- {8, 5, 1, 7, 10, 12}
// 8 lies between INT_MIN and INT_MAX, so it is the root node (leftmost node). moving on to 5. Check if it lies between INT_MIN and 8, it does, so 5 becomes it's left child.
// Again, we will try to create left child, so it should lie between INT_MIN and 5. 1 does, so 1 becomes 5's left child. Now it's left child should be between INT_MIN and 1. 7 doesn't fulfill that so now look for right child.
// Right of 1 should lie between 1 and 5. 7 doesn't fulfill that so go one up, now look for right child of 5. Right child of 5 should lie between 5 and 8. 7 does, so 7 becomes right child of 5.
// 10 can't become left child of 7, and also can't become right child of 7 (doesn't lie in ranges for both cases) so it goes up, 5 already has both child, again goes up comes to 8. Right child of 8 should lie between 8 and INT_MAX. 10 does so it becomes right child of 8.
// Similarly, 12 will become right child of 10 as 12 is greater than 8 to 10 which is the range for left child of 10. 

#include <iostream>     // For input/output operations.
#include <vector>       // To use std::vector for the preorder traversal.
#include <climits>      // For INT_MIN and INT_MAX.
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;            // Node's value.
    TreeNode *left;     // Pointer to the left child.
    TreeNode *right;    // Pointer to the right child.

    // Constructor to initialize a node with a value and null children.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to construct a BST from its preorder traversal.
class Solution {
public:
    /*
     * Recursive helper function to build the BST.
     *
     * Parameters:
     * - preorder: Reference to the vector containing the preorder traversal.
     * - index: Reference to the current index in the preorder vector.
     * - min: The minimum allowable value for the current node.
     * - max: The maximum allowable value for the current node.
     *
     * Returns:
     * - Pointer to the constructed TreeNode (or nullptr if conditions are not met).
     *
     * The idea behind the function is that every node in a BST must fall within a valid
     * range. For the root node, the range is [INT_MIN, INT_MAX]. When moving to the left,
     * the allowable range becomes [min, current_node_value]. For the right subtree, it becomes
     * [current_node_value, max]. This constraint ensures that the BST property is maintained.
     */
    TreeNode* BST(vector<int>& preorder, int& index, int min, int max) {
        // Base case: If we have processed all nodes or the current node's value
        // does not lie within the valid range, return nullptr.
        if (index == preorder.size() || preorder[index] < min || preorder[index] > max)
            return nullptr;

        // Create the current node with the current value and increment the index.
        TreeNode* root = new TreeNode(preorder[index++]);

        // Recursively build the left subtree.
        // For the left child, the valid range is [min, root->val].
        root->left = BST(preorder, index, min, root->val);

        // Recursively build the right subtree.
        // For the right child, the valid range is [root->val, max].
        root->right = BST(preorder, index, root->val, max);

        // Return the constructed node.
        return root;
    }

    /*
     * Main function to build a BST from preorder traversal.
     *
     * Parameter:
     * - preorder: A vector of integers representing the preorder traversal of the BST.
     *
     * Returns:
     * - Pointer to the root of the constructed BST.
     *
     * This function initializes the starting index to 0 and calls the helper function
     * with the full range [INT_MIN, INT_MAX] to allow any integer value for the root.
     */
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;  // Start at the first element in the preorder vector.
        return BST(preorder, index, INT_MIN, INT_MAX);
    }
};

/*
 * Helper function to perform an inorder traversal of the BST.
 *
 * Inorder traversal of a BST will print the values in sorted order.
 */
void inorderTraversal(TreeNode* root) {
    if (!root)
        return;
    inorderTraversal(root->left);         // Traverse the left subtree.
    cout << root->val << " ";               // Print the current node's value.
    inorderTraversal(root->right);          // Traverse the right subtree.
}

/*
 * Helper function to perform a preorder traversal of the BST.
 *
 * Preorder traversal prints the root first, then left and right subtrees.
 * It should match the original preorder vector used to build the BST.
 */
void preorderTraversal(TreeNode* root) {
    if (!root)
        return;
    cout << root->val << " ";               // Print the current node's value.
    preorderTraversal(root->left);          // Traverse the left subtree.
    preorderTraversal(root->right);         // Traverse the right subtree.
}

/*
 * Helper function to delete/free the BST nodes.
 *
 * This function performs a postorder traversal to safely delete each node,
 * ensuring that all dynamically allocated memory is freed.
 */
void deleteTree(TreeNode* root) {
    if (!root)
        return;
    deleteTree(root->left);   // Delete left subtree.
    deleteTree(root->right);  // Delete right subtree.
    delete root;              // Delete the current node.
}

int main() {
    // ------------------------
    // Example Preorder Traversal:
    // The given preorder traversal for a BST is:
    // {8, 5, 1, 7, 10, 12}
    // The first element (8) is the root.
    // Nodes less than 8 will form the left subtree and nodes greater than 8 will form the right subtree.
    // ------------------------
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Create an instance of the solution.
    Solution solution;

    // Construct the BST from the given preorder traversal.
    TreeNode* root = solution.bstFromPreorder(preorder);

    // ------------------------
    // Verify the constructed BST.
    // Inorder traversal of the BST should yield a sorted sequence: 1 5 7 8 10 12.
    // Preorder traversal of the BST should match the original preorder vector: 8 5 1 7 10 12.
    // ------------------------
    cout << "Inorder Traversal (Sorted Order): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal (Original Preorder): ";
    preorderTraversal(root);
    cout << endl;

    // Clean up the dynamically allocated memory for the BST.
    deleteTree(root);

    return 0;
}
