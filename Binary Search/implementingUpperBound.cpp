// The upper bound is the smallest index, ind, where arr[ind] > x. But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array.
// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.



#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n; // Initialize ans to n, assuming no valid upper bound found.

    // Binary search loop to find the upper bound
    while (low <= high) {
        int mid = (low + high) / 2;  // Calculate the middle index

        // Check if the element at mid is greater than x
        if (arr[mid] > x) {
            ans = mid;  // Potential answer found at mid
            high = mid - 1;  // Continue searching in the left half to find the first occurrence greater than x
        }
        else {
            low = mid + 1;  // If arr[mid] is less than or equal to x, search in the right half
        }
    }
    // Return the index of the first element that is strictly greater than x.
    // If no such element exists, ans will remain n (which is beyond the array size).
    return ans;
}


int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = upperBound(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}

