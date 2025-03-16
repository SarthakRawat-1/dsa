// Problem Statement :- https://leetcode.com/problems/maximum-subarray-with-equal-products/description/

// Check the condition for every subarray and return the length of longest subarray.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate GCD using Euclid's Algorithm
// GCD(a, b) is the largest number that divides both a and b without leaving a remainder.
int gcd(int a, int b) {
    if (b == 0) return a; // Base case: GCD(a, 0) is a
    return gcd(b, a % b); // Recursive call with remainder
}

// Function to calculate LCM using the relation: LCM(a, b) * GCD(a, b) = a * b
int lcm(int a, int b) {
    // Multiplying and typecasting to long long to avoid integer overflow.
    return 1LL * (a * b) / gcd(a, b);
}

// Function to find the length of the longest subarray satisfying the given condition
int maxLength(vector<int>& nums) {
    int n = nums.size(); // Get the size of the input array
    int ans = 2;         // Minimum length of subarray satisfying condition is 2

    // Iterate through all possible starting points of subarrays
    for (int i = 0; i < n; i++) {
        // Initialize product, GCD, and LCM with the first element of subarray
        long long prod = nums[i], g = nums[i], l = nums[i];

        // Extend the subarray from index i to j
        for (int j = i + 1; j < n; j++) {
            // Update product, GCD, and LCM as we add elements
            prod *= nums[j];                 // Update product by multiplying current element
            g = gcd(g, nums[j]);             // Compute GCD with current element
            l = lcm(l, nums[j]);             // Compute LCM with current element
            
            // Check if product is equal to GCD * LCM
            if (prod != g * l) break;        // If condition fails, exit the inner loop

            // Update the answer with the length of the current subarray
            ans = max(ans, j - i + 1);
        }
    }

    return ans; // Return the maximum length of subarray satisfying the condition
}

int main() {
    vector<int> nums = {1, 2, 1, 1, 1}; // Input array

    cout << maxLength(nums) << endl;   // Output the result
    return 0;
}
