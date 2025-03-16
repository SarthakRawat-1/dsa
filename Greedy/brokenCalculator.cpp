// Problem Statement :- https://leetcode.com/problems/broken-calculator/

#include <bits/stdc++.h>
using namespace std;

int brokenCalc(int startValue, int target) {
    // If the starting value is already greater than or equal to the target,
    // the only operation possible is subtraction. Simply subtract to make 
    // the values equal and return the number of steps required.
    if (startValue >= target)
        return startValue - target;

    // If the target is even, divide it by 2.
    // This works because multiplication (×2) in the reverse direction 
    // corresponds to division (/2) when trying to reach the target.
    // We recursively call the function, reducing the target size.
    if (target % 2 == 0) {
        return 1 + brokenCalc(startValue, target / 2);
    }

    // If the target is odd, add 1 to make it even.
    // Adding 1 mimics the reverse operation of subtracting 1 
    // in the forward direction. This helps to eventually divide the value by 2.
    // We recursively call the function, incrementing the target size.
    return 1 + brokenCalc(startValue, target + 1);
}

int main() {
    int startValue = 2;
    int target = 3;
    cout << brokenCalc(startValue, target) << endl;
    return 0;
}