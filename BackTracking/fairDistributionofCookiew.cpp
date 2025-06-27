// Problem Statement :- https://leetcode.com/problems/fair-distribution-of-cookies/

#include <bits/stdc++.h>
using namespace std;

// Global variable to store the minimum unfairness found.
// We initialize it with INT_MAX since we are looking for the minimum possible "max cookies" distribution.
int result = INT_MAX;

// Global variable to store the total number of cookies.
// It is used in the recursive function to determine when we have distributed all cookies.
int n;

// Recursive helper function: "solve"
// This function tries every possible way to distribute cookies to children recursively.
// Parameters:
//   - idx: Current index in the cookies vector that we are trying to assign.
//   - cookies: The vector that holds the number of cookies in each pack.
//   - children: A vector that holds the current total cookies given to each child.
//   - k: The total number of children.
void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
    // Base Case: if all cookies have been distributed
    if (idx >= n) {
        // Determine the maximum cookies any child has (i.e., the "unfairness" of this distribution)
        int unfairness = *max_element(children.begin(), children.end());
        // Update the global result with the minimum unfairness found so far
        result = min(result, unfairness);
        return;
    }

    // Get the number of cookies in the current pack at index 'idx'
    int cookie = cookies[idx];

    // Iterate over each child to try to assign the current cookie pack to that child
    for (int i = 0; i < k; i++) {
        // Add the current pack's cookies to the i-th child's total
        children[i] += cookie;
        // Recursively try distributing the rest of the cookie packs
        solve(idx + 1, cookies, children, k);
        // Backtrack: Remove the current pack's cookies from the i-th child's total
        // This step is crucial to try the next possibility of distribution correctly.
        children[i] -= cookie;
    }
}

// Function to compute the minimum unfairness in distributing cookies among k children.
// It initializes the child cookies vector and starts the recursive backtracking process.
int distributeCookies(vector<int>& cookies, int k) {
    // Set the global variable 'n' to represent the total number of cookie packs.
    n = cookies.size();

    // Initialize the 'children' vector with k elements, all set to 0 initially,
    // meaning each child starts with no cookies.
    vector<int> children(k, 0);

    // Start the recursion with the first cookie pack (index 0).
    solve(0, cookies, children, k);

    // Return the minimum unfairness computed.
    return result;
}

// Main function (entry point). This function can be further expanded to test the functionality.
// It is currently empty as the focus is on the algorithm and detailed commentary.
int main() {
    // Example test: Uncomment the following lines to run a test.
    vector<int> cookies = {8, 15, 10, 20, 8};
    int k = 2;
    cout << "Minimum Unfairness: " << distributeCookies(cookies, k) << endl;
    return 0;
}
