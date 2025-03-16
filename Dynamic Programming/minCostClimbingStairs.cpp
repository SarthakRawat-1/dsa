// Problem Statement :- https://leetcode.com/problems/min-cost-climbing-stairs/description/

// First, we will solve this using Recursion.
// Again, as it was in climbingStairs.cpp, we can reach n, either from (n - 1) or (n - 2).
// So, minimum cost to reach nth stair = cost of (n - 1) + min cost to reach (n - 1) stair or cost of (n - 2) + min cost to reach (n - 2) stair. We will take the min of both as answer.
// Cost to reach 0 or 1 stair is zero, because we can start from either of them meaning we already have access to them.

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach (Memoization)
int ways(int n, vector<int> &cost, vector<int> &dp) {
    // Base case: If n is 0 or 1, the cost to reach these stairs is 0
    // because we can start from either of them.
    if (n <= 1) {
        return 0;
    }

    // If the result for the current stair `n` is already computed,
    // return it from the dp array to avoid redundant calculations.
    if (dp[n] != -1) {
        return dp[n];
    }

    // Recursively calculate the minimum cost to reach the nth stair:
    // Option 1: Climb from (n-1)th stair and add its cost.
    // Option 2: Climb from (n-2)th stair and add its cost.
    // Store the result in the dp array and return it.
    return dp[n] = min(cost[n - 1] + ways(n - 1, cost, dp), cost[n - 2] + ways(n - 2, cost, dp));
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    // Initialize a dp array with size (n + 1) and fill it with -1
    // to indicate that no calculations have been done yet.
    vector<int> dp(n + 1, -1);
    
    // Call the recursive function to compute the minimum cost.
    return ways(n, cost, dp);
}

// Bottom Up Approach (Tabulation)
// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();

//     // Initialize a dp array with size (n + 1) to store the minimum cost
//     // to reach each stair.
//     vector<int> dp(n + 1, -1);

//     // Base cases:
//     // Cost to reach stair 0 is 0 (we can start here).
//     // Cost to reach stair 1 is 0 (we can start here).
//     dp[0] = 0;
//     dp[1] = 0;

//     // Iterate from stair 2 to stair n and compute the minimum cost
//     // to reach each stair using the results from previous stairs.
//     for(int i = 2; i <= n; i++) {
//         dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
//     }

//     // Return the minimum cost to reach the nth stair.
//     return dp[n];
// }

// Space Optimized Approach
// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();

//     // Initialize variables to store the cost of reaching the previous two stairs.
//     int prev2 = 0; // Cost to reach stair 0
//     int prev1 = 0; // Cost to reach stair 1

//     // Iterate from stair 2 to stair n and compute the minimum cost
//     // to reach each stair using the results from the previous two stairs.
//     for(int i = 2; i <= n; i++) {
//         int current = min(cost[i - 1] + prev1, cost[i - 2] + prev2);
        
//         // Update the previous two stairs' costs for the next iteration.
//         prev2 = prev1;
//         prev1 = current;
//     }

//     // Return the minimum cost to reach the nth stair.
//     return prev1;
// }

int main() {
    // Example usage:
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost (Top Down): " << minCostClimbingStairs(cost) << endl;
    return 0;
}