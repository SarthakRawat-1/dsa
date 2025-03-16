// Problem Statement :- https://leetcode.com/problems/number-of-provinces/description/

// We can simply make an adjacency list first and then use DFS to find the number of provinces. A DFS on a single node will find all others in a provinces as they are connected directly or indirectly.
// Then it will come back to for loop and it will then start for another node of a province which is not visited yet (as it was not connected directly or indirectly to province before).
// In this way, we can find all provinces.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Variation 1: Using DFS with an explicit adjacency list representation
    // void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
    //     // Mark the current node as visited
    //     visited[u] = true;

    //     // Traverse all adjacent nodes of 'u'
    //     for (int &v : adj[u]) {
    //         if (!visited[v]) {
    //             dfs(adj, v, visited); // Recursively call DFS for unvisited neighbors
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size(); // Number of nodes (cities)

    //     vector<bool> visited(n, false); // Vector to keep track of visited nodes

    //     // Build the adjacency list representation of the graph
    //     unordered_map<int, vector<int>> adj;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (isConnected[i][j] == 1) { // If there's a connection between i and j
    //                 adj[i].push_back(j); // Add j to i's adjacency list
    //                 adj[j].push_back(i); // Add i to j's adjacency list (undirected graph)
    //             }
    //         }
    //     }

    //     int count = 0; // Count of connected components (or provinces)

    //     // Perform DFS for every unvisited node
    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) { // If the node is not visited
    //             dfs(adj, i, visited); // Explore the connected component
    //             count++; // Increment the count of provinces
    //         }
    //     }

    //     return count; // Return the total number of provinces
    // }

    // Variation 2: Using DFS directly on the given adjacency matrix
    // int n; // Class variable to store the size of the graph

    // void dfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
    //     // Mark the current node as visited
    //     visited[u] = true;

    //     // Traverse all possible neighbors of 'u'
    //     for (int v = 0; v < n; v++) {
    //         // Check if there's a direct connection and if 'v' is unvisited
    //         if (!visited[v] && isConnected[u][v] == 1) {
    //             dfs(isConnected, v, visited); // Recursively call DFS for 'v'
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     n = isConnected.size(); // Number of nodes (cities)

    //     vector<bool> visited(n, false); // Vector to keep track of visited nodes

    //     int count = 0; // Count of connected components (or provinces)

    //     // Perform DFS for every unvisited node
    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) { // If the node is not visited
    //             dfs(isConnected, i, visited); // Explore the connected component
    //             count++; // Increment the count of provinces
    //         }
    //     }

    //     return count; // Return the total number of provinces
    // }

    // Variation 1 :- BFS function to explore the graph from a given node 'u'
    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        // Initialize a queue for BFS traversal
        queue<int> que;

        // Start with node 'u' and mark it visited
        que.push(u);
        visited[u] = true;

        // Process nodes in the queue
        while (!que.empty()) {
            int node = que.front(); // Get the front node
            que.pop();             // Remove the processed node

            // Visit all adjacent nodes of 'node'
            for (int &v : adj[node]) { // Iterate through neighbors
                if (!visited[v]) {     // If neighbor is unvisited
                    visited[v] = true; // Mark as visited
                    que.push(v);       // Add it to the queue for further exploration
                }
            }
        }
    }

    // Function to find the number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of nodes

        // Step 1: Create an adjacency list using unordered_map
        unordered_map<int, vector<int>> adj;

        // Populate adjacency list based on the input matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) { // If there's a connection
                    adj[i].push_back(j);     // Add edge (i → j)
                    adj[j].push_back(i);     // Add edge (j → i) since graph is undirected
                }
            }
        }

        // Step 2: Initialize visited array to track visited nodes
        vector<bool> visited(n, false);
        int count = 0; // Count of connected components

        // Step 3: Perform BFS for all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {      // If the node is unvisited
                bfs(adj, i, visited); // Start BFS from this node
                count++;            // Increment the count of provinces
            }
        }

        return count; // Return the total number of provinces
    }

    // Variation 2 
    int n;
    
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;          // Initialize a queue for BFS traversal
        que.push(u);             // Start with node 'u'
        visited[u] = true;       // Mark node 'u' as visited

        while (!que.empty()) {
            int node = que.front(); // Get the front node
            que.pop();              // Remove the processed node

            // Visit all neighbors of the current node
            for (int v = 0; v < n; v++) {
                // Check if 'v' is a neighbor and unvisited
                if (adj[node][v] == 1 && !visited[v]) {
                    visited[v] = true; // Mark 'v' as visited
                    que.push(v);       // Push 'v' into the queue
                }
            }
        }
    }

    // Function to find the number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size(); // Number of nodes

        vector<bool> visited(n, false); // To keep track of visited nodes
        int count = 0;                  // Count of connected components

        // Perform BFS for all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {             // If the node is unvisited
                bfs(isConnected, i, visited); // Start BFS from this node
                count++;                   // Increment count of provinces
            }
        }

        return count; // Return the total number of provinces
    }
};

// Example Usage
int main() {
    Solution solution;

    // Example graph as an adjacency matrix
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    // Finding the number of provinces (connected components)
    int result = solution.findCircleNum(isConnected);
    cout << "Number of Provinces: " << result << endl;

    return 0;
}
