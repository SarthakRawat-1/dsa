// The Floyd-Warshall algorithm is a classic dynamic programming method used to find the shortest paths between all pairs of vertices in a weighted graph. It is especially useful because it can handle graphs with negative edge weights, as long as there are no negative cycles (cycles whose total weight is negative).
// It works for both directed and undirected graphs.

// First, we will consider it for Directed Graphs.
// Let's say we have a Graph with A, B, C and D vertices with weights :- A->B = 2, A->C = 8, B->D = 1, B->C = 4, and D->C = 2.
// The graph is connected like :- A->B->D->C
//                                ↓  ↓
//                                C  C
// Initially, we consider the weights as the shortest path. But A->C have shorter paths which are A->B->C = 2 + 4 = 6 and A->B->D->C = 2 + 1 + 2 = 5.
// But how do we solve it?
// We can say that, we can go from A->B which is valid, then from B we can go to B->C and total distance of this path is 6 which is shorter than 8, so we update the shortest distance.
// This is what Floyd Warshall Algorithm is.
// Warshall says :- If there is a relation of A->B and B->C, then there also exists a relation of A->C (Law of Transitivity).
// Floyd updates the shorter distance.

// Applying this further, we know we can go to C from D, i.e. D->C but we don't have any direct path from A to go to D i.e. A->D.
// But we know that A->B exists and B->D exists, so we can go from A to D via B (Warshall). Hence, now we have a new path :- A->D = 3
// From here, we can go A->D = 3 and D->C = 2 hence 3 + 2 = 5, which is shorter. There exists no other ways, so the shortest path is 5.
// And similarly, we can also find that shortest path from B->C is 3.

// Algorithm Structure :-
// Let D be a 2D array (or matrix) where D[i][j] represents the shortest distance from vertex i to vertex j.
// Initially, D[i][j] is set to:
    // The weight of the edge from i to j if there is a direct edge.
    // Zero if i equals j.
    // Infinity (or a very large number) if there is no direct edge between i and j.
// The algorithm then iteratively updates D by considering each vertex as an intermediate point.

// In which order you take vertices as intermediate points doesn't matter. In the end, after considering all vertices as intermediate points, we will get the shortest path. 
// Ofcourse, say A->B->C where B is an intermediate node. This doesn't mean that there was an actual path from A->B or B->C, it could be that there were more nodes b/w A and B which we used to do A->B (same for B->C) but we already knwo that distance in our D array, so we need not mention it explicitly.

#include <iostream>
#include <vector>
#include <climits>   // For INT_MAX to represent infinity.
#include <iomanip>   // For std::setw (used in printing the matrix)
#include <algorithm> // For std::min

using namespace std;

void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Step 1: Preprocess the matrix:
    // Replace all occurrences of -1 (indicating no direct edge) with INT_MAX.
    // We use INT_MAX to represent "infinity" (i.e., an unreachable distance).
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = INT_MAX;
            }
        }
    }

    // Step 2: Apply the Floyd-Warshall algorithm.
    // The algorithm considers each vertex as an intermediate point between every pair of vertices.
    // If the path from i to j via k is shorter than the current known path from i to j,
    // then update the distance.
    for (int k = 0; k < n; k++) {           // k is the intermediate vertex.
        for (int i = 0; i < n; i++) {       // i is the source vertex.
            for (int j = 0; j < n; j++) {   // j is the destination vertex.

                // Check if there is a path from i to k and from k to j.
                // If either is INT_MAX, it means there is no valid path through k.
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) {
                    continue;
                }

                // Update the shortest distance from i to j by taking the minimum of:
                // 1. The current known distance from i to j.
                // 2. The new distance calculated as the distance from i to k plus the distance from k to j.
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Step 3: Postprocess the matrix:
    // Convert all INT_MAX values back to -1 to indicate that no path exists between those vertices.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INT_MAX) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    // Example Graph:
    // We have four vertices: A, B, C, and D.
    // We map these vertices to indices: 0 (A), 1 (B), 2 (C), 3 (D).
    //
    // The graph has the following directed edges with weights:
    //   A -> B = 2
    //   A -> C = 8
    //   B -> C = 4
    //   B -> D = 1
    //   D -> C = 2
    //
    // For any pair (i, j) that does not have a direct edge, we use -1.
    vector<vector<int>> matrix = {
        //  A    B    C    D
        {  0,   2,   8,  -1 },  // From A: A->A=0, A->B=2, A->C=8, A->D=no direct edge (-1)
        { -1,   0,   4,   1 },  // From B: B->A=no edge, B->B=0, B->C=4, B->D=1
        { -1,  -1,   0,  -1 },  // From C: C->A=no edge, C->B=no edge, C->C=0, C->D=no edge
        { -1,  -1,   2,   0 }   // From D: D->A=no edge, D->B=no edge, D->C=2, D->D=0
    };

    // Display the original adjacency matrix.
    cout << "Original adjacency matrix (with -1 indicating no direct edge):\n";
    for (const auto &row : matrix) {
        for (const auto &val : row) {
            // setw(4) ensures the output is nicely formatted in columns.
            cout << setw(4) << val;
        }
        cout << "\n";
    }
    cout << "\n";

    // Call the function to compute the shortest distances.
    shortest_distance(matrix);

    // Display the final matrix which now contains the shortest path distances between every pair of vertices.
    cout << "Shortest path matrix after applying Floyd-Warshall algorithm:\n";
    cout << "(with -1 indicating that no path exists between vertices)\n";
    for (const auto &row : matrix) {
        for (const auto &val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }

    return 0;
}
