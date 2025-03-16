// Problem Statement :- https://leetcode.com/problems/ugly-number/description/

#include <bits/stdc++.h>
using namespace std;

bool isUgly(int n) {
    // Keep dividning number till it's greater than 1
    while (n > 1) {
        // If number is divisble by 2, divide it by 2
        if (n % 2 == 0) {
            n = n / 2;
        } else if (n % 3 == 0) { // If number is divisble by 3, divide it by 3
            n = n / 3;
        } else if (n % 5 == 0) { // If number is divisble by 5, divide it by 5
            n = n / 5;
        } else {
            return false; // If number is not divisible by 2, 3, or 5 and it is greater than 1, return false
        }
    }

    if (n == 1) return true;
    else return false; // If n is a negative number or zero, return false
}

int main() {
    int number = 59;
    cout << "Is " << number << " a Ugly number? " << isUgly(number) << endl;
}