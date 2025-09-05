// Problem Statement :- https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    // If array has at least 2 elements (since problem guarantees n+1 elements with values 1…n)
    if (nums.size() > 1)
    {
        // Phase 1: Detect the cycle
        // Initialize two pointers:
        // slow moves one step at a time
        // fast moves two steps at a time
        int slow = nums[0];          // first step from index 0
        int fast = nums[nums[0]];    // two steps from index 0

        // Keep moving slow and fast until they meet inside the cycle
        while (slow != fast)
        {
            slow = nums[slow];           // slow moves one step
            fast = nums[nums[fast]];     // fast moves two steps
        }

        // Phase 2: Find the entry point of the cycle (duplicate number)
        // Reset one pointer to the "start" (index 0)
        fast = 0;

        // Move both one step at a time until they meet again
        // The point where they meet is the duplicate number
        while (fast != slow)
        {
            fast = nums[fast];   // move one step
            slow = nums[slow];   // move one step
        }

        // Return the duplicate number
        return slow;
    }

    // If input size is invalid (edge case), return -1
    return -1;
}

int main() {

}