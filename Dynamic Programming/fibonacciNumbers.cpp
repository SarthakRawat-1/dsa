// Problem Statement :- https://leetcode.com/problems/fibonacci-number/description/

// Let's say we want to find n = 5. We know the recursive implementation of Fibonacci number already.
// But this, will calculate intermediate results a lot of time. F(5) = F(4) + F(3), F(4) = F(3) + F(2), F(3) = F(2) + F(1) and F(2) = F(1) + F(0)
// We need F(3) in two different places, F(2) in two different places (without considering that F(2) will be needed in one more F(3) calculation, as F(3) itself is needed two times!) and also F(1) in two different places (this also will technically be needed more times than two).
// Instead of finding F(3), F(2) anf F(1) again and again (Overlapping subproblems), we can optimize this using DP.
// We can store these intermediate results in an array (or even some other data structure). In our case, we will use array of length n + 1 (because if we have to find F(n), the lowest it can go is F(0)).

// In Top Down Approach, we go from up to down (towards base case). Think of Recursion tree and up to down in that context.
// In Bottom Up Approach, we go from down (base case) to up. Think of Recursion tree and down to up in that context.

// We can do space optimization in this code. For any n, we only need to know F(n - 1) and F(n - 2). Rest all are quite useless. 
// So we can just take a vector of size 3 (or take 3 variables), for containing F(n - 2), F(n - 1) and F(n). We will continously update the vector at every iteration, moving F(n - 2) and F(n - 1) by 1, and calculating new F(n), till we reach desired F(n).

#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
int fibon(int n, vector<int> &dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fibon(n - 1, dp) + fibon(n - 2, dp);
}

int fib(int n) {
    vector<int> dp(n + 1, -1);

    return fibon(n, dp);
}

// Bottom Up Approach
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimization
int fib(int n) {
    if (n <= 1) {
        return n;
    }

    int curr, prev = 1, prev2 = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return curr;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}
