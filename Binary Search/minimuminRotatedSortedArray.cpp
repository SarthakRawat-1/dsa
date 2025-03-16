// Problem Statement :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// Brute Force Approach :- We will traverse the array and find the minimum element in it. Linear Search basically.

// Optimized Approach :- Using Binary Search.
// Consider :- {4, 6, 8, 10, 1, 2} here we can divide our array in two parts {4, 6, 8, 10} and {1, 2} and both become sorted arrays so we can use binary search here.
// Now, if we pick any element, we can say that it is sorted from one side atleast. For eg :- if we pick 4 or 6 or 8 or 10, it is sorted from left side (can't be from right side as 1 and 2 are shorter than them) and if we pick 1 or 2, it is sorted from right side (can't be from left side as all 10 is greater than them).
// We can find whether elements are sorted from right side or left side by comparing it with the first element, in our case 4. If the element (this we will mark using mid) is greater than first element, then it is sorted from left side. In this case search in right space. If the element is less than first element, then it is sorted from right side. In this case, search in left space (because as it is sorted from right side, the elements after it will obviously be greater than it). Update answer value with the value (just in case, we are not able to find a better answer) and eliminate the right space.
// Once we know from which side elements are sorted, we can find elements (or part of array) shorter than it, and once we know that, we can just find the starting position of that part as it'll obviously be the minimum element.

// If array was not rotated, then it means it is still sorted in ascending order. In this case, our algorithm will not be able to update the answer varaible as first element is shorter than every other element. So to get around this, intialize the answer variable with first element.

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum element in a rotated sorted array
int findMin(vector<int>& nums) {
    // Initialize the starting and ending indices of the search space
    int start = 0, end = nums.size() - 1;

    // Initialize the answer variable with the first element of the array
    // This is necessary in case the array is not rotated and is already sorted.
    int ans = nums[0];

    // Perform binary search while the search space is valid
    while (start <= end) {
        // Calculate the mid-point index of the current search space
        int mid = start + (end - start) / 2;

        // If the middle element is greater than or equal to the first element,
        // it means that the left side of the array (including the mid) is sorted.
        // Hence, the minimum element must be on the right side.
        if (nums[mid] >= nums[0]) {
            start = mid + 1;  // Move the start pointer to search in the right half
        } 
        // If the middle element is less than the first element,
        // it means the right side of the array (including mid) is sorted,
        // and the minimum element lies to the left of the current mid.
        else {
            // Update the answer with the current mid element
            ans = nums[mid];  // Mid could be the minimum, so store it as a potential answer

            // Move the end pointer to search in the left half
            end = mid - 1;
        }
    }

    // Return the minimum element found
    return ans;
}

int main() {
    vector <int> A = {4, 6, 8, 10, 1, 2};

    int min = findMin(A);

    cout << "Minimum element in rotated array is :- " << min << endl;
}