// Problem Statement :- 

#include <bits/stdc++.h>
using namespace std;

// ---------------- Binary Tree Node Structure ----------------
struct TreeNode {
    int val;               // value of the node
    TreeNode *left;        // pointer to left child
    TreeNode *right;       // pointer to right child
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------------- Helper Function (DFS Traversal) ----------------
void dfs(TreeNode* root, vector<int> &currentPath, vector<vector<int>> &allPaths) {
    if (!root) return;  // base case: if node is NULL, just return
    
    // Step 1: Add the current node to path
    currentPath.push_back(root->val);
    
    // Step 2: If it's a leaf node, save the path
    if (!root->left && !root->right) {
        allPaths.push_back(currentPath);
    } else {
        // Step 3: Explore left and right subtrees
        dfs(root->left, currentPath, allPaths);
        dfs(root->right, currentPath, allPaths);
    }
    
    // Step 4: Backtrack → remove current node before returning to parent
    currentPath.pop_back();
}

// ---------------- Main Function to Return Paths ----------------
vector<vector<int>> binaryTreePaths(TreeNode* root) {
    vector<vector<int>> allPaths;  // stores all root-to-leaf paths
    vector<int> currentPath;       // stores current traversal path
    dfs(root, currentPath, allPaths);
    return allPaths;
}

// ---------------- Driver Code (Example) ----------------
int main() {
    /* Example Tree:
             1
            / \
           2   3
            \
             5
       Paths: 1->2->5 , 1->3
    */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<vector<int>> paths = binaryTreePaths(root);
    
    cout << "Root-to-Leaf Paths:" << endl;
    for (auto &path : paths) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// ---------------- Binary Tree Node Structure ----------------
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------------- Helper Function ----------------
// Returns true if target is found in the subtree rooted at 'root'
bool findPath(TreeNode* root, int target, vector<int> &path) {
    if (!root) return false;  // base case
    
    // Step 1: Add current node to path
    path.push_back(root->val);
    
    // Step 2: If this is the target node, we found the path
    if (root->val == target) return true;
    
    // Step 3: Search in left or right subtree
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }
    
    // Step 4: If not found, backtrack (remove current node)
    path.pop_back();
    return false;
}

// ---------------- Driver Code ----------------
int main() {
    /* Example Tree:
             1
            / \
           2   3
          / \
         4   5
    */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int target = 5;  // Example: find path to node with value 5
    vector<int> path;
    
    if (findPath(root, target, path)) {
        cout << "Path to node " << target << ": ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Node " << target << " not found in the tree." << endl;
    }
    
    return 0;
}

