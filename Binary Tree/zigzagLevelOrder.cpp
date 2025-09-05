// Problem Statement :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for reverse

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // start with left-to-right direction

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // If the direction is right-to-left, reverse this level
            if (!leftToRight) {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            result.push_back(currentLevel);

            // Toggle direction for the next level
            leftToRight = !leftToRight;
        }

        return result;
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

// Utility function to print the zigzag level order result
void printZigzag(const vector<vector<int>>& levels) {
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
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    printZigzag(result);

    return 0;
}

// Deque Approach
// vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//     vector<vector<int>> result;
//     if (!root) return result;

//     queue<TreeNode*> q;
//     q.push(root);
//     bool leftToRight = true; // direction flag

//     while (!q.empty()) {
//         int levelSize = q.size();
//         deque<int> currentLevel; // deque to allow push_front

//         for (int i = 0; i < levelSize; ++i) {
//             TreeNode* node = q.front();
//             q.pop();

//             if (leftToRight) {
//                 currentLevel.push_back(node->val);   // left to right
//             } else {
//                 currentLevel.push_front(node->val);  // right to left
//             }

//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }

//         // Convert deque to vector for result
//         result.push_back(vector<int>(currentLevel.begin(), currentLevel.end()));

//         // Flip direction
//         leftToRight = !leftToRight;
//     }

//     return result;
// }