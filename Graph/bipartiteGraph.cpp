// Problem Statement :- https://www.geeksforgeeks.org/problems/bipartite-graph/1
//                      https://leetcode.com/problems/is-graph-bipartite/description/

// Bipartite graph is a graph in which the vertices can be divided into two disjoint sets.
// Such that no two vertices within the same set are adjacent.
// In other words, it is a graph in which every edge connects a vertex of one set to a vertex of another set.

// Two Color Algorithm 
// We want to color every node of graph such that no two adjacent nodes have the same color.
// If there is no cycle in graph then it is bipartite.
// If there is cycle in graph then it is bipartite if cycle is of even length.
// We will use BFS to traverse, for the first node, we will assign it a color and then look to it's adjacent nodes, after popping it, and assign them the opposite color. 
// In here, for every node that we visit, we visit a node by popping it from the queue and then we will only enter those adjacent elements that are not already visited i..e marked with color in the queue.

// We will use a colors array, initialized with -1, meaning no color, then 0 and 1 entry referes which color they got.
// Then for BFS< we will use queue, when inserting into queue, we will also give them a color, then when we remove it from queue, we will insert all those elements into the queue which are it's adjacents and not colored yet.
// We will also color those nodes the opposite.  After they have been colored, they will be inserted into the queue.
// Every node while coloring adjacent elements, will also check those adjacent elements which has already been colored. If they are of the same color, then it can't be a bipartite graph.

// This however will not work for disconnected graphs. So, for that, we will use a for loop again, to check for those vertices.

#include <bits/stdc++.h>
using namespace std;

// Using BFS
// Function to check if a graph is bipartite using BFS
bool isPartite(int V, vector<int> adj[]) {
    vector<int> colors(V, -1); // Initialize all vertices as uncolored (-1)

    queue<int> q; // Queue for BFS traversal
    
    // Check for each component of the graph (in case it's disconnected)
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) { // If node is unvisited
            q.push(i);
            colors[i] = 0; // Assign the first color (0)

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // Traverse all adjacent nodes
                for (int j = 0; j < adj[node].size(); j++) {
                    int neighbor = adj[node][j];

                    if (colors[neighbor] == -1) { // If neighbor is uncolored
                        colors[neighbor] = (colors[node] + 1) % 2; // Assign opposite color
                        q.push(neighbor);
                    } 
                    else if (colors[neighbor] == colors[node]) { 
                        // If adjacent nodes have the same color, the graph is not bipartite
                        return false;
                    }
                }
            }
        }
    }

    return true; // If BFS completes without conflicts, graph is bipartite
}

// To solve Leetcode
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, -1);  // -1 indicates that the node hasn't been colored yet
    
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {  // not visited yet
            queue<int> q;
            q.push(i);
            colors[i] = 0;  // assign initial color
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[node];  // assign opposite color
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[node]) {
                        // Found two adjacent nodes with the same color.
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// If we want to use DFS, we will simply traverse using DFS and keep assigning colors. 
// At one point, when a node wants to go to it's adjacent node, it will find that it has already been colored.
// If the color is opposite, then it's fine, it will return 1, indicating this branch is bipartite, but if it's not then it will return 0, indicating, the graph is not bipartite.
// Every path will return 1, if it's bipartite, else it will return 0. It returns this, when the path has hit a dead end.
// Basically how DFS executes.

// Using DFS
bool checkBip(int node, vector<int> adj[], vector<int> &colors) {
    // Traverse all adjacent nodes
    for (int j = 0; j < adj[node].size(); j++) {
        int neighbor = adj[node][j];

        if (colors[neighbor] == -1) { // If neighbor is uncolored
            colors[neighbor] = (colors[node] + 1) % 2; // Assign opposite color
            if (!checkBip(neighbor, adj, colors)) {
                return false; // If any branch is not bipartite, return false
            }
        } 
        else if (colors[neighbor] == colors[node]) {
            // If adjacent nodes have the same color, the graph is not bipartite
            return false;
        }
    }

    return true; // If all branches are bipartite, return true
}

// Wrapper function for DFS approach
bool isPartiteDFS(int V, vector<int> adj[]) {
    vector<int> colors(V, -1); // Initialize all vertices as uncolored (-1)

    // Check for each component of the graph (in case it's disconnected)
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1) { // If node is unvisited
            colors[i] = 0; // Assign first color
            if (!checkBip(i, adj, colors)) {
                return false; // If any component is not bipartite, return false
            }
        }
    }

    return true; // If all components are bipartite, return true
}

// To solve Leetcode 
bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
    colors[node] = color;
    for (int neighbor : graph[node]) {
        // If the neighbor hasn't been colored, assign the opposite color and DFS on it
        if (colors[neighbor] == -1) {
            if (!dfs(graph, colors, neighbor, 1 - color))
                return false;
        } 
        // If the neighbor already has the same color, the graph is not bipartite
        else if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, -1);  // Initialize all vertices as uncolored (-1)
    
    // Check each component of the graph (in case the graph is disconnected)
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            if (!dfs(graph, colors, i, 0))
                return false;
        }
    }
    return true;
}

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    if (isPartite(V, adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

}

