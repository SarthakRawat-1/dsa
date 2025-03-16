// Problem Statement :- We have to print a 2D array in a wave form i.e. print first column in order, then print second column in reverse order, then print third column in order and so on.
// Hence, for If it’s an even-indexed column, we traverse top to bottom. If it’s an odd-indexed column, we traverse bottom to top.

#include <iostream>
#include <vector>
using namespace std;

// Function to print 2D array in wave form
void printWaveForm(const vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int col = 0; col < cols; col++) {
        if (col % 2 == 0) {
            // Even column index :- Top to Bottom
            for (int row = 0; row < rows; row++) {
                cout << arr[row][col] << " ";
            }
        } else {
            // Odd column index :- Bottom to Top
            for (int row = rows - 1; row >= 0; row--) {
                cout << arr[row][col] << " ";
            }
        }
    }

    cout << endl;
}

int main() {
    // Example 2D array
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Wave form traversal of the 2D array:\n";
    printWaveForm(arr);

    return 0;
}


