// Problem Statement :- https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

// Approach 1 :- Use a pointer to traverse the array. When it comes to 0 element, keep track till when a 0 is coming, so that we can find the length of this subarray. Then for all these subarrays use the formula :- n * (n + 1) / 2 to find number of subarrays (where n is the length of array).
// For eg :- {1, 3, 0, 0, 2, 0, 0, 4} here we have two subarrays of 0 :- {0, 0} and {0, 0} but even among these, there can be multiple as {0, 0} itself will have 2 more subarrays namely, {0} and {0}. So we use n * (n + 1) / 2 formula to find all the subarrays. For n = 2, it will give us 3 and since there are 2 such subarrays, we will have 2 x 3 = 6 as the answer.

// Approach 2 :- If we only have {0} then ans is 1, if we have {0, 0} then answer is 3 (which is prev ans (1) + number of zeros (2)) and if we have {0, 0, 0} then the answer becomes 6 (prev ans (3) + number of zeros (3)).
// Hence, instead of using formula, we will use this approach to find number of answers for a contiguous subarrays of 0.

#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    // // Approach 1

    // // Initialize result variable to store the total number of zero-filled subarrays
    // long long result = 0;
    
    // // Get the size of the input array
    // int n = nums.size();
    
    // // Pointer to traverse the array
    // int i = 0;

    // // Traverse the entire array
    // while (i < n) {
    //     // Initialize a counter to track the length of a continuous segment of 0s
    //     long long l = 0;

    //     // Check if the current element is 0
    //     if (nums[i] == 0) {
    //         // Continue to move the pointer and count the length while 0s are found
    //         while (i < n && nums[i] == 0) {
    //             l++;    // Increment length counter for each 0 found
    //             i++;    // Move to the next element
    //         }
    //     } else {
    //         // Move the pointer to the next element if it's not 0
    //         i++;
    //     }

    //     // Add the count of zero-filled subarrays for this segment of 0s
    //     // Formula: n * (n + 1) / 2 where 'l' is the length of consecutive 0s
    //     result += l * (l + 1) / 2;
    // }

    // // Return the total count of zero-filled subarrays
    // return result;


    // Approach 2 

    // Initialize result to store the total number of zero-filled subarrays
    long long result = 0;

    // Get the size of the input array
    int n = nums.size();

    // Initialize count to keep track of consecutive 0s
    int count = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the current element is 0, increase the count
        if (nums[i] == 0) {
            count++;
        } else {
            // Reset count to 0 if the current element is not 0
            count = 0;
        }

        // Add the count to the result
        // Each time we find a zero, count represents the number of subarrays ending at this 0
        result += count;
    }

    // Return the total count of zero-filled subarrays
    return result;
}

int main() {
    vector<int> nums = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    cout << zeroFilledSubarray(nums) << endl;
    return 0;
}