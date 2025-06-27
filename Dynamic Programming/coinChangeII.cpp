// Problem Statement :- https://leetcode.com/problems/coin-change-ii/description/

// Revise subset sum and count of subset before this.
// This is the number of ways varaition of coin change.
// This is an unbounded knapsack problem. The coin array is like the weight array of knapsack and W is sum here.

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
// Recursive function to find the number of combinations to make up 'amount' using coins[0..index]
int find(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    // Base case: if amount becomes 0, one valid combination is found
    if (amount == 0) {
        return 1;
    }

    // Base case: if no coins are left and amount is still not 0, no combination possible
    if (index < 0) {
        return 0;
    }

    // If result is already computed, return it (memoization)
    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    // If the current coin is greater than the remaining amount, skip it
    if (coins[index] > amount) {
        // Explore the option of excluding the current coin
        return dp[index][amount] = find(index - 1, amount, coins, dp);
    } else {
        // Two choices:
        // 1. Include the current coin and stay at the same index (unlimited supply)
        // 2. Exclude the current coin and move to the next smaller index
        return dp[index][amount] = find(index, amount - coins[index], coins, dp) + 
                                   find(index - 1, amount, coins, dp);
    }
}

// Main function to initiate the process and create DP table
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    // DP table initialized with -1 (to denote uncomputed states)
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    // Start the recursion from the last index
    return find(n - 1, amount, coins, dp);
}

// Bottom Up Approach
// But this is not working for the last test case.
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    
    // Initialize a 2D DP table where dp[i][j] will store the number of ways 
    // to make amount 'j' using the first 'i' types of coins
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base Case: There is exactly 1 way to make amount 0 — by choosing no coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] > j) {
                // If the current coin value is greater than the amount,
                // we can't include this coin. So we take the value from the row above.
                dp[i][j] = dp[i - 1][j];
            } else {
                // Otherwise, we consider two possibilities:
                // 1. Include the current coin (stay in the same row)
                // 2. Exclude the current coin (take value from the row above)
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
        }
    }

    // The final answer is the number of ways to make 'amount' using all 'n' coins
    return dp[n][amount];
}

// Space Optimized Approach
int change(int amount, vector<int>& coins) {
    vector<double> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return (int)(dp[amount] + 0.1);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    return 0;
}