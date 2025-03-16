// Adjacency List

// We will first make an array containing all the vertexes. 
// Then each element of this array will be part of a Linked list (or vector) which will contain vertices connected to it in the graph.
// For eg :- If we have an undirected graph with vertexes 0, 1, 2, 3, and 4 where 0 is connected to 1 and 2, 1 is connected to 0, 2, and 3, 2 is connected to 0, 1, and 4, 3 is connected to 1 and 4, and 4 is connected to 3 and 2.
// The Adjacency List will look like :-
// 0 -> 1 -> 2
// 1 -> 0 -> 3 -> 2
// 2 -> 0 -> 1 -> 4
// 3 -> 1 -> 4
// 4 -> 2 -> 3
// This is more efficient than Adjacency matrix as we are only storing the information about where there are edges (and not storing when there are no edges).

// For a weighted graph, we can store the weight of each edge in the Adjacency List by making an individual element of the vector or linked list as a pair instead of just a single value.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // For Undirected Unweighted Graph
    // int vertex, edges;

    // Input the number of vertices and edges in the graph
    // cin >> vertex >> edges;

    // Declare an adjacency list using a vector of vectors
    // vector<int> AdjList[vertex];

    // int u, v;

    // Input all edges and populate the adjacency list
    // for (int i = 0; i < edges; i++) {
        // cin >> u >> v; // Input each edge as a pair of vertices (u, v)
        // AdjList[u].push_back(v); // Add v to the adjacency list of u
        // AdjList[v].push_back(u); // Add u to the adjacency list of v (since the graph is undirected)
    // }

    // Print the adjacency list representation of the graph
    // for (int i = 0; i < vertex; i++) {
        // cout << i << " -> "; // Print the current vertex
        // for (int j = 0; j < AdjList[i].size(); j++) {
            // cout << AdjList[i][j] << " "; // Print all adjacent vertices
        // }
        // cout << endl; // Move to the next vertex
    // }

    // For Undirected Weighted Graph
    // int vertex, edges;

    // cin >> vertex >> edges;

    // vector<vector<pair<int, int>>> AdjList(vertex);

    // int u, v, weight;

    // for (int i = 0; i < edges; i++) {
    //     cin >> u >> v >> weight;
    //     AdjList[u].push_back(make_pair(v, weight));
    //     AdjList[v].push_back(make_pair(u, weight));
    // }

    // for (int i = 0; i < vertex; i++) {
    //     cout << i << " -> ";
    //     for (int j = 0; j < AdjList[i].size(); j++) {
    //         cout << "(" << AdjList[i][j].first << ", " << AdjList[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }

    // For Directed Unweighted Graph
    // int vertex, edges;

    // cin >> vertex >> edges;

    // vector<vector<int>> AdjList(vertex);

    // int u, v;

    // for (int i = 0; i < edges; i++) {
    //     cin >> u >> v; 
    //     AdjList[u].push_back(v); 
    // }

    // for (int i = 0; i < vertex; i++) {
    //     cout << i << " -> "; 
    //     for (int j = 0; j < AdjList[i].size(); j++) {
    //         cout << AdjList[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }

    // For Directed Weighted Graph
    int vertex, edges;

    cin >> vertex >> edges;

    vector<vector<pair<int, int>>> AdjList(vertex);

    int u, v, weight;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight; 
        AdjList[u].push_back(make_pair(v, weight)); 
    }

    for (int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << "(" << AdjList[i][j].first << ", " << AdjList[i][j].second << ") "; 
        }
        cout << endl; 
    }
}