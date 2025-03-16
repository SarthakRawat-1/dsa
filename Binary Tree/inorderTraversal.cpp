// Inorder traversal follows the Left-Root-Right pattern, such that :- The left subtree is traversed first. Then the root node for that subtree is traversed. Finally, the right subtree is traversed 
// In simple terms, when we start from a node, we will first visit it's left child. If a node doesn't have a left child, we will now visit that node (which didn't had a left child). After that we will visit it's right child. This we have to check for each node.
// It can be denoted as LNR, first go to the left child i.e. L. Keep doing this till you find a node which doesn't have a left child (because for each node we have to implement LNR). Now, visit the node i.e. perform N. Finally, visit the right child of that node i.e. implement R. 

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

// Recursive Implementation
void inorder(Node *root) {
    if (root == NULL) { // Base case: If the root node is NULL, return, as this means there is no subtree to traverse.
        return;
    }

    inorder(root->left); // Visit the left subtree.
    cout << root->data << " "; // Visit the root node.
    inorder(root->right); // Visit the right subtree.
}

// Iterative Implementation
// Here we will need to maintain two Stacks. We have LNR, so when we visit the node second time, that's when we have to print that. One stack will hold the number of times the values have been visited.
void inorder(Node *root) {
    // Stack to hold the nodes of the tree
    stack<Node*> s;
    // Stack to keep track of whether the node has been visited for inorder
    stack<bool> visited;

    // If the tree is empty, return
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }

    // Vector to store the inorder traversal result
    vector<int> ans;

    // Push the root node onto the stack with false, meaning the node hasn't been visited
    s.push(root);
    visited.push(false);

    // While there are nodes in the stack to process
    while (!s.empty()) {
        // Get the node at the top of the stack
        Node* temp = s.top();
        s.pop();  // Remove it from the stack

        // Get the flag indicating if the node has been visited
        bool flag = visited.top();
        visited.pop();  // Remove the flag from the visited stack

        // If the node hasn't been visited, process it
        if (!flag) {
            // First push the right child to the stack (if any), it will be processed later
            if (temp->right) {
                s.push(temp->right);
                visited.push(false);  // Mark it as not visited
            }

            // Push the current node back onto the stack with flag set to true (to mark it for visit)
            s.push(temp);
            visited.push(true);

            // Then push the left child to the stack (if any), so it will be processed first
            if (temp->left) {
                s.push(temp->left);
                visited.push(false);  // Mark left child as not visited
            }
        } else {
            // If the node has been visited, we can add its value to the result vector
            ans.push_back(temp->data);
        }
    }

    // Output the inorder traversal result
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    cout << "Inorder traversal of the binary tree is :- "; // Print the inorder traversal of the binary tree.
    inorder(root);

    return 0;
}


// Problem Statement :- https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class for inorder traversal.
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorderHelper(node->left, result);

        // Visit the current node
        result.push_back(node->val);

        // Traverse the right subtree
        inorderHelper(node->right, result);
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

// Utility function to print the traversal result
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> treeNodes = {1, -1, 2, -1, -1, 3};

    TreeNode* root = buildTree(treeNodes, 0);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    printVector(result);

    return 0;
}
