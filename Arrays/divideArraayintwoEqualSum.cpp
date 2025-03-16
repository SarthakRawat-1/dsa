// We have to divide an array into two subarrays such that the sum of elements of both subarrays are equal.

// One way to solve this is checking sums of both subarrays for each case. You can check that for an array with elements n, the total pairs can be n - 1 as remember that subarray is made from contiguous elements and we have to divide the array to get subarrays meaning not even a single element can be shared between them. 
// This approach will require a for loop to check all possible pairs. So this will go from 0 to n - 2 (included), not n - 1, as if we divide array after the last element it doesn't make any sense. Let's say this loop is represented by i. Now from 0 to i we have our first subarray and from i + 1 to n - 1 we have our second subarray. Now just use for loops for both of them to calculate their sum and compare.

// A better appraoch is using Prefix sum. 
// First calculate the total sum of the array, then calculate Prefix sum of each element in the array. Now we can compare the prefix sum of each element with the remaining sum of the array using Total sum.
// For eg :- You have {3, 4, -2, 5, 8, 20, -10, 8} Total sum = 36, Now prefix sum of 3 is 3 and now rest of the array sum will be 36 - 3 = 33. Now 3 and 33 are not equal, meaning we can't divide here for equal sum.
// Now prefix sum of 4 will be 7 and remaining sum 36 - 7 = 29, so here also we can't divide. Continue doing this till the prefix sum and remaining sum becomes equal, that'll be our answer. If they never become equal, then it means the array cannot be divided into two equal sums.

#include <bits/stdc++.h>
using namespace std;

// Function to divide the array into two parts with equal sum
void divideSubarray(vector<int> arr, int n) {
    int prefix = 0;     // Prefix sum that keeps track of the sum from the start of the array
    int total_sum = 0;  // Variable to store the total sum of all elements in the array

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];  // Add each element to the total sum
    }

    // Traverse the array to find a point where the prefix sum equals the remaining sum
    for (int i = 0; i < n; i++) {
        prefix += arr[i];  // Increment the prefix sum with the current element
        int remaining_sum = total_sum - prefix;  // Calculate the remaining sum after removing the prefix sum

        // Check if the prefix sum is equal to the remaining sum
        if (remaining_sum == prefix) {
            // If equal, print the index where the array can be divided
            cout << "Array can be divided at index " + to_string(i);
            return;  // Exit the function once the point is found
        }
    }

    // If no such point is found, print that the array cannot be divided equally
    cout << "Array cannot be divided into two parts with equal sum";
    return;
}

int main() {
    vector<int> v = {3, 4, -2, 5, 8, 20, -10, 8};
    int n = v.size();

    divideSubarray(v, n);
}