// Problem Statement :- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

// Brute Force :- Check all possible divisors from 1 to max(arr[]). The minimum number for which the result <= threshold value, will be our answer.

// Optimal Approach :- We know that the answer lies between 1 and max(arr[]), and this array is in sorted order, so we can use binary search on this.
// Now we know, that if for any number, say x, result <= threshold is possible, then for numbers greater than x also it will be possible, but for numbers less than it, it may or may not be possible. So we have to search in left space and not right space as we need to find the smallest divisor.
// Similarly, if it's not possible for a number, then it won't be possible for numbers lower than that, hence in this case, we need to eliminate the left space.

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // for accumulate
#include <cmath>   // for ceil
using namespace std;

// Function to compute the sum of division results for a given divisor
int computeSumWithDivisor(const vector<int>& nums, int divisor) {
    int sum = 0;
    
    // Iterate through each number in the array
    for (int num : nums) {
        // Efficient ceiling calculation:
        // (num + divisor - 1) / divisor is an integer-based method to calculate the ceiling of (num / divisor)
        // This avoids the use of floating-point arithmetic and the ceil() function, making it more efficient.
        // Example:
        // If num = 5, divisor = 2:
        // (5 + 2 - 1) / 2 = (6) / 2 = 3 (which is the ceiling of 5 / 2 = 2.5)
        // This method works by adjusting the numerator, adding (divisor - 1) ensures that any remainder 
        // from dividing `num` by `divisor` will result in an increment in the result, effectively achieving ceiling.
        sum += (num + divisor - 1) / divisor;
    }
    
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    // Binary search setup:
    // low is set to 1 because 1 is the smallest possible divisor.
    int low = 1;
    
    // high is set to the maximum element in the array since dividing by the maximum element yields the smallest sum.
    int high = *max_element(nums.begin(), nums.end());
    
    // Initially, set the result to high (the largest possible divisor), as a placeholder.
    int result = high;

    // Binary search to find the smallest divisor
    while (low <= high) {
        // Calculate the middle divisor (mid) using the binary search technique
        int mid = low + (high - low) / 2;

        // Calculate the sum of division results using the current mid as the divisor
        int sum = computeSumWithDivisor(nums, mid);

        // Check if the sum is less than or equal to the threshold
        if (sum <= threshold) {
            // If the sum is within the threshold, mid is a valid divisor
            result = mid;  // Update result to mid because it's a valid candidate for the smallest divisor
            high = mid - 1;  // Try to find a smaller divisor by adjusting the upper bound
        } else {
            // If the sum exceeds the threshold, we need to increase the divisor to reduce the sum
            low = mid + 1;  // Adjust the lower bound to search for a larger divisor
        }
    }

    return result;  // Return the smallest valid divisor
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};  // Example array
    int limit = 8;  // Threshold value
    int ans = smallestDivisor(arr, limit);  // Find the smallest divisor
    cout << "The minimum divisor is: " << ans << "\n";  // Output the result
    return 0;
}
