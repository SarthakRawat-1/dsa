// Problem Statment :- https://www.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1

// This is a lot similar to climbingStairs.cpp just you can also take 3 steps.
// So, Total number of ways to reach n = Total number of ways to reach n - 1 + Total number of ways to reach n - 2 + Total number of ways to reach n - 3

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
// Function to compute the number of ways to reach step 'n' using recursion with memoization
// int ways(int n, vector<long long> &dp) {
//     // Base cases:
//     // If the frog is on step 0 or 1, there is only 1 way to stay there.
//     if (n <= 1) {
//         return 1;
//     }

//     // If the frog is on step 2, there are 2 ways (1+1 or a direct jump of 2).
//     if (n == 2) {
//         return 2;
//     }

//     // Check if the result for step 'n' is already calculated (memoized).
//     if (dp[n] != -1) {
//         return dp[n];
//     }

//     // Recursively calculate the number of ways to reach step 'n' using steps (n-1), (n-2), and (n-3),
//     // taking modulo 10^9+7 to avoid integer overflow.
//     return dp[n] = (ways(n - 1, dp) + ways(n - 2, dp) + ways(n - 3, dp)) % 1000000007;
// }

// // Wrapper function to initialize the memoization table and invoke the recursive function.
// long long countWays(int n) {
//     // Create a memoization table initialized with -1, indicating uncomputed values.
//     vector<long long> dp(n + 1, -1);
//     // Call the helper function and return the result.
//     return ways(n, dp);
// }

// Bottom Up Approach
// long long countWays(int n) {
//     const int MOD = 1000000007;

//     // Base cases for small values of n
//     if (n == 0) return 1; // 1 way to stay at the ground (do nothing)
//     if (n == 1) return 1; // Only 1 way to jump 1 step
//     if (n == 2) return 2; // Two ways: (1+1) or (2)

//     // Create a dp array to store results for each step
//     vector<long long> dp(n + 1, 0);

//     // Initialize base cases
//     dp[0] = 1; // 1 way to stay at step 0
//     dp[1] = 1; // 1 way to reach step 1
//     dp[2] = 2; // 2 ways to reach step 2

//     // Fill the dp array iteratively for steps 3 to n
//     for (int i = 3; i <= n; i++) {
//         dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
//     }

//     // Return the number of ways to reach step 'n'
//     return dp[n];
// }

// Space Optimized Approach
// Function to compute the number of ways using a space-optimized bottom-up approach
long long countWays(int n) {
    const int MOD = 1000000007;

    // Base cases for small values of n
    if (n == 0) return 1; // 1 way to stay at the ground (do nothing)
    if (n == 1) return 1; // Only 1 way to jump 1 step
    if (n == 2) return 2; // Two ways: (1+1) or (2)

    // Use three variables to store the last three results
    long long prev3 = 1; // dp[0]
    long long prev2 = 1; // dp[1]
    long long prev1 = 2; // dp[2]

    // Iteratively compute the number of ways for steps 3 to n
    for (int i = 3; i <= n; i++) {
        long long curr = (prev1 + prev2 + prev3) % MOD; // Current number of ways
        prev3 = prev2; // Shift the variables
        prev2 = prev1;
        prev1 = curr;
    }

    // Return the number of ways to reach step 'n'
    return prev1;
}

int main() {
    int n = 5; // Example input
    cout << "Number of ways to reach step " << n << ": " << countWays(n) << endl;
    return 0;
}