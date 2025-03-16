// Problem Statement :- https://leetcode.com/problems/course-schedule/description/

// If there is a cycle in the graph (which is directed graph here), then it is not possible to finish all courses. 
// Obviously if there is no cycle, then it is possible to write the vertices of graph in topolgical order as it becomes a DAG.
// Hence, we can also say that if we can find a Topolgical sort for the graph, then it is possible to finish all courses as there is no cycle present.

#include <bits/stdc++.h>
using namespace std;

// Function to check if topological sorting is possible using Kahn's algorithm (BFS approach)
bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
    queue<int> que;
    int count = 0; // To count the number of courses we can take
    
    // Push all courses with zero in-degree (no prerequisites) into the queue
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            count++;
            que.push(i);
        }
    }
    
    // Process nodes with zero in-degree
    while(!que.empty()) {
        int u = que.front(); // Get the course with zero in-degree
        que.pop();
        
        for(int &v : adj[u]) { // Visit all dependent courses
            indegree[v]--; // Reduce in-degree
            if(indegree[v] == 0) { // If in-degree becomes zero, add it to the queue
                count++;
                que.push(v);
            }
        }
    }
    
    return count == n; // If we were able to process all courses, return true
}

// Function to determine if all courses can be finished (BFS approach)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(numCourses, 0); // Store in-degree of each course
    
    // Build adjacency list and in-degree array
    for(auto &vec : prerequisites) {
        int a = vec[0];
        int b = vec[1];
        adj[b].push_back(a); // b -> a (b is a prerequisite for a)
        indegree[a]++;
    }
    
    return topologicalSortCheck(adj, numCourses, indegree);
}

// Function to check for cycles using DFS
// bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
//     visited[u] = true; // Mark node as visited
//     inRecursion[u] = true; // Mark node as in recursion stack
    
//     for(int &v : adj[u]) { // Visit all adjacent nodes
//         if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)) // If not visited, do DFS
//             return true; // If cycle is detected, return true
//         else if(inRecursion[v]) // If already in recursion stack, cycle found
//             return true;
//     }
    
//     inRecursion[u] = false; // Remove from recursion stack after processing
//     return false;
// }

// // Function to determine if all courses can be finished (DFS approach)
// bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//     unordered_map<int, vector<int>> adj;
//     vector<bool> visited(numCourses, false);
//     vector<bool> inRecursion(numCourses, false);
    
//     // Build adjacency list
//     for(auto &vec : prerequisites) {
//         int a = vec[0];
//         int b = vec[1];
//         adj[b].push_back(a);
//     }
    
//     // Check for cycles in each component of the graph
//     for(int i = 0; i < numCourses; i++) {
//         if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
//             return false; // If cycle detected, return false
//     }
    
//     return true; // If no cycle detected, all courses can be finished
// }

// Main function to test both BFS and DFS approaches
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}}; // This has a cycle
    
    if (canFinish(numCourses, prerequisites))
        cout << "All courses can be finished using BFS approach." << endl;
    else
        cout << "It is not possible to finish all courses using BFS approach." << endl;

    return 0;
}
