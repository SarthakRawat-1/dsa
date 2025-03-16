// Problem Statement :- https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

// We need not consider y coordinates of any point as height for each point's area is infinitely long, we only need to consider the width.
// First we will sort the points based on their x coordinates. Then we will calculate the difference between the x coordinates of adjacent points. The maximum difference will be our answer.

#include <bits/stdc++.h>
using namespace std;


int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end());

    int ans = 0;

    for (int i = 1; i < n; i++) {
        ans = max(ans, points[i][0] - points[i - 1][0]);
    }
    
    return ans;
}

int main() {
    vector<vector<int>> points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    cout << maxWidthOfVerticalArea(points) << endl;
    return 0;
}