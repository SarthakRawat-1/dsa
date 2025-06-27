// Problem Statement :- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

// Maximize the min or Minimmize the max usually hints towards Bianry Search on Answer.

// Let's say we have nums = {2, 4, 8, 2} and maxOp = 4. Greedily, we will try to divide the max value i.e. into equal halves 4 and 4. If we do uneven, one half might become bigger.
// Then continously do this. Hence, everytime we are finding max value in array to divide. We can use max heap for this.
// This will fail for odd numbers, as :- consider 9, which splits as 6 and 3 to give the best result rather than 4 and 5 if there's one more operation left after this.
// Hence, greedy approach fails.

// Consider nums = {7, 17} and maxOps = 2, worst case result = 17, if no op applied. Best case, every bag has one ball so result = 1.
// Hence, try each of the possibilities between them which will use maxOps = 2 or less.
// We will use BS to search effectively instead of trying each of them.

// To write the possible function, we can use this logic :-
// Consider the {7, 17} problem with mid = 4. How many ops to split 17 to 4 or below? 17 splits to 4 and 13 then 13 splits to 4 and 9 and 9 splits to 4 and 5 and 5 splits to 4 and 1.
// Sot otal 4 operations which is 17/4 = 4. This is becz 17 is non divisible by 4. If we had 16, then it will take 3 oeprations i.e. 16/4 - 1

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int maxOps, int mid) {
    long long totalOps = 0;

    for(int &num : nums) {
        // If number is already <= mid, no operation is needed
        if (num <= mid) continue;

        // Count operations needed to make 'num' <= mid
        // Total splits needed = ceil(num / mid) - 1
        // Which is same as: (num - 1) / mid
        // But using the direct approach:
        int ops = num / mid;

        // If num divides evenly, reduce 1 unnecessary operation
        if(num % mid == 0) {
            ops -= 1;
        }

        totalOps += ops;
    }

    // Return true if we can do it within the allowed number of operations
    return totalOps <= maxOps;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int l = 1; // smallest possible max size per bag
    int r = *max_element(begin(nums), end(nums)); // largest number in nums as upper bound
    int result = r; // store the best (minimum possible maximum size)

    // Binary Search on answer space
    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(isPossible(nums, maxOperations, mid)) {
            // It's possible to make all numbers <= mid with allowed operations
            // So try to find even smaller max size
            result = mid;
            r = mid - 1;
        } else {
            // Not possible with current mid, try larger values
            l = mid + 1;
        }
    }

    return result;
}

int main() {
    // Example usage:
    vector<int> nums = {7, 17};
    int maxOperations = 2;
    cout << "Minimum possible max bag size: " << minimumSize(nums, maxOperations) << endl;
}