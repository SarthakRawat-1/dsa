// Problem Statement :- https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

// Brute Force :- Linear Search with a counter.

// Optimal Approach :- We will find the first and last position of the number like we did in firstandLastPositionofElementSortedArray.cpp. Then we will use the formula (last - first + 1) to find the number of occurences.

#include <bits/stdc++.h>
using namespace std;

// Function to search for the first and last occurrence of the target in a sorted array and return the number of occurences of the target element.
int numberofOccurences(vector<int> &nums, int target) {
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

    // Return the number of occurences of the number
    return last - first + 1;
}

int main() {
    vector <int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int ans = numberofOccurences(nums, target);
    cout << "Number of occurences of the element :- " << ans << "\n";
    return 0;
}