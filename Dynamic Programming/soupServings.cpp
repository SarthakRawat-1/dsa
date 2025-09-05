// Problem Statement :- https://leetcode.com/problems/soup-servings/description/

// If A is already empty, then prob of A being empty first is 1. So for, A <= 0, then we will return 1
// If A and B both are empty, then ofc from prev statement prob of A <= 0 is 1, it's half will be 0.5. So, for A <= 0 and B <= 0, we will return 0.5
// If B is empty, then prob of A being empty is 0, i.e. for B <= 0 we will simply return 0. Because we were not asked for prob regarding B.
// This was all for prob of A being empty, that's why disregard for B.

// Consider n = 50, we have A = 50 and B = 50 then. We can't do first op completely, but as mentioned in ques we can give as much as we can, so first op where we take 100ml (50ml in real) from A, will leave A empty. So prob 1 for this option as A became 0 and A <= 0 gives 1.
// Similarly, for second op, we can again make A zero. A <= 0 gives prob 1.
// Now, for third op, we have to take 50 from both. This leaves both A and B empty. Hence, we have to return 0.5 as prob
// Fourth op, will make B empty but not A, we don't care, so prob = 0
// Ofc for total prob, we have to add prob of all four operations. But each operation prob is 0.25
// Hence, final answer = (0.25 * P1) + (0.25 * P2) + (0.25 * P3) + (0.25 * P4) Just take 0.25 common

#include <bits/stdc++.h>
using namespace std;

// This solution works fine but will give memory limit exceeded. Because n is too big.
vector<pair<int, int>> serves = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

vector<vector<double>> t;

double solve(double A, double B) {
    if (A <= 0 && B <= 0) {
        return 0.5;
    } 
    if (A <= 0) {
        return 1.0;
    } 
    if (B <= 0) {
        return 0.0;
    }

    if (t[A][B] != -1.0) {
        return t[A][B];
    }

    double prob = 0.0;

    for (auto &p : serves) {
        int A_taken = p.first;
        int B_taken = p.second;
        
        prob += solve(A - A_taken, B - B_taken);
    }

    return t[A][B] = 0.25 * prob;
}

double soupServings(int n) {
    if (n >= 4800) {
        return 1;
    }

    t.resize(n + 1, vector<double>(n + 1, -1.0));
    return solve(n, n);
}

int main() {

}

// To actually handle very large cases. We have to look at the Note.
// There is no operation that pours 0 mL from A and 100 mL from B.
// Hence, as n increases, A will naturally be easier to empty and B will be harder to finish before A. Hence prob of A being empty is increased.
// So, for A >= 4800, simply take prob = 1