// Problem Statement :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node class representing a single node in a binary tree
class TreeNode {
public:
    int val;          // Value stored in the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize the node with a value
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// Class containing the solution for zigzag level order traversal
class Solution {
public:
    /**
     * Function to perform zigzag level order traversal of a binary tree.
     * @param root: Pointer to the root node of the binary tree.
     * @return A 2D vector where each inner vector represents a level's nodes in zigzag order.
     */
    vector<vector<int>> ZigZagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // Vector to store the final zigzag traversal

        // If the tree is empty, return an empty result
        if (!root) {
            return result;
        }

        queue<TreeNode*> nodesQueue; // Queue to facilitate level order traversal
        nodesQueue.push(root);  // Start with the root node

        bool leftToRight = true; // Direction flag: true for left-to-right, false for right-to-left

        // Process nodes level by level
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size(); // Number of nodes at the current level
            vector<int> row(size);       // Vector to store the current level's nodes

            // Traverse all nodes at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodesQueue.front(); // Retrieve the front node from the queue
                nodesQueue.pop();

                // Determine the index to insert the node's value based on the direction
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = node->val;

                // Enqueue the left child if it exists
                if (node->left) {
                    nodesQueue.push(node->left);
                }

                // Enqueue the right child if it exists
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }

            // Add the current level's nodes to the result
            result.push_back(row);

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return result; // Return the zigzag level order traversal
    }
};

// Helper function to print the result of zigzag traversal
void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Creating a solution object
    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal: \n";
    printResult(result);

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
