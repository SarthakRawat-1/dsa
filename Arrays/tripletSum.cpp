// Problem Statement :- https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Brute Force approach would be to use three loops, using that take 3 numbers (different combiantions), and check if their sum is equal to target.

// A more Optimized approach involves first sorting the array. Then, use two pointers. Intially, first pointer will point to first element, and second pointer will point to second element. Find their sum. Do Target - Sum, this will give you what the third number should be. To find that, we can just use binary search in the rest of the array, as it is sorted.
// If the third number is not found, move the second pointer by one such that it points to third element. Again, use binary search for elements after the second pointer to find the third number. Keep doing this, till you don't find the number. Do this till second pointer points to the second last element (no need to check for last element, as nothing exists beyond that so we can't get third number anyway).
// If you were not able to find till now, then move the first pointer now. The first pointer points to the second element, and the second pointer starts from the third element. Continue doing this, till you find the third number. First pointer can be moved till the third last element (because we need 3 numbers).

#include <bits/stdc++.h>
using namespace std;

// Helper function to use binary search for finding the third number.
bool binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return true;   // Target found.
        else if (arr[mid] < target) left = mid + 1;  // Move to the right half.
        else right = mid - 1;  // Move to the left half.
    }
    return false;  // Target not found.
}

int findTriplet(int arr[], int n, int x) {
    // Step 1: Sort the array
    sort(arr, arr + n);

    // Step 2: Fix the first element one by one and try to find the other two elements
    for (int i = 0; i < n - 2; i++) {  // First pointer can move up to n-3
        for (int j = i + 1; j < n - 1; j++) {  // Second pointer can move up to n-2
            int sum = arr[i] + arr[j];  // Sum of the first two elements

            // Step 3: Calculate what the third element should be
            int target = x - sum;  // We need this target as the third number

            // Step 4: Use binary search to find the third number
            if (binarySearch(arr, j + 1, n - 1, target)) {  
                // If we find the third number, return 1 (triplet found)
                return 1;
            }
        }
    }

    // Step 5: If no triplet is found after all the checks, return 0
    return 0;
}

int main() {
    int arr1[] = {1, 4, 45, 6, 10, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 13;
    cout << "Example 1: " << findTriplet(arr1, n1, x1) << endl;  // Output: 1 (Triplet found)

    int arr2[] = {1, 2, 4, 3, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int x2 = 10;
    cout << "Example 2: " << findTriplet(arr2, n2, x2) << endl;  // Output: 1 (Triplets found)

    int arr3[] = {40, 20, 10, 3, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int x3 = 24;
    cout << "Example 3: " << findTriplet(arr3, n3, x3) << endl;  // Output: 0 (No triplet found)

    return 0;
}


// There exists an even better approach. The idea is to convert this into a Two sum problem.
// First, sort the array.
// Intialaly we assume that the first number that we want, is our first element. Do target - first number, we get the sum of rest two numbers. Use Two pointer approach in array after first number to search for two numbers whose sum equals target - first number.
// If you don't find them, then our first number will now be second element. Do the same procedure. If you don't find them, then our first number will now be third element. Do the same procedure. If you don't find them, then first number becomes third element.

#include <bits/stdc++.h>
using namespace std;

int findTriplet(int arr[], int n, int x) {
    // Step 1: Sort the array to use two-pointer technique efficiently.
    sort(arr, arr + n);

    // Step 2: Iterate through the array, treating each element as the first number of the triplet.
    for (int i = 0; i < n - 2; i++) {
        int target = x - arr[i];  // The sum we need from the remaining two numbers.

        // Step 3: Use two-pointer approach to find two numbers whose sum is equal to target.
        int left = i + 1;  // Start the second pointer from the element just after the first element.
        int right = n - 1;  // Start the third pointer from the last element.

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {  // If the sum matches the target, we found a triplet.
                return 1;
            }
            else if (sum < target) {
                // If sum is less than target, move the left pointer right to increase the sum.
                left++;
            }
            else {
                // If sum is greater than target, move the right pointer left to decrease the sum.
                right--;
            }
        }
    }

    // Step 4: If no triplet is found, return 0.
    return 0;
}

int main() {
    int arr1[] = {1, 4, 45, 6, 10, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 13;
    cout << "Example 1: " << findTriplet(arr1, n1, x1) << endl;  // Output: 1 (Triplet found)

    int arr2[] = {1, 2, 4, 3, 6, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int x2 = 10;
    cout << "Example 2: " << findTriplet(arr2, n2, x2) << endl;  // Output: 1 (Triplets found)

    int arr3[] = {40, 20, 10, 3, 6, 7};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int x3 = 24;
    cout << "Example 3: " << findTriplet(arr3, n3, x3) << endl;  // Output: 0 (No triplet found)

    return 0;
}
