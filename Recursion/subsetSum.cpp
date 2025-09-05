// Problem Statement :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Refer subsets.cpp
// Just we also have to maintain a sum or target variable initialized with 0 and we also keep track of sum when we add elements.
// Here, we will simply abort a branch if the sum of that branch exceeds the required sum.

// First there is the code to generate sum of all subsets and from which subset it came.

#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive function to generate all subsets and their corresponding sums.
 * @param arr     - Input array.
 * @param index   - Current index in the array.
 * @param n       - Total number of elements.
 * @param sum     - Running sum of the current subset.
 * @param subset  - Vector storing current elements included in subset.
 */
// void print(int arr[], int index, int n, int sum, vector<int>& subset) {
//     // Base case: when we've considered all elements
//     if (index == n) {
//         cout << "Subset: ";
//         for (int num : subset) {
//             cout << num << " ";
//         }
//         cout << "| Sum: " << sum << endl;
//         return;
//     }

//     // Case 1: Exclude current element
//     print(arr, index + 1, n, sum, subset);

//     // Case 2: Include current element
//     subset.push_back(arr[index]);
//     print(arr, index + 1, n, sum + arr[index], subset);
//     subset.pop_back();  // Backtrack to explore next possibility
// }

// int main() {
//     int arr[] = {1, 2, 3, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     vector<int> subset;

//     print(arr, 0, n, 0, subset);

//     return 0;
// }

// This is the solution for the actual subset sum problem.

#include <iostream>
using namespace std;

/*
 * Recursive function to determine if a subset with the given target sum exists.
 *
 * @param arr    - Input array of integers.
 * @param index  - Current index in the array we're processing.
 * @param n      - Total number of elements in the array.
 * @param target - The remaining sum we're trying to achieve.
 * @return       - true (1) if a valid subset is found, otherwise false (0).
 */

bool find(int arr[], int index, int n, int target) {
    // ✅ Base case: if target becomes 0, we found a valid subset
    if (target == 0) {
        return true;
    }

    // ❌ Base case: if we've considered all elements or target goes negative, no valid subset
    if (index == n || target < 0) {
        return false;
    }

    /*
     * We have two choices at every step:
     * 1. Skip the current element → don't include arr[index] in the subset.
     * 2. Include the current element → reduce target by arr[index].
     * 
     * We return true if **either** choice leads to a valid solution.
     */
    return find(arr, index + 1, n, target)               // Exclude current element
        || find(arr, index + 1, n, target - arr[index]); // Include current element
}

int main() {
    int arr[] = {2, 4, 1, 8, 7};   // Input array
    int target = 19;              // Target sum to check for

    // Call the recursive function starting from index 0
    cout << find(arr, 0, 5, target) << " ";  // Output will be 1 if found, 0 if not
}

// What if we could repeat numbers i.e. take a number more than one time?

// Say we had :- {2, 3, 4} and target = 6. First, we can use either 2 or not use 2. If we didn't use 2, then no worries.
// If we did, target = 4 and now again we have choice of either choosing 2 or not. Hence, now if we pick an element, we won't move the index.
// Now simply, we can continue. Ofcourse once target becomes negative abort the route.

bool find(int arr[], int index, int n, int target) {
    // ✅ Base case: if target becomes 0, we found a valid subset
    if (target == 0) {
        return true;
    }

    // ❌ Base case: if we've considered all elements or target goes negative, no valid subset
    if (index == n || target < 0) {
        return false;
    }

    /*
     * We have two choices at every step:
     * 1. Skip the current element → don't include arr[index] in the subset.
     * 2. Include the current element → reduce target by arr[index].
     * 
     * We return true if **either** choice leads to a valid solution.
     */
    return find(arr, index + 1, n, target)               // Exclude current element
        || find(arr, index, n, target - arr[index]); // Include current element. But don't move index
}
