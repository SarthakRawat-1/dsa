// Problem Statement :- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// We will simplify this a bit. Consider, you have 6 visitors :- 0, 1, 2, 3, 4, 5
// You take 0 and 1, ask 0 if he knows 1 and ask 1 if he knows 0. Now there can be 4 possibilities of answers for both.
// If both say yes and yes, then both can't be celebrity. If both answer no, then also both can't be celebrity, as everyone else should know celebrity. If only one of them say no, and other says yes, then the person saying no, can be a celebrity.
// We can see their answers in our matrix!
// So let's say, 0 is not celebrity. Now, we have 1 and we invite one more, we got 2. So, now we ask the same question to these two. In a similar way, we will eliminate further and find if there is a celebrity or not.
// Once, if there is a visitor left in the end, then we have to do a final check in matrix to ensure that everyone knows him but he doesn't know anyone, to declare him a celebrity.

#include <bits/stdc++.h>
using namespace std;

// Function to determine the celebrity among 'n' people using the matrix 'M'.
int celebrity(vector<vector<int>> &M, int n) {
    stack<int> st;

    // Push all individuals (0 to n-1) onto the stack.
    for (int i = n - 1; i >= 0; i--) {
        st.push(i);
    }

    int first, second;

    // Eliminate non-celebrities using pairwise comparisons.
    while(st.size() > 1) {
        // Pop two individuals from the stack.
        first = st.top();
        st.pop();
        second = st.top();
        st.pop();

        // Check the relationship between 'first' and 'second':
        // If 'first' knows 'second' and 'second' does not know 'first',
        // 'first' cannot be a celebrity. Push 'second' back to the stack.
        if (M[first][second] && !M[second][first]) {
            st.push(second);
        } 
        // If 'first' does not know 'second' but 'second' knows 'first',
        // 'second' cannot be a celebrity. Push 'first' back to the stack.
        else if (!M[first][second] && M[second][first]) {
            st.push(first);
        } 
        // If neither condition is met, both 'first' and 'second' are disqualified.
    }

    // If the stack is empty, there is no potential celebrity.
    if (st.empty()) {
        return -1;
    } 

    // Get the last remaining candidate for celebrity.
    int num = st.top();
    st.pop();

    // Verify the candidate by checking:
    // 1. The candidate should not know anyone (row of candidate should be all 0s).
    // 2. Everyone else should know the candidate (column of candidate should be all 1s, except self).
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        row += M[num][i];  // Count of people the candidate knows.
        col += M[i][num];  // Count of people who know the candidate.
    }

    // A valid celebrity will have row == 0 (knows no one) and col == n - 1 (known by everyone else).
    return row == 0 && col == n - 1 ? num : -1;
}

int main() {
    // Example matrix:
    // M[i][j] = 1 means person 'i' knows person 'j', 0 otherwise.
    vector<vector<int>> M = {{0, 1, 0}, 
                             {0, 0, 0}, 
                             {0, 1, 0}};
    int n = 3; // Number of people.

    // Output the index of the celebrity, or -1 if there is none.
    cout << celebrity(M, n) << endl;

    return 0;
}

