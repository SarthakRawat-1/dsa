// Problem Statement :- https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1

// Method 1 :- Last element will be the root node. Then simply we can make the BST like how we normally do (but visit node from right to left in traversal).

// Method 2 :- Same Logic as in constructBSTfromPreorder.cpp
// Just slight change, we were going in NLR form in constructBSTfromPreorder.cpp, but now we are going in NRL form. Reverse of NRL is LRN which is Postorder traversal.

#include <iostream>   // For input/output operations.
#include <climits>    // For INT_MIN and INT_MAX.
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;       // The value stored in the node.
    Node* left;     // Pointer to the left child.
    Node* right;    // Pointer to the right child.

    // Constructor to initialize the node with a value and set children to nullptr.
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

/*
 * Function: BST
 * -------------
 * Constructs a BST from the given postorder traversal array.
 *
 * Parameters:
 * - post: Array of integers representing the postorder traversal.
 * - index: Reference to the current index in the postorder array. Since we process
 *          the array from the end (postorder: left-right-root), this index is
 *          decreased as nodes are processed.
 * - min: The minimum value allowed for the current node (to maintain BST property).
 * - max: The maximum value allowed for the current node.
 *
 * Returns:
 * - Pointer to the root node of the subtree constructed from the postorder array.
 *
 * Explanation:
 * - In postorder traversal, the last element is the root.
 * - The function creates a new node if the current postorder element is within the valid
 *   range [min, max]. Then, it recursively constructs the right subtree (using the updated
 *   range from current node's value to max) followed by the left subtree (range: min to current node's value).
 */
Node* BST(int post[], int& index, int min, int max) {
    // If there are no more elements to process or the current element does not satisfy
    // the BST constraints, return nullptr.
    if (index < 0 || post[index] < min || post[index] > max)
        return nullptr;

    // Create a new node with the current postorder element.
    Node* root = new Node(post[index--]);

    // Recursively construct the right subtree first.
    // For the right child, valid values are in the range [root->data, max].
    root->right = BST(post, index, root->data, max);

    // Then, recursively construct the left subtree.
    // For the left child, valid values are in the range [min, root->data].
    root->left = BST(post, index, min, root->data);

    // Return the constructed node.
    return root;
}

/*
 * Function: constructTree
 * -----------------------
 * Initiates the construction of the BST from the postorder traversal array.
 *
 * Parameters:
 * - post: Array of integers representing the postorder traversal.
 * - size: The number of elements in the postorder array.
 *
 * Returns:
 * - Pointer to the root node of the constructed BST.
 *
 * Explanation:
 * - Since postorder traversal is in left-right-root order, the last element in the array
 *   is the root. The function initializes the index to the last element and calls the BST
 *   helper function with the full range [INT_MIN, INT_MAX].
 */
Node* constructTree(int post[], int size) {
    int index = size - 1; // Start from the last element in the postorder array.
    return BST(post, index, INT_MIN, INT_MAX);
}

/*
 * Function: inorderTraversal
 * --------------------------
 * Performs an inorder traversal of the BST and prints node values.
 * Inorder traversal of a BST prints values in sorted (ascending) order.
 *
 * Parameters:
 * - root: Pointer to the root of the BST.
 */
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);       // Traverse the left subtree.
    cout << root->data << " ";          // Print the current node's data.
    inorderTraversal(root->right);      // Traverse the right subtree.
}

/*
 * Function: deleteTree
 * --------------------
 * Deletes all nodes of the BST to free allocated memory.
 * Uses a postorder traversal (left-right-root) to safely delete nodes.
 *
 * Parameters:
 * - root: Pointer to the root of the BST.
 */
void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);   // Delete left subtree.
    deleteTree(root->right);  // Delete right subtree.
    delete root;              // Delete current node.
}

int main() {
    // ------------------------
    // Example postorder traversal array.
    // For instance, consider the postorder array:
    // {1, 7, 5, 50, 40, 10}
    // The BST constructed from this array should satisfy BST properties.
    // ------------------------
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(post) / sizeof(post[0]);

    // Construct the BST from the postorder array.
    Node* root = constructTree(post, size);

    // ------------------------
    // Verify the constructed BST by performing an inorder traversal.
    // Inorder traversal of a BST should print the values in ascending order.
    // ------------------------
    cout << "Inorder Traversal of Constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    // Clean up the dynamically allocated memory for the BST.
    deleteTree(root);

    return 0;
}
