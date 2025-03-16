// Problem Statement :- https://leetcode.com/problems/binary-tree-right-side-view/description/

// The right view of a Binary Tree is a set of rightmost nodes for every level.

// To solve this, we can simply use Level Order traversal. For every level, we will put the rightmost node in the result.
// You can also do it in second way as described in binaryTreeLeftSideView.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class for level order traversal.
class Solution {
    public:
    
    vector<int> rightSideView(TreeNode* root) {
        // Queue to facilitate level-order traversal of the tree.
        queue<TreeNode*> q;
        // Vector to store the result (right view of the tree).
        vector<int> ans;

        // If the tree is empty, return an empty vector.
        if (root == NULL) {
            return ans;
        }

        // Push the root node into the queue to start the traversal.
        q.push(root);

        // Perform a level-order traversal.
        while (!q.empty()) {
            // Add the first node of the current level to the result.
            ans.push_back(q.front()->val);

            // Get the number of nodes at the current level.
            int n = q.size();

            // Process all nodes at the current level.
            while (n--) {
                // Remove the front node from the queue.
                TreeNode* temp = q.front();
                q.pop();

                // Add the right child of the current node to the queue, if it exists.
                if (temp->right) {
                    q.push(temp->right);
                }

                // Add the left child of the current node to the queue, if it exists.
                if (temp->left) {
                    q.push(temp->left);
                }
            }
        }

        // Return the computed right view.
        return ans;
    }
};

// Utility function to insert nodes in a binary tree (for testing)
TreeNode* buildTree(vector<int> nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);

    return root;
}

// Utility function to print the level order result
void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> treeNodes = {3, 9, 20, -1, -1, 15, 7};

    TreeNode* root = buildTree(treeNodes, 0);

    Solution solution;

    vector<int> result = solution.rightSideView(root);

    printLevelOrder({result});

    return 0;
}