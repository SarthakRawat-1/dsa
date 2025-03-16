// Problem Statement :- https://leetcode.com/problems/set-matrix-zeroes/description/

// Brute Force :- Given a n x m matrix, iterate over it using nested for loops. Whenever we find a zero in any cell (say i, j), we will mark all cells in row i and column j with -1 except those which contain 0. The reason we mark with -1, is because if we replace everything with zero, it will just create even more zeros in the matrix that we will now end up checking because of our nested for loops (but we only want to modify rows and columns based on intial zeros). So the main idea with replacing with -1 is that we first get to know all the zeros that were present intially, set -1 where we want to, and finally at the end replace all -1 with 0
// Ofc replacing with -1 is based on the assumption that array doesn't contain negative number. If it does, find some other way to mark elements.

#include <bits/stdc++.h>
using namespace std;

// Function to mark all non-zero elements in the row 'i' as -1.
// This is done so that later we can convert these -1s to 0s,
// without immediately marking all zeros in the first pass.
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // Loop through each column in the row:
    for (int j = 0; j < m; j++) {
        // If the current element is not zero, mark it as -1:
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

// Function to mark all non-zero elements in the column 'j' as -1.
// This is done to mark the entire column where we encounter a zero,
// but we use -1 so we don't accidentally change any zeros during this pass.
void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // Loop through each row in the column:
    for (int i = 0; i < n; i++) {
        // If the current element is not zero, mark it as -1:
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

// Main function that modifies the matrix by setting rows and columns
// to zero if a zero is present in that row or column.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // First pass: Mark rows and columns that should be zeroed by marking non-zero elements as -1.
    // The zero elements themselves are left unchanged.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If an element is 0, mark its entire row and column:
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i); // Mark the entire row
                markCol(matrix, n, m, j); // Mark the entire column
            }
        }
    }

    // Second pass: Convert all marked -1s into 0s.
    // This is because all positions marked as -1 need to be turned to 0
    // (as they are in the row/column of an original zero).
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the element is -1, change it to 0:
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    // Return the modified matrix:
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, 
                                  {1, 0, 1}, 
                                  {1, 1, 1}};
    
    int n = matrix.size();     // Number of rows
    int m = matrix[0].size();  // Number of columns

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";  
        }
        cout << "\n";  
    }
    
    return 0;
}


// Better Approach :- In the previous approach, we were marking the row and column with -1 while traversing the matrix. Here we will reduce the time complexity by marking the cells after the traversal. This will use two extra arrays though.
// First, we declare two arrays :- a row array of size n and a col array of size m and both are initialized with 0. Use two loops(nested loops) to traverse all the cells of the matrix. If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will be 0 in the final matrix. Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.

#include <bits/stdc++.h>
using namespace std;

// Function that sets entire rows and columns to zero if any element is zero.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Arrays to keep track of which rows and columns should be set to zero.
    // Initially, all elements in row[] and col[] are set to 0.
    int row[n] = {0};  // row array to track rows that need to be zeroed
    int col[m] = {0};  // col array to track columns that need to be zeroed

    // Traverse the matrix to find all zeros:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If an element in the matrix is 0:
            if (matrix[i][j] == 0) {
                // Mark the ith row for zeroing by setting row[i] to 1.
                row[i] = 1;

                // Mark the jth column for zeroing by setting col[j] to 1.
                col[j] = 1;
            }
        }
    }

    // Second pass: Modify the matrix to set appropriate elements to 0.
    // If row[i] or col[j] is marked as 1, set matrix[i][j] to 0.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the current row or column is marked, set the element to 0.
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    // Return the modified matrix.
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, 
                                  {1, 0, 1}, 
                                  {1, 1, 1}};
    
    int n = matrix.size();     // Number of rows
    int m = matrix[0].size();  // Number of columns

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";  
        }
        cout << "\n";  
    }
    
    return 0;
}


// Optimal Approach :- Instead of using two different matrixes row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0.
// But there is a problem, if we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice.
// So, we will use one extra variable col0 intialized with 1. Now the entire first column of matrix will serve as the row array of our matrix. The first row of the matrix, barring the first element i.e. matrix[0][0] will serve as the col array of the matrix with the extra variable now acting as matrix[0][0]
// Traverse the matrix. If an element is 0 (say, elem[i][j]) then we will mark corresponding element in first row as 0 and first column as 0 i.e. matrix[0] [j] and matrix[i] [0] with zero.
// If i is 0, then we will mark matrix[0] [0] as 0 but if j is 0 then we will mark col0 as 0
// After marking, we will modify the rest of cells, according to the first row, first column and col0 of the matrix. We will not modify them because modification of rest of the matrix depends on them.
// Finally we will change the 1st row and column using the values from matrix[0] [0] and col0 variable. Here also we will change the row first and then the column. This is because modification of first column is based on the col0 variable which is an independent variable. Now, if we modify the 1st column first, matrix[0] [0] might be changed and this will hinder the modification of the 1st row as well.

#include <bits/stdc++.h>
using namespace std;

// Function to set rows and columns to zero if an element is 0.
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Variable to track the state of the first column.
    // It is initialized to 1 and will be set to 0 if any element in the first column is 0.
    int col0 = 1;

    // Step 1: Traverse the matrix to mark rows and columns
    // If any element is 0, mark the corresponding first row and first column element as 0.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Mark the i-th row by setting the first element of the row to 0.
                matrix[i][0] = 0;

                // Mark the j-th column by setting the first element of the column to 0,
                // unless j == 0, in which case we update col0.
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Traverse from (1,1) to (n-1, m-1) and modify the elements.
    // If the row or column is marked, set the element to 0.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // If the first element of the i-th row or the j-th column is 0,
                // set matrix[i][j] to 0.
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Finally, update the first row and first column.
    // If the first element of the matrix is 0, set the entire first row to 0.
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // If col0 is 0, set the entire first column to 0.
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    // Return the modified matrix.
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
