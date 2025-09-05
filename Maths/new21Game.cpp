// Problem Statement :- https://leetcode.com/problems/new-21-game/description/

// Basically we have to find individual prob of her having points from k to n.
// Eg :- n = 21 and k = 17 and maxpoint = 10, we need to find :- P(21) + P(20) + P(19) + P(18) + P(17)
// Now P(21) can be obtained by P(16) * P(5) or P(15) * P(6) or so on till P(11) * P(10) i.e. P(21 - 10) * P(10) or P(n - maxpoint) * P(maxpoint). 
// Ofc as long as P(num) num <= maxpoint then P(num) = 1/maxpoint
// We can see P(21) = P(k - 1) * 1/maxpoint + P(k - 2) * 1/maxpoint + ...
// Similarly we will find for P(20), P(19), P(18) and P(17).
// So, find prob of 1 to 21 and subtract prob of 1 to k - 1.
// P[0] will be 1 as she starts from 0 score.

// I don't really understand this tbh.

#include <bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts) {

}

int main() {

}