// Problem Statemnt :- https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

// This is basically a special case of Max Consecutive Ones III where k = 1 and because we have to delete an element, so we got to return final ans - 1.

#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int l = 0, r = 0, numZeroes = 0, maxLen = 0;

    while (r < nums.size()) {
        if (nums[r] == 0) {
            numZeroes++;
        } 

        while(numZeroes > 1) {
            if (nums[l] == 0) {
                numZeroes--;
            }
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen - 1;
}

int main() {

}