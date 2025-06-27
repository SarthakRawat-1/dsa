// Given a list of cities and the distances between each pair of cities, the Travelling Salesperson Problem asks:
// What is the shortest possible route that visits each city exactly once and returns to the origin city?

// Input:
//     A list of N cities.
//     A distance matrix dist[i][j] representing the distance between city i and city j.
// Objective:
//     Find a minimum cost Hamiltonian cycle (a cycle that visits every vertex once and returns to the start).

// We can effectively solve this using Dynamic Programming which gives rise to Held Karp algorithm.

// Let's say we have four cities 1, 2, 3 and 4. 
// Adjacency matrix
//      0   1   2    3
// 0    0   1   15   6  
// 1    2   0   7    3
// 2    9   6   0    12
// 3    10  4   8    0
// Startvertex = 0

// We can find many ways to go through. 
// Let's say we want to go to 1 via empty set. Basically 0 to 1, which is 1.
// Similarly for 2 and 3 via empty set will be 15 and 6 respectively.
// Similarly, now we want to go to 2 from 0 via 1, which will be cost of moving to 1 from 0 + cost of moving from 1 to 2. This makes up 8.
// Similarly, distance to go to 3 from 0 via 1 will be 4. Similarly you can find for reaching nodes via 2 and 3.
// Cost to reach 3 from 0 when moving via 1 or 2, we will have to select the one whihc gives lesser answer.
// Cost to reach 0 from 0 when moving via 1 or 2 or 3, will be 21.
// For all of these we will have to track parents, i.e. from where have we come. We will recreate the tour using backtracking now.
// Check from where the parent came, in our case that 21 ([0], {1, 2, 3}) came from 2. We reach 2 ([2], {1, 3}), via 3 the cheapest, then 3 (3, {1}) we reach via 1 and 1 ([1, 0]) parent is 0.
// You can also confirm teh path that 0 -> 1 -> 3 -> 2 -> 0 gives 1 + 3 + 8 + 9 = 21

// C++ program to find the shortest possible route
// that visits every city exactly once and returns to
// the starting point using memoization and bitmasking

// Without Bitmasking we have to explicitly usw a set of visited cities instead.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the minimum cost to visit all cities
// Parameters:
// - mask: a bitmask representing the set of cities already visited
// - pos: current city position
// - n: total number of cities
// - cost: adjacency matrix representing travel costs between cities
int totalCost(int mask, int pos, int n, vector<vector<int>> &cost) {
  
    // Base case: If all cities are visited (i.e., mask has all bits set)
    // then return the cost to go back to the starting city (0)
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    int ans = INT_MAX; // Initialize the answer to maximum possible value

    // Try all possible next cities that haven't been visited yet
    for (int i = 0; i < n; i++) {

        // Check if the i-th city has not been visited
        // (mask & (1 << i)) checks if the i-th bit is 0 (i.e., not visited)
        if ((mask & (1 << i)) == 0) {

            // Visit the i-th city by setting its bit in the mask
            // Recursively calculate the cost to visit the rest of the cities
            int newCost = cost[pos][i] + totalCost(mask | (1 << i), i, n, cost);

            // Take the minimum cost among all possible paths
            ans = min(ans, newCost);
        }
    }

    // Return the minimum cost found from current position and mask state
    return ans;
}
 
// Main function to start TSP from city 0
int tsp(vector<vector<int>> &cost) {
    int n = cost.size(); // Total number of cities

    // We start from city 0, so only city 0 is visited initially.
    // mask = 1 means binary 0001 (only 0th bit is set)
    return totalCost(1, 0, n, cost);  
}

int main() {
    // Example cost adjacency matrix of 4 cities
    vector<vector<int>> cost = {
        {0, 10, 15, 20}, 
        {10, 0, 35, 25}, 
        {15, 35, 0, 30}, 
        {20, 25, 30, 0}
    };

    // Run the TSP algorithm and print the result
    int res = tsp(cost);
    cout << "Minimum cost: " << res << endl;

    return 0;
}


// Other method using DP with Formula :- 
// Caution :- This ain't DP
// We again have four vertices/cities with starting city say A
// A
// ├── B
// │   ├── C
// │   │   └── D
// │   └── D
// │       └── C
// ├── C
// │   ├── B
// │   │   └── D
// │   └── D
// │       └── B
// └── D
//     ├── B
//     │   └── C
//     └── C
//         └── B
// Now after this, he has to return to A. So, we will think in reverse.
// Let's say he has covered all cities and is at D. Now he has to reach A from D. Find cost for that.
// Similarly find this for C and B. 
// Now go one level up, find cost from C to D, and do so for others as well. Then go one level up again, and find cost from B to C and B to D and similarly for others. Since, we have a choice here, we will choose the minimum.
// And finally, we will find cost to reach B, C and D from A. 
// Now we will calculate cost for each path and pick the minimum. This is Brute Force Approach.

// Now, in a sense, we can see, that we have to minimize the cost repeatedly.

// Formula :- g(i, S) = min(w(i, j) + g(j, {S - j})) Here, i is starting vertex, w is weight and j is one of the vertices in S.
// S is the set of vertices other than starting vertex so for our case :- {B, C, D}
// S - j implies S after removing j. So if, j = B, then S - j = {C, D} and g(j, {S - j}) implies a recursive call to solve it again for minimmum distance using this route.
// For diff values of j, we will get diff choices of the formula g, we have to select the minimum of it.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the cost of a particular path
int calculatePathCost(const vector<int>& path, const vector<vector<int>>& costMatrix) {
    int totalCost = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        totalCost += costMatrix[path[i]][path[i+1]];
    }
    totalCost += costMatrix[path.back()][path[0]]; // return to starting point
    return totalCost;
}

int main() {
    // 4 cities: A, B, C, D → indices 0, 1, 2, 3
    vector<vector<int>> cost = {
        { 0, 10, 15, 20 },
        { 10, 0, 35, 25 },
        { 15, 35, 0, 30 },
        { 20, 25, 30, 0 }
    };

    vector<int> cities = {1, 2, 3}; // we fix 0 (A) as the starting point
    int minCost = INT_MAX;
    vector<int> bestPath;

    do {
        vector<int> currentPath = {0}; // start from A (0)
        currentPath.insert(currentPath.end(), cities.begin(), cities.end());
        
        int currentCost = calculatePathCost(currentPath, cost);
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = currentPath;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    // Output the best path and its cost
    cout << "Minimum cost path: ";
    for (int city : bestPath) {
        cout << char('A' + city) << " -> ";
    }
    cout << "A" << endl; // return to starting city

    cout << "Minimum total cost: " << minCost << endl;

    return 0;
}


// Using Branch and Bound

// We again have four vertices/cities with starting city say A
// A
// ├── B
// │   ├── C
// │   │   └── D
// │   └── D
// │       └── C
// ├── C
// │   ├── B
// │   │   └── D
// │   └── D
// │       └── B
// └── D
//     ├── B
//     │   └── C
//     └── C
//         └── B
// This generates node level wise. While generating we also find cost and we find it's cost getting more than an upper bound. We will kill it and not produce nodes further for that branch.
// Let's say we get an adjacency matrix. First, reduce the matrix i.e. find minimum value of each row and subtract it from all elements of that row.
// Add all the minimum elements from each row. This will give you cost of reducing rows.
// Similarly, reduce columns.
// Add these all as well, and add the result to the cost of reducing rows.
// Note :- If an element value becomes zero, no need to reduce further past it, as cost can't be negative.
// This combined sum may indicate the minimum cost of tour. 

// After this simply look at Abdul Bari or GFG article.