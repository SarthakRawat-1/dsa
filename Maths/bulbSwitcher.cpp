// Problem Statement :- https://leetcode.com/problems/bulb-switcher/description/

// We can observe that bulb is on, when it is toggled odd number of times.
// Take n = 20 and do as said in the Problem Statement. In the end you will notice, we have 1, 4, 9, 16 bulbs on. These are all perfect squares less than equal to 20.
// Why are only perfect squares bulbs on? This is because the multiples of a non perfect square will form even pairs. For eg :- n = 24, multiples are :- (1, 24) or (24, 1), (2, 12) or (12, 2), (3, 8) or (8, 3), (4, 6) or (6, 4)
// If we had a perfect square, say n = 16, then one more pair will come (4, 4) which will form odd number of pairs.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the number of bulbs that are on after n rounds of toggling
int bulbSwitch(int n) {
    // The perfect squares less than or equal to n are:
    // 1^2, 2^2, 3^2, ..., k^2 where k is the largest integer such that k^2 <= n.
    
    // The count of perfect squares up to n is simply the integer part of the square root of n.
    // This can be calculated as :-
    return sqrt(n); // Count of perfect squares less than or equal to n

    // This works because the square of any whole number is greater than the squares of smaller whole numbers. For example, the square of 5 (25) is greater than the square of 4, 3, 2, and 1 (16, 9, 4, and 1, respectively). Therefore, the number of squares smaller than the square of a number, is the number of whole numbers less than it.
}

int main() {
    int n = 25;
    cout << "Number of bulbs on :- "  << bulbSwitch(n) << endl;
}