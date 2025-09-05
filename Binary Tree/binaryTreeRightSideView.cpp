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
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            // Traverse all nodes of this level
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // First node of this level (i == 0) -> left view
                if (i == n - 1) ans.push_back(temp->val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

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