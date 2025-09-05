// Problem Statement :- 

// Please look at amountofTimeForBinaryTreetoInfected.cpp first.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     * Convert the binary tree into an undirected graph (adjacency list)
     * Each node connects to its parent and children.
     */
    void convert(TreeNode* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) return;

        // Connect current node with its parent
        if (parent != -1) {
            adj[current->val].push_back(parent);
        }

        // Connect current node with its children
        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        } 
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }

        // Recursive calls for left and right child
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    /*
     * BFS traversal to find all nodes at distance K from the target.
     */
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);  // Build adjacency list

        queue<int> q;
        unordered_set<int> visited;

        // Start BFS from the target node
        q.push(target->val);
        visited.insert(target->val);

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();

            // If we've reached distance K, stop expanding further
            if (dist == k) break;
            dist++;

            while (size--) {
                int curr = q.front();
                q.pop();

                // Traverse all neighbors of current node
                for (int ngbr : adj[curr]) {
                    // Only process unvisited nodes
                    if (visited.find(ngbr) == visited.end()) {
                        q.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
        }

        // Remaining nodes in the queue are exactly distance K from target
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};


int main() {

}