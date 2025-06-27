// Spanning tree is a subset of edges that forms a tree, where every node of the graph is a part of a tree.
// Minimum Spanning tree is made by considering weights of a weighted graph in graph when converting it to tree.
// Let's say we have graph :- 
//       (3)
//   A -------- B
//   |          |
// 10|          |5
//   |          |
//   C -------- D
//       ( 2 )  
// It's minimum spanning tree will be :-
//       (3)
//   A -------- B
//              |
//              |5
//              |
//   C -------- D
//       ( 2 )  

// An MST is a subset of the edges of a graph that:
//     Connects all the vertices (no node is left out),
//     Has no cycles, and
//     Has the minimum possible total edge weight.

// Let's say we have graph :- 
//       (5)
//   A -------- B
//   |          |
//  2|          |4
//   |          |
//   C -------- D
//       ( 3 )  
// Starting from A, visited set is A, and there are two edges available :- A - B and A - C. We choose minimum weight edge among these which is A - C.
// Now visited set is A and C, now we have edges C - D and A - B. Again choosing minimum edge, we choose C - D. 
// Now visited set is {A, C, D} and new edges are :- D - B and A - B and D - B is lesser, so we pick that and our final minimum spanning tree is done.

// Initialize a set MST with one starting node
// While MST does not contain all nodes:
//     Find the minimum-weight edge that connects a node in MST to a node outside MST
//     Add that edge and the new node to MST

// Just remember Always add the lowest-weight edge that connects a new vertex to the set of already connected vertices (without forming a cycle).
// To check if including an edge makes a cycle or not, we will check teh destination node of the edge. If that node is already in visisted, then it will make a cycle.

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<bool> IsMST(V, 0);
    vector<int> parent(V);

    int cost = 0;
    pq.push({0, {0, -1}});

    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        pq.pop();

        if (!IsMST[node]) {
            IsMST[node] = 1;
            cost += wt;
            parent[node] = par;

            for (int j = 0; j < adj[node].size(); j++) {
                if (!IsMST[adj[node][j][0]]) {
                    pq.push({adj[node][j][1], {adj[node][j][0], node}});
                }
            }
        }
    }

    return cost;
}

int main() {

}
