// Problem Statement :- https://www.geeksforgeeks.org/problems/four-elements2452/1

// First, sort the array. For each element in the array, treat it as the first element of the combination of four. Apply a three sum technique (similar to the triplet problem but for three elements) on the remaining part of the array using two pointers. Check if the sum of four elements equals X. If it does, return true. Continue the search if the sum doesn't match, adjusting the two pointers as needed. If no such combination is found, return false.

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int N, int X) {
    // Step 1: Sort the array to apply two-pointer technique
    sort(A, A + N);

    // Step 2: Iterate through the array and fix the first element
    for (int i = 0; i < N - 3; i++) {
        // Step 3: Iterate for the second element
        for (int j = i + 1; j < N - 2; j++) {
            // Now, we need to find two numbers whose sum is X - (A[i] + A[j])
            int target = X - (A[i] + A[j]);

            // Step 4: Use two-pointer approach to find the remaining two numbers
            int left = j + 1;  // Second pointer
            int right = N - 1;  // Third pointer

            while (left < right) {
                int sum = A[left] + A[right];
                if (sum == target) {
                    // Found a valid combination of four numbers
                    return true;
                }
                else if (sum < target) {
                    // If sum is less than the target, move the left pointer to the right to increase the sum
                    left++;
                }
                else {
                    // If sum is greater than the target, move the right pointer to the left to decrease the sum
                    right--;
                }
            }
        }
    }

    // If no valid combination is found, return false
    return false;
}

int main() {
    int N = 6;
    int A[] = {1, 5, 1, 0, 6, 0};
    int X = 7;

    if (find4Numbers(A, N, X))
        cout << "1\n";  // Output: 1 (Combination found)
    else
        cout << "0\n";  // Output: 0 (No combination found)

    return 0;
}


// There's a better appraoch to solve this in just O(N^2) time complexity using hashing based approach. I am not writing this, for now...