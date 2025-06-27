// Problem Statement :- https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// We will be given input :- weight array, value array and W.
// We have to find maximum profit.
// As there are choice to include a item or not, this is a recursive problem. 
// Let's say you have Item 1 i.e. W1, we have to put it in bag. 
// We can only put it in bag, if the sum of bag (W) will be more than item. In this case, we can either put it in bag or not i.e. we have a choice.
// If item weight is more, then no choice, we can't include it in the bag.

#include <bits/stdc++.h>
using namespace std;


// Recursive approach (Without memoization)
int knapsack(int wt[], int val[], int W, int n) {
    // Base condition: if no items left or bag capacity is zero
    if (n == 0 || W == 0) {
        return 0;
    }

    // If weight of nth item is less than or equal to capacity W,
    // we have two choices: either include it or exclude it
    if (wt[n - 1] <= W) {
        return max(
            val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),  // Include the item
            knapsack(wt, val, W, n - 1)                            // Exclude the item
        );
    } else {
        // If weight is more than current capacity, can't include it
        return knapsack(wt, val, W, n - 1);
    }
}

// Memoized Recursive approach
int knapsackMemoUtil(int wt[], int val[], int W, int n, vector<vector<int>> &dp) {
    // Base condition: if no items or no capacity
    if (n == 0 || W == 0) {
        return 0;
    }

    // If result already computed, return it
    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    // If weight of item is less than or equal to remaining capacity
    if (wt[n - 1] <= W) {
        dp[n][W] = max(
            val[n - 1] + knapsackMemoUtil(wt, val, W - wt[n - 1], n - 1, dp),  // Include item
            knapsackMemoUtil(wt, val, W, n - 1, dp)                            // Exclude item
        );
    } else {
        // If item can't be included
        dp[n][W] = knapsackMemoUtil(wt, val, W, n - 1, dp);
    }

    return dp[n][W];
}

// Wrapper function for memoization
int knapsackMemo(int wt[], int val[], int W, int n) {
    // Initialize dp table with -1 indicating uncomputed states
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapsackMemoUtil(wt, val, W, n, dp);
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value that can be obtained: " << knapsackMemo(wt, val, W, n) << endl;

    return 0;
}