// Problem Statement :- https://leetcode.com/problems/power-of-four/description/

// Approach 1 :- Just use a loop to divide the number repeatedly by 4 (ofc first check if the number is divisble by 4 or not) till it becomes one. If it's not divisble by 4 but still greater than 1, then number is not power of 4, so return false. Otherwise return true. Refer uglyNumber.cpp

// Approach 2 :- If a number is power of 4, then :- n = 4^x Now use log both sides :- x = log(base 4) n = ln n / ln 4 With this we can find x. Then, just check if 4^x gives n or not.

// Approach 3 :- Every n which is a power of 4 must also be power of 2. To check for power of 2, we can refer powerofTwo.cpp from Maths or Bit Manipulation.
// Another Property is that, every n which is power of 4 has a property :- n - 1 (or 4^x - 1) will be divisble by 3.

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0) return false; // Negative number and Zero number can't be power of 4

    if ((n & (n - 1)) == 0 && (n - 1) % 3 == 0) return true; // If number is power of 2 and number - 1 is divisble by 3, then number is also power of 4
    else return false; 
}

int main() {
    int n = 16;
    cout << isPowerOfFour(n) << endl;
    return 0;
}

// If you want to solve it like powerofThree.cpp
// bool isPowerOfFour(int n) {
//     return n > 0 && 1073741824 % n == 0 && n % 3 == 1;
// }
// Checking n % 3 == 1 because the first two checks works for even divisble by 2 but not by 4.
