// Problem Statement :- https://leetcode.com/problems/find-peak-element/description/

// Brute Force :- Checks each element in the array to see if it satisfies the peak condition. 
// Edge Cases :- Single Element Array (n == 1): The single element is a peak by default. First Element (i == 0): Since there is no element before it, only check if arr[0] > arr[1]. Last Element (i == n-1): Since there is no element after it, only check if arr[n-1] > arr[n-2].
// General Condition :- For other elements, the peak condition is arr[i-1] < arr[i] > arr[i+1]
// The final condition for identifying a peak is :- If ((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])), then arr[i] is a peak, and the index i is returned.

// Optimal Approach :- Let's consider the case when array has only one peak element. In this case, we can divide the array about peak into two parts. The part where the elements will be increasing (intially) and where it will be decreasing (after peak).
// We can have 3 cases :- peak is mid, peak is to the right or left of mid. The first thing we check is if the element at mid is the peak element itself. If mid was not peak and it is bigger than element just before it, then it's on the increasing side. Hence, peak should lie to the right of that. So eliminate the left search space.
// If mid was not peak element and it is greater than element just after it (or smaller than the element just before it), then it's on the decreasing side. Hence, peak should lie on the left of that. So eliminate the right search space.
// This code will work even if arrays contains more than one peak because if there are multiple peaks in the array, the algorithm will return one of them because it continues to explore the region where a peak must exist. It doesn't matter if there are more peaks because the binary search only focuses on one part of the array at a time.
// The search space is halved on each iteration, and as long as the conditions (arr[mid - 1] < arr[mid] > arr[mid + 1]) hold, a peak is always guaranteed to be found in either the left or right subarray.

// Edge Case 1 :- If an array has only one element, return it's index i.e. 0
// Edge Case 2 :- If the first element is greater than the second element, return 0 as it is the peak element.
// Edge Case 3 :- If the last element is greater than the second-to-last element, return n-1 as it is the peak element.


#include <bits/stdc++.h>
using namespace std;

// Function to find a peak element in the array
int findPeakElement(vector<int> &arr) {
    int n = arr.size(); // Get the size of the array

    // Edge case: If the array has only one element, return its index (0)
    if (n == 1) return 0;

    // Check if the first element is greater than the second element
    // If true, return index 0 as it is a peak
    if (arr[0] > arr[1]) return 0;

    // Check if the last element is greater than the second-to-last element
    // If true, return index n-1 as it is a peak
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    // Initialize the search range, excluding the first and last elements
    int low = 1, high = n - 2; 

    // Perform binary search within the range [low, high]
    while (low <= high) {
        // Calculate the middle index
        int mid = (low + high) / 2;

        // Check if the middle element is a peak
        // A peak element is greater than its neighbors
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid; // Return the index of the peak element

        // If the middle element is greater than its left neighbor,
        // it indicates that there is a potential peak on the right side
        if (arr[mid] > arr[mid - 1]) 
            low = mid + 1; // Move the low pointer to search in the right half

        // If the middle element is less than or equal to its left neighbor,
        // it indicates a potential peak on the left side (or at mid)
        else 
            high = mid - 1; // Move the high pointer to search in the left half
    }
    
    // Dummy return statement; this point should never be reached as 
    // a peak element is guaranteed to exist.
    return -1; 
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

// The same method/code can also solve the Problem Statement :- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
