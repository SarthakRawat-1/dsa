#include <bits/stdc++.h>
using namespace std;

// Function to count the number of set bits in a given number n
// This function implements a straightforward approach to count the number of 1's in the binary 
// representation of the number n by checking each bit individually.
int countSetBitsInSingleNumber(int n) {
    int count = 0;  // Initialize a counter to keep track of the number of set bits
    
    // Loop until n becomes 0, meaning there are no more bits left to check.
    // The idea is to check each bit of the number from right to left (Least Significant Bit to Most Significant Bit).
    while (n > 0) {
        // Check if the least significant bit (LSB) is set (i.e., if n & 1 is 1).
        // `n & 1` checks the rightmost bit by performing a bitwise AND operation between n and 1:
        // - If the result is 1, it means the current bit is set (i.e., it is 1).
        // - If the result is 0, it means the current bit is not set (i.e., it is 0).
        if (n & 1) {
            count++;  // If the current bit is set, increment the count of set bits.
        }
        
        // Right shift n by 1 bit (`n >>= 1`) to move to the next bit.
        // This operation effectively divides n by 2 (in binary), discarding the rightmost bit
        // and shifting all remaining bits one position to the right.
        n >>= 1;
    }
    
    // Return the total count of set bits found during the loop.
    return count;
}

int main() {
    int n = 17;  

    cout << "Total set bits in " << n << " is: " << countSetBitsInSingleNumber(n) << endl;

    return 0;
}

