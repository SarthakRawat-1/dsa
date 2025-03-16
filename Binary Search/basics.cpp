#include <bits/stdc++.h>
using namespace std;

// Function to perform binary search on a sorted vector of integers. It returns the index of the target element if found, otherwise it returns -1. 
// Bianry Search only works for sorted vectors or arrays.
// It operates by dividing the search space in half at each step, significantly reducing the number of comparisons required compared to a linear search, which checks every element.
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); // Store the size of the vector.
    int low = 0, high = n - 1; // 'low' and 'high' represent the current bounds of the search space. Initially, they are the beginning and end of the evctor respectively.

     // Once low becomes greater than or equal to high, the search space becomes empty, hence we end our loop at taht time.
    while (low <= high) {
        // (low + high) / 2 can potentially cause overflow, but for simplicity here, we use it.
        // int mid = (low + high) / 2;

        // Safer way to calculate the mid-point without overflow.
        int mid = low + (high - low) / 2;

        // Check if the middle element is the target. If yes, return the index 'mid'.
        if (nums[mid] == target) return mid;

        // If the target is greater than the middle element, the target must be in the right half.
        // We narrow the search space by setting 'low' to mid + 1 (exclude the left half).
        else if (target > nums[mid]) low = mid + 1;

        // If the target is smaller than the middle element, the target must be in the left half.
        // We narrow the search space by setting 'high' to mid - 1 (exclude the right half).
        else high = mid - 1;
    }
    // If the target is not found after the loop, return -1 to indicate it's not present.
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}

// When low + high is calculated directly, there’s a potential risk of overflow if both low and high are large numbers.
// By using low + (high - low) / 2, we avoid adding two potentially large numbers directly. Instead, we first subtract low from high (which is safe because high is greater or equal to low), and then divide the difference by 2 before adding it to low.