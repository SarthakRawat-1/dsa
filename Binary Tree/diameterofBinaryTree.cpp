// Problem Statement :- https://leetcode.com/problems/diameter-of-binary-tree/description/

#include <bits/stdc++.h>
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

    // For any node, it can have left and right child and even a parent. If it doesn't have a parent node, then we can find one of the possible answer for longest diameter by simply finding and adding the longest edge path in either half of the subtree.
    // If it does have a parent node, then for that parent node, we can only take longest edge of either of the two subtree of it's child node i.e. max(left_edge, right_edge) + 1 (+1 because we also have to count the edge connecting child and parent node) This will be transferred to the parent node which will check if it can be a possible answer or not.
    // Ofc this will also be a result given to the parent node by one of it's subtree, similarly we can calculate for other subtree and then do left + right for this as well, for a possible answer.
    // Helper function to calculate the diameter of a binary tree
    // while simultaneously updating the maximum diameter found so far.
    int diameter(TreeNode* root, int& result) {
        // Base case: If the current node is NULL, its height is 0.
        if (!root)
            return 0;
        
        // Recursively calculate the height of the left subtree.
        int left = diameter(root->left, result);
        
        // Recursively calculate the height of the right subtree.
        int right = diameter(root->right, result);
        
        // Update the maximum diameter (result) if the current path
        // passing through this node (left subtree + right subtree) is larger.
        // This considers the case where the longest path passes through
        // the current node, connecting the left and right subtrees.
        result = max(result, left + right);
        
        // Return the height of the current subtree, which is the maximum height
        // of its left or right subtree plus 1 (for the current node).
        // This is needed for parent nodes to compute their diameter.
        return max(left, right) + 1;
    }

    // Main function to calculate the diameter of a binary tree.
    int diameterOfBinaryTree(TreeNode* root) {
        // If the tree is empty, its diameter is 0.
        if (!root)
            return 0;
        
        // Variable to store the maximum diameter found.
        int result = INT_MIN;
        
        // Call the helper function to calculate the diameter.
        diameter(root, result);
        
        // Return the maximum diameter found.
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

    cout << solution.diameterOfBinaryTree(root) << endl;
    
    return 0;
}