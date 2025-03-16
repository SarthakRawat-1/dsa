// Morris Traversal is a tree traversal algorithm that performs in-order or pre-order traversal without using extra space for recursion or a stack. It modifies the tree temporarily to achieve O(1) space complexity while maintaining O(n) time complexity.

// The main problem of not using a stack for inorder traversal is that how will we come back to the node after going to it's left subtree.
// This can be solved using this way :-
// For every node, we will go the root of the left subtree, and from there we will keep going to the rightmost node from there. The last rightmost node will point to the original node now. 
// Hence, from there we can go back to the node after traversing the left subtree.

// But how will a node deduce that it's left subtree has been traversed?
// We can simply deduce it by checking if there is a link to that node from that rightmost node. This too we can easily find if we again to the left part and in a cycle or loop, return back to the original node.

// Similarly for preorder, rest of the algorithm remains same.
// but we will first include the result in vector before going to left subtree. 
// We will check if for a node it's left subtree is traversed. If it is, then we won't include that in the answer again.

// For postorder traversal, we can't use Morris Traversal directly. 
// But Postorder is LRN. If we reverse it, it becomes NRL. NRL we can do using Morris Traversal. The reverse of that result will be postorder traversal.
// For NRL also, you will have to create link and check conditions, as we did in preorder traversal.

#include <iostream>
#include <vector>
using namespace std;

// Structure for a node in the binary tree
struct Node {
    int data;      // Value stored in the node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child
};

// Function that returns the in-order traversal of a binary tree using Morris Traversal
vector<int> inOrder(Node* root) {
    vector<int> ans;  // Vector to store the in-order traversal results

    // Traverse the tree until there are no nodes left to process
    while (root) {
        // Case 1: If there is no left subtree, process the current node and move to right child.
        if (root->left == nullptr) {
            // Since there is no left subtree, we can directly add the current node's data.
            ans.push_back(root->data);
            // Move to the right subtree
            root = root->right;
        } else {
            // Case 2: The current node has a left subtree.
            // Find the inorder predecessor of the current node in its left subtree.
            // The inorder predecessor is the rightmost node in the current node's left subtree.
            Node* predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root) {
                predecessor = predecessor->right;
            }
            
            // If the right child of the inorder predecessor is null, then we haven't yet established a link back to the current node.
            if (predecessor->right == nullptr) {
                // Establish a temporary link (thread) from the predecessor back to the current node.
                predecessor->right = root;
                // Move current node to its left child to continue traversal.
                root = root->left;
            } 
            // Else, a thread already exists which means we've finished traversing the left subtree.
            else {
                // Remove the temporary thread, restoring the original tree structure.
                predecessor->right = nullptr;
                // Process the current node's data now that the left subtree has been fully visited.
                ans.push_back(root->data);
                // Move to the right subtree to continue the in-order traversal.
                root = root->right;
            }
        }
    }
    
    // Return the vector containing the in-order traversal sequence.
    return ans;
}

// Function that returns the pre-order traversal of a binary tree using Morris Traversal.
vector<int> preOrder(Node* root) {
    vector<int> ans;  // Vector to store the pre-order traversal results.

    // Traverse the tree until there are no nodes left to process.
    while (root) {
        // Case 1: If there is no left subtree, process the current node and move to its right child.
        if (root->left == nullptr) {
            // Process the current node (add its data to the result vector).
            ans.push_back(root->data);
            // Move directly to the right child.
            root = root->right;
        } else {
            // Case 2: The current node has a left subtree.
            // Find the inorder predecessor of the current node in the left subtree.
            // The predecessor is the rightmost node in the current node's left subtree.
            Node* predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root) {
                predecessor = predecessor->right;
            }
            
            // If the right pointer of the predecessor is null, it means we haven't yet
            // established a link back to the current node.
            if (predecessor->right == nullptr) {
                // Process the current node before going to the left subtree (pre-order: root before left).
                ans.push_back(root->data);
                // Establish a temporary link (thread) from the predecessor back to the current node.
                predecessor->right = root;
                // Move to the left child to continue traversal.
                root = root->left;
            } else {
                // If the thread already exists, it means the left subtree has been processed.
                // Remove the temporary thread to restore the tree structure.
                predecessor->right = nullptr;
                // Now, move to the right child of the current node.
                root = root->right;
            }
        }
    }
    
    // Return the vector containing the pre-order traversal sequence.
    return ans;
}

int main() {
    // Example usage:
    // Constructing the following binary tree:
    //         4
    //        / \
    //       2   6
    //      / \ / \
    //     1  3 5  7

    Node* root = new Node{4, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{6, nullptr, nullptr};
    root->left->left = new Node{1, nullptr, nullptr};
    root->left->right = new Node{3, nullptr, nullptr};
    root->right->left = new Node{5, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    vector<int> traversal = inOrder(root);

    // Print the in-order traversal result
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup: Deallocate the created nodes.
    // (In production code, you'd need to properly delete every allocated node.)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
