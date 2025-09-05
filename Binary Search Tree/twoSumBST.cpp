// Problem Statement :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// This is preorder traversal
bool dfs(TreeNode* root, unordered_set<int>& set, int k){
    if(root == NULL) return false; // if node is null, stop recursion

    // check if the complement (k - current value) already exists in the set
    if(set.count(k - root->val)) return true;

    // otherwise store the current value in the set
    set.insert(root->val);

    // recursively check left subtree or right subtree
    return dfs(root->left, set, k) || dfs(root->right, set, k);
}

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> set;
    return dfs(root, set, k);
}

int main() {
    // Example BST:
    //       5
    //      / \
    //     3   6
    //    / \    \
    //   2   4    7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 9;
    cout << (findTarget(root, k) ? "True" : "False") << endl; // Expected True (2 + 7)

    k = 28;
    cout << (findTarget(root, k) ? "True" : "False") << endl; // Expected False

    return 0;
}
