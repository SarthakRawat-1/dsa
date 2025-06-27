// The Bellman-Ford algorithm is a graph algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative edge weights. It also helps detect negative weight cycles.
// Bellman-Ford repeatedly relaxes all the edges. That means it tries to improve the shortest path by considering each edge and seeing if going through that edge gives a shorter path.
// So Bellman-Ford focuses on edge selection but Dijkstra focuses on vertex solution.
// Btw relaxation means :- u -> v then if dist[u] + wt < dist[v] update dist[v] = dist[u] + wt
// We have to relax :- number of nodes - 1 times and then one more time to check if there is a cycle or not. If any distance value changes in this, then there is a cycle. If no cycle, we have got our shortest path.

// Note :- For a negative cycle (combined weight in a cycle is negative), no method can find the shortest path.


