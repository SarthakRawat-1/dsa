// Topological sorting can only be performed on a DAG (Directed Acyclic Graph), as cycles would prevent any vertex from being ordered before another.
// Topological sort can only be performed on a DAG because in Undirected Graphs we can't confirm which vertex will come before and which after.
// The reason we need acyclic is that if we have cyclic graph, we have a loop which will create conflicts on which vertex is coming before.

// Topological Sort is an ordering of the vertices of a directed acyclic graph (DAG) such that for every directed edge u→v, vertex u comes before v in the ordering.
// Let's say we have an edge u -> v, then u should be ordered before v.
// For eg :- If we have a graph :- 0 -> 1 -> 3   
                            //     ↓         ↑
                            //     2 --------- 
// The topological sort for this :- 0 2 1 3 or 0 1 2 3 (i.e. we can have multiple answers)

// Topological Sort using DFS
// Say, we have a graph :- 4 -> 5 -> 0 -> 1 -> 2 -> 3
// We will apply DFS on it like in dfsTraversal.cpp
// But if we normally apply DFS on it, we will get :- 0 1 2 3 4 5 which is not what we want.
// Consider the visited array :- {0, 0, 0, 0, 0, 0} and take one more array ans.
// We start with 0, mark index 0 in visited array as 1 and append 0 to ans. Similarly, do it for 1, 2 and 3.
// We have, visited array :- {1, 1, 1, 1, 0, 0} and ans :- {0, 1, 2, 3}. Now DFS will visit 4 and 5. ans will become :- {0, 1, 2, 3, 4, 5}
// But our ans should be :- {4, 5, 0, 1, 2, 3}. If we had put {4, 5} in the front we would have got our answer.
// But this will increase Time complexity and even more so for more complex graphs. Instead of a vector array, we can use a Stack.

// Using a Stack, we will do DFS as usual, visited array will also be marked as usual. But as soon as we encounter a vertex, we are not going to put it in Stack, for every vertex, we will put the vertices dependent on that first inside the Stack (this is followed for subsequent vertices as well). 
// Dependence basically means that where the vertex is directing to, so in our eg, for 0, 1 is dependent on 0.
// After 0, we will arrive on 1 but as 2 is dependent on 1, similarly 3 is dependent on 2, so finally 3 will go first in Stack. Now as 3 is already inside Stack, so now 2 can also go inside Stack. Similarly 1 and 0 will also go in Stack.
// Similarly, 5 will be inserted in Stack before 4. Stack in end when all vertices are visited :- {4, 5, 0, 1, 2, 3} where 4 is at the top and 3 is at the bottom.
// We can simply pop elements from Stack and append them to our ans in the end.

#include <bits/stdc++.h>
using namespace std;

// Depth-First Search (DFS) function to explore each node
// and push it onto the stack after visiting all its dependencies
void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    // Mark the current node as visited
    visited[node] = 1;

    // Recur for all the adjacent vertices (dependencies) of the current node
    for (int i = 0; i < adj[node].size(); i++) {
        // If the adjacent node has not been visited, apply DFS on it
        if (!visited[adj[node][i]]) {
            DFS(adj[node][i], adj, visited, st);
        }
    }

    // Push the current node onto the stack after all its dependencies are processed
    st.push(node);
}

// Topological Sort function that returns a list of vertices in topologically sorted order
vector<int> topoSort(int V, vector<int> adj[]) {
    // Vector to track visited nodes (initially all nodes are unvisited)
    vector<bool> visited(V, 0);

    // Stack to hold the nodes in topologically sorted order
    stack<int> st;

    // Perform DFS for all nodes to ensure all nodes are visited
    // We need to do this, as we may have Graph islands.
    for (int i = 0; i < V; i++) {
        // If the node is not visited, apply DFS on it
        if (!visited[i]) {
            DFS(i, adj, visited, st);
        }
    }

    // Vector to store the topologically sorted order
    vector<int> ans;

    // Pop elements from the stack and add them to the answer vector
    // This will give the correct topological order (the node at the top of the stack
    // should come first in the topological order)
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    // Return the topologically sorted order
    return ans;
}

int main() {
    // Example graph with 6 vertices (0 to 5)
    int V = 6;
    
    // Adjacency list representation of the graph
    // Each index represents a vertex and the list at that index represents the vertices it points to
    vector<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Call the topoSort function to get the topologically sorted order of vertices
    vector<int> sortedOrder = topoSort(V, adj);

    // Print the topological sort
    for (int i = 0; i < sortedOrder.size(); i++) {
        cout << sortedOrder[i] << " ";
    }

    return 0;
}


// Topological Sort using BFS (Kahn Algorithm)
// We will first visit those vertices which has no incoming edge i.e. it is not dependent on any other vertex, i.e. it doesn't have a parent i.e. their indegree is 0.
// After visiting these, we will remove all the outgoing edges from them. Now in the leftover graph, again search for those vertices which don't have any parent.
// Keep doing this, till you visit every node.

// We will first find Indegree of every node/vertex and store it in a vector (where index represents the vertex).
// Then we will visit those vertices (index) whose indegree is 0. We can put all such vertices in a Queue (as we are using BFS). Then we will pop one element from front of queue and append it to answer.
// As vertex is deleted from queue and appended in answer, then outgoing edge from this node to other nodes should be removed. This we will acheive by decreasing the value by 1 for all those connected vertices in indegree array.
// After this, we will append those nodes who just got their indegrees to 0 (if no one became 0, simply continue and follow the next step without appending). 
// Then after this, we will pop another element, and the cycle repeats.

#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using BFS (Kahn's Algorithm)
vector<int> topSort(int V, vector<int> adj[]) {
    // Step 1: Initialize an array to store the in-degree (number of incoming edges) of each vertex
    vector<int> indegree(V, 0);
    
    // Step 2: Calculate the in-degree for each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++; // Increment in-degree of adjacent node
        }
    }

    // Step 3: Initialize a queue to store vertices with in-degree 0 (i.e., no dependencies)
    queue<int> q;

    // Step 4: Push all vertices with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 5: Perform BFS traversal and process nodes in topological order
    vector<int> ans; // Stores the topological sort order
    while (!q.empty()) {
        int node = q.front(); // Get the front node
        q.pop();
        ans.push_back(node); // Add the node to the result

        // Step 6: Reduce the in-degree of all adjacent nodes (i.e., remove outgoing edges)
        for (int i = 0; i < adj[node].size(); i++) {
            indegree[adj[node][i]]--;

            // If the in-degree of a node becomes 0, push it into the queue
            if (indegree[adj[node][i]] == 0) {
                q.push(adj[node][i]);
            }
        }
    }

    // Step 7: Return the topological order
    return ans;
}

int main() {
    // Example graph with 6 vertices (0 to 5)
    int V = 6;
    
    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Call topSort function to get the topological sorting order
    vector<int> sortedOrder = topSort(V, adj);

    // Print the topological sort result
    cout << "Topological Sort (BFS - Kahn's Algorithm): ";
    for (int i = 0; i < sortedOrder.size(); i++) {
        cout << sortedOrder[i] << " ";
    }

    return 0;
}
