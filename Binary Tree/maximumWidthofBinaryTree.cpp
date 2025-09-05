// Problem Statement :- https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// If we know the leftmost and rightmost index then width can easily be calcualted as :- right - left + 1
// So we have to number them somehow. We have to use Level Order Traversal (aka BFS) as width is different for each level
// How to index? If root idx = 0, then it's left child idx => 2 * idx + 1 = 1 and right child idx => 2 * idx + 2 = 2
// This works even for other nodes. 

#include <iostream>
#include <queue>
#include <algorithm> // for std::max
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;           // Value of the node
    TreeNode* left;    // Pointer to the left child
    TreeNode* right;   // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor
};

class Solution {
public:
    typedef unsigned long long ll; // Use unsigned long long to avoid overflow for large tree indices

    int widthOfBinaryTree(TreeNode* root) {
        if (!root)   // If the tree is empty, width is 0
            return 0;

        // Queue will store pairs of (node, index)
        // Indexing follows the same convention as a "complete binary tree"
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});
        ll maxWidth = 0;

        while (!que.empty()) {
            int n = que.size();         // Number of nodes at current level
            ll f = que.front().second;  // Index of first node at this level
            ll l = que.back().second;   // Index of last node at this level

            // Update maximum width seen so far
            maxWidth = max(maxWidth, l - f + 1);

            // Process all nodes at current level
            while (n--) {
                TreeNode* curr = que.front().first;
                ll d          = que.front().second; // Current node's index
                que.pop();

                // If left child exists, assign index 2*d + 1
                if (curr->left) {
                    que.push({curr->left, 2*d + 1});
                }
                // If right child exists, assign index 2*d + 2
                if (curr->right) {
                    que.push({curr->right, 2*d + 2});
                }
            }
        }

        return maxWidth;
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    Solution sol;

    // Build a sample binary tree
    TreeNode* root = buildSampleTree();

    // Compute and print the maximum width of the binary tree
    cout << "Maximum width of the binary tree is: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
