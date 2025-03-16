// Problem Statement :- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// The Boundary Traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root. 

#include <iostream>
#include <vector>

using namespace std;

// Node class representing a single node in a binary tree
class Node {
public:
    int data;          // Value stored in the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize the node with a given value.
    // Both left and right children are initially set to nullptr.
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class containing the solution for boundary traversal of a binary tree
class Solution {
public:
    /*
     * Function: isLeaf
     * ----------------------------
     * Checks whether the given node is a leaf node.
     *
     * A node is considered a leaf if:
     *   - It is not a nullptr, and
     *   - It does not have any left or right children.
     *
     * Parameters:
     *   - root: Pointer to the current node.
     *
     * Returns:
     *   - true if the node is a leaf, otherwise false.
     */
    bool isLeaf(Node* root) {
        return root && !root->left && !root->right;
    }

    /*
     * Function: addLeftBoundary
     * ----------------------------
     * Traverses the left boundary of the binary tree (excluding the leaf nodes)
     * and adds the values of those nodes to the result vector.
     *
     * The left boundary is defined as the path from the root's left child down
     * to the last non-leaf node along the leftmost edge.
     *
     * Parameters:
     *   - root: Pointer to the root of the tree.
     *   - res: Reference to a vector that stores the boundary traversal result.
     *
     * Process:
     *   1. Start with the left child of the root.
     *   2. For each node encountered, if it's not a leaf, add its value.
     *   3. Move to the next node by preferring the left child; if no left child
     *      exists, then move to the right child.
     */
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            // Check if the current node is not a leaf before adding it.
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            // Prefer the left child for the next step; if left child is missing,
            // then use the right child.
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    /*
     * Function: addRightBoundary
     * ----------------------------
     * Traverses the right boundary of the binary tree (excluding the leaf nodes)
     * and adds the values of those nodes to the result vector.
     *
     * The right boundary is defined as the path from the root's right child down
     * to the last non-leaf node along the rightmost edge.
     *
     * Since we need to output the right boundary in bottom-up order (to follow
     * anticlockwise traversal), we temporarily store the nodes in a vector and
     * then reverse it before adding to the final result.
     *
     * Parameters:
     *   - root: Pointer to the root of the tree.
     *   - res: Reference to a vector that stores the boundary traversal result.
     *
     * Process:
     *   1. Start with the right child of the root.
     *   2. For each node encountered, if it's not a leaf, add its value to a temporary vector.
     *   3. Move to the next node by preferring the right child; if no right child exists,
     *      then move to the left child.
     *   4. After the loop, reverse the temporary vector and append its values to the result.
     */
    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp; // Temporary vector to hold right boundary nodes
        while (curr) {
            // Add node value only if it's not a leaf.
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Prefer the right child for the next step; if right child is missing,
            // then use the left child.
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Reverse the temporary vector to get the correct order (bottom-up)
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    /*
     * Function: addLeaves
     * ----------------------------
     * Recursively traverses the binary tree and adds the leaf nodes' values
     * to the result vector.
     *
     * A leaf node is defined as a node with no left and right children.
     *
     * Parameters:
     *   - root: Pointer to the current node in the traversal.
     *   - res: Reference to a vector that stores the boundary traversal result.
     *
     * Process:
     *   1. If the current node is null, return.
     *   2. If the current node is a leaf, add its value to the result.
     *   3. Otherwise, recursively process the left subtree followed by the right subtree.
     */
    void addLeaves(Node* root, vector<int>& res) {
        // Base case: if node is nullptr, simply return.
        if (!root) return;

        // If the node is a leaf, add its data and return.
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        // Recursively traverse the left subtree.
        if (root->left) {
            addLeaves(root->left, res);
        }
        // Recursively traverse the right subtree.
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    /*
     * Function: printBoundary
     * ----------------------------
     * Performs the boundary traversal of the binary tree in an anticlockwise direction.
     *
     * The boundary traversal order is:
     *   1. Root node (if it's not a leaf).
     *   2. Left boundary (excluding the leaf nodes).
     *   3. All the leaf nodes (from left subtree then right subtree).
     *   4. Right boundary (excluding the leaf nodes, added in bottom-up order).
     *
     * Parameters:
     *   - root: Pointer to the root of the binary tree.
     *
     * Returns:
     *   - A vector of integers representing the boundary traversal.
     */
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        // If the tree is empty, return an empty vector.
        if (!root) {
            return res;
        }

        // Add the root's data if it is not a leaf node.
        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        // Add the left boundary nodes (excluding the leaves).
        addLeftBoundary(root, res);

        // Add all the leaf nodes.
        addLeaves(root, res);

        // Add the right boundary nodes (excluding the leaves) in bottom-up order.
        addRightBoundary(root, res);

        // Return the final boundary traversal result.
        return res;
    }
};

// Helper function to print the boundary traversal result stored in a vector
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    //
    // The expected boundary traversal (anticlockwise) is:
    //   Root: 1
    //   Left boundary (excluding leaf nodes): 2
    //   Leaves (from left to right): 4, 5, 6, 7
    //   Right boundary (excluding leaf nodes, in reverse): 3
    // Final Output: 1 2 4 5 6 7 3

    Node* root = new Node(1);         // Root node
    root->left = new Node(2);           // Left child of root
    root->right = new Node(3);          // Right child of root
    root->left->left = new Node(4);     // Left child of node 2
    root->left->right = new Node(5);    // Right child of node 2
    root->right->left = new Node(6);    // Left child of node 3
    root->right->right = new Node(7);   // Right child of node 3

    // Creating a Solution object to perform boundary traversal.
    Solution solution;

    // Get the boundary traversal of the tree.
    vector<int> result = solution.printBoundary(root);

    // Print the result.
    cout << "Boundary Traversal: ";
    printResult(result);

    // Clean up dynamically allocated memory to prevent memory leaks.
    delete root->left->left;    // Delete node 4
    delete root->left->right;   // Delete node 5
    delete root->right->left;   // Delete node 6
    delete root->right->right;  // Delete node 7
    delete root->left;          // Delete node 2
    delete root->right;         // Delete node 3
    delete root;                // Delete root node

    return 0;
}

