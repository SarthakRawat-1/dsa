// The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
// The lower bound of an array refers to the first position (or index) in a sorted array where a specified value (or key) could be inserted without violating the order of the array.

// If the value exists in the array :- The lower bound is the index of the first occurrence of that value.
// If the value does not exist :- The lower bound is the index where that value could be inserted to maintain the sorted order. 

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Initialize ans to n, assuming no valid lower bound found.

    // Binary search loop to find the lower bound
    while (low <= high) {
        int mid = (low + high) / 2;  // Calculate the middle index

        // Check if the element at mid is greater than or equal to x
        if (arr[mid] >= x) {
            ans = mid;  // Potential answer found at mid
            high = mid - 1;  // Continue searching in the left half to find the first occurrence
        }
        else {
            low = mid + 1;  // If arr[mid] is less than x, search in the right half
        }
    }
    // Return the index of the first element that is not less than x.
    // If no such element exists, ans will remain n (which is beyond the array size).
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}

// The problem statement :- https://leetcode.com/problems/search-insert-position/description/ can be solved by finding Lower Bound.