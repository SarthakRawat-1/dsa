// Problem Statement :- https://www.geeksforgeeks.org/problems/level-order-traversal/1

// Level Order Traversal technique is defined as a method to traverse a Tree such that all nodes present in the same level are traversed completely before traversing the next level.
// This can be done efficiently using a Queue. Check implementingBinaryTreeUsingQueue.cpp, we are using an approach similar to that.

#include <bits/stdc++.h>
using namespace std;

// Define a Node class to represent each node in the binary tree.
class Node {
    public:
    int data;        // Stores the value of the node.
    Node* left;      // Pointer to the left child of the node.
    Node* right;     // Pointer to the right child of the node.

    // Constructor to initialize a node with a given value.
    Node (int value) {
        data = value;
        left = right = NULL; // Initially, left and right children are set to NULL.
    }
};

// Function to create a binary tree using recursive input.
Node* BinaryTree() {
    int x; 
    cin >> x; // Input the value for the current node.

    // Base case: If the input is -1, do not create a node; return NULL.
    if (x == -1) {
        return NULL;
    }

    // Create a new node with the input value.
    Node* temp = new Node(x);

    // Prompt the user to enter the left child for the current node.
    cout << "Enter the left child of " << x << " :- ";
    // Recursively create the left subtree. If -1 is input, the left pointer will remain NULL.
    temp->left = BinaryTree();

    // Prompt the user to enter the right child for the current node.
    cout << "Enter the right child of " << x << " :- ";
    // Recursively create the right subtree. If -1 is input, the right pointer will remain NULL.
    temp->right = BinaryTree();
    
    // Return the address of the created node to be connected to its parent.
    return temp;
}

vector<int> levelOrder(Node* root) {
    // Create a queue to store the nodes to be processed.
    // The queue helps in visiting nodes level by level.
    queue<Node*> q;

    // Push the root node into the queue to start the traversal.
    q.push(root);

    // Create a vector to store the result of the level-order traversal.
    vector<int> ans;

    // Temporary variable to hold the current node being processed.
    Node* temp;

    // Continue processing nodes until the queue becomes empty.
    while (!q.empty()) {
        // Retrieve and remove the front node from the queue.
        temp = q.front();
        q.pop();

        // Store the value of the current node in the result vector.
        ans.push_back(temp->data);

        // Check if the current node has a left child.
        // If it does, enqueue the left child to process it later.
        if (temp->left) {
            q.push(temp->left);
        }

        // Check if the current node has a right child.
        // If it does, enqueue the right child to process it later.
        if (temp->right) {
            q.push(temp->right);
        }
    }

    // Return the final vector containing the level-order traversal.
    return ans;
}

int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    cout << "Level order traversal of the binary tree is :- "; // Print the level order traversal of the binary tree.
    vector <int> ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


// Problem Statement :- https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // This will store the final level order traversal result.
        
        // If the tree is empty, return an empty result.
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q; // A queue to manage nodes during the BFS traversal.
        q.push(root); // Start the BFS with the root node.

        // Continue the BFS until there are no nodes left to process.
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level.
            vector<int> currentLevel; // Temporary container for the values of the current level.

            // Process all nodes at the current level.
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front(); // Get the front node from the queue.
                q.pop(); // Remove the processed node from the queue.
                
                // Add the value of the current node to the current level.
                currentLevel.push_back(currentNode->val);

                // If the current node has a left child, add it to the queue for processing in the next level.
                if (currentNode->left) {
                    q.push(currentNode->left);
                }

                // If the current node has a right child, add it to the queue for processing in the next level.
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }

            // Add the completed level to the result.
            result.push_back(currentLevel);
        }

        return result; // Return the final result containing all levels.
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
    vector<vector<int>> result = solution.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    printLevelOrder(result);

    return 0;
}


// Level Order Traversal in Spiral Form
// 