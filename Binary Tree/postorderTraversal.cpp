// Postorder traversal follows the Left-Right-Root policy such that :- The left subtree is traversed first. Then the right subtree is traversed Finally, the root node of the subtree is traversed.
// In simple terms, when we start from a node, we will first visit it's left child. If a node doesn't have a left child we will then visit it's right child. After that we will vsiit the node. This we have to check for each node.
// It can be denoted as LRN, first go to the left child i.e. L. Keep doing this till you find a node which doesn't have a left child (because for each node we have to implement LRN). Now, visit the right child of that node i.e.implement R. Once a node doesn't have any of the two child (so no new node is traversed and both L and R are completed). We can finally visit the node i.e. perform N.

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
void postorder(Node *root) {
    if (root == NULL) { // Base case: If the root node is NULL, return, as this means there is no subtree to traverse.
        return;
    }

    postorder(root->left); // Visit the left subtree.
    postorder(root->right); // Visit the right subtree.
    
    cout << root->data << " "; // Visit the root node.
}

// Iterative Implementation
// PostOrder means LRN and reverse of that is NRL, so if we find answer for NRL and then reverse the answer, we will get answer for LRN.
void postorder(Node* root) {
    stack <Node*> s; // Create a stack to store the nodes.

    s.push(root); // Push the root node onto the stack.

    vector <int> ans; // Create a vector to store the result of the postorder traversal.

    while(!s.empty()) {
        Node* temp = s.top(); // Get the top node from the stack.
        s.pop(); // Pop the top node from the stack.

        ans.push_back(temp->data); // Store the value of the current node in the result vector.

        if (temp->left) {
            s.push(temp->left); // Push the left child onto the stack. Pushing left before right is important, as we access only to the node at top of Stack.
        }

        if (temp->right) {
            s.push(temp->right); // Push the right child onto the stack.
        }
    }

    reverse(ans.begin(), ans.end()); // Reverse the order of the elements in the result vector.

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " "; // Print the elements of the result vector.
    }
}

// Iterative Implementation of Postorder Traversal Using Two Stacks
void postOrder(Node* root) {
    // Vector to store the result of the postorder traversal
    vector<int> postorder;

    // Step 1: Handle the base case where the tree is empty
    if (root == NULL) {
        // If the tree is empty, print a message and exit
        cout << "Tree is empty" << endl;
        return;
    }

    // Step 2: Initialize two stacks for the iterative traversal
    // st1: Used for processing nodes in a depth-first manner (similar to recursion)
    // st2: Used to reverse the order of nodes to match postorder traversal
    stack<Node*> st1, st2;

    // Step 3: Push the root node onto st1 to start the traversal
    st1.push(root);

    // Step 4: Process all nodes using st1
    while (!st1.empty()) {
        // Take the top node from st1
        root = st1.top();
        st1.pop(); // Remove it from st1

        // Push the current node onto st2
        // This ensures that the root is processed after its children
        st2.push(root);

        // If the current node has a left child, push it onto st1
        // Left child is processed before the right child to maintain postorder sequence
        if (root->left != NULL) {
            st1.push(root->left);
        }

        // If the current node has a right child, push it onto st1
        // Right child is processed after the left child
        if (root->right != NULL) {
            st1.push(root->right);
        }
    }

    // Step 5: Process nodes from st2 to construct the postorder traversal
    // At this point, st2 contains nodes in the reverse of the postorder sequence
    while (!st2.empty()) {
        // Take the top node from st2 and add its value to the postorder vector
        postorder.push_back(st2.top()->data);
        st2.pop(); // Remove the node from st2
    }

    // Step 6: Output the postorder traversal
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i] << " "; // Print each value in the postorder sequence
    }
}

int main() {
    cout << "Enter the root element :- ";

    // Call the BinaryTree function to create the tree starting from the root node.
    Node* root = BinaryTree();

    cout << "Postorder traversal of the binary tree is :- "; // Print the postorder traversal of the binary tree.
    postorder(root);

    return 0;
}


// Problem Statement :- https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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

// Solution class for postorder traversal.
class Solution {
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

    private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // Traverse the left subtree
        postorderHelper(node->left, result);

        // Traverse the right subtree
        postorderHelper(node->right, result);

        // Visit the current node
        result.push_back(node->val);
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
    vector<int> result = solution.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    printVector(result);

    return 0;
}
