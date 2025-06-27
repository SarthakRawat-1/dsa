// Problem Statement :- https://leetcode.com/problems/gray-code/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode1(int n) {
    // Total number of gray codes = 2^n
    int returnSize = 1 << n;  // Equivalent to pow(2, n)

    // Initialize result vector of required size
    vector<int> result(returnSize);

    // First gray code is always 0
    result[0] = 0;

    // Build the sequence iteratively
    for (int i = 1; i < returnSize; ++i) {
        // Flip the rightmost set bit of previous number
        // This ensures only one bit changes between result[i-1] and result[i]
        result[i] = result[i - 1] ^ (i & -i);
    }

    return result;
}

#include <vector>

vector<int> grayCode(int n) {
    int size = 1 << n; // Total number of Gray codes (2^n)
    vector<int> result;

    for (int i = 0; i < size; ++i) {
        result.push_back(i ^ (i >> 1)); // Apply standard Gray code formula
    }

    return result;
}

int main() {
    int n = 4;
    vector<int> result = grayCode(n);

    // Print the vector
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
