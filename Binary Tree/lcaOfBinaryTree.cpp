// Problem Statement :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// Traverse tree. Let's say we need to find p and q.
// When we arrive at node = p, return it to it's parent, similarly, when we arrive at node = q for it's parent, return it to it's parent.
// THe first node where both p and q arrive (by getting returned) is the LCA.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * Function to find the Lowest Common Ancestor (LCA) of two nodes p and q in a binary tree.
 * - If the root is NULL, return NULL.
 * - If the root matches either p or q, return root.
 * - Recursively search in the left and right subtrees.
 * - If both left and right recursive calls return non-NULL, root is the LCA.
 * - If only one side returns non-NULL, propagate that result upward.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return NULL; // Base case: empty subtree
    }

    if (root == p || root == q) {
        return root; // If root is p or q, return root (could be LCA)
    }

    // Recursively search left and right subtrees
    TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

    // If p and q found in different subtrees, current root is LCA
    if (leftN && rightN) {
        return root;
    } // Btw once found, this doesn't get overwritten while bubbling up to parent because then the other subtree in which this is not there will be null so it will never be executed again.

    // Otherwise, return the non-NULL child (or NULL if both are NULL)
    return leftN ? leftN : rightN;
}

// Helper function to print the value of a node
void printNode(TreeNode* node) {
    if (node) {
        cout << node->val << endl;
    } else {
        cout << "NULL" << endl;
    }
}

int main() {
    /*
     * Create a sample binary tree:
     *          3
     *         / \
     *        5   1
     *       / \ / \
     *      6  2 0  8
     *        / \
     *       7   4
     */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: ";
    printNode(lca);

    // Clean up memory (optional for small demo)
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
