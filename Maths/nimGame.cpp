// Problem Statement :- https://leetcode.com/problems/nim-game/description/

// This is a Game Theory Problem.

#include <bits/stdc++.h>
using namespace std;

bool canWinNim(int n) {
        // If the number of stones is a multiple of 4, you will lose because
        // no matter how many stones you take (1, 2, or 3), your opponent
        // can always reduce the pile to another multiple of 4.
        return n % 4 != 0;
}

int main() {
    int n = 23;
    cout << canWinNim(n) << endl;
}