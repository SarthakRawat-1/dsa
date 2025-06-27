// Dijkstra’s Algorithm is a classic graph traversal algorithm used to find the shortest path from a starting node (source) to all other nodes in a weighted graph (with non-negative edge weights).

// Dijkstra focuses on **vertex selection** — it picks the vertex with the currently known smallest distance and tries to improve distances to its neighbors.
// Dijkstra performs a **greedy approach**: once a node is visited and finalized, it’s not revisited.
// Relaxation means: for edge u -> v,
// if dist[u] + wt < dist[v], then update dist[v] = dist[u] + wt.

// Basically start with starting node, ofc distance to itself is 0. Then look at nodes connected to it and update the smallest distance.
// Then take one of the neighbour node. Remember, once you take a node, smallest distance to it has already been found. So no need to then consider it as neighbour nodes for other nodes.
// Eitherway, now using this node, update distances of it's neighbour nodes. And continue moving like this. Whenever you take a node, just remember, you need not find shortest distance for that node ever again. But using that, you can update distances for it's neighbour nodes (if they haven't been taken before).
// But wait, how do u choose which node to take next from any given node?
// Let's say we have starting node (or any otehr node) and there are two (or more) nodes connected to it. Which one do u take next?
// Take the one with lower distance.

// Now actually, we don't have to take the nodes connected to it. Actually we have to take the node which distance is minimum among all the unexplored vertices.
// It's just that initially everyone distance besides starting node is inf. So unless, one node has updated their distances (by being their neighbour), their dist will remain inf.




// If we are given a source node and a destination node in a weighted undirected graph, and we want to find shortest distance between the two.
// We will first use Dijkstra algorithm to find the shortest distance to each node. But now how will we find path?
// We can simply modify it a bit. Now every node, while also updating their distance, will store from where the shortest path to it is coming? i.e. from whcih neighbour node, is it's shortest path updated just before the node was taken.
// In a sense, everyone stores information of their parent. Starting node parent will be -1.
// Ofc, we may not specifically need to track the parent. Simply whenever you are updating distance for neighbour nodes,a lso update their parents. Once we reach that node, we will already know what that correct parent is. We can't update it wrongly after as we already have an array to track which nodes have been taken already.
// Now simply everyone can look at their parent and find the path.

