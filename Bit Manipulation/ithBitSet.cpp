// Problem Statement :- https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

// Brute Force :- Start traversing from the back of the binary number and check if the bit is set or not. But this requires converting int to binary.

// Optimal Approach :- We can do this using Left/Right Shift operators.

#include <iostream>
using namespace std;

// Function to check if the kth bit of number n is set
bool isKthBitSet(int n, int k) {
    // Left shift '1' by k bits to create a mask with the kth bit set
    // The mask will have the value 2^k, which in binary has only the kth bit as 1
    int mask = 1 << k;  // For eg if k = 2, then mask = 100, now we can AND operator and every other bit will become 0. The kth bit will remain 1 if it was set.

    // Perform bitwise AND between the number n and the mask
    // If the kth bit of n is set, the result will be non-zero (same as the mask value)
    // If the kth bit is not set, the result will be 0
    if (n & mask) {
        return true;  // kth bit is set
    } else {
        return false; // kth bit is not set
    }
}

int main() {
    int n = 4;  // Number
    int k = 2;  // Bit position to check

    if (isKthBitSet(n, k)) {
        cout << "Yes" << endl;  // kth bit is set
    } else {
        cout << "No" << endl;   // kth bit is not set
    }

    return 0;
}


// If you want to do it using right shift operator. The idea will be to shift the kth bit in the original bit to the extreme right. In this way, the kth bit has become the least significant bit, now you can just check if it is 1 or not.

// #include <iostream>
// using namespace std;

// // Function to check if the kth bit of number n is set using right shift operator
// bool isKthBitSet(int n, int k) {
//     // Right shift the number n by k positions
//     // After shifting, the kth bit will move to the least significant bit (LSB) position
//     // We then check if the LSB is set (1) or not (0) by using bitwise AND with 1
//     if ((n >> k) & 1) {
//         return true;  // kth bit is set
//     } else {
//         return false; // kth bit is not set
//     }
// }

// int main() {
//     int n = 4;  
//     int k = 2;  

//     if (isKthBitSet(n, k)) {
//         cout << "Yes" << endl;  
//     } else {
//         cout << "No" << endl;   
//     }

//     return 0;
// }


// If you want to set the kth bit instead of just checking it, we can use the same approach as we used in Left shift method, but use OR method instead of AND.
// If you want to clear the kth bit, we can use Left shift, AND and NOT operator. 