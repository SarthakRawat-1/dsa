// Problem Statement :- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

// Brute Force :- Try diff combiantions of picking a elements from front and k - a elements from back.
// Optimized Approach :- Take all k cards from the left for the starting sum (leftSum). Maintain a rightSum starting from 0. In each step, remove the least significant left card, and add a new card from the right end. Update the best score among all those transitions.

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    // Edge case: if k equals total cards, take all cards
    if (k == n) {
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);
    }

    // 1. Compute initial sum by taking the first k cards from the left
    int leftSum = 0;
    for (int i = 0; i < k; ++i) {
        leftSum += cardPoints[i];
    }

    // Initialize rightSum (points from taken cards on the right),
    // as well as the maximum answer so far
    int rightSum = 0;
    int maxPoints = leftSum;

    // 2. Slide: repeatedly shift one card from left->right
    // We'll remove cards from the left end of our initial selection,
    // and add cards from the right end of the array instead
    int rightIndex = n - 1;
    for (int leftIndex = k - 1; leftIndex >= 0; --leftIndex) {
        leftSum -= cardPoints[leftIndex];         // give up one card from the left
        rightSum += cardPoints[rightIndex--];     // take one additional from the right
        maxPoints = max(maxPoints, leftSum + rightSum);  // track the best total
    }

    return maxPoints;
}

int main() {

}