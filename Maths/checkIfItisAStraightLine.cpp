// Problem Statement :- https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

// If the points make a straight line, then just use the concept of slope. The slope should be same, for any two points.
// In our case, we will fix the first point and check the slope with the rest of the points. Also to check slope, we will fix the slope obtained from first and second point.
// Edge Case :- We know formula for finding slope is (y2 - y1) / (x2 - x1). If x2 - x1 = 0, then Zero Divison Error will occur, so to prevent this, use cross multiplication. Instead of checking like :- (y2 - y1) / (x2 - x1) == (y3 - y1) / (x3 - x1), we will check like :- (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)

#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();

    int dy = coordinates[1][1] - coordinates[0][1];  // y2 - y1
    int dx = coordinates[1][0] - coordinates[0][0];  // x2 - x1

    for (int i = 2; i < n; i++) { // Start comparing slope from third element
        int dy_i = coordinates[i][1] - coordinates[0][1];  // y3 - y1
        int dx_i = coordinates[i][0] - coordinates[0][0];  // x3 - x1

        if (dy * dx_i != dy_i * dx) { // If slopes are not equal, return false
            return false;
        }
    }

    return true; // If all slopes are equal, return true
}

int main() {
    vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout << checkStraightLine(coordinates) << endl;
    return 0;
}