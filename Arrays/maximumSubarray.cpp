// Problem Statement :- https://leetcode.com/problems/maximum-subarray/description/

// Brute Force Approach :- We will check the sum of every possible subarray and consider the maximum among them. Check out A2Z Sheet for this.
// A better approach involves using the concept of prefix sum. We can notice that to get the sum of the current subarray we just need to add the current element to the sum of the previous subarray.
// Assume previous subarray = arr[i……j-1] Current subarray = arr[i…..j] Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]
// Cosnider we have the array {4, -6, 2, 8}, possible subarrays for this include {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}, {1}, {1, 2}, {1, 2, 3}, {2}, {2, 3}, {3} These are not elements, i have used index instead of elements to signify possible subarrays.
// Now we will use which will go to each index one by one. And for every index it'll calculate prefix sum of that element (As if it was the first elment of the array) and elements after it.
// So for 0 index, prefix sum will calculate prefix sum till index 3. For 1 index, prefix sum will also calculate till index 3, but this time element at index 0 will be not considered for adding to prefix sum.
// In this way, we can get all the subarrays sum, which is nothing but their prefix sum. Then we can jsut compare which prefix sum is the maximum.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum subarray sum
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // Initialize maxi to the smallest possible value to track the maximum subarray sum

    // Loop over each element to set the starting point of the subarray
    for (int i = 0; i < n; i++) {
        int prefixSum = 0; // Initialize prefixSum to 0 for the current subarray starting from arr[i]

        // Loop to extend the subarray from index 'i' to 'j'
        for (int j = i; j < n; j++) {
            // Current subarray is arr[i...j]

            // Add the current element arr[j] to the prefixSum
            // This adds the element to the prefixSum of the previous subarray (arr[i...j-1])
            prefixSum += arr[j];

            // Update the maximum subarray sum found so far
            maxi = max(maxi, prefixSum);
        }
    }

    // Return the maximum subarray sum found
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}


// However the optimal solution to this comes using an algorithm named Kadane Algorithm. It also works on the basis of prefix sum.
// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
// Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
// Note :- In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one. For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // Initialize the maximum sum to the smallest possible long integer
    long long sum = 0;         // Initialize sum for the current subarray

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {

        sum += arr[i];  // Add the current element to the sum of the current subarray

        // Update the maximum sum if the current subarray sum is greater than the previous maximum
        if (sum > maxi) {
            maxi = sum;
        }

        // If the sum becomes negative, reset it to 0
        // because any subarray with a negative sum cannot contribute to a maximum sum
        if (sum < 0) {
            sum = 0;
        }
    }

    // If we want to consider the sum of the empty subarray (sum = 0), 
    // we can uncomment the below condition. It handles cases where all elements are negative.
    // if (maxi < 0) maxi = 0;

    // Return the maximum subarray sum found
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    long long maxSum = maxSubarraySum(arr, n);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}

// There's a follow up question to this :- There might be more than one subarray with the maximum sum. We need to print any of them.
// Our approach is to store the starting index and the ending index of the subarray. Thus we can easily get the subarray afterward without actually storing the subarray elements.
// If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).
// So, we will keep a track of the starting index inside the loop using a start variable. We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i. The rest of the approach will be the same as Kadane’s Algorithm.

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm and also track the starting and ending indices of the subarray
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // Initialize the maximum sum to the smallest possible long integer
    long long sum = 0;         // Initialize sum for the current subarray

    int start = 0;             // Variable to store the starting index of the current subarray
    int ansStart = -1, ansEnd = -1;  // Variables to store the final start and end indices of the max subarray

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {

        // If the sum is 0, it means a new subarray is starting
        if (sum == 0) start = i; // Mark the starting index of the current subarray

        // Add the current element to the sum of the subarray
        sum += arr[i];

        // Update the maximum sum and track the indices if a new maximum is found
        if (sum > maxi) {
            maxi = sum;         // Update the maximum sum
            ansStart = start;   // Store the starting index of the max subarray
            ansEnd = i;         // Store the ending index of the max subarray
        }

        // If the sum becomes negative, reset it to 0
        // because any subarray with a negative sum will not contribute to the maximum sum
        if (sum < 0) {
            sum = 0; // Reset the sum to start a new subarray from the next element
        }
    }

    // Printing the subarray that gives the maximum sum:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";  // Print each element in the subarray
    }
    cout << "]\n";  // End the subarray output

    // To consider the sum of the empty subarray (sum = 0), 
    // we can uncomment the below condition. It handles cases where all elements are negative.
    // if (maxi < 0) maxi = 0;

    // Return the maximum subarray sum found
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    long long maxSum = maxSubarraySum(arr, n);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}
