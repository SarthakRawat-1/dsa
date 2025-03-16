// Problem Statement :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// This problem is a variation of maximumDifferencebetweenTwoElements.cpp
// The only difference is that In the stock problem, if there is no positive difference (i.e., no profit can be made), you should return 0 instead of the maximum negative difference.
// The approaches that we have used there can be used here as well.
// But i am going to use a more optimal approach which you can use in the maximumDifferencebetweenTwoElements.cpp as well.

// Optimal Approach :- Traverse the array once. Keep track of the minimum element/price encountered so far. Calculate the difference between the current element and the minimum element. This will calculate the potential profit you would make if you bought at the minimum price and sold on the current day. Keep track of the maximum difference/profit found.

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    // If there's no price data, profit is 0
    if (n == 0) return 0;
    
    int minPrice = prices[0];  // Track the minimum price encountered so far
    int maxProfit = 0;         // Track the maximum profit (or maximum difference)
    
    // Traverse the array of prices
    for (int i = 1; i < n; i++) {
        // Calculate profit by selling at day i and buying at minPrice
        maxProfit = max(maxProfit, prices[i] - minPrice);
        
        // Update minPrice to the smallest price seen so far
        minPrice = min(minPrice, prices[i]);
    }
    
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Maximum profit: " << maxProfit(prices2) << endl;
    
    return 0;
}

// This appraoch ensures that the larger element comes after the smaller element becuas of the way we update the minPrice and calculate the profit during each iteration of the array traversal.
//As we iterate through the array, we first update minPrice if we find a new smaller price. This ensures that when we calculate the potential profit on any day, we are using the smallest price before that day. In other words, you only calculate profit based on prices that occur after the minimum price has been set, ensuring that the "buy" day is always earlier than the "sell" day.
// For each day i, the potential profit is calculated as prices[i] - minPrice. Since minPrice is the lowest price seen up to day i, it always represents a "buy" on a previous or current day, and prices[i] represents a "sell" on the current day. This guarantees that the selling day is after or on the same day as the buying day, but since we only care about the maximum profit, the algorithm effectively ensures that the selling happens after the buying in practice.