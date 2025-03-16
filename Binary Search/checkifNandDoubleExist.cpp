// Problem Statement :- https://leetcode.com/problems/check-if-n-and-its-double-exist/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using a Set for Hashing
bool checkIfExistHashing(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> st; // Hash set to store elements of the array.

    // Traverse the array to check conditions.
    for (int i = 0; i < n; i++) {
        // Check if double or half (if even) of the current element exists in the set.
        if (st.find(arr[i] * 2) != st.end()) {
            return true; // Double of the current element exists.
        } else if (arr[i] % 2 == 0 && st.find(arr[i] / 2) != st.end()) {
            return true; // Half of the current element exists.
        }

        // Insert the current element into the set.
        st.insert(arr[i]);
    }

    return false; // No such elements found.
}

// Approach 2: Using Binary Search
int bSearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;

    // Perform binary search for the target.
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target) {
            return mid; // Target found.
        } else if (arr[mid] > target) {
            r = mid - 1; // Search in the left half.
        } else {
            l = mid + 1; // Search in the right half.
        }
    }

    return -1; // Target not found.
}

bool checkIfExistBinarySearch(vector<int>& arr) {
    int n = arr.size();

    // Sort the array to enable binary search.
    sort(begin(arr), end(arr));

    // Traverse each element and search for its double.
    for (int i = 0; i < n; i++) {
        int j = bSearch(arr, 2 * arr[i]);

        // Check if a valid double is found.
        if (j != -1 && j != i) {
            return true;
        }
    }

    return false; // No such elements found.
}

int main() {
    // Test case 1: Basic example
    vector<int> arr1 = {10, 5, 1, 2, 3};
    cout << "Result (Hashing): " << (checkIfExistHashing(arr1) ? "True" : "False") << endl;
    cout << "Result (Binary Search): " << (checkIfExistBinarySearch(arr1) ? "True" : "False") << endl;

    return 0;
}
