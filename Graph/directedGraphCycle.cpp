// Problem Statement :- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Using DFS
// We can say that for a node, if it's neighbour is already visited and it's not a parent, then we can say that there exists a cycle.
// This logic however is flawed. Consider the graph :- 4 -> 5 -> 0 -> 1 -> 2 -> 3
// We start traversing from 0 till 3, then start from 4 and then 5. Finally when it tries to go to 0 from 5, as 5 is not it's parent, but is it's neighbour, our previous logic will say there's a cycle which is not true.
// Hence, on the basis of visited we can't determine our answer.
// For detecting cycle in directed graph using DFS, we will check if a node is present in the path explored more than one time.
// But if we are going to a node already visited using a different path, in which it was not explored previously, then for us it is as if we have encountered it the first time (because we have explored it first time only for that path).
// But how can we keep track of the path being traversed?
// For this we can a bool path array which will mark the nodes visisted in the current path.
// Now whenever we move back in a path, we will again make that node's index in the bool array 0.

// We can optimize this further to avoid traversing that subpath which can't return a cycle, which we can deduce from our previous path traversals.
// This is when we can use visited array to track the node which we have already visited.



// Using BFS
// We can use Topolgical Sort concept i.e. Kahn's algorithm.
// For a Directed Cyclic Graph, Kahn algorithm will not return the nodes that form cycle in the final answer. This is because none of them will have 0 indegree, so none will go into the queue.
// Hence number of vertices in original graph and in answer will not match.