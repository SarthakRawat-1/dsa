// Problem Statement :- https://leetcode.com/problems/sqrtx/description/

#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0; // Special case for sqrt(0)

    // Start checking from 1 upwards until we find the largest number
    // whose square is less than or equal to x.
    int i = 1;
    while (i * i <= x) {
        i++;
    }
    
    // Return the largest integer 'i - 1' whose square was <= x.
    return i - 1;
}


int main() {
    int number = 20;

    cout << "Sqrt of " << number << " is " << mySqrt(number) << endl;
}