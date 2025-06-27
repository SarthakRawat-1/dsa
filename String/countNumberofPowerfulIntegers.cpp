// Problem Statement :- https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

// If we have 5 digits and we have to fill one place, we will have 5 ways i.e. 5 numbers.
// If we have to fill two places, it becomes 5 x 5 i.e. 25 ways.
// We will write a fucntion, say solve, which will find powerful numbers below a specified value.
// In this case, we can find powerful numbers between start and finish as :- solve(finish) - solve(start - 1) 
// As we have to include start value, so we do start - 1 in function.
// After fixing suffix, for the highest digit in remaining str, we will take all possibilities lower than the highest digit of finish. This is to be on the safe side. 
// But this only applies if that number is lower than the limit. If it's greater than the limit, then 0 to limit, numbers, all can be possibilities.
// Any position to fill aafter that can have limit + 1 possibilities.

// Edge Case :- If remaining suffix >= suffix in question, then count += 1, because then in highest digit of prefix, the limit numbercan also come.

#include <bits/stdc++.h>
using namespace std;

// This function calculates how many numbers <= str follow the constraints:
// - Digits are from 0 to 'limit'
// - Suffix of the number is >= inputSuffix
long long solve(string& str, string& inputSuffix, int limit) {
    // If the number is shorter than the required suffix, it's invalid
    if(str.length() < inputSuffix.length()) {
        return 0;
    }

    long long count = 0;

    // Extract the last digits (suffix) from the string to compare later
    string trailString = str.substr(str.length() - inputSuffix.length());

    // Number of digits we can freely choose (excluding suffix)
    int remainL = str.length() - inputSuffix.length();

    // Loop over the free digits to count all combinations less than or equal to 'str'
    for(int i = 0; i < remainL; i++) {
        int digit = str[i] - '0'; // Convert char to int

        if(digit <= limit) {
            // Count all combinations with digits [0..digit-1] for this position,
            // and all (limit+1) possibilities for the remaining positions
            count += digit * pow(limit+1, remainL - i - 1);
        } else {
            // If the digit exceeds the limit, we can fix all previous digits,
            // and pick all possible combinations for remaining positions
            count += pow(limit+1, remainL - i);
            return count; // No need to continue further
        }
    }

    // After processing free digits, check if the suffix is also valid
    // If trailString >= inputSuffix, then this number is valid too, include it
    if(trailString >= inputSuffix) {
        count += 1;
    }

    return count;
}

// Main function to compute how many powerful integers lie in [start, finish]
long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string startStr = to_string(start - 1); // We count up to finish and subtract up to (start - 1)
    string finishStr = to_string(finish);

    // Total powerful integers = count up to finish - count up to (start - 1)
    return solve(finishStr, s, limit) - solve(startStr, s, limit);
}

int main() {
    int start = 1, finish = 1000, limit = 1; 
    string s = "1";
    cout << numberOfPowerfulInt(start, finish, limit, s) << endl;
    return 0;
}