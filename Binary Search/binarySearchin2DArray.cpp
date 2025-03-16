// Problem Statement :- https://leetcode.com/problems/search-a-2d-matrix/description/

// Binary Search can be applied on a 2D array if it is sorted both rowwise and columnwise and even across rows.

// Approach 1 :- For every row, check if the element to be found can be present in that row. This we can do quite easily if the row is sorted.
// For eg if the first row is {2, 6, 10, 14, 18} and the number to be found is 52, it can't lie between 2 and 18 so we skip it.
// Now, if row is {47, 52, 78, 93, 102} then as 52 lies between 47 and 102, so if 52 is in our 2D array, it has to be present here. It can't be in any other row and hence, we will skip all rows beneath this row.
// For searching element in this row, we can use Binary Search.

// Approach 2 :- We can convert our sorted 2D array to a 1D array by traversing row by row, and we will get a sorted 1D row. Now, we can easily search in this 1D array.
// However, we need nota ctually create a 1D array. Use the concept of Row Major order. 
// We can write the start and end index of the 1D array without writing the 1D array itself. We will then find it's mid will be 9. Now this 9th index element, we will try to locate in our 2D array. After locating the 9th index, we have to actually find it's index as per our 2D arrangement.
// This we can find using :- row_index = index/col_size and col_index = index%col_size, these are formulae for row major order.
// Now with this, u can simply apply binary search as normal.

#include <bits/stdc++.h>
using namespace std;

// Function to search for a target element in a sorted 2D matrix.
// The matrix is sorted such that each row is sorted and the first element of each row is greater than the last element of the previous row.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Get the dimensions of the matrix.
    int N = matrix.size();       // Number of rows
    int M = matrix[0].size();    // Number of columns

    // Define the search space in terms of a virtual 1D array.
    int start = 0, end = N * M - 1, mid;

    // Variables to store row and column indices derived from the mid index.
    int row_index, col_index;

    // Perform binary search on the virtual 1D array.
    while (start <= end) {
        // Calculate the middle index of the current search space.
        mid = start + (end - start) / 2;

        // Convert the 1D index (mid) into 2D row and column indices using row-major order.
        row_index = mid / M;        // Row index: mid divided by the number of columns.
        col_index = mid % M;        // Column index: mid modulo the number of columns.

        // Check if the target matches the current element.
        if (matrix[row_index][col_index] == target) {
            return true;            // Target found, return true.
        } else if (matrix[row_index][col_index] < target) {
            // If the current element is smaller than the target, search the right half.
            start = mid + 1;
        } else {
            // If the current element is larger than the target, search the left half.
            end = mid - 1;
        }
    }

    // If the loop ends, the target is not in the matrix.
    return false;
}

int main() {
    // Example 1: Basic test case
    vector<vector<int>> matrix1 = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    int target1 = 9;
    cout << "Result: " << (searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;

    // Example 2: Target not in matrix
    vector<vector<int>> matrix2 = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    int target2 = 10;
    cout << "Result: " << (searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;

    // Example 3: Single row matrix
    vector<vector<int>> matrix3 = {{1, 2, 3, 4, 5}};
    int target3 = 4;
    cout << "Result: " << (searchMatrix(matrix3, target3) ? "Found" : "Not Found") << endl;

    // Example 4: Single column matrix
    vector<vector<int>> matrix4 = {{1}, {3}, {5}, {7}, {9}};
    int target4 = 6;
    cout << "Result: " << (searchMatrix(matrix4, target4) ? "Found" : "Not Found") << endl;

    // Example 5: Empty matrix (invalid case)
    vector<vector<int>> matrix5 = {};
    // This example is skipped as it requires additional error checking.

    return 0;
}
