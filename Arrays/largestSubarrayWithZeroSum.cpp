// Problem Statement :- https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Let’s say we are calculating the prefix sum while traversing the array.
// Suppose at index i, prefix sum is S, and again at index j, prefix sum becomes S (same sum again).
// That means: The sum of elements from index (i+1 to j) is zero

#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    // Hash map to store the first occurrence of each prefix sum
    unordered_map<int, int> mpp; 
    
    int maxi = 0; // Variable to store the length of the longest subarray with sum = 0
    int sum = 0;  // Variable to store the cumulative sum (prefix sum)

    for (int i = 0; i < n; i++) {
        sum += A[i]; // Update the prefix sum with the current element

        if (sum == 0) {
            // If the prefix sum is 0, the subarray from index 0 to i has sum 0
            maxi = i + 1;
        }
        else {
            // If this prefix sum has been seen before
            if (mpp.find(sum) != mpp.end()) {
                // The subarray between previous index (where this sum was seen)
                // and the current index has sum 0
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                // If this sum is seen for the first time, store its index
                mpp[sum] = i;
            }
        }   
    }

    // Return the maximum length found
    return maxi;
}

int main() {

}