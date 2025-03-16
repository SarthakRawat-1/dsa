// Bread First Search (BFS) is a graph traversal algorithm that starts traversing the graph from the root node and explores all the neighboring nodes. 
// Then, it selects the nearest node and explores all the unexplored nodes. 
// While using BFS for traversal, any node in the graph can be considered as the root node.
// Steps to follow :-
// 1. Start at a node (usually the starting or root node).
// 2. Visit all its immediate neighbors (nodes directly connected to it).
// 3. Move to the next level, visiting the neighbors of those neighbors.
// 4. Repeat this process until all nodes are visited or the target node is found.

#include <bits/stdc++.h>
using namespace std;

// Function to perform Breadth First Search (BFS) traversal
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Create a queue to manage the BFS process
    queue<int> q;

    // Start BFS from node 0
    q.push(0);

    // Create a visited array to track visited nodes
    vector<bool> visited(V, false);
    visited[0] = true; // Mark the starting node as visited

    // Vector to store the BFS traversal order
    vector<int> bfs;
    int node;

    // Process the queue until it's empty
    while (!q.empty()) {
        // Extract the front node from the queue
        node = q.front();
        q.pop();

        // Add the node to the BFS traversal result
        bfs.push_back(node);

        // Visit all the adjacent nodes of the current node
        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];
            // If the neighbor node has not been visited
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor);         // Add it to the queue
            }
        }
    }

    return bfs;
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    // Perform BFS traversal starting from node 0
    vector<int> result = bfsOfGraph(V, adj);

    cout << "BFS Traversal of the graph: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}