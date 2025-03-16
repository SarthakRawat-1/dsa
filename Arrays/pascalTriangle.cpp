// Problem Statement :- https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Building Pascal's Triangle by Addition
// This approach mimics the way Pascal's triangle is typically built by hand.
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows); // Result vector to store all rows

    // Iterate through each row
    for (int i = 0; i < numRows; i++) {
        // Initialize the current row with '1's. 
        // Each row has (i+1) elements, with the first and last elements being '1'.
        result[i] = vector<int>(i + 1, 1);

        // Fill in the inner values of the row (only needed if i > 1)
        for (int j = 1; j < i; j++) {
            // Calculate each element as the sum of the two elements directly above it
            result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
    }

    // Return the complete Pascal's Triangle up to the specified number of rows
    return result;
}

// Approach 2: Using Combinatorial Math
// This approach uses the mathematical formula to directly compute each row of Pascal's Triangle.
// Formula: The k-th element of the n-th row is given by nCk = n! / (k! * (n - k)!)
// vector<int> getRow(int line) {
//     int prev = 1; // Start with the first element in the row as '1'
//     vector<int> temp{1}; // Initialize the row with the first element as '1'

//     // Calculate each element based on the previous one using the combinatorial formula
//     for (int i = 1; i <= line; i++) {
//         // Compute the next element using the formula (line-i+1) * prev / i
//         // This avoids recalculating factorials and keeps computations within bounds
//         int curr = ((line - i + 1) * prev) / i;
//         temp.push_back(curr); // Add the current element to the row
//         prev = curr; // Update prev for the next element calculation
//     }
    
//     return temp; // Return the computed row
// }

// vector<vector<int>> generate(int line) {
//     vector<vector<int>> result; // Vector to store all rows of Pascal's Triangle
//     result.push_back({1}); // Start with the first row [1]
    
//     // If only one row is needed, return the result immediately
//     if (line == 1) {
//         return result;
//     }

//     // Generate each subsequent row using the getRow function
//     for (int lineNo = 1; lineNo < line; lineNo++) {
//         result.push_back(getRow(lineNo)); // Add each row to the result
//     }
    
//     return result; // Return Pascal's Triangle up to the specified number of rows
// }

int main() {
    int numRows = 5;

    vector<vector<int>> triangle1 = generate(numRows);
    cout << "Approach 1 - Pascal's Triangle by Addition:\n";
    for (const auto& row : triangle1) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
