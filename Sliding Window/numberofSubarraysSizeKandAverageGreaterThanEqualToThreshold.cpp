// Problem Statement :- https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

// Start with beginning and grow the window till the specified k, and start calculating average for each window.
// Effective way to calculate average is to keep track of window's sum. We can simply divide it by k to find average.
// Whenever we find a subarray satisfying the given constraints, we will add 1 to the result.

#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays of size k with average >= threshold
int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n = arr.size();          // Total number of elements in the array
    int windowSum = 0;           // Current sum of the sliding window of size k
    int count = 0;               // Counter for valid subarrays

    // Step 1: Calculate the sum of the first window of size k
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }

    // Check if the first window satisfies the condition
    // Instead of computing average, compare windowSum with k * threshold
    if (windowSum >= k * threshold) count++;

    // Step 2: Slide the window through the array
    for (int i = k; i < n; ++i) {
        // Add the next element and remove the element going out of the window
        windowSum += arr[i] - arr[i - k];

        // Check if the new window satisfies the condition
        if (windowSum >= k * threshold) count++;
    }

    // Return the total count of valid subarrays
    return count;
}

int main() {
    // Example test case
    vector<int> arr = {2, 1, 3, 4, 5};  // Input array
    int k = 2;                          // Subarray size
    int threshold = 3;                 // Minimum average threshold

    // Call the function and store result
    int result = numOfSubarrays(arr, k, threshold);

    // Output the result
    cout << "Number of valid subarrays: " << result << endl;

    return 0;
}
