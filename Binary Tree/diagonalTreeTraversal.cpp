// Problem Statement :- https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// In this too, if we consider the number of lefts and number of rights that we need to take to arrive at a node from root node, we will observe a pattern for nodes in a diagonal.
// We will create a 2D array where the row index represents the number of lefts. Same number of lefts for elements means they are in a diagonal. We will store elements of the tree in the row index representing numebr of lefts.
// If we have multiple elements on the same diagonal from both left and right subtree, we have to first traverse the left subtree.
// We can use preorder traversal to visit and store the elements in 2D array.

#include <bits/stdc++.h>
using namespace std;

// Structure defining a node of the binary tree.
struct Node {
    int data;       // The value stored in the node.
    Node* left;     // Pointer to the left child.
    Node* right;    // Pointer to the right child.
};

/*
 * Function: find
 * ----------------------------
 * Traverses the binary tree to determine the maximum diagonal index,
 * which is defined as the number of left moves taken from the root.
 *
 * Here, when we go to the left child, we increment the diagonal index (pos) by 1.
 * For the right child, the diagonal index remains unchanged.
 *
 * Parameters:
 *   - root: Pointer to the current node.
 *   - pos: The current diagonal index (number of left moves from the root).
 *   - l: Reference to an integer that stores the maximum diagonal index encountered.
 *
 * The function updates 'l' so that after traversal, 'l' equals the highest number of left moves
 * encountered along any path from the root. This will help in determining the size of the
 * 2D vector used for storing nodes by their diagonal.
 */
void find(Node* root, int pos, int &l) {
    // Base case: if the current node is NULL, simply return.
    if (root == NULL) {
        return;
    }
    
    // Update the maximum diagonal index encountered.
    l = max(l, pos);

    // For the left subtree, increment the diagonal index (pos+1) because a left move means a new diagonal.
    find(root->left, pos + 1, l);
    // For the right subtree, the diagonal index remains the same.
    find(root->right, pos, l);
}

/*
 * Function: findDig
 * ----------------------------
 * Populates a 2D vector with nodes grouped by their diagonal index.
 *
 * Each row in the vector 'ans' represents a diagonal of the binary tree.
 * Nodes that are on the same diagonal (i.e., have the same number of left moves from the root)
 * are stored in the same row.
 *
 * Parameters:
 *   - root: Pointer to the current node.
 *   - pos: The current diagonal index for the node.
 *   - ans: A reference to a 2D vector where each row corresponds to a diagonal.
 *
 * The function uses a preorder traversal to ensure that nodes from the left subtree
 * (which should appear first for the same diagonal) are processed before the right subtree.
 */
void findDig(Node* root, int pos, vector<vector<int>> &ans) {
    // Base case: if the node is NULL, return.
    if (root == NULL) {
        return;
    }

    // Add the current node's data to the corresponding diagonal group.
    ans[pos].push_back(root->data);

    // Recur for the left child: a left move increases the diagonal index.
    findDig(root->left, pos + 1, ans);
    // Recur for the right child: a right move does not change the diagonal index.
    findDig(root->right, pos, ans);
}

/*
 * Function: diagonal
 * ----------------------------
 * Performs a diagonal traversal of a binary tree and returns the traversal as a 1D vector.
 *
 * The idea behind the diagonal traversal is:
 *   1. Determine the maximum diagonal index (number of left moves) in the tree using the 'find' function.
 *   2. Create a 2D vector where each row corresponds to one diagonal.
 *   3. Use the 'findDig' function to store nodes in their respective diagonal (row) based on the number of left moves.
 *   4. Flatten the 2D vector into a single 1D vector where the diagonals are concatenated in order.
 *
 * Returns:
 *   A vector<int> containing the nodes in the order of diagonal traversal.
 */
vector<int> diagonal(Node *root) {
    // 'l' will hold the maximum diagonal index found in the tree.
    int l = 0;
    
    // Determine the maximum number of left moves (i.e., maximum diagonal index).
    find(root, 0, l);

    // Create a 2D vector with (l+1) rows.
    // Each row 'i' will store nodes that are on the i-th diagonal.
    vector<vector<int>> ans(l + 1);

    // Fill the 2D vector with nodes from the tree grouped by their diagonal index.
    findDig(root, 0, ans);

    // Create a vector to store the final diagonal traversal order.
    vector<int> temp;

    // Flatten the 2D vector by concatenating each diagonal group.
    // The diagonals are processed from top (diagonal 0) to bottom (diagonal l).
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            temp.push_back(ans[i][j]);
        }  
    }
    
    // Return the final 1D vector representing the diagonal traversal.
    return temp;
}

int main() {
    // Example usage:
    // Construct the following binary tree:
    //          1
    //         / \
    //        2   3
    //       / \   \
    //      4   5   6
    //
    // Expected diagonal groups:
    //   Diagonal 0: 1, 3, 6
    //   Diagonal 1: 2, 5
    //   Diagonal 2: 4

    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->right = new Node{6, nullptr, nullptr};

    // Get the diagonal traversal of the binary tree.
    vector<int> result = diagonal(root);

    // Print the diagonal traversal.
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
