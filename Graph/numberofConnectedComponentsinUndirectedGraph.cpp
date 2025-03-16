// Problem Explanation :-
// You are given n nodes labeled from 0 to n - 1 and a list of edges where edges[i] = [u, v] represents an undirected edge between nodes u and v.
// A connected component is a maximal set of nodes such that there exists a path between every pair of nodes within this set.
// Your task is to return the number of connected components.

// Method 1 :- DFS

// #include <iostream>
// #include <vector>
// using namespace std;

// // Helper function to perform DFS traversal
// void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
//     visited[node] = true; // Mark the current node as visited
//     for (int neighbor : adjList[node]) { // Iterate through all adjacent nodes
//         if (!visited[neighbor]) { // If a neighbor has not been visited
//             dfs(neighbor, adjList, visited); // Recursively visit the neighbor
//         }
//     }
// }

// int countComponents(int n, vector<vector<int>>& edges) {
//     // Step 1: Build the adjacency list for the graph
//     vector<vector<int>> adjList(n);
//     for (const auto& edge : edges) { 
//         adjList[edge[0]].push_back(edge[1]); // Add edge from u to v
//         adjList[edge[1]].push_back(edge[0]); // Add edge from v to u (undirected graph)
//     }

//     // Step 2: Initialize a visited array to keep track of visited nodes
//     vector<bool> visited(n, false);
//     int components = 0; // Variable to count the number of connected components

//     // Step 3: Iterate through all nodes
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) { // If the node is not visited
//             components++; // Increment the connected component count
//             dfs(i, adjList, visited); // Perform DFS starting from this node
//         }
//     }

//     return components; // Return the total number of connected components
// }

// int main() {
//     int n = 5; // Number of nodes
//     vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}}; // Edges of the graph

//     // Call the function and print the result
//     cout << "Number of connected components: " << countComponents(n, edges) << endl;
//     return 0;
// }


// Method 2 :- Union Find Algorithm

#include <iostream>
#include <vector>
using namespace std;

// Union-Find class for managing connected components
class UnionFind {
private:
    vector<int> parent; // Array to store the parent of each node
    vector<int> rank;   // Array to store the rank (depth) of each tree

public:
    // Constructor to initialize parent and rank arrays
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initialize all ranks to 0
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Initially, each node is its own parent
        }
    }

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x) { // If x is not the root of its set
            parent[x] = find(parent[x]); // Path compression: make x's parent point to the root
        }
        return parent[x]; // Return the root of x's set
    }

    // Union operation to merge two sets
    void unite(int x, int y) {
        int rootX = find(x); // Find the root of x
        int rootY = find(y); // Find the root of y

        if (rootX != rootY) { // If x and y are in different sets
            if (rank[rootX] > rank[rootY]) { // Attach the smaller tree under the larger tree
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else { // If ranks are equal, attach one tree to the other and increment rank
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n); // Initialize Union-Find for n nodes

    // Process each edge to unify the nodes
    for (const auto& edge : edges) {
        uf.unite(edge[0], edge[1]); // Union the two nodes of the edge
    }

    // Count the number of unique roots (connected components)
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (uf.find(i) == i) { // If a node is its own parent, it's a root
            components++;
        }
    }

    return components; // Return the total number of connected components
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}}; // Edges of the graph

    // Call the function and print the result
    cout << "Number of connected components: " << countComponents(n, edges) << endl;
    return 0;
}
