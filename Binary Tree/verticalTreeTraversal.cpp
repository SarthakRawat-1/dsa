// Problem Statement :- https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// The logic for solving this will be similar to the one in top view of Binary Tree.
// We will put 0 as index of the root node of Binary Tree. All nodes at the same vertical level (for eg :- L + R will be at same level as L and R will cancel each other) will be marked 0.
// All nodes, one vertical level to the left of it (which can be L or L + L + R as L and R will cancel and so on) will be marked -1.
// All nodes, two vertical level to the left of it (L or L + L + R + L etc) will be marked -2.
// Similarly, nodes one vertical level to the right of the root node will be marked 1 and so on.
// The lower the marked number, the earlier they appear in the traversal.
// If there are more than one node at the same vertical level, the node with the smaller level (horizontal level) will be printed first.

// But how do we traverse this tree to find the lowest marked number? 
// Use a 2D array to store negative marked numbers (not elements of binary tree but the numbers you have marked them with i.e. -1, -2, row index of this 2D array i.e. 1 and 2 will denote -1, -2 respectively).
// Simialrly, make one for positive numbers (row index of this 2D array will denote marked numbers too). 
// Now use Level order traversal on tree, when you find an element, check it's marked number and store it accordingly in one of the 2D arrays with correct row index.
// Now simply create a 1D array, and store the results accordingly in it from those 2D arrays.

#include <bits/stdc++.h>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    int data;       // The value stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child
};

/*
 * Helper function to determine the horizontal boundaries (min and max vertical indices)
 * for the binary tree.
 *
 * Parameters:
 *   - root: pointer to the current node in the tree.
 *   - pos: the current horizontal distance (vertical index) from the root.
 *          For the root, pos is initialized as 0.
 *          For left child, pos decreases by 1.
 *          For right child, pos increases by 1.
 *   - l: reference to an integer that stores the minimum horizontal distance encountered.
 *   - r: reference to an integer that stores the maximum horizontal distance encountered.
 *
 * This function updates l and r with the lowest and highest indices found in the tree.
 */
void find(Node* root, int pos, int &l, int &r) {
    // Base case: if the current node is NULL, return.
    if(root == NULL) {
        return;
    }

    // Update the minimum and maximum horizontal distances.
    l = min(l, pos);
    r = max(r, pos);

    // Recursively find boundaries in the left subtree with pos-1
    find(root->left, pos - 1, l, r);
    // Recursively find boundaries in the right subtree with pos+1
    find(root->right, pos + 1, l, r);
}

/*
 * Function to print the vertical order traversal of a binary tree.
 *
 * The idea:
 * 1. Use a modified level order traversal (BFS) to ensure nodes are processed level by level.
 * 2. Keep track of the horizontal distance (vertical index) for each node.
 *    - The root is at index 0.
 *    - Left child is at pos-1.
 *    - Right child is at pos+1.
 * 3. Since the horizontal distance (or marked number) can be negative or positive,
 *    we store nodes in two separate 2D vectors:
 *      - 'negative' for nodes with negative horizontal distance.
 *      - 'positive' for nodes with zero or positive horizontal distance.
 * 4. Finally, merge these two arrays (processing the negative side in reverse order)
 *    to get the final vertical order.
 *
 * Returns:
 *   A vector<int> containing the vertical order traversal of the tree.
 */
vector<int> verticalOrder(Node *root) {
    // Variables to store the minimum (l) and maximum (r) horizontal distances.
    int l = 0, r = 0;
    // Determine the boundaries of the horizontal distances in the tree.
    find(root, 0, l, r);

    // Create 2D vectors to store nodes according to their horizontal distance.
    // 'positive' holds nodes with horizontal distance >= 0.
    // The size is (r + 1) because indices range from 0 to r.
    vector<vector<int>> positive(r + 1);
    // 'negative' holds nodes with horizontal distance < 0.
    // The size is (abs(l) + 1) because if l is -3 then we need indices 1,2,3 to store -1,-2,-3 respectively.
    vector<vector<int>> negative(abs(l) + 1);

    // Initialize two queues for level order traversal:
    // One for nodes and another for their corresponding horizontal indices.
    queue<Node*> q;
    queue<int> index;

    // Start with the root node at horizontal index 0.
    q.push(root);
    index.push(0);

    // Process the tree using level order traversal.
    while(!q.empty()) {
        // Get the front node and its horizontal position.
        Node* temp = q.front();
        q.pop();

        int pos = index.front();
        index.pop();

        // Depending on the horizontal distance, add the node's data to the appropriate vector.
        if (pos >= 0) {
            // For non-negative positions, store in 'positive' vector.
            positive[pos].push_back(temp->data);
        } else {
            // For negative positions, store in 'negative' vector.
            // We use abs(pos) to convert negative index into positive index for the vector.
            negative[abs(pos)].push_back(temp->data);
        }

        // If the left child exists, push it into the queue with horizontal distance pos - 1.
        if (temp->left) {
            q.push(temp->left);
            index.push(pos - 1);
        }

        // If the right child exists, push it into the queue with horizontal distance pos + 1.
        if (temp->right) {
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    // Vector to hold the final vertical order traversal.
    vector<int> ans;

    /*
     * First, add the nodes from the negative horizontal distances.
     * Since in the vertical order the leftmost columns (more negative)
     * should come first, we iterate from the highest index in 'negative'
     * (which corresponds to the smallest horizontal distance) down to 1.
     */
    for(int i = negative.size() - 1; i > 0; i--) {
        // Append all nodes stored in this vertical level.
        for(int j = 0; j < negative[i].size(); j++) {
            ans.push_back(negative[i][j]);
        }
    }

    /*
     * Then, add the nodes from the non-negative horizontal distances.
     * Here, we iterate from 0 to the maximum horizontal distance.
     */
    for(int i = 0; i < positive.size(); i++) {
        // Append all nodes stored in this vertical level.
        for(int j = 0; j < positive[i].size(); j++) {
            ans.push_back(positive[i][j]);
        }
    }
    
    // Return the final vertical order traversal.
    return ans;
}

int main() {
    // Example usage:
    // Create a simple binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    // Get the vertical order traversal of the tree.
    vector<int> vertical = verticalOrder(root);

    // Print the vertical order traversal.
    for (int val : vertical) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
