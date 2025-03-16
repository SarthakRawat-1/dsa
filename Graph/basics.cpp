// A Graph is a data structure that consists of a finite set of vertices (or nodes) and a set of edges that connect pairs of vertices. It is used to represent relationships or connections between objects.
// A Graph is a non-linear data structure.
// Vertices (Nodes) :- Represent entities or points in the graph.
// Edges :- Represent connections or relationships between vertices. They can be directed or undirected.

// Degree of a graph refers to the number of edges that go inside or outside that node.
// Properties of Degrees in Graphs :-
// Undirected Graph :- The total degree of a graph is the sum of the degrees of all vertices. 
// Property :- The total degree is equal to 2×E, where E is the number of edges, as each edge contributes to the degree of two vertices.
// Example :- If degrees of vertices are 2,2,3,2,3, then: Total Degree = 2+2+3+2+3 = 12 = 2×6

// Directed Graph :- Each vertex has two types of degrees: Indegree which is the number of incoming edges to a vertex. Outdegree which is the number of outgoing edges from a vertex.
// Property :- The sum of all indegrees is equal to the sum of all outdegrees, and both are equal to the number of edges: ∑(Indegree) = ∑(Outdegree) = E

// Types of Graphs :-

// Undirected Graph :- Edges are bidirectional, with no direction. The pairs (u,v) and (v,u) represent the same edge.
// Directed Graph: Edges have direction, forming ordered pairs. ⟨u,v⟩ and (v,u⟩ represent two different edges.

// Cyclic Graph :- A graph that contains at least one cycle, where a cycle is a path of edges and vertices that starts and ends at the same vertex without retracing any edge.
// Acyclic Graph :- A graph that contains no cycles.

// Connected Graph :- A graph where there is a path between every pair of vertices, ensuring all vertices are reachable from any other vertex.
// Disconnected Graph :- A graph that consists of two or more separate components, where some vertices are not reachable from others.

// A Complete Graph is a graph in which every vertex is connected to every other vertex by a unique edge.
// If the graph has n vertices, it will have exactly n(n−1)/2​ edges (in an undirected graph).
// In a directed graph, each vertex will have edges to all other vertices, resulting in n(n−1) edges.
// Every vertex has a degree of n−1 in an undirected complete graph.

// Weighted Graph :- A graph where each edge has an associated weight or cost, representing attributes like distance, time, or capacity.
// Unweighted Graph :- A graph where edges do not have any weight or cost; all edges are treated as equal.