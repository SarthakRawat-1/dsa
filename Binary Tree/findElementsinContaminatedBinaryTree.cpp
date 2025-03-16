// Problem Statement :- https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;            // Value stored in the node.
    TreeNode *left;     // Pointer to the left child.
    TreeNode *right;    // Pointer to the right child.
    
    // Default constructor: Initializes node value to 0 and children to nullptr.
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    // Constructor with an integer parameter: Initializes node value to x and children to nullptr.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    // Constructor with value and pointers to left and right children.
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// The FindElements class recovers a contaminated binary tree.
// The tree is "contaminated" in that every node's value is initially -1.
// Recovery is done by setting the root's value to 0 and assigning values to each node as follows:
//   For a node with value x:
//     - Its left child (if it exists) is assigned 2*x + 1.
//     - Its right child (if it exists) is assigned 2*x + 2.
// Additionally, the class supports a find() method to check if a recovered value exists in the tree.
class FindElements {
public:
    // An unordered set to store all recovered values for quick lookup.
    unordered_set<int> s;
    
    // Depth-first search (DFS) helper function to recover the tree.
    // Parameters:
    // - root: pointer to the current TreeNode.
    // - val: the value to assign to the current node.
    void dfs(TreeNode* root, int val) {
        if (!root) return;  // Base case: If the node is null, do nothing.
        
        // Set the current node's value to the provided value.
        root->val = val;
        // Insert the value into the set for later lookup.
        s.insert(val);
        
        // Recursively recover the left subtree.
        // According to the problem, the left child's value is 2 * val + 1.
        dfs(root->left, 2 * val + 1);
        
        // Recursively recover the right subtree.
        // According to the problem, the right child's value is 2 * val + 2.
        dfs(root->right, 2 * val + 2);
    }
    
    // Breadth-first search (BFS) helper function to recover the tree.
    // This function is an alternative to DFS. It uses a queue to traverse nodes level-by-level.
    // Parameters:
    // - root: pointer to the root node.
    // - val: the value to assign to the root.
    void bfs(TreeNode* root, int val) {
        queue<TreeNode*> q;  // Queue for BFS traversal.
        
        // Initialize the root node with the provided value and push it onto the queue.
        root->val = val;
        q.push(root);
        
        // Process nodes until the queue is empty.
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Record the node's value in the set.
            s.insert(node->val);
            
            // Process the left child if it exists.
            if (node->left) {
                node->left->val = 2 * node->val + 1;  // Compute and assign left child's value.
                q.push(node->left);                   // Enqueue the left child.
            }
            // Process the right child if it exists.
            if (node->right) {
                node->right->val = 2 * node->val + 2;  // Compute and assign right child's value.
                q.push(node->right);                   // Enqueue the right child.
            }
        }
    }
    
    // Constructor for the FindElements class.
    // It takes the root of a contaminated binary tree and recovers it.
    // By default, DFS is used to recover the tree. Alternatively, you can call bfs(root, 0).
    FindElements(TreeNode* root) {
        s.clear();        // Ensure the set is empty.
        dfs(root, 0);     // Start recovery using DFS with the root value set to 0.
        // Alternatively, use BFS:
        // bfs(root, 0);
    }
    
    // The find() method checks if a target value exists in the recovered tree.
    // It returns true if the target is found in the set, and false otherwise.
    bool find(int target) {
        return s.count(target) > 0;
    }
};

int main() {
    // ------------------------
    // Construct a contaminated binary tree manually.
    //
    // Consider the following contaminated tree:
    //         -1
    //        /  \
    //      -1    -1
    //     /       \
    //   -1        -1
    //
    // The tree is built using TreeNode instances, all initially set to -1.
    // ------------------------
    
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->right->right = new TreeNode(-1);
    
    // ------------------------
    // Recover the tree using the FindElements class.
    // After recovery, the tree values should be updated as follows:
    //         0
    //        /  \
    //       1    2
    //      /      \
    //     3        6
    // ------------------------
    FindElements finder(root);
    
    // ------------------------
    // Test the find() method to see if specific target values exist in the recovered tree.
    // Expected outputs:
    // - find(1) should return True.
    // - find(2) should return True.
    // - find(3) should return True.
    // - find(4) should return False (since 4 is not in the tree).
    // - find(6) should return True.
    // ------------------------
    cout << "Find 1: " << (finder.find(1) ? "True" : "False") << endl;  // Expected output: True
    cout << "Find 2: " << (finder.find(2) ? "True" : "False") << endl;  // Expected output: True
    cout << "Find 3: " << (finder.find(3) ? "True" : "False") << endl;  // Expected output: True
    cout << "Find 4: " << (finder.find(4) ? "True" : "False") << endl;  // Expected output: False
    cout << "Find 6: " << (finder.find(6) ? "True" : "False") << endl;  // Expected output: True
    
    // ------------------------
    // Clean up the allocated memory to avoid memory leaks.
    // In production code, you would typically implement a destructor or use smart pointers.
    // ------------------------
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}
