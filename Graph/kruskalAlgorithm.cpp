// Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.
// The general idea is to start by picking that edge (and those two vertices) which has the minimum weight. Then place those, which has the second minimum weight and so on.
// Whenever you are placing the edge, make sure it doesn't form a cycle. If it does, skip that.
// Now whenever, we want to place a edge, we wwant to first check if there already exists a path which is connecting the source and destination node of that edge. Because if there is, then if we place that edge too, it will become a loop.
// But for finding this, we can use BFS or DFS which is not feasible as it takes more time i.e. O(n).

// We will use a Disjoint Set Union which will do this in O(1) time.

// We will only place the edge if the source and destination node belong to different sets.
// A set implies, all the node inside the set have a path to travel to any other node inside the same set.
// Hence, after placing the edge, the set will increase, as more nodes will be part of the same set.

// Initially, all will be in different sets. We can make an array to tell which element is in which element.
// Using this we can check if the edge we want to place, it's vertices belong to differnt sets. If yes, place edge and now both belong to same set.
// In that set array, update one of the edge's value to the same as the other's to denote both have same value i.e. belong to same set.

// This will still require O(n) time. We need to use DSU.
// We can use either Union by size or Union by rank

// Union by Rank
// Let's say we have :- (0, 1), (1, 2), (3, 4), (5, 6), (7, 8), (3, 6)
// We will have parent array first and then a rank array. Parent array tells which set does the node (represented by index) belongs in.
// Rank tells which set to merge with?
// Basically when we merge, we will try to do few changes, so it's better taht after merge, we retain the set number of that which had more members.
// This is what rank helps us achieve.
// U can imagine rank as height of the intermediate tree.

// Initially parent values are same as index and rank values are all 0.
// Find ultimate parent of u and v (In our eg (0, 1) u is 0 and v is 1, same for other vertices). Ultimate parent (deduced by parent array, go to index noted by value, find it's parent and so on) different means different sets, so we can merge them. Find the rank of ultimate parent (using rank array). Merge the smaller set to Larger set.


// Union by Size
// Almost same but instead of rank use size array (no. of nodes in a set is size), and we compare and merge by size.

#include <bits/stdc++.h>
using namespace std;

int findParent(int u, vector<int> &parent) {
    if (u == parent[u]) {
        return u;
    }

    return parent[u] = findParent(parent[u], parent);
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});

        }
    }

    int cost  = 0;
    int edges = 0;

    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        if (findParent(u, parent) != findParent(v, parent)) {
            cost += wt;
            unionByRank(u, v, parent, rank);
            edges++;
        }

        if (edges == V - 1) {
            break;
        }
    }

    return cost;
}

int main() {

}