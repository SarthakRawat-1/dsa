// Problem Statement :- https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

// Let's say you have candies :- {5, 3, 2, 1, 4} with k = 2
// For minimum cost, we will buy the cheapest candy i.e. 1 and take the most expensive i.e. 5 and the second most expensive i.e. 4 candy for free.
// Now, we have left :- {2, 3}, 2 is the cheapest so we buy that and we take 3 for free.
// For maximum cost, we will buy the most expensive candy i.e. 5 and take cheapest i.e. 1 and second cheapest i.e. 2 candy for free.
// Now, we have left :- {3, 4}, 4 is the most expensive so we buy that and we take 3 for free.

// So, first we will sort this array. We will use two pointers to track the candies bought/taken.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimum and maximum cost of buying candies
vector<int> candyStore(int candies[], int N, int K) {
    // Sort the candies array in ascending order to prioritize cheapest and most expensive
    sort(candies, candies + N);

    // Variables to store the minimum and maximum amounts
    int min_amount = 0, max_amount = 0;

    // Variables to handle pointers for minimum cost calculation
    int i = 0, j = N - 1;

    // Calculate minimum amount by buying cheapest candies and skipping K most expensive
    while (i <= j) {
        min_amount += candies[i]; // Buy the cheapest candy
        i++; // Move to the next cheapest
        j -= K; // Skip K most expensive candies
    }

    // Reset pointers for maximum cost calculation
    i = N - 1, j = 0;

    // Calculate maximum amount by buying most expensive candies and skipping K cheapest
    while (i >= j) {
        max_amount += candies[i]; // Buy the most expensive candy
        i--; // Move to the next most expensive
        j += K; // Skip K cheapest candies
    }

    // Store results in a vector
    vector<int> ans;
    ans.push_back(min_amount); // Minimum cost
    ans.push_back(max_amount); // Maximum cost

    return ans; // Return results
}

int main() {
    int N = 5, K = 2;
    int candies[] = {5, 3, 2, 1, 4};

    vector<int> ans = candyStore(candies, N, K);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }   

    return 0;
}