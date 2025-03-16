// Problem Statement :- https://leetcode.com/problems/sqrtx/description/

// Brute Force :- Try all possible integers from 1 to X and check whether the square of that integer is less than or equal to X

// The optimized approach uses binary search to find the square root of X.

#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    // Special case: If x is 0 or 1, the square root is x itself.
    if (x == 0 || x == 1)
        return x; // Return x directly if it's 0 or 1 as sqrt(0) = 0 and sqrt(1) = 1.
    
    // Initialize binary search range
    int low = 1, high = x; // We start from 1 to x as possible values for the square root.
    int ans = 0; // This will store our result, i.e., the floor value of the square root.

    // Binary Search Loop: Continue until the low pointer crosses the high pointer.
    while (low <= high) {
        // Calculate mid to avoid overflow: (low + high) / 2
        int mid = low + (high - low) / 2; // Using (low + (high - low) / 2) prevents overflow.

        // Case 1: Check if mid*mid is exactly equal to x (perfect square)
        if (mid * mid == x) {
            return mid; // Found the exact square root, return mid immediately.
        }
        // Case 2: If mid*mid is less than x, move the low pointer to mid + 1
        else if (mid * mid < x) {
            ans = mid; // mid is a possible answer, as mid*mid < x, store it in ans.
            low = mid + 1; // Narrow the search space to the right half to find a better answer.
        }
        // Case 3: If mid*mid is greater than x, move the high pointer to mid - 1
        else {
            high = mid - 1; // Narrow the search space to the left half.
        }
    }

    // Return the largest integer value where mid*mid <= x (stored in ans).
    return ans;
}

int main() {
    int X = 2345;

    int ans = mySqrt(X);

    cout << "The Square root of required number is :- " << ans << endl;
}

// This can cause an overflow, as we are multiplying mid * mid, which can be a very large number.
// To avoid this, use the conditions mid == mid / x and mid < mid / x instead.