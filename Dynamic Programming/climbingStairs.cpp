// Problem Statement :- https://leetcode.com/problems/climbing-stairs/description/

// Refer Recursion directory for Recursion solution to this first. 

#include <iostream>
#include <vector>
using namespace std;

/**
 * Helper function for memoized top-down dynamic programming approach
 * 
 * @param n Current step being evaluated
 * @param memo Reference to a vector storing precomputed results (avoids redundant calculations)
 * @return Number of ways to reach step 'n'
 */
// int climbHelper(int n, vector<int>& memo) {
//     // Base Case 1: There's 1 way to stay at ground level (0 steps)
//     // Base Case 2: There's 1 way to reach step 1 (single 1-step)
//     if (n == 0 || n == 1) {
//         return 1;
//     }
    
//     // If we've already computed the value for step 'n', return it immediately
//     // This is the core optimization of memoization that prevents redundant work
//     if (memo[n] != -1) {
//         return memo[n];
//     }
    
//     // Recursive case: 
//     // Total ways = ways to reach (n-1) + ways to reach (n-2)
//     // This works because:
//     // - From (n-1), we take 1-step to reach n
//     // - From (n-2), we take 2-step to reach n
//     memo[n] = climbHelper(n - 1, memo) + climbHelper(n - 2, memo);
    
//     // Store the computed value in memoization table before returning
//     return memo[n];
// }

// /**
//  * Main function to calculate number of ways to climb stairs using DP
//  * 
//  * @param n Total number of steps in staircase
//  * @return Total distinct ways to reach the top
//  */
// int climbStairs(int n) {
//     // Initialize memoization table with -1 (indicates uncomputed values)
//     // Size = n+1 to accommodate steps 0 through n (inclusive)
//     vector<int> memo(n + 1, -1);
    
//     // Start recursive computation from step 'n'
//     return climbHelper(n, memo);
// }

/**
 * Bottom-up dynamic programming solution for climbing stairs problem
 * 
 * @param n The total number of steps in the staircase
 * @return The total number of distinct ways to reach the top
 */
int climbStairs(int n) {
    // Handle base cases directly for early return
    if (n <= 1) {
        return 1;
    }
    
    // Create a DP table where dp[i] represents number of ways to reach step i
    // Size is n+1 to accommodate steps from 0 to n inclusive
    vector<int> dp(n + 1);
    
    // Base case initialization:
    dp[0] = 1; // Zero steps: 1 way (do nothing)
    dp[1] = 1; // One step: 1 way (single step)
    
    // Build solution from bottom up (step 2 to final step n)
    for (int i = 2; i <= n; i++) {
        // Recurrence relation:
        // Ways to reach current step = ways to reach previous step + ways to reach two steps back
        // This works because we can either:
        // - Come from previous step (i-1) with 1-step jump
        // - Come from two steps back (i-2) with 2-step jump
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    // The final answer is stored in dp[n]
    return dp[n];
}

// Space-optimized version (optional bonus implementation)
// This reduces space complexity from O(n) to O(1) by only tracking previous two values
/*
int climbStairs(int n) {
    if (n <= 1) return 1;
    
    int prev_prev = 1; // Ways to reach step 0
    int prev = 1;      // Ways to reach step 1
    int current;
    
    for (int i = 2; i <= n; i++) {
        current = prev + prev_prev;
        prev_prev = prev;
        prev = current;
    }
    
    return current;
}
*/

int main() {
    int n;
    
    // User input: Get number of steps
    cout << "Enter the number of steps: ";
    cin >> n;
    
    // Calculate and display result using memoized DP approach
    cout << "Number of distinct ways to climb " << n << " steps: " << climbStairs(n) << endl;

    return 0;
}

