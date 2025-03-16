// Problem Statement :- https://leetcode.com/problems/count-total-number-of-colored-cells/description/

// This is following a simple pattern of 1 at n = 1, 5 (1 + 4) at n = 2, 13 (1 + 4 + 8) at n = 3 and (1 + 4 + 8 + 12) at n = 4. And observe that 4 can be written as 4 * 1, 8 as 4 * 2, 12 as 4 * 3 etc.

#include <bits/stdc++.h>
using namespace std;

long long coloredCells(int n) {
    int t = 1;
    long long cells = 1;

    while (t <= n) {
        cells += (4 * (t - 1));
        t++;
    }

    return cells;
}

int main() {
    int n = 3;
    cout << coloredCells(n) << endl;
    return 0;
}