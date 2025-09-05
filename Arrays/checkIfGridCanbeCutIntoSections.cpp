// Problem Statement :- https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

// Every rectangle, will capture a certain range over x and over y. Which means, we can't draw a line between these ranges.
// Eg :- Let's say we have grid of size 5 and a yellow rectangle is occupying x from 1 to 5. Now, we can't draw a vertical line at 2, 3, 4, and 5. Now, we can only make cuts at 1, adn that too if some rectangle doesn't cover that range.
// Eg :- If a red rectangle occupies range x from 0 to 2, then no vertical cuts can be made. And hence, dividing grid with vertical cuts is not possible.

// Basically, yellow and red are overlapping. Let's say yellow => (1, 0, 5, 2) and red => (0, 2, 2, 4). x axis => (1, 5) and (0, 2), for merging take min and max so => (0, 5) which covers entire range i.e. grid.
// Ofc, now u need not but u can still take other rectangles and merge their range with these. And reaffirm that entire range is occupied.

// Now try to cut horizontal lines. Yellow and Red y axis => (0, 2) and (2, 4). These are not overlapping. So we can cut a line at y = 2.
// But we still would like to merge intervals. For eg we have two rectangles red and green y axis => (2, 4) and (2, 3) overlapping so merge them => (2, 4)

// Basically, we will try to merge as many intervals as we can. Then, finally we will check how many intervals are left (merged included) after merging all possible. Ofc, no of intervals - 1 is the cuts we can make.
// Since, we are asked to make two cuts, we have to check for minimum 3 intervals in final result.

// Ofc, first from all rectangles we will extract the range of x/y axis based on where we want to make cuts.
// In interval based questions, sort, that might make things easier. First try, starting point based sort, if that doesn't work, then ending point sort.
// Let's say you got :- {(0, 2), (0, 4), (1, 5), (3, 5)} Now add first interval in result :- {(0, 2)}. Then look at (0, 4), it's starting point is less than ending point of prev interval (last in result, in this case it's also the first). So overlapping, merge by taking min(starting point of both) and max(enging point of both).
// Add this merged interval to result and remove the constituent intervals of this from result and original intervals vector. Then continue with others similarly.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    sort(begin(intervals), end(intervals));

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] < result.back()[1]) { // In the check grid problem only < not <=
            result.back()[0] = min(result.back()[0], intervals[i][0]); // This tbh is not needed as we have already sorted the result vector.
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<vector<int>> hor; // x axis
    vector<vector<int>> vert; // y axis

    for (auto &coord : rectangles) {
        int x1 = coord[0];
        int y1 = coord[1];
        int x2 = coord[2];
        int y2 = coord[3];

        hor.push_back({x1, x2});
        vert.push_back({y1, y2});
    }

    vector<vector<int>> result1 = merge(hor);
    vector<vector<int>> result2 = merge(vert);

    return result1.size() >= 3 || result2.size() >= 3;
}

int main() {

}