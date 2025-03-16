// Graph can be represented as an adjacency matrix or adjacency list.

// Adjacency Matrix

// We will be given information about vertexes and edges of the graph.
// An Adjacency matrix is a 2D array where each row represents a vertex and each column represents another vertex.
// If there is an edge between the two vertices, the corresponding entry in the matrix will be 1.
// If there is no edge between the two vertices, the corresponding entry in the matrix will be 0.

// In an undirected graph, the edges have no direction, meaning that if there's an edge from vertex u to vertex v, it also implies an edge from v to u. The adjacency matrix is symmetric in this case.
// If there's an edge between vertex i and vertex j, the matrix entry A[i][j] and A[j][i] are set to 1 (or a non-zero value).

// In a directed graph, the edges have a direction. If there is an edge from vertex u to vertex v, the matrix entry A[u][v] is set to 1 (or a non-zero value), but there is no entry for A[v][u] unless there is a reverse edge.

// The adjacency matrix for a weighted graph includes the weights instead of just 1 to indicate the presence of an edge. If there's no edge between two vertices, the corresponding entry is set to a special value, usually 0 or ∞ (infinity), depending on the application.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // // For Undirected Unweighted Graph
    // int vertex, edges; 

    // // If 5 is given as vertexes, we will assume them to be 0, 1, 2, 3 and 4.
    // cout << "Enter the number of vertexes and edges: ";
    // cin >> vertex >> edges;

    // // Create an adjacency matrix to represent the graph.
    // // The matrix is of size vertex x vertex, and initially all elements are set to 0 (no edges).
    // // The adjacency matrix will be used to store the presence (1) or absence (0) of an edge between any two vertices.
    // vector<vector<bool> > AdjMat(vertex, vector<bool>(vertex, 0));

    // int u, v;

    // // This will tell us about the edges i.e. we have edges from where to where.
    // cout << "Enter the edges: ";
    // for (int i = 0; i < edges; i++) {
    //     // The adjacency matrix is updated to mark the edge between vertex u and vertex v as present (set to 1).
    //     cin >> u >> v;
    //     // For an undirected graph, an edge between u and v is bidirectional.
    //     // We mark both AdjMat[u][v] and AdjMat[v][u] as 1 to indicate that an edge exists in both directions.
    //     AdjMat[u][v] = 1;
    //     AdjMat[v][u] = 1;
    // }

    // // Display the adjacency matrix to visualize the graph.
    // for (int i = 0; i < vertex; i++) {
    //     for (int j = 0; j < vertex; j++) {
    //         cout << AdjMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // // For Undirected Weighted Graph
    // int vertex, edges;

    // cout << "Enter the number of vertexes and edges: ";
    // cin >> vertex >> edges;

    // vector<vector<int> > AdjMat(vertex, vector<int>(vertex, 0));

    // int u, v, weight;

    // cout << "Enter the edges: ";
    // for (int i = 0; i < edges; i++) {
    //     cin >> u >> v >> weight;
    //     AdjMat[u][v] = weight;
    //     AdjMat[v][u] = weight;
    // }

    // for (int i = 0; i < vertex; i++) {
    //     for (int j = 0; j < vertex; j++) {
    //         cout << AdjMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // // For Directed Unweighted Graph
    // int vertex, edges;

    // cout << "Enter the number of vertexes and edges: ";
    // cin >> vertex >> edges;

    // vector<vector<bool> > AdjMat(vertex, vector<bool>(vertex, 0));

    // int u, v;

    // for (int i = 0; i < edges; i++) {
    //     cin >> u >> v;
    //     AdjMat[u][v] = 1;
    // }

    // for (int i = 0; i < vertex; i++) {
    //     for (int j = 0; j < vertex; j++) {
    //         cout << AdjMat[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // For Directed Weighted Graph
    int vertex, edges;

    cout << "Enter the number of vertexes and edges: ";
    cin >> vertex >> edges;

    int u, v, weight;

    vector<vector<int> > AdjMat(vertex, vector<int>(vertex, 0));

    cout << "Enter the edges: ";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight;
        AdjMat[u][v] = weight;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

