// Problem Statement :- https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-xor-of-numbers-from-l-to-r

// Remember this property :-
// The XOR from 0 to n for any integer n follows a repeating pattern. Specifically :-
// 1. If n % 4 == 0, then XOR(0 to n) = n
// 2. If n % 4 == 1, then XOR(0 to n) = 1
// 3. If n % 4 == 2, then XOR(0 to n) = n + 1
// 4. If n % 4 == 3, then XOR(0 to n) = 0

#include <iostream>
using namespace std;

// Function to find XOR from 0 to n using pattern
int xorFromZeroToN(int n) {
    // Based on the pattern explained above
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// Function to find XOR from L to R
int findXOR(int L, int R) {
    // XOR from L to R is the XOR from 0 to R XOR'd with XOR from 0 to L-1
    return xorFromZeroToN(R) ^ xorFromZeroToN(L - 1);
}

int main() {
    int L = 4, R = 8;
    cout << "XOR from " << L << " to " << R << " is: " << findXOR(L, R) << endl;
    return 0;
}
