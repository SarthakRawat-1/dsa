// Problem Statement :- https://leetcode.com/problems/assign-cookies/description/

// We will first sort both greed and size array. In this way, we will ensure that we will use the smallest cookie possible to satisfy greed factor of a particular child.

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sort the greed factor array and the cookie size array in ascending order.
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // Initialize result to count the number of content children.
    int res = 0;

    // Two pointers: i for greed factor array and j for cookie size array.
    int i = 0, j = 0;

    // Iterate through both arrays while there are children and cookies to evaluate.
    while (i < g.size() && j < s.size()) {
        // If the current cookie can satisfy the greed of the current child.
        if (g[i] <= s[j]) {
            res++;      // Increment the count of content children.
            i++;        // Move to the next child.
            j++;        // Move to the next cookie.
        } else {
            // If the cookie cannot satisfy the current child, try the next larger cookie.
            j++;
        }
    }

    // Return the total number of content children.
    return res; // You can return i also instead of using an extra variable res
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << findContentChildren(g, s) << endl;
    return 0;
}