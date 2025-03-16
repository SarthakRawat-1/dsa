// Problem Statement :- https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum number of integers that can be chosen
// from the range [1, n] such that their sum does not exceed maxSum and 
// none of the chosen integers are in the banned list.
int maxCount(vector<int>& banned, int n, int maxSum) {
    // Use an unordered_set for quick lookup of banned numbers.
    unordered_set<int> ban(banned.begin(), banned.end());
    
    // Initialize variables to keep track of the count of chosen integers and their sum.
    int count = 0, sum = 0;

    // Iterate through numbers from 1 to n.
    for (int num = 1; num <= n; num++) {
        // If the current number is in the banned set, skip it.
        if (ban.count(num)) {
            continue;
        }

        // If adding the current number does not exceed maxSum,
        // include it in the count and update the sum.
        if (sum + num <= maxSum) {
            count++;
            sum += num;
        } else {
            // Break the loop if the sum exceeds maxSum.
            break;
        }
    }

    // Return the total count of chosen integers.
    return count;
}

int main() {
    vector<int> banned1 = {1, 4, 6};
    int n1 = 10, maxSum1 = 20;
    cout << "Maximum count of integers: " << maxCount(banned1, n1, maxSum1) << endl;

    return 0;
}