// Problem Statement :- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

// First review maximum width of binary tree, as this is just that with extension of keeping track sum and level, instead of width.

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) // Empty tree
            return 0;

        queue<TreeNode*> que; // BFS queue
        que.push(root);

        pair<int,int> maxResult = {INT_MIN, 0}; // {maxSum, level}
        int level = 0;

        while (!que.empty()) {
            int n = que.size();   // Number of nodes at current level
            int levelSum = 0;
            level++;

            // Process all nodes at the current level
            while (n--) {
                TreeNode* curr = que.front();
                que.pop();

                levelSum += curr->val; // Add current node's value

                if (curr->left)  que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }

            // Update max sum and level if needed
            if (levelSum > maxResult.first) {
                maxResult.first = levelSum;
                maxResult.second = level;
            }
        }

        return maxResult.second; // Return the level with maximum sum
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    cout << "Level with maximum sum is: " << sol.maxLevelSum(root) << endl;

    return 0;
}
