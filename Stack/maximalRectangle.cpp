// Problem Statement :- https://leetcode.com/problems/maximal-rectangle/description/

// This is a variation of largestRectangleinHistogram.cpp
// For every row, in each of the element in that row, all the continuous 1's appearing in that column (above the element), we can think of them as a histogram rectangle.
// Now, we can find the largest rectangle area in each row and take the maximum of all of them. This, we have to do for each row.
// We can use a vector initialized with all 0's, and update it for every row. This will represent the heights vector that we had in largestRectangleinHistogram.cpp for each row.

#include <bits/stdc++.h>
using namespace std;

// Method 1
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(); // Number of bars in the histogram

    // Arrays to store the indices of the Next Smaller Element (NSE) on the right and left
    vector<int> Right(n); // Stores the index of the next smaller element to the right
    vector<int> Left(n);  // Stores the index of the next smaller element to the left

    stack<int> st; // Stack to help find the NSE indices efficiently

    // Step 1: Compute the indices of the next smaller element on the right for each bar
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack until we find an element smaller than the current height
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Right[st.top()] = i; // Update the NSE index for the top of the stack
            st.pop();            // Remove the element from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // If no smaller element exists to the right, set the index to `n` (end of the array)
    while (!st.empty()) {
        Right[st.top()] = n;
        st.pop();
    }

    // Step 2: Compute the indices of the next smaller element on the left for each bar
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until we find an element smaller than the current height
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Left[st.top()] = i; // Update the NSE index for the top of the stack
            st.pop();           // Remove the element from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // If no smaller element exists to the left, set the index to `-1` (start of the array)
    while (!st.empty()) {
        Left[st.top()] = -1;
        st.pop();
    }

    int ans = 0; // Variable to store the maximum rectangle area

    // Step 3: Calculate the maximum rectangle area
    for (int i = 0; i < n; i++) {
        // Calculate the width of the rectangle: (Right[i] - Left[i] - 1)
        int width = Right[i] - Left[i] - 1;

        // Calculate the area of the rectangle with height `heights[i]`
        int area = heights[i] * width;

        // Update the maximum area
        ans = max(ans, area);
    }

    return ans; // Return the maximum rectangle area
}

// Function to calculate the maximal rectangle in a binary matrix
int maximalRectangle(vector<vector<char>>& matrix) {
    int ans = 0; // Variable to store the maximum rectangle area
    int row = matrix.size();    // Number of rows in the matrix
    int column = matrix[0].size(); // Number of columns in the matrix

    // Vector to store the heights of histogram bars for the current row
    vector<int> heights(column, 0);

    // Traverse each row in the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            // Update the height of the histogram bar for the current column
            if (matrix[i][j] == '0') {
                heights[j] = 0; // Reset height to 0 if the current element is '0'
            } else {
                heights[j] += 1; // Increment height if the current element is '1'
            }
        }

        // Calculate the largest rectangle area for the current row's histogram
        ans = max(ans, largestRectangleArea(heights));
    }

    return ans; // Return the maximal rectangle area
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << maximalRectangle(matrix);

    return 0;
}