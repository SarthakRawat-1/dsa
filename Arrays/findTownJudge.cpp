// Problem Statement :- https://leetcode.com/problems/find-the-town-judge/description/

// Approach 1 :- Count the number of arrows at every node. We will make two vectors, indegree (number of arrows coming) and outdegree (number of arrows going). The index of vector will represent the person. 
// Eg :- For {{1, 3}, {2, 3}} Indegree will be {0, 0, 0, 2} and Outdegree will  be {0, 1, 1, 0} (there's 0 initially in both vectors because vector has 0 based indexing but we know that there can't be a zero person, we could have also done that 0 index represents first person, 1 index represents second and so on).
// Now from our arrays, we can see that for person 3, it doesn't trust on anyone(that's why it's outdegree is 0) and it's indegree is 2 i.e. n - 1 meaning everyone else trusts on him.

// Approach 2 :- Just take one array named count (all elements initialized to 0). It's index will also represent person in town. Take eg :- {{1, 3}, {2, 3}}, we can see that in {1, 3}, 1 is trusting on someone (here 3), hence 1 cannot be judge. But 3 might have a chance to become judge. Hence, make index 1 as -1. Increase 3 by 1. 
// Now for {2, 3}, 2 is trusting on 3, hence 2 cannot be judge. But 3 might have a chance to become judge. Hence, make index 2 as -1. Increase 3 by 1. Vector is exhausted now. Now check in our count vector if someone has n - 1 value. That will be judge.

#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    // Approach 1
    // vector<int> indegree(n + 1, 0), outdegree(n + 1, 0);

    // for (vector<int> &vec : trust) {
    //     int u = vec[0];
    //     int v = vec[1];

    //     outdegree[u]++;
    //     indegree[v]++;
    // }

    // for (int i = 1; i <= n; i++) {
    //     if (indegree[i] == n - 1 && outdegree[i] == 0) {
    //         return i;
    //     }
    // }

    // return -1;


    // Approach 2
    vector<int> count(n + 1, 0);

    for (vector<int> &vec : trust) {
        int u = vec[0];
        int v = vec[1];

        count[u] = -1;
        count[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (count[i] == n - 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << findJudge(3, trust) << endl;
    return 0;
}