// Problem Statement :- https://leetcode.com/problems/single-number-iii/description/

// If you XOR all elements of the array, in the end we will be left with XOR of the two numbers which appear only once because all other elements that appear twice will cancel out (i.e., result in 0).
// We will try to separate all the array elements in two different groups such that the elements that appear only once are in different groups. Then we if take XOR of all elements in a group, only the elements that appear once will be left, rest all will cancel as they appear twice.
// But how will we ensure that both elements that appear once are in different groups? We can say, that all numbers whose kth bit is set, will be in group A, rest will be in group B. We will choose kth bit such that it is different for the elements that appear only once.
// We can find the bit which is different using pointer at the LSB of both numbers. Check if they are different. If they are not different, then Right shift both by 1, then check again. The number of right shifts we need till LSB becomes different is the bit that was different in the numbers (if we needed 0 right shifts, then zeroth bit was different, if we needed 2 however, second bit was different).
// With this knowledge of which bit is different, we can create a mask where that bit is set, to separate all the numbers into two groups.
// But here, comes another problem, how do we know which numbers to right shift to find the different bit? We have the XOR of the two numbers which appear only once by XOR of all elements. So, we will create our mask using this XOR. 
// We know that XOR results in 1 when the bits are different and 0 if the bits are same. So in the XOR of both, just check the position of the rightmost set bit. This will tell us where 1 should be in our mask.
// Another way to make mask is :- (XOR of those two numbers which appear only once) & (2's complement of (XOR of those two numbers which appear only once)) which will give us the mask. We can just do -(XOR of those two numbers which appear only once) to find (2's complement of (XOR of those two numbers which appear only once)).
// This is because it gives us a number where the rightmost set bit common to both numbers, is the only one set in result, and rest all becomes zero.

#include <bits/stdc++.h>    
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    long long xor_r = 0; // To hold hold the XOR of all numbers in the array.

    // Step 2: XOR all the numbers in the array.
    for (int &num : nums) {
        xor_r ^= num;
    }

    // Step 3: Find the rightmost set bit in the XOR result (xor_r).
    // We use the expression xor_r & (-xor_r) to isolate the rightmost set bit.
    // (The 2's complement of xor_r is -xor_r, which flips all the bits after the rightmost set bit).
    int mask = (xor_r) & (-xor_r);

    // Step 4: Initialize two variables, groupA and groupB, to 0.
    // These will store the XOR of numbers in two different groups.
    int groupA = 0, groupB = 0;

    // Step 5: Partition the numbers into two groups based on the rightmost set bit.
    // If the number has the rightmost set bit (as determined by `mask`), it belongs to groupA; otherwise, it belongs to groupB.
    for (int &num : nums) {
        if (num & mask) {
            groupA ^= num;
        } else {
            groupB ^= num;
        }
    }

    // Step 6: At the end of the loop, groupA will contain one unique number, and groupB will contain the other unique number.
    return {groupA, groupB};
}

int main() {
    vector <int> nums = {5, 5, 4, 4, 99, 99, 2, 3};

    vector <int> result = singleNumber(nums);

    cout << "The two numbers which appear only once are :- " << result[0] << " and " << result[1] << endl;
    
}