// Problem Statement :- https://leetcode.com/problems/longest-harmonious-subsequence/description/

// Let's say you have :- {1, 3, 2, 2, 5, 2, 3, 7}
// We start by taking 1, now we need to ensure that moving forward we either encounter 1 or 2 or 0.
// If we encounter any other number then 1 can't be part of the longest harmonious subsequence.
// So 3 can't be part of subsequence containing 1. Hence, we will select 2. If we select 2, it won't change the minimmum, it is still 1.
// So, we can only pick remaining 2's as still min = 1 and max = 2.

// At any point :- max = min + 1
// Hence, result can only have two numbers. One will be min other will be max.

// If we started subsequence with 3, then we could have taken 2, as 3 - 2 = 1 and min is now 2. And 3 becomes max.
// In this case :- {3, 2, 2, 2, 3} is the answer.

// A simple way to solve :-
// Once you select a number to start subsequence, then we will consider it as min. We find max by min + 1. Then the subsequence can only contain these two numbers, so we can simply find freq of both.

#include <bits/stdc++.h>
using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> mp;
    int result = 0;

    for (int &num : nums) {
        mp[num]++;
    }

    for (int &num: nums) {
        int minNum = num;
        int maxNum = num + 1;

        if (mp.count(maxNum)) {
            result = max(result, mp[minNum] + mp[maxNum]);
        }
    }

    return result;
}

int main() {

}