// Problem Statement :- https://takeuforward.org/plus/dsa/problems/generate-binary-strings-without-consecutive-1s

// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given an integer n, generate all binary strings of length n
that do NOT contain consecutive '1's. Return them in
lexicographically increasing order.

We’ll implement three methods:
1. Backtracking (DFS) – natural and lexicographically ordered.
2. Iterative using a stack (DFS-like) – also produces lexicographic order.
3. Dynamic Programming:
   a) Count only (fast O(n) solution).
   b) Optional generation via constrained recursion.
*/

// 1️⃣ BACKTRACKING (DFS)
void dfs_backtrack(int n, string &curr, vector<string> &ans) {
    if ((int)curr.size() == n) {
        ans.push_back(curr);
        return;
    }
    // Always safe to append '0'
    curr.push_back('0');
    dfs_backtrack(n, curr, ans);
    curr.pop_back();

    // Append '1' only if no previous '1'
    if (curr.empty() || curr.back() != '1') {
        curr.push_back('1');
        dfs_backtrack(n, curr, ans);
        curr.pop_back();
    }
}

vector<string> generate_backtrack(int n) {
    vector<string> ans;
    string curr;
    dfs_backtrack(n, curr, ans);
    return ans;
}

// 2️⃣ ITERATIVE (using stack – DFS-like)
vector<string> generate_iterative(int n) {
    vector<string> ans;
    stack<string> st;
    st.push("");  // start with an empty prefix

    while (!st.empty()) {
        string s = st.top();
        st.pop();

        if ((int)s.size() == n) {
            ans.push_back(s);
        } else {
            // To maintain lex order when reversing final result, push '1' first
            if (s.empty() || s.back() != '1') {
                st.push(s + "1");
            }
            st.push(s + "0");
        }
    }

    // Because stack-based DFS produces reverse lex order, reverse at the end
    reverse(ans.begin(), ans.end());
    return ans;
}

// 3️⃣ DYNAMIC PROGRAMMING (Counting + optional generation)
/*
Count only using DP:
dp0[i] = number of strings of length i ending with '0'
dp1[i] = number of strings of length i ending with '1'

dp0[1] = 1 ("0"), dp1[1] = 1 ("1")
Recurrence:
  dp0[i] = dp0[i-1] + dp1[i-1]  // append '0' to any string
  dp1[i] = dp0[i-1]             // append '1' only if previous was '0'
*/
long long count_dp(int n) {
    if (n == 0) return 1;   // only the empty string
    if (n == 1) return 2;   // "0" and "1"

    vector<long long> dp0(n + 1), dp1(n + 1);
    dp0[1] = 1;
    dp1[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp0[i] = dp0[i - 1] + dp1[i - 1];
        dp1[i] = dp0[i - 1];
    }
    return dp0[n] + dp1[n];
}

// Optional: Reuse backtracking logic to generate strings (just for consistency)
vector<string> generate_dp(int n) {
    vector<string> ans;
    function<void(string&)> dfs = [&](string &curr) {
        if ((int)curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        dfs(curr);
        curr.pop_back();
        if (curr.empty() || curr.back() != '1') {
            curr.push_back('1');
            dfs(curr);
            curr.pop_back();
        }
    };
    string curr;
    dfs(curr);
    return ans;
}

// --- Driver / Demo ---
int main() {
    int n = 3;

    cout << "1) Backtracking (DFS):\n";
    auto res1 = generate_backtrack(n);
    for (const string &s : res1) cout << s << " ";
    cout << "\n\n";

    cout << "2) Iterative (Stack-based DFS):\n";
    auto res2 = generate_iterative(n);
    for (const string &s : res2) cout << s << " ";
    cout << "\n\n";

    cout << "3) DP Count Only:\n";
    cout << "Count of valid strings of length " << n << " = " << count_dp(n) << "\n\n";

    cout << "4) DP Generation (reuses DFS):\n";
    auto res4 = generate_dp(n);
    for (const string &s : res4) cout << s << " ";
    cout << "\n";

    return 0;
}
