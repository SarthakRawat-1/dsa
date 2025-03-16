// Problem Statement :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// Brute Force Appraoch is to use Linear Search twice, once from beginning and other from end of the array to search for first and last occurence of array.

// Optimised Approach :- We will use Binary Search for this. But this time, we will not return the index instantly once we find it. We will still try to find the same element in rest of the space for finding it's first and last occurence.

#include <bits/stdc++.h>
using namespace std;

// Function to search for the first and last occurrence of the target in a sorted array
vector<int> searchRange(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1; // Initialize pointers: start at the beginning, end at the last index
    int first = -1, last = -1; // Variables to store the first and last occurrence of the target
    int mid; // Variable to store the middle index

    // Find the first occurrence of the target using binary search
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate the middle index to prevent overflow

        if (nums[mid] == target) {
            first = mid; // If target is found, update 'first' with the current mid
            end = mid - 1; // Search in the left half to find the first occurrence
        } 
        else if (nums[mid] < target) {
            start = mid + 1; // If the middle element is less than the target, move the start pointer to the right
        } 
        else {
            end = mid - 1; // If the middle element is greater than the target, move the end pointer to the left
        }
    }

    // Reset pointers to find the last occurrence of the target
    start = 0, end = nums.size() - 1;

    // Find the last occurrence of the target using binary search
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate the middle index

        if (nums[mid] == target) {
            last = mid; // If target is found, update 'last' with the current mid
            start = mid + 1; // Search in the right half to find the last occurrence
        } 
        else if (nums[mid] < target) {
            start = mid + 1; // If the middle element is less than the target, move the start pointer to the right
        } 
        else {
            end = mid - 1; // If the middle element is greater than the target, move the end pointer to the left
        }
    }

    // Return a vector with the first and last occurrence
    vector<int> ans = {first, last};
    return ans;
}

int main() {
    vector <int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector <int> ans = searchRange(nums, target);
    cout << "First Occurence: " << ans[0] << "\nLast Occurence: " << ans[1] << "\n";
    return 0;
}