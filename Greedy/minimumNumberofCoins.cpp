// Problem Statement :- https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

// Let's say we are given N = 143
// We can think of getting the coin which is smaller than or equal to 143, but the biggest of the available options. In our case it will be 100.
// After that we need to make 43, we can again apply the same approach and find that 20 fits the criteria.
// For 23, also 20 fits the criteria. For 3, we will use a coin of 2 and finally for 1 we will use a coin of 1.

// Hence, first we will check if N is divisble by the coins available (starting from biggest). If division gives 0 as result, it means the coin is bigger than N, so we can't take that.
// The first non zero divison result giving coin will be the coin which we will select. The division result will be the number of times, that coin is taken. For eg :- 143/100 = 1, so take 100 one time but 43/20 = 2 so take 20 two times.

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of currency notes/coins required
vector<int> minPartition(int N) {
    // Define available currency denominations in descending order
    int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int notes = 0; // Variable to store the number of notes for each denomination
    int i = 0;     // Index to traverse the currency array

    vector<int> ans; // Vector to store the result (denominations used)

    // Loop until the entire amount is partitioned
    while (N) {
        // Calculate the number of notes of the current denomination required
        notes = N / currency[i];

        // Add the current denomination 'notes' times to the result
        while (notes--) {
            ans.push_back(currency[i]);
        }

        // Update the remaining amount after using the current denomination
        N = N % currency[i];
        i++; // Move to the next denomination
    }

    return ans; // Return the list of denominations used
}

int main() {
    int N = 143;
    
    vector<int> ans = minPartition(N);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}


// Note :- Greedy will not work in every question. Suppose we wanted to make 6 and available number of coins were :- [4, 3, 1]
// In this case, minimum number of coins are 2 for {3, 3} but if we used Greedy and took 4 first, then we will have to take two 1 coins, making 3 total number of coins.
