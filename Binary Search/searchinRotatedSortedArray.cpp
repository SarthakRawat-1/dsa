// Problem Statement :- https://leetcode.com/problems/search-in-rotated-sorted-array/description/ and https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

// Brute Force :- Linear Search

// Optimal Approach :- Binary Search
// Check if element at mid is the target element or not. If it's not, how do we know which space to eliminate?
// We know that every element in array will be sorted from atleast one side (refer minimuminRotatedSortedArray.cpp). With this, we can find the sorted portion and compare first element and element at mid. 
// Let's consider intiallly, the element at mid was sorted from left side. Now if our target is not in range of [first element, mid element], then obv we have to eliminate the left space.
// Similarly, if an element is sorted from right side, we have to check if it lies between the range [mid element, last element]. If not, eliminate the right space.

#include <bits/stdc++.h>
using namespace std;

// Function to search for the target in a rotated sorted array
int search(vector<int> &arr, int target) {

    int start = 0, end = arr.size() - 1;
    int mid;

    // Binary search to find the target
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate the middle index to avoid overflow

        // Case 1: Target found at mid
        if (arr[mid] == target) {
            return mid; // Return the index of the target
        }

        // Case 2: Left side of the array is sorted
        else if (arr[mid] >= arr[start]) {
            // Check if the target lies in the left sorted portion
            if (arr[start] <= target && arr[mid] > target) {
                end = mid - 1; // Eliminate the right half
            } else {
                start = mid + 1; // Eliminate the left half
            }
        }

        // Case 3: Right side of the array is sorted
        else {
            // Check if the target lies in the right sorted portion
            if (arr[mid] < target && arr[end] >= target) {
                start = mid + 1; // Eliminate the left half
            } else {
                end = mid - 1; // Eliminate the right half
            }
        }
    }

    // If target is not found, return -1
    return -1;
}

int main() {
    vector <int> nums = {4, 5, 6, 7, 0, 1, 2};

    int target = 0;
    int ans = search(nums, target);
    cout << "Element found at index: " << ans << endl;

}


// For the II part, we have to make some modifications, as now array can also have duplicates.
// The previous approach will not work, when arr[start] = arr[mid] = arr[end]
// When arr[low] == arr[mid] == arr[high], you lose the ability to decide which half of the array is sorted. Because of this, binary search cannot progress effectively :- You can’t determine if the left half (arr[low] to arr[mid]) is sorted, nor can you tell if the right half (arr[mid] to arr[high]) is sorted, since all three values are the same.
// Skipping arr[low] and arr[high] reduces ambiguity by eliminating the confusion caused by duplicates, allowing binary search to proceed without getting stuck. While arr[low] or arr[high] might still be the target, they were already compared in previous iterations. By skipping them, the search space is narrowed without missing the target, and binary search can continue effectively once the ambiguity is resolved.
// In our previous algorithm, we add one more edge case :- when arr[start] = arr[mid] = arr[end] it means that neither arr[start] nor arr[end] can be the target. To handle this edge case, we simply remove arr[start] and arr[end] from our search space, without affecting the original algorithm. 

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return true;
        }

        // Handling duplicates
        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
            start++;
            end--;
        } 
        // Check if left side is sorted
        else if (arr[start] <= arr[mid]) {
            // Target is in the left sorted part
            if (arr[start] <= target && target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } 
        // Right side is sorted
        else {
            // Target is in the right sorted part
            if (arr[mid] < target && target <= arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    
    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    
    bool result = search(nums, target);
    cout << (result ? "Target found" : "Target not found") << endl;

    return 0;
}
