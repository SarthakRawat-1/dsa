// Problem Statement :- https://leetcode.com/problems/pascals-triangle-ii/description/

// This is pretty much similar to pascalTriangle.cpp

#include <bits/stdc++.h>
using namespace std;

// // Function to return the rowIndex-th row (0-indexed) of Pascal's Triangle using combinatorial formula
// vector<int> getRow(int rowIndex) {
//     vector<int> row; // Initialize the row to store the elements of the requested row
//     int prev = 1; // Start with the first element as '1'
//     row.push_back(prev); // Add the first element to the row

//     // Use the combinatorial formula to calculate each element in the row
//     for (int i = 1; i <= rowIndex; i++) {
//         int curr = (long long)(prev * (rowIndex - i + 1)) / i; // Compute the next element
//         row.push_back(curr); // Add the current element to the row
//         prev = curr; // Update prev for the next calculation
//     }
    
//     return row; // Return the computed row
// }

// Function to return the rowIndex-th row (0-indexed) of Pascal's Triangle
vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1); // Initialize row with all elements as 1

    // Iteratively update the row from the end to the start for each row level
    for (int i = 1; i < rowIndex; i++) {  
        for (int j = i; j > 0; j--) {  
            row[j] = row[j] + row[j - 1]; // Update each element by summing up the two elements above it
        }
    }

    return row; // Return the completed row
}

int main() {
    int rowIndex;

    // Test case 1
    rowIndex = 3;
    vector<int> result1 = getRow(rowIndex);
    cout << "Row " << rowIndex << " of Pascal's Triangle: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    return 0;
}
