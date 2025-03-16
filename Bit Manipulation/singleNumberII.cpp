// Problem Statement :- https://leetcode.com/problems/single-number-ii/description/

// Brute Force :- Just count the number of occurrences of each number in the array and return the number that occurs only once.
// Other Approach :- Sort the array. Now you can traverse the array and check which element is not equal to both the number before it and after it. That will be the number occuring only once.

// Optimal Approach :- Using Bit Manipulation. This is a generalised solution. It works even if other elements were appearing 2 times and one element was occuring 1 time.
// Before doing this, do refer ithBitSet.cpp
// First look at the zeroth bit of all numbers, and count the number of zeros and number of ones. Let's say initially only you got zeros six times and ones one time, then here only we can deduce that number whose zeroth bit is one, will be the number that appears once. Basically, if count of bit is not in a multiple of 3, then the unique number zeroth bit is also that.
// Similarly, looking at the first bit, count the number of zeros and number of ones. Whichever does not appear in multiple of 3, that bit should be the first bit of the number that appears only once.
// Continue doing this for all the bits (last will be 31st bit).
// Now that we know which bit is what for the number that appears only once, we can actually construct that number (result variable) using left shift operator and OR operator.  

#include <bits/stdc++.h>
using namespace std;    

int singleNumber(vector<int>& nums) {
    int result = 0;

    // Iterate over each of the 32 bit positions
    for (int k = 0; k <= 31; k++) {
        int temp = (1 << k);  // temp is a number with only the k-th bit set
        int countOnes = 0;

        // Count how many numbers have the k-th bit set
        for (int &num : nums) {
            if ((num & temp) != 0) {
                countOnes++;  // Increment count if k-th bit is set
            }
        }

        // If count of ones at this bit position is not a multiple of 3
        // it means the unique number has a 1 at this bit position
        if (countOnes % 3 == 1) {
            result = (result | temp);  // Set this bit in the result
        }
    }

    return result;
}


int main() {
    vector <int> nums = {0,1,0,1,0,1,99};
    cout << singleNumber(nums);
}