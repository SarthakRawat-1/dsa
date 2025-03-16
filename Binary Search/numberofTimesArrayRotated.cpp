// Problem Statement :- https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

// In a sorted array, the smallest element is always at index 0. When the array is rotated, the smallest element "rotates" along with the array. The index of the smallest element in the rotated array tells you how many positions the array has been shifted to the right.

// Brute Force Approach :- Just find the index of minimum element using Linear Search.

// Optimized Approach :- Refer minimuminRotatedSortedArray.cpp In that we only found the minimum element, but did not keep track of it's index. Here, we will also keep track of the index with help of an additional variable.

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum element in a rotated sorted array along with its index
pair<int, int> findMin(vector<int>& nums) {
    // Initialize the starting and ending indices of the search space
    int start = 0, end = nums.size() - 1;

    // Initialize the answer variable and its index with the first element of the array
    // This is necessary in case the array is not rotated and is already sorted.
    int ans = nums[0];
    int minIndex = 0;

    // Perform binary search while the search space is valid
    while (start <= end) {
        // If the array is already sorted, return the first element and index 0
        if (nums[start] <= nums[end]) {
            return {nums[start], start};  // The minimum element is at the start index
        }

        // Calculate the mid-point index of the current search space
        int mid = start + (end - start) / 2;

        // If the middle element is greater than or equal to the first element,
        // it means that the left side of the array (including the mid) is sorted.
        // Hence, the minimum element must be on the right side.
        if (nums[mid] >= nums[start]) {
            start = mid + 1;  // Move the start pointer to search in the right half
        } 
        // If the middle element is less than the first element,
        // it means the right side of the array (including mid) is sorted,
        // and the minimum element lies to the left of the current mid.
        else {
            // Update the answer and the index with the current mid element
            ans = nums[mid];  // Mid could be the minimum, so store it as a potential answer
            minIndex = mid;   // Update the index of the minimum element

            // Move the end pointer to search in the left half
            end = mid - 1;
        }
    }

    // Return the minimum element and its index
    return {ans, minIndex};
}

int main() {
    vector<int> A = {4, 6, 8, 10, 1, 2};

    pair<int, int> result = findMin(A);

    cout << "Minimum element in rotated array is: " << result.first << endl;
    cout << "Index of the minimum element is: " << result.second << endl;

    cout << "Number of rotations: " << result.second << endl;
}



