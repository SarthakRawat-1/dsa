// Problem Statement :- https://leetcode.com/problems/add-digits/description/

#include <bits/stdc++.h>    
using namespace std;

int addDigits(int num) {
        // If the number is 0, we directly return 0 as the answer.
    if (num == 0) return 0;

    // Apply the digital root formula:
    // For any number num, the result is 1 + (num - 1) % 9
    // This works for all positive numbers.
    return 1 + (num - 1) % 9;
}

int main() {
    int num = 389765;
    cout << "Sum of Digits of the given number :- " << addDigits(num) << endl;
}