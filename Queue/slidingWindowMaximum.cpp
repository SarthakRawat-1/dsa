// Problem Statement :- https://leetcode.com/problems/sliding-window-maximum/description/

// Say you have :- {5, 3, 2, 1, 0, 10} and k = 5, first window aka {5, 3, 2, 1, 0} has 5 as max element and when we shift window by 1 {3, 2, 1, 0, 10} we get 10 as max.
// Now as we keep shifting, we realize that in next window say {2, 1, 0, 10, x}, there is no way that 2, or 1 or 0 will be ans for this window as10 is already there. So ans can only be either 10 or the new element.
// Now if u move once more {1, 0, 10, x, y}, ans can be 10 or x or y. So we use this concept of not keeping the smaller elements in queue as they don't have any chance.
// Eg :- {1, 3, -1, -3, 5, 3, 6, 7} and k = 3, say we start with i = 0, we got 1, we take 1 in window.
// Moving to next, we got 3, our window is {1, 3} but we know that whatever window we come further across, 1 can't be answer for that, so we kinda cross that as an option.
// Next we got -1 which is smaller but as it's on right, so we have to keep it. Now k = 3 and we have {1, 3, -1} where 1 is crossed.
// Max element is at the front aka 3. Max element is always at front. Now we move and we got window {3, -1, -3}, again 3 is max.
// Next we got {-1, -3, 5} becz we had to remove 3, how do we know how to remove that from queue? Simply add idx instead of elements.
// In {-1, -3, 5}, we have all 2 smaller than 5, so we cross them. Finally 5 is at front. So 5 is max. And ofc remove element -1 from start of window.

// The deque does not represent the whole window directly.
// It only stores indices of candidates that might be the max.
// So:
// The window itself always has size k (because that’s determined by i and i-k).
// The deque may have fewer than k elements because we deliberately throw away “useless” ones.
// That’s why popping does not shrink the window — it just removes elements that cannot possibly be the maximum.

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    // Deque will store indices of elements (not actual values).
    // It will maintain the property that elements inside are in decreasing order
    // based on their values in nums[].
    deque<int> deq;

    // Result array to store the maximum for each sliding window
    vector<int> result;

    // Iterate over all elements
    for (int i = 0; i < n; i++) {

        // 1. Remove indices from the front which are out of this window
        // Example: If window size is k=3 and current index is i=5,
        //          then valid window indices are [3,4,5]. 
        //          So if deq.front() <= i-k, that index is outside → pop it.
        while (!deq.empty() && deq.front() <= i - k) {
            deq.pop_front();
        }

        // 2. Maintain decreasing order in deque
        // If current element nums[i] is larger than nums[deq.back()],
        // then those smaller elements at the back will NEVER be max
        // in this or any future window → pop them.
        while (!deq.empty() && nums[i] > nums[deq.back()]) {
            deq.pop_back();
        }

        // 3. Push the current index at the back
        deq.push_back(i);

        // 4. Start recording max values once we have the first full window
        // (i >= k-1 means at least k elements have been processed).
        if (i >= k - 1) {
            // The front of deque always holds the index of the max element 
            // for the current window.
            result.push_back(nums[deq.front()]);
        }
    }    

    return result;
}

int main() {
    // Example test
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    // Print result: [3, 3, 5, 5, 6, 7]
    for (int x : ans) cout << x << " ";
}