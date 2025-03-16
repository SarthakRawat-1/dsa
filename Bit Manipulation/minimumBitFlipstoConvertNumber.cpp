// Problem Statement :- https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// The Problem statement is equivalent to counting the number of positions at which the two numbers have different bits.
// XOR between two bits is 1 if the bits are different and 0 if they are the same. Thus, performing an XOR between start and goal will give a number where each 1 bit represents a position where start and goal have different bits.
// Once we have the XOR result, we simply count the number of 1s in the binary representation of the XOR result. Each 1 represents a bit that needs to be flipped to convert start to goal.

#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    // Step 1: XOR start and goal to find differing bits
    int xor_result = start ^ goal;

    // Step 2: Count the number of 1s in the XOR result
    int bit_flips = 0;
    while (xor_result > 0) {
        // Increment the flip count if the least significant bit is 1
        bit_flips += xor_result & 1;
        // Right shift xor_result to check the next bit
        xor_result >>= 1;
    }

    return bit_flips;
}

int main() {
    int start1 = 10, goal1 = 7;
    cout << "Minimum bit flips (10 to 7): " << minBitFlips(start1, goal1) << endl;  // Output: 3

    int start2 = 3, goal2 = 4;
    cout << "Minimum bit flips (3 to 4): " << minBitFlips(start2, goal2) << endl;  // Output: 3

    return 0;
}
