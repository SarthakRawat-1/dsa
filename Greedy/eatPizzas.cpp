// Problem Statement :- https://leetcode.com/problems/eat-pizzas/description/

#include <bits/stdc++.h>
using namespace std;

long long maxWeight(vector<int>& pizzas) {
    // Step 1: Sort the pizzas in non-decreasing order.
    // This lets us easily access the heaviest pizzas (which are at the end of the vector)
    // and plan our grouping to maximize the total weight gain.
    sort(pizzas.begin(), pizzas.end());

    // Total number of pizzas
    int n = pizzas.size();
    // Calculate the total number of days we will be eating.
    // Since we eat 4 pizzas per day, the number of days is n / 4.
    int days = n / 4;

    // 'index' will be used to point to the current pizza we are selecting from the end (largest side).
    int index = n - 1;

    // This variable will accumulate the total weight gained.
    long long totalWeight = 0;

    // -------------------------------
    // Process odd-numbered days (1-indexed)
    // -------------------------------
    // On odd days, you gain the weight of the heaviest pizza in that day's group.
    // We simulate this by taking the largest available pizza for each odd day.
    for (int day = 1; day <= days; day += 2) {
        // pizzas[index] is the largest remaining pizza.
        // Add its weight to totalWeight (this is the gain for an odd day).
        totalWeight += pizzas[index];
        // Decrement index to mark that this pizza has been used.
        index--;
    }

    // -------------------------------
    // Process even-numbered days (1-indexed)
    // -------------------------------
    // On even days, you gain the weight of the second heaviest pizza in that day's group.
    // Before processing even days, we adjust the index:
    //   - The pizza at pizzas[index] now would act as a "filler" (or a non-scoring pizza) in the grouping.
    //   - Thus, we skip one pizza by decrementing the index.
    index--;

    // Now, iterate over the even-numbered days.
    for (int day = 2; day <= days; day += 2) {
        // pizzas[index] now holds the optimal pizza weight for an even day,
        // which is the second heaviest in that group.
        totalWeight += pizzas[index];

        // After selecting the scoring pizza for the even day, we need to simulate removing
        // the remaining pizzas in that day's group:
        //   - One pizza was used as the scoring pizza (we just picked it).
        //   - One pizza will serve as the filler pizza (already skipped by our previous decrement).
        // Hence, we need to move the index two positions back.
        index -= 2;
    }

    // Return the computed maximum total weight gain after eating all pizzas optimally.
    return totalWeight;
}

int main() {
    vector<int> pizzas = {1,2,3,4,5,6,7,8};

    cout << maxWeight(pizzas) << endl;

    return 0;
}