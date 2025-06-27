// Problem Statement :- https://leetcode.com/problems/ugly-number-ii/description/

// Brute Force :- Keep dividing till it's possible with 2, then with 3, and then with 5. If it's divisible in the end, then it is an ugly number. Btw even power 0 is allowed i.e. if it's divisble even with just 2 and 3, then it is an ugly number.
// Optimal Approach :- Uses DP
// Even 2 or 3 or 5 or 1 is also an ugly number as all can be represented as powers of 2.3.5
// Starting with 1 which is our first ugly number, we can multiply either with 2 or 3 or 5 which will also result in an ugly number.
// Then in their results we have to choice to multiply with 2, 3 or 5.
// We can use a table to store all the ugly nummbers where the index of table represent the ith ugly number.
// Let's start with 1. Take 3 separate routes. One where we do 1 * 2, 2 * 2, 3 * 2 etc. other with 1 * 3, 2 * 3, 3 * 3, and third with 1 * 5, 2 * 5, 3 * 5 etc.
// Now everytime, we can find i2, i3 or i5, where i represents the ugly number and i2 represents the product of i and 2. Initially i2 will point to 2, and i3 will point to 3 and i5 point to 5.
// Find min of these and populate the array. Then move the i2 to next option.
// Similarly do for others.

// For finding the minimum element, we can use a min heap.

#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Recursion + Memoization)
// T.C : O(n * log k), where k is the number range to find the nth ugly number.
// S.C : O(u), where u is the number of distinct values stored in the memoization map mp.

// class Solution {
// public:
//     unordered_map<int, bool> mp; // To store previously computed results

//     // Function to check whether a number is an ugly number or not
//     bool isUgly(int n) {
//         if(n <= 0)
//             return false; // Ugly numbers must be positive
//         if(n == 1)
//             return true;  // 1 is considered an ugly number

//         // If already computed, return result from map
//         if(mp.find(n) != mp.end())
//             return mp[n];

//         // Recur for n/2, n/3, n/5 if divisible
//         if(n % 2 == 0 && isUgly(n / 2))
//             return mp[n] = true;
//         else if(n % 3 == 0 && isUgly(n / 3))
//             return mp[n] = true;
//         else if(n % 5 == 0 && isUgly(n / 5))
//             return mp[n] = true;

//         return mp[n] = false; // Not divisible by 2, 3, or 5
//     }

//     int nthUglyNumber(int n) {
//         mp.clear(); // Clear the map for fresh calculation
//         int num = 1; // Start checking from 1 upwards
//         while(n > 0) {
//             if(isUgly(num)) {
//                 n--; // If current number is ugly, reduce the count
//             }
//             num++; // Move to next number
//         }

//         return num - 1; // The nth ugly number
//     }
// };


// Approach-2 (Bottom-Up Dynamic Programming)
// T.C : O(n)
// S.C : O(n)

/*
    Idea:
    - Build a list of ugly numbers up to the nth one.
    - Start with 1, which is the first ugly number.
    - Use three pointers (i2, i3, i5) to track the multiples of 2, 3, and 5 respectively.
    - For each position i in array t, calculate:
        - next multiple of 2 = t[i2] * 2
        - next multiple of 3 = t[i3] * 3
        - next multiple of 5 = t[i5] * 5
    - Select the minimum among them as the next ugly number.
    - Move the pointer(s) whose value matched the selected minimum.
    - Repeat until nth ugly number is found.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n + 1); // Array to store ugly numbers from 1 to n
        t[1] = 1; // 1st ugly number is 1

        // i2, i3, i5 are pointers for current position of multiples of 2, 3, and 5
        int i2 = 1, i3 = 1, i5 = 1;

        for(int i = 2; i <= n; i++) {
            int i2th_ugly = t[i2] * 2; // Next multiple of 2
            int i3rd_ugly = t[i3] * 3; // Next multiple of 3
            int i5th_ugly = t[i5] * 5; // Next multiple of 5

            // Select the smallest one as the next ugly number
            t[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});

            // Advance the pointer(s) for which we used the value
            if(t[i] == i2th_ugly) i2++;
            if(t[i] == i3rd_ugly) i3++;
            if(t[i] == i5th_ugly) i5++;
        }

        return t[n]; // Return the nth ugly number
    }
};

int main() {

}