// Problem Statement :- https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

// Approach 1 :- Using Recursion with Memoization
// First we will find square of the number.
// Then we will convert that number to string. Now this string will be splitted into substrings using for loops. Using two for loops i, j and two substrings, first from i to j and second after that.
// Recursively, we will further expand those strings, which can broken down further into susbtrings. This we can do by further applying i, j for loops for them separately.
// We will only expand those which can be a valid punishment. As if a substring sum is already greater than the original number, breaking it into further substrings will only increase the sum further.

// Approach 2 :- Using Integer Manipulation (Similar to Approach 1)
// Here, we can simplify breaking the number part. Instead of converting to string and finding substring, we can use classic digit logic.
// If we mod by 10, we get the last digit of a number, if we divide by 10, we get the number without the last digit. In this way, we got one possible split.
// Simmilarly we can do mod by 100, divide by 100 and so on.
// We will keep this 10, 100, 1000 number i.e. 10 to the power 1, 2, 3 etc. till only 10 to the power 3. This is because it is given that num can be from 1 to 1000. Because even if there's a big number after squaring num. Then if we mod it by 1000, we will get last 3 digits, and if we divide by 1000, we will get the number without the last 3 digits. Their sum actually, you can check will be comparable to num. But if you we go beyond this, the summ will become too big.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if we can partition the square of a number
// such that the sum of its substrings equals the original number.
// bool check(int i, int currsum, string str, int num, vector<vector<int>>& dp) {
//     // Base Case: If we have processed the entire string
//     if (i == str.length()) {
//         return currsum == num; // Check if sum matches the original number
//     }

//     // If the current sum already exceeds the number, return false (pruning)
//     if (currsum > num) {
//         return false;
//     }

//     // Memoization: Return precomputed result if available
//     if (dp[i][currsum] != -1) {
//         return dp[i][currsum];
//     }

//     bool possible = false;

//     // Iterate through the string to generate substrings
//     for (int j = i; j < str.length(); j++) {
//         string first = str.substr(i, j - i + 1); // Extract substring
//         int val = stoi(first); // Convert substring to integer
        
//         // Recursively check the remaining part of the string
//         possible = possible || check(j + 1, currsum + val, str, num, dp);

//         // If we find a valid partition, return true immediately
//         if (possible) {
//             return true;
//         }
//     }

//     return dp[i][currsum] = possible; // Store result in DP table
// }

// // Function to compute the punishment number up to 'n'
// int punishmentNumber(int n) {
//     int punish = 0;

//     // Iterate through all numbers from 1 to n
//     for (int num = 1; num <= n; num++) {
//         int square = num * num; // Compute square of the number
//         string str = to_string(square); // Convert square to string

//         // DP table initialized to -1 for memoization
//         vector<vector<int>> dp(str.length(), vector<int>(num + 1, -1));

//         // If the square can be partitioned into substrings summing to the number, add it to punishment sum
//         if (check(0, 0, str, num, dp)) {
//             punish += square;
//         }
//     }

//     return punish; // Return the total punishment number
// }

// Approach 2

// Recursive function to check if we can partition the square of a number
// such that the sum of its substrings equals the original number.
bool check(int sq, int currsum, int num) {
    // Base Case: If the remaining square value is 0
    if (sq == 0) {
        return currsum == num; // Check if accumulated sum matches the number
    }

    // Try different ways to partition the number by considering last 1, 2, or 3 digits
    return check(sq / 10, currsum + (sq % 10), num) ||  // Consider last digit
           check(sq / 100, currsum + (sq % 100), num) || // Consider last two digits
           check(sq / 1000, currsum + (sq % 1000), num); // Consider last three digits
}

// Function to compute the punishment number up to 'n'
int punishmentNumber(int n) {
    int punish = 0;

    // Iterate through all numbers from 1 to n
    for(int num = 1; num <= n; num++) {
        int sq = num * num; // Compute square of the number

        // If the square can be partitioned into substrings summing to the number, add it to punishment sum
        if (check(sq, 0, num)) {
            punish += sq;
        }
    }

    return punish; // Return the total punishment number
}

// Main function
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n; // Take input from user

    int result = punishmentNumber(n); // Compute punishment number
    cout << "Punishment Number: " << result << endl; // Output result
    
    return 0;
}
