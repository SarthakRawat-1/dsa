// Problem Statement :- https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Let's say we have value = {60, 100, 120} and weight = {10, 20, 30} and capacity = 50
// Greedily, we will take the weight of that one with highest value. After that second highest value. But this is not a good way to solve. In this case we only have 120 + 100 = 220
// If we put weight 10, then weight 20 and then break weight 30 and put 20 from that. We will get 60 + 100 + 80 = 240
// Hence, here we will find value per weight for each of the item. Then the highest one of them will first be inserted.

#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item with value and weight
struct Item {
    int value, weight;
};

// Comparator function to sort items based on value-to-weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in descending order of value-to-weight ratio
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items by value-to-weight ratio
    sort(arr, arr + n, cmp);

    double finalValue = 0.0; // Total value of the knapsack

    // Traverse through all items
    for (int i = 0; i < n; i++) {
        // If the entire item can fit in the knapsack, take it
        if (arr[i].weight <= W) {
            W -= arr[i].weight;         // Reduce remaining weight
            finalValue += arr[i].value; // Add full value of the item
        } 
        // If only a fraction of the item can fit, take the fraction
        else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break; // No more space left in the knapsack
        }
    }

    return finalValue; // Return the maximum value obtained
}

int main() {
    int W = 50; 

    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]); 

    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
