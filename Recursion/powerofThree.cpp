// Problem Statement :- https://leetcode.com/problems/power-of-three/

// Brute Force :- Simply divide input by 3 repeatedly if divisible (i.e. % gives 0). If we get 1, then sure.
// Second approach :- Simply do above but with recursion instead of a loop.
// We are asked 3^x = n. Log both sides => x log 3  = log n => x = (log n)/(log 3) and then check if x is a valid integer.

// Best Approach :- Without Recursion/Loop i.e. solved in constant time.
// Let's say we are given n = 9. Then randomly take x = soemthing, say 4. Ofc this will be a legit power of 3 so that's fine.
// Now check if n is able to divide this 3^x or not, i.e. 3^x % n == 0. If yes, then n is a power of 3.
// But if we take x such that n > 3^x, we may not be able to deduce correctly as it will never be divisble by 3 becz it's smaller.
// 3^19 is just under the limit of 32 bit integer. Hence, we can simmply take x = 19 for checking.

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

int main() {

}