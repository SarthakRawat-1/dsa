// Problem Statement :- https://leetcode.com/problems/minimum-time-to-repair-cars/description/

// There can be a lot of possibility in distributing different number of cars to mechanics.

// Intution :-
// Max from all of time required by each mechanics, will be the answer. For Leetcode eg :- max(16, 8, 12, 16) = 16 is the answer. In a sense we can say that the slowest mechanic will decide the answer. 
// But we can have several of such cases. We have to minimize the maximum of each case. This is a hint to BS on Answers.
// We are asked for time in the question, so we apply BS on time. 
// We will assign minimmum value of time i.e. 1 to low and maximum value of time i.e. max(ranks) * cars * cars to high.
// Now calculate mid and check if it is possible to fix the cars using mechanics in this time. This we can find by n x n = time/rank where n is the car assigned to a mechanic. We will do this for every mechanic, find for all and sum them to check it's greater than equal to cars.
// Remember, we can do this because all mechanics can work simultaneously. Look at above Leetcode eg.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // Defining a shorthand for long long to handle large values easily.

// Helper function to check if it's possible to repair 'cars' in 'mid' time.
bool isPossible(vector<int>& ranks, ll mid, int cars) {
    ll carsFixed = 0; // Counter to track the number of cars that can be repaired within 'mid' time.

    for(int i = 0; i < ranks.size(); i++) {
        // The formula sqrt(mid / ranks[i]) calculates how many cars a mechanic with rank[i] can repair in 'mid' time.
        carsFixed += sqrt(mid / ranks[i]); // Ignoring this part for now, as per user instruction.
    }

    return carsFixed >= cars; // If we can repair at least 'cars' vehicles, return true.
}

// Main function to find the minimum possible time required to repair all cars.
long long repairCars(vector<int>& ranks, int cars) {
    int n = ranks.size(); // Number of mechanics.

    ll l = 1; // Minimum possible time required (at least 1 unit).
    int maxR = *max_element(begin(ranks), end(ranks)); // Finding the maximum rank of mechanics.
    ll r = 1LL * maxR * cars * cars; // Upper bound on time (worst case: slowest mechanic repairing all cars).

    ll result = -1; // To store the minimum time required.

    // Binary search to find the minimum time.
    // Time Complexity: O(n * log(maxR * cars * cars))
    while (l <= r) { // log(maxR * cars * cars) iterations
        ll mid = l + (r - l) / 2; // Middle time point.

        // Check if we can repair 'cars' within 'mid' time.
        if (isPossible(ranks, mid, cars)) { // O(n) complexity
            result = mid; // Update the result with the possible minimum time.
            r = mid - 1; // Try to find a smaller valid time.
        } else {
            l = mid + 1; // Increase the time limit if not enough cars are repaired.
        }
    }

    return result; // Return the minimum time found.
}

int main() {
    vector<int> ranks = {4, 2, 3, 1}; // Example ranks of mechanics.
    int cars = 10; // Number of cars to repair.

    cout << repairCars(ranks, cars) << endl; // Output the minimum time required.

    return 0;
}