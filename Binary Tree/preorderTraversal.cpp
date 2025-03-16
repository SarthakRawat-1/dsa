// Preorder traversal follows the Root-Left-Right policy where :- The root node of the subtree is visited first. Then the left subtree is traversed. At last, the right subtree is traversed.
// In simple terms, whenever we visit a node, we first visit it's left child. If a node doesn't have a left child, we then visit it's right child. This we have to check for each node.
// It can be denoted as NLR, first visit the node i.e. N, then go to left child i.e. L. As this left child will also be a Node so for this also NLR will apply. And hence, before visiting the right child of it's parent i.e. completing R for the parent. We will first do NLR for this child.

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
// void preorder(Node *root) {
//     if (root == NULL) { // Base case: If the root node is NULL, return, as this means there is no subtree to traverse.
//         return;
//     }

//     cout << root->data << " "; // Visit the root node.

//     preorder(root->left); // Visit the left subtree.
//     preorder(root->right); // Visit the right subtree.
// }

// Iterative Implementation
void preorder(Node *root) {
    stack<Node*> s; // Create a stack to store the nodes.
    s.push(root); // Push the root node onto the stack.

    while (!s.empty()) { // While the stack is not empty.
        Node* temp = s.top(); // Get the top node from the stack.
        s.pop(); // Remove the top node from the stack.

        cout << temp->data << " "; // Visit the current node.

        if (temp->right) { // If the right child of the current node is not NULL, push it onto the stack. Pushing right before left is important, as we access only to the node at top of Stack.
            s.push(temp->right);
        }
        if (temp->left) { // If the left child of the current node is not NULL, push it onto the stack.
            s.push(temp->left);
        }
    }   
}

int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    cout << "Preorder traversal of the binary tree is :- "; // Print the preorder traversal of the binary tree.
    preorder(root);

    return 0;
}


// Problem Statement :- https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
    }
};

// Solution class for preorder traversal.
class Solution {
    public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // Visit the current node
        result.push_back(node->val);

        // Traverse the left subtree
        preorderHelper(node->left, result);

        // Traverse the right subtree
        preorderHelper(node->right, result);
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

// Utility function to print the preorder traversal result
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
    vector<int> result = solution.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    printVector(result);

    return 0;
}
