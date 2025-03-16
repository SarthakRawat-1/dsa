// Problem Statement :- https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

// Brute Force Approach :- Take two for loops. In the outer loop, pick elements one by one and in the inner loop calculate the difference of the picked element with every other element in the array (after the picked element) and compare the difference with the maximum difference calculated so far.  
// A better approach would be that for every picked element, we can find the maximum element in the rest of the array and calculate the difference with the picked element. Then we can compare the difference with the maximum difference calculated so far.
// To find that maximum element, we can use suffix max. For the last element, suffix sum will be the last element itself. Now we come to second last element, compare it with current suffix max. If it's greater replace, the suffix max. Continue doing this till the end. 
// With this, you will find the maximum element in rest of the array very easily. For eg :- if fourth last element is our picked element then maximum element after that in rest of the array will be value of suffix max at third last element.

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum difference
int maxDifference(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;  // No difference can be calculated if there's less than two elements

    // Initialize the suffix max array
    vector<int> suffixMax(n);
    
    // Set the last element of suffixMax to be the last element of the array
    suffixMax[n-1] = arr[n-1];
    
    // Fill the suffix max array by iterating backwards
    for (int i = n-2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i+1], arr[i]);
    }

    int maxDiff = INT_MIN;

    // Calculate the maximum difference
    for (int i = 0; i < n-1; i++) {
        // Compare the current element with the maximum element in the suffix. Necessary because problem statement states that larger number should come after the picked element.
        if (suffixMax[i+1] > arr[i]) {
            maxDiff = max(maxDiff, suffixMax[i+1] - arr[i]);
        }
    }

    return maxDiff;
}

int main() {
    vector<int> arr = {2, 3, 10, 6, 4, 8, 1};
    int result = maxDifference(arr);
    
    if (result != INT_MIN) {
        cout << "Maximum difference is: " << result << endl;
    } else {
        cout << "No valid difference found." << endl;
    }

    return 0;
}
