// Problem Statement :- https://leetcode.com/problems/bag-of-tokens/description/

// Let's say we have tokens = {100, 200, 300, 400} and power = 200
// Initially, score will be zero. Greedily, we will try to increase score as much as possible initally.
// So, we can do 200 - 100 = 100, score = 1 and power = 100 left. Next token is 200, hence, we will try to increase power. We will try to increase our power to maximum by taking the biggest token. So, score = 0 and power = 500.
// We have {200, 300} tokens left. 500 - 200 = 300, score = 1 and 300 - 300 = 0, score = 2. So, maximum score = 2

// Hence, we will sort the tokens array in ascending order. In this way, wehn we want to increase power, we will take elements from end of array.
// When we want to increase score, we will start from beginning of array. This is because we want to greedily take smaller tokens to increase score, so that we still have as much power as we can left.

#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int P) {
    // Get the number of tokens
    int n = tokens.size();

    // Sort tokens to facilitate greedy selection of smallest and largest tokens
    sort(tokens.begin(), tokens.end());

    // Initialize current score and maximum score trackers
    int currScore = 0;
    int maxScore  = 0;

    // Use two pointers: l for the smallest token, r for the largest token
    int l = 0, r = n - 1;

    // GREEDY APPROACH:
    // While losing power, we select the smallest token (left pointer)
    // While gaining power, we select the largest token (right pointer)
    while(l <= r) {
        // Check if we can afford the smallest token to increase score
        if(P >= tokens[l]) {
            currScore++; // Increase the score by 1
            maxScore = max(maxScore, currScore); // Update max score if needed
            P -= tokens[l]; // Deduct power equivalent to the smallest token value
            l++; // Move left pointer to the next smallest token
        }
        // If not enough power, check if we can trade score for power
        else if(currScore >= 1) {
            currScore--; // Decrease score by 1
            P += tokens[r]; // Gain power equivalent to the largest token value
            r--; // Move right pointer to the next largest token
        }
        // If neither option is viable, exit the loop as no further moves are possible
        else {
            return maxScore; // Return the maximum score achieved so far
        }
    }
    // Return the maximum score achieved at the end of the process
    return maxScore;
}

int main() {
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    cout << bagOfTokensScore(tokens, power) << endl;
    return 0;
}