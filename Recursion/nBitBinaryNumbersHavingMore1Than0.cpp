// Problem Statement :- https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/0

// We can simply use concept of permutation and putting 0 or 1 in a specific place.
// For eg :- For N = 4, we can think that we have 4 palces to fill :- _, _, _, _ and each of them can be filled in 2 ways so 2 x 2 x 2 x 2 will be total possible ways.
// But on thousandth place we can't palce 0, as then 0 will exceed 1, so for any N, the highest place, has only 1 way to fill.
// Now the second highest place can be 0 or 1, so 2 ways. But now third highest place can be 0 only if second highest place is 1, else it can be 1 only. Hence, now number of ways depends on previous value.
// This will give rise to recursion tree logic.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all N-bit binary numbers 
// such that in every prefix, the number of 1s is >= number of 0s
void find(int N, vector<string> &ans, string temp, int zeroes, int ones) {
    // Base case: If the current string's size reaches N, 
    // it is a valid string and can be added to the answer list
    if (temp.size() == N) {
        ans.push_back(temp);
        return;
    }

    // Always try to place '1' first because we want the output in decreasing order lexicographically.
    temp.push_back('1');
    // Recurse with one more '1' added
    find(N, ans, temp, zeroes, ones + 1);
    temp.pop_back();  // Backtrack to try other possibilities

    // Only add '0' if number of 1s > number of 0s
    // This ensures that in every prefix, 1s are not less than 0s
    if (ones > zeroes) {
        temp.push_back('0');
        // Recurse with one more '0' added
        find(N, ans, temp, zeroes + 1, ones);
        temp.pop_back();  // Backtrack
    }
}

// Main function that initializes necessary variables
vector<string> NBitBinary(int N) {
    vector<string> ans; // To store all valid N-bit binary numbers
    string temp;         // Temporary string to build each binary number

    // Start recursive generation with 0 ones and 0 zeroes
    find(N, ans, temp, 0, 0);

    return ans;
}

int main() {
    int N = 4;
    vector<string> ans = NBitBinary(N);

    // Print all valid N-bit binary numbers
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}