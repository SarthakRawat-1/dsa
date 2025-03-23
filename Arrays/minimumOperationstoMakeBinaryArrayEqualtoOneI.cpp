// Problem Statement :- https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    // Get the size of the array
    int n = nums.size();
    // Variable to store the minimum number of operations needed
    int minimumOps = 0;

    // Iterate through the array up to the third last element
    for (int i = 0; i < n - 2; i++) {
        // If the current element is 0, perform the operation
        if (nums[i] == 0) {
            // Flip the current element to 1
            nums[i] = 1;
            // Flip the next two elements (toggle 0 to 1 and 1 to 0)
            nums[i + 1] = 1 - nums[i + 1];
            nums[i + 2] = 1 - nums[i + 2];
            // Increment the operation count
            minimumOps++;
        }
    }

    // If the last two elements are still 0, return -1 as it's impossible to convert
    if (nums[n - 2] == 0 || nums[n - 1] == 0) {
        return -1;
    }

    // Return the minimum number of operations performed
    return minimumOps;
}

int main() {
    vector<int> nums = {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1};

    cout << minOperations(nums) << endl;

    return 0;
}