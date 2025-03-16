// Depth First Search (DFS) is a graph traversal algorithm that starts at the root node and explores as far as possible along each branch before backtracking. 
// It uses a stack or recursion to traverse nodes and ensures each node is visited only once using a boolean visited array to avoid cycles.
// Steps to follow :-
// 1. Start at a node (usually the starting or root node).
// 2. Visit a neighbor (a directly connected node).
// 3. Keep going deeper into neighbors until you reach a node with no unvisited neighbors.
// 4. Backtrack to the previous node and check for other unvisited neighbors.
// 5. Repeat until all nodes are visited or the target node is found.

#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS helper function
// Parameters:
// - node: Current vertex being visited
// - adj: Adjacency list of the graph
// - ans: Vector to store the DFS traversal result
// - visited: Boolean vector to track visited vertices
void DFS(int node, vector<int> adj[], vector<int>& ans, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;

    // Add the current node to the DFS traversal result
    ans.push_back(node);

    // Traverse all adjacent vertices of the current node
    for (int j = 0; j < adj[node].size(); j++) {
        // If the adjacent vertex has not been visited, make a recursive DFS call
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, ans, visited);
        }
    }
}

// Function to perform DFS of a graph
// Parameters:
// - V: Number of vertices in the graph
// - adj: Adjacency list of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Vector to track visited vertices (initialized to false)
    vector<bool> visited(V, false);

    // Vector to store the result of the DFS traversal
    vector<int> dfs;

    // Start DFS from vertex 0
    DFS(0, adj, dfs, visited);

    // Return the DFS traversal result
    return dfs;
}

int main() {
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list to represent the graph
    vector<int> adj[V];

    adj[0] = {1, 2, 3};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    // Perform DFS traversal
    vector<int> dfsResult = dfsOfGraph(V, adj);

    // Output the DFS traversal result
    cout << "DFS Traversal Result: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }

    return 0;
}
