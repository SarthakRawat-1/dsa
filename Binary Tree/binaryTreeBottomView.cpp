// Very similar to top view.

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to return the bottom view of the binary tree
    vector<int> bottomView(Node* root) {
        // Vector to store the result
        vector<int> ans;

        // Edge case: empty tree
        if (root == NULL) {
            return ans;
        }

        // Map to store nodes by their horizontal distance (HD)
        // Key   = HD (column index)
        // Value = node's data (last seen node at this HD)
        map<int, int> mpp;

        // Queue for BFS traversal
        // Each element is a pair of (node pointer, HD)
        queue<pair<Node*, int>> q;

        // Start with root at HD = 0
        q.push({root, 0});

        // BFS traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // For bottom view, we always overwrite the value at this HD
            mpp[line] = node->data;

            // If left child exists, push with HD - 1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // If right child exists, push with HD + 1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Collect results from leftmost HD to rightmost HD
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// Driver code
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the bottom view traversal
    vector<int> bottom = solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottom) {
        cout << node << " ";
    }

    return 0;
}
