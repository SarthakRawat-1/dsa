// Problem Statement :- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// When traversing, if we visit a node twice, we know that there is a cycle in the graph.
// However during traversing, we don't have to consider the previous node in our logic. So for eg :- If our graph has only two nodes and one edge 1 <-> 2 This doesn't have a cycle, because after 2 we are going back to 1, which was the previous node for 2.
// Eg :- If we had 1 <-> 2 <-> 3 <-> 1, then we have a cycle, because after 1, we are going 2. 2 has two neighbours 1 and 3, we will only choose 3, as 1 was it's previous node (or parent node you can say). Then 3 will only choose 1 out of 1 and 2 as 1 was it's previous node. We arrived back at 1 which we have already visited before, hence there is a cycle.
// So, for DFS, we will traverse the graph recursively. Recursion will return the number of cycles above. If we hit a node which doesn't have any neighbour aside from it's prev node, we know that there is no cycle from this side, so this branch will return 0.

// Now if we have a single graph which is not fully connected  (eg :- 0 -> 1 -> 2 and 3 -> 4, here 3 -> 4 comes in same graph but they are not connected to any node of 0 -> 1 -> 2), the above approach will not work correctly.
// For this case, we will have to use the visited array, to check if we have visited all of the nodes in the graph.

// Program to Detect Cycle in an Undirected Graph using DFS
#include <bits/stdc++.h> 
using namespace std; 

// Method 1 :- Using DFS
// Function to perform DFS and detect cycles
bool CycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    // Mark the current node as visited
    visited[node] = true;

    // Iterate through all the adjacent nodes of the current node
    for (int j = 0; j < adj[node].size(); j++) {
        int neighbor = adj[node][j]; // Get the adjacent node

        // Skip the parent node as it's the node we came from
        if (neighbor == parent) {
            continue;
        }

        // If the adjacent node is already visited and not the parent, a cycle exists
        if (visited[neighbor]) {
            return true; // Cycle detected
        }

        // Recursively visit the adjacent node
        if (CycleDetect(neighbor, node, adj, visited)) {
            return true; // Cycle detected in the recursive call
        }
    }

    // No cycle detected from this path
    return false;
}

// Main function to detect a cycle in an undirected graph
bool isCycle(int V, vector<int> adj[]) {
    // Create a visited array to track visited nodes
    vector<bool> visited(V, false);

    // Loop through all vertices to handle disconnected graphs
    for (int i = 0; i < V; i++) {
        // If the vertex is not visited, perform DFS to check for cycles
        if (!visited[i]) {
            if (CycleDetect(i, -1, adj, visited)) {
                return true; // Cycle detected
            }
        }
    }

    // No cycle found in the graph
    return false;
}

// Method 2 :- Using BFS
bool BFS(int vertex, vector<int> adj[], vector<bool> &visited) {
    // Create a queue to perform BFS, storing pairs of node and its parent
    queue<pair<int, int>> q;
    
    // Mark the starting vertex as visited
    visited[vertex] = true;
    
    // Push the starting vertex into the queue with parent as -1
    q.push(make_pair(vertex, -1));

    // While there are nodes in the queue, continue the BFS traversal
    while (!q.empty()) {
        int node = q.front().first;  // Current node being processed
        int parent = q.front().second;  // Parent node of the current node
        q.pop();  // Remove the front element from the queue

        // Iterate over all adjacent nodes of the current node
        for (int j = 0; j < adj[node].size(); j++) {
            // Skip the parent node to avoid going back to the node we came from
            if (parent == adj[node][j]) {
                continue;
            }       
            
            // If the adjacent node is already visited, then a cycle is detected
            if (visited[adj[node][j]]) {
                return true;  // Cycle detected
            }

            // Mark the adjacent node as visited
            visited[adj[node][j]] = true;
            
            // Push the adjacent node into the queue with current node as its parent
            q.push(make_pair(adj[node][j], node));
        }
    }

    // No cycle detected from this vertex
    return 0;
}

// Function to detect cycle in an undirected graph using BFS
bool isCycle(int V, vector<int> adj[]) {
    // Create a visited array to track visited nodes
    vector<bool> visited(V, false);

    // Loop through all vertices in the graph
    for (int i = 0; i < V; i++) {
        // If the vertex is not visited, perform BFS to check for cycles
        if (!visited[i] && BFS(i, adj, visited)) {
            return 1;  // Cycle detected
        }
    }

    // No cycle found in the graph
    return 0;
}

int main() {
    // Define the number of vertices
    int V = 10; // Total vertices in the graph

    // Create an adjacency list to represent the graph
    vector<int> adj[V];

    // Create 3 disconnected components (islands)

    // Island 1 (contains a cycle: 0 -> 1 -> 2 -> 0)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);

    // Island 2 (no cycle: 3 -> 4 -> 5)
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);

    // Island 3 (no cycle: 6 -> 7, 8 -> 9)
    adj[6].push_back(7);
    adj[7].push_back(6);
    adj[8].push_back(9);
    adj[9].push_back(8);

    // Call the function to check for cycles
    if (isCycle(V, adj)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
