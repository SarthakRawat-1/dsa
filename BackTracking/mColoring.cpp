// Problem Statement :- https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Recursive DFS function to try coloring the graph
bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n) {
    // Try assigning each of the m colors
    for (int c = 0; c < m; c++) {
        bool canUse = true;

        // Check if any adjacent vertex already has this color
        for (int j = 0; j < n; j++) {
            if (graph[node][j] && color[j] == c) {
                canUse = false; // neighbor conflict
                break;
            }
        }

        // If this color cannot be used, try next color
        if (!canUse) continue;

        // Assign this color to current node
        color[node] = c;

        bool allGood = true;

        // Recurse on uncolored neighbors
        for (int j = 0; j < n; j++) {
            if (graph[node][j] && color[j] == -1) {
                if (!DFS(j, color, graph, m, n)) {
                    allGood = false; // neighbor couldn't be colored
                    break;
                }
            }
        }

        // If all neighbors are colored successfully, return true
        if (allGood) return true;

        // Otherwise backtrack and try another color
        color[node] = -1;
    }

    // If no color works for this node → fail
    return false;
}

// Main function to check if graph can be colored using m colors
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, -1); // -1 means uncolored

    // Try to color each connected component
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            // If DFS fails for this component → not possible
            if (!DFS(i, color, graph, m, n)) {
                return false;
            }
        }
    }

    // If all nodes are colored → success
    return true;
}

// More common Approach

// Recursive function to try coloring the graph
bool find(int node, bool graph[101][101], int n, int m, vector<int> &color) {
    // Base case: if all nodes are assigned a color, solution is found
    if (node == n) {
        return true;
    }

    // Try assigning each of the m colors to this node
    for (int c = 0; c < m; c++) {
        bool isPossible = true;

        // Check if any adjacent node already has the same color
        for (int j = 0; j < n; j++) {
            if (graph[node][j] && color[j] == c) {
                isPossible = false; // conflict with neighbor
                break;
            }
        }

        // If no conflict, assign this color
        if (isPossible) {
            color[node] = c;

            // Recurse to color the next node
            if (find(node + 1, graph, n, m, color)) {
                return true; // if valid coloring found, propagate success
            }

            // Backtrack: unassign color and try next option
            color[node] = -1;
        }
    }

    // If no color works for this node → fail
    return false;
}

// Main function to check if graph can be colored using m colors
bool graphColoring(bool graph[101][101], int m, int n) {
    // -1 means "uncolored"
    vector<int> color(n, -1);

    // Start coloring from node 0
    return find(0, graph, n, m, color);
}

int main() {

}

