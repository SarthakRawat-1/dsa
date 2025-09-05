// Problem Statement :- https://leetcode.com/problems/merge-intervals/description/

// For logic, check the problem :- checkIfGridCanbeCutIntoSections.cpp

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    sort(begin(intervals), end(intervals));

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result.back()[1]) { // In the check grid problem only < not <=
            result.back()[0] = min(result.back()[0], intervals[i][0]); // This tbh is not needed as we have already sorted the result vector.
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {

}