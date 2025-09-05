// Problem Statement :- https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

// Let's say you are at a node.
// First case :- From it's left and from it's right subtree, we got decent path sum from both. So in this case, for this node, this path will be the best aka max path sum for this.
// In this case :- max path sum = left + right + root val. With this, we won't go above.
// Second case :- Let's say from left side we got a -ve sum but from right we got a decent sum, so in this case, we will want to take only right and not take anything from left.
// Same goes in vice versa case. In this case :- max path sum = max(left, right) + root val
// Third case :- If both left and right is giivng bad ans, only root val is best ans

// But now consider case 1 again. We can't really send it to the parent node (as it's left or right path sum) because it's not a single path for it. But ofc it can be a valid candidate for the final ans still.
// For case 2 and case 3, the max path sum can also be returned.
// So all 3 cases max path sum can be valid as candidates for final ans but for ret we need to send max of case 2 and case 3 ans.

#include <bits/stdc++.h>
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
    
    int maxSum; // Global variable to keep track of the maximum path sum found so far
    
    // Recursive helper function to compute maximum contribution from each node
    int solve(TreeNode* root) {
        if(root == NULL)
            return 0; // Base case: if node is NULL, it contributes 0 to the path
        
        // Recursively compute max contribution from left and right subtrees
        int l = solve(root->left);
        int r = solve(root->right);
        
        // Case (1): Path goes through this node as the "highest point"
        // Includes left subtree + right subtree + current node value
        int neeche_hi_milgaya_answer = l + r + root->val; 
        
        // Case (2): Best path includes current node and *one* of its children
        int koi_ek_acha = max(l, r) + root->val; 
        
        // Case (3): Path only contains the current node
        int only_root_acha = root->val; 
        
        // Update the global maxSum considering all possibilities at this node
        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});
        
        // Important:
        // When returning to parent, we cannot return a "V-shaped" path
        // (i.e., l + r + root->val), because parent cannot use both sides.
        // So we return the best single-branch contribution upwards.
        return max(koi_ek_acha, only_root_acha);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // Initialize global max with minimum possible
        
        solve(root); // Run DFS to compute max path sum
        
        return maxSum; // Final result
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

    int sum = solution.maxPathSum(root);

    cout << sum;

    return 0;
}