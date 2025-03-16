// Problem Statement :- https://www.geeksforgeeks.org/problems/minimum-rotations-to-unlock-a-circular-lock1001/0

// Let's say we have R = 222 and we want to make D = 333
// We can rotate the lock both clockwise (i.e. increase number by 1) and counter clockwise (i.e. decrease number by 1).
// For minimum rotations, we can simply subtract the corresponding digits. For eg :- if we had R = 2345 and D = 5432 we get 5 - 2 = 3, 4 - 3 = 1, 3 - 4 = 1 (absolute) and 2 - 5 = 3 (absolute), then we simply add i.e. 3 + 1 + 1 + 3 = 8, so we need 8 rotations.
// We only take the absolute value, as we can rotate in either direction. 
// But this won't work for this case :- R = 3658 and D = 9240 as it is faster to go 8 -> 9 -> 0 in 2 moves than in 8 moves. How do we resolve this?
// We will check for both clockwise and counter clockwise by deducting the result of subtraction from 10 and comparing which one is smaller. For eg :- 8 or 10 - 8 = 2, smaller is 2, so we took that.

// This is Greedy because at each digit, we independently minimize the number of rotations required to match that digit by selecting the smaller rotation count (clockwise or counter-clockwise).
// By adding the optimal rotations for each digit, we minimize the total rotations required for the entire lock.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimum rotations to unlock a circular lock
int rotationCount(long long R, long long D) {
    int ans = 0; // To store the total rotations
    int first, second; // Variables to store digits

    // Process each digit of R and D until R becomes 0
    while (R) {
        first = R % 10; // Get the last digit of R
        second = D % 10; // Get the last digit of D

        // Calculate minimum rotations for each digit
        ans += min(abs(first - second), 10 - abs(first - second));

        R /= 10; // Remove the last digit of R
        D /= 10; // Remove the last digit of D
    }

    return ans; // Return total rotations
}

int main() {
    long long R = 3658; 
    long long D = 9240; 

    int rotations = rotationCount(R, D);
  
    cout << rotations << endl;

    return 0;
}