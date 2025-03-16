// Problem Statement :- https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// The left view of a Binary Tree is a set of leftmost nodes for every level.

// Method 1 :- Using Queue
// To solve this, we can simply use Level Order traversal. For every level, we will put the leftmost node in the result.

// Method 2 :- Using Recursion
// We start from root node, this will obviously be in our answer. Then we first traverse the left side, and the node here will also be our answer as we want the leftmost node and we have arrived at this level for the first time.
// Hence, we have to only keep track of the level, if we arrive at a new level, then that node will be our answer (as we are traversing left side first) and all nodes after that in same level will not be our answer.
// To keep track of level, we can use an array of size which can represent all of the levels of the tree from 0 to n. All elements will be initialized with 0 which indicates that we have not visited that level yet. When we arrive at a new level, we will mark that level as visited by updating that element of the array to 1.
// To create this array however, you need to traverse tree beforehand to know the number of levels. What if u don't want to traverse a tree beforehand?
// In this case, first we put root node becz obv it is going to be in answer. Then we traverse left side. If we assume level starting from 0, we just have to check if the current node level is equal to size of ans array. If it is, then we have visited that level first time, and hence push that node in ans array.

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

// Method 1 :- Using Queue and Level Order Traversal
// Function to compute the left view of a binary tree.
// The left view contains the first node at each level of the tree when viewed from the left.
vector<int> leftView(Node* root) {
    // Queue to facilitate level-order traversal of the tree.
    queue<Node*> q;
    // Vector to store the result (left view of the tree).
    vector<int> ans;

    // If the tree is empty, return an empty vector.
    if (root == NULL) {
        return ans;
    }

    // Push the root node into the queue to start the traversal.
    q.push(root);

    // Perform a level-order traversal.
    while (!q.empty()) {
        // Add the first node of the current level to the result.
        ans.push_back(q.front()->data);

        // Get the number of nodes at the current level.
        int n = q.size();

        // Process all nodes at the current level.
        while (n--) {
            // Remove the front node from the queue.
            Node* temp = q.front();
            q.pop();

            // Add the left child of the current node to the queue, if it exists.
            if (temp->left) {
                q.push(temp->left);
            }

            // Add the right child of the current node to the queue, if it exists.
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    // Return the computed left view.
    return ans;
}


// Method 2 :- Using Recursion
// It traverses the tree in pre-order fashion (Root-Left-Right) and captures the first node at each level.
void Lview(Node* root, int level, vector<int>& ans) {
    // Base case: If the current node is null, return.
    if (!root) {
        return;
    }

    // If the current level is being visited for the first time (size of ans equals level),
    // add the current node's data to the result.
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // Recur for the left subtree first to prioritize left-side nodes.
    Lview(root->left, level + 1, ans);
    
    // Recur for the right subtree.
    Lview(root->right, level + 1, ans);
}

// Function to compute the left view of a binary tree using recursion.
vector<int> leftView(Node* root) {
    // Vector to store the result (left view of the tree).
    vector<int> ans;

    // If the tree is empty, return an empty vector.
    if (!root) {
        return ans;
    }

    // Call the recursive helper function starting from level 0.
    Lview(root, 0, ans);

    // Return the computed left view.
    return ans;
}

int main() {
    cout << "Enter the root element :- ";

    Node* root = BinaryTree();

    cout << "Left view of the binary tree is :- "; 

    vector<int> ans = leftView(root);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}