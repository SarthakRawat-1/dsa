// Problem Statement :- https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int start = 0; // Start of the sliding window
    int maxLen = 0; // Maximum length of valid subarray
    unordered_map<int, int> basket; // Keeps count of each fruit type in the window

    // Iterate through the fruits with the end of the window
    for (int end = 0; end < fruits.size(); ++end) {
        basket[fruits[end]]++; // Add current fruit to the basket

        // If we have more than 2 types of fruits, shrink the window from the left
        while (basket.size() > 2) {
            basket[fruits[start]]--; // Remove one occurrence of the fruit at start
            if (basket[fruits[start]] == 0) {
                basket.erase(fruits[start]); // Remove fruit type if count becomes 0
            }
            start++; // Move the start of the window to the right
        }

        // Update the maximum length of valid subarray
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen; // Return the result
}

int main() {
    
}