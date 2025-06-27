// Problem Statement :- https://leetcode.com/problems/count-good-triplets/description/

#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size();  // Get the size of the array
    int count = 0;       // Initialize a counter to store the number of good triplets

    // Iterate over all possible triplets (i, j, k) such that i < j < k
    for (int i = 0; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {

            // First condition: |arr[i] - arr[j]| <= a
            if (abs(arr[i] - arr[j]) <= a) {

                for (int k = j + 1; k <= n - 1; k++) {

                    // Second condition: |arr[j] - arr[k]| <= b
                    // Third condition: |arr[i] - arr[k]| <= c
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        // If all conditions are satisfied, it's a good triplet
                        count++;
                    }
                }
            }
        }
    }

    // Return the total number of good triplets found
    return count;
}

int main() {
    vector<int> arr = {3, 0, 1, 1, 9, 7};  // Example array
    int a = 7, b = 2, c = 3;               // Example values for a, b, and c

    int result = countGoodTriplets(arr, a, b, c);  // Call the function to count good triplets

    cout << "Number of good triplets: " << result << endl;  // Print the result

    return 0;
}