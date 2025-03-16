// Problem Statement :- https://leetcode.com/problems/course-schedule-ii/description/

// This is just an extension of courseSchedule.cpp
// We can simply return the Topological sorted order if we can complete all courses.

#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sorting using Kahn's Algorithm (BFS approach)
// vector<int> topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
//     queue<int> que;
//     vector<int> result;
//     int count = 0;
    
//     // Push all courses with zero in-degree into the queue
//     for(int i = 0; i < n; i++) {
//         if(indegree[i] == 0) {
//             result.push_back(i);
//             count++;
//             que.push(i);
//         }
//     }
    
//     // Process nodes with zero in-degree
//     while(!que.empty()) {
//         int u = que.front();
//         que.pop();
        
//         for(int &v : adj[u]) { // Visit all dependent courses
//             indegree[v]--;
//             if(indegree[v] == 0) {
//                 result.push_back(v);
//                 count++;
//                 que.push(v);
//             }
//         }
//     }
    
//     return (count == n) ? result : vector<int>{}; // If all courses are processed, return result
// }

// // Function to find course order using BFS (Kahn's Algorithm)
// vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//     unordered_map<int, vector<int>> adj;
//     vector<int> indegree(numCourses, 0);
    
//     // Build adjacency list and in-degree array
//     for(auto &vec : prerequisites) {
//         int a = vec[0];
//         int b = vec[1];
//         adj[b].push_back(a); // b -> a (b is a prerequisite for a)
//         indegree[a]++;
//     }
    
//     return topologicalSortCheck(adj, numCourses, indegree);
// }

// Global variable to track cycle presence
bool hasCycle = false;

// Function to perform DFS and detect cycles
void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
    visited[u] = true;
    inRecursion[u] = true;
    
    for(int &v : adj[u]) { // Visit all adjacent nodes
        if(inRecursion[v]) { // Cycle detected
            hasCycle = true;
            return;
        }
        if(!visited[v])
            DFS(adj, v, visited, st, inRecursion);
    }
    
    st.push(u); // Push node into stack after visiting all dependencies
    inRecursion[u] = false;
}

// Function to find course order using DFS (Topological Sort)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(numCourses, false);
    vector<bool> inRecursion(numCourses, false);
    stack<int> st;
    hasCycle = false;
    
    // Build adjacency list
    for(auto &vec : prerequisites) {
        int a = vec[0];
        int b = vec[1];
        adj[b].push_back(a);
    }
    
    // Perform DFS on all unvisited nodes
    for(int i = 0; i < numCourses; i++) {
        if(!visited[i])
            DFS(adj, i, visited, st, inRecursion);
    }
    
    if(hasCycle)
        return {}; // Return empty vector if cycle detected
    
    vector<int> result;
    while(!st.empty()) { // Extract topological order from stack
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

// Main function to test both BFS and DFS approaches
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}}; // This has a cycle
    
    vector<int> orderBFS = findOrder(numCourses, prerequisites);
    if (!orderBFS.empty()) {
        cout << "Course order using BFS: ";
        for(int course : orderBFS) cout << course << " ";
        cout << endl;
    } else {
        cout << "It is not possible to finish all courses using BFS approach." << endl;
    }
    
    return 0;
}

