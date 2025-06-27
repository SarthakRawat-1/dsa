// Pretty much like 0 1 Knapsack but here we can put multiple instances of same item in the knapsack.
// For any item, we have two choices, either we include it or we exclude it. If we exclude it, then it's processed, so we will never come back to it.
// But if we include it, then we can come back to it again, so it's still not commpletely processed (Note in 0 1 Knapsack, this will be considered processed too).

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// 🧠 Recursive approach for Unbounded Knapsack (Without memoization)
int unboundedKnapsack(int wt[], int val[], int W, int n) {
    // Base case: If no items left or capacity is 0, profit is 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // If current item's weight is less than or equal to remaining capacity
    if (wt[n - 1] <= W) {
        // Two choices:
        // 1. Include the item → reduce capacity by wt[n-1], but keep 'n' same (because we can reuse the item)
        // 2. Exclude the item → move to next item (n-1)
        return max(
            val[n - 1] + unboundedKnapsack(wt, val, W - wt[n - 1], n),  // Include the item (stay at same n)
            unboundedKnapsack(wt, val, W, n - 1)                         // Exclude the item
        );
    } else {
        // If current item's weight > capacity → cannot include it, move to next item
        return unboundedKnapsack(wt, val, W, n - 1);
    }
}

// 🧠 Memoized Recursive approach for Unbounded Knapsack
int unboundedKnapsackMemoUtil(int wt[], int val[], int W, int n, vector<vector<int>> &dp) {
    // Base case: If no items or capacity is 0 → profit is 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // If already computed, return stored value
    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    // If current item can be included (i.e., weight fits in remaining capacity)
    if (wt[n - 1] <= W) {
        // Two choices:
        // 1. Include item → stay at same index (can include again)
        // 2. Exclude item → move to previous item
        dp[n][W] = max(
            val[n - 1] + unboundedKnapsackMemoUtil(wt, val, W - wt[n - 1], n, dp),  // Include (stay at n)
            unboundedKnapsackMemoUtil(wt, val, W, n - 1, dp)                        // Exclude (move to n - 1)
        );
    } else {
        // Can't include item → move to previous item
        dp[n][W] = unboundedKnapsackMemoUtil(wt, val, W, n - 1, dp);
    }

    return dp[n][W];
}

// Wrapper function to handle memo table initialization
int unboundedKnapsackMemo(int wt[], int val[], int W, int n) {
    // Initialize memo table with -1 indicating uncomputed states
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return unboundedKnapsackMemoUtil(wt, val, W, n, dp);
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }


}