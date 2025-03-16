// Problem Statement :- https://leetcode.com/problems/subsets/description/

// First understand that if N (size of array) = 1, then number of subsets will be 2. If N = 2, then number of subsets will be 4. If N = 3, then number of subsets will be 8. If N = 4, then number of subsets will be 16.
// So number of subsets are 2^n or 1 << n
// Each element in the array can either be included in a subset or not. Thus, we can think of each subset as a binary string of length n where :- 1 indicates the inclusion of the corresponding element in the subset. 0 indicates the exclusion of the corresponding element.
// For an array of size n, there are 2^n subsets. Each subset can be represented by a binary number from 0 to 2^n - 1. Each bit of the binary number will tell us whether to include the corresponding element in the subset or not. Loop through all numbers from 0 to 2^n - 1 and use the binary representation of each number to decide which elements of the array are included in the corresponding subset.

// Eg :- For nums = [1, 2, 3]
// The binary numbers from 0 to 7 (i.e., 2^3 - 1) represent the subsets :-
// 000: []
// 001: [1]
// 010: [2]
// 011: [1, 2]
// 100: [3]
// 101: [1, 3]
// 110: [2, 3]
// 111: [1, 2, 3]

#include <vector>
#include <iostream>
using namespace std;

// Function to generate all subsets of a given set of unique integers
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();                // Get the size of the input array
    int totalSubsets = 1 << n;          // Calculate the total number of subsets (2^n)
    vector<vector<int>> result;         // To store the final list of subsets

    // Iterate over all possible subset combinations (from 0 to 2^n - 1)
    for (int i = 0; i < totalSubsets; i++) {
        vector<int> subset;             // Temporary vector to store the current subset
        // Check each bit of the number i to decide which elements to include
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {         // If the j-th bit is set in i, include nums[j]
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);       // Add the current subset to the result
    }
    
    return result;                      // Return all subsets
}

// Helper function to print subsets
void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[";
    for (int i = 0; i < subsets.size(); i++) {
        cout << "[";
        for (int j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j];
            if (j != subsets[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != subsets.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    cout << "Subsets of [1, 2, 3]: " << endl;
    vector<vector<int>> result1 = subsets(nums1);
    printSubsets(result1); 

    return 0;
}

