// Problem Statement :- https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/

// Fromm nums array, we will try to turn other values into the one which is around the mid of all i.e. avoid extreme low or extreme high values. This will minimize the operations needed overall. 
// This mid we can find, by finding the biggest value (right) and smallest value (left). Now use binary search to find mid. But now, how do we know which half to eliminate??
// Let's say we have :- nums = {1, 3, 5, 2} and cost = {2, 3, 1, 14}, we get left = 1 and right = 5 and mid becomes 1 + (5 - 1)/2 = 3
// This means, we will try to make all other 3. Now find cost for making this, it will be 4 + 0 + 2 + 14 = 20. Now, we will check (mid - 1) and (mid + 1) values. It is 2 and 4 respectively. 
// We will first check value for (mid + 1) i.e. 4,  this will tell if we should go to right half or not, if we get a greater cost here, we will directly go to left half. 
// We will check costs for turning every value to 4, it will be :- 6 + 3 + 1 + 28 = 38, which increases cost. So, we should not eliminate left half and go right.
// We will now directly go to left half and check for in array 1 to (mid - 1) i.e. {1, 2} which gives mid as 1 + (2 - 1)/2 = 1, we get :- 0 + 6 + 4 + 14 = 24. Now, (mid + 1) and (mid - 1) for this, as well. For (mid + 1), we get 1 + 1 = 2.
// For 2, we get cost :- 2 + 3 + 3 + 0 = 8, which is smaller than 24. So, now we go to right half i.e. left is moved to 2. But from {1, 2}, the right was also aready at 2, so mid will also be 2.
// Now, for (mid + 1) i.e 3, we already know it's cost (which is greater than that at 2). So, we go left half, but if we do, right will come before left, breaking the binary search loop.
// Cost we will store as min of costs for mid or (mid + 1) or (mid - 1), even for further iterations.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate the total cost of converting all elements in nums
// to the value 'mid', using the corresponding weights in the cost array.
ll findCost(vector<int>& nums, vector<int>& cost, int mid) {
    ll result = 0;

    // Iterate through the nums array and calculate the cost for each element
    for (int i = 0; i < nums.size(); i++) {
        result += (ll) abs(nums[i] - mid) * cost[i];
    }

    return result;
}

// Main function to find the minimum cost to make all elements in nums equal
long long minCost(vector<int>& nums, vector<int>& cost) {
    ll answer = INT_MAX; // Initialize the answer with the maximum possible value

    // Find the smallest (left) and largest (right) values in the nums array
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());

    // Perform binary search on the range [left, right]
    while (left <= right) {
        // Calculate the midpoint of the current range
        int mid = left + (right - left) / 2;

        // Calculate the cost for making all elements equal to mid
        ll midcost = findCost(nums, cost, mid);

        // Calculate the cost for making all elements equal to mid + 1
        ll rightCost = findCost(nums, cost, mid + 1);

        // Update the answer with the minimum cost found so far
        answer = min(midcost, rightCost);

        // Decide which half of the search space to explore next:
        // - If the cost for mid + 1 is greater than the cost for mid,
        //   the minimum cost must lie in the left half (move 'right').
        // - Otherwise, explore the right half (move 'left').
        if (rightCost > midcost) {
            right = mid - 1; // Narrow the range to [left, mid - 1]
        } else {
            left = mid + 1;  // Narrow the range to [mid + 1, right]
        }
    }

    // Return the minimum cost found
    // If answer remains INT_MAX, it means no valid conversion was possible (edge case)
    return answer == INT_MAX ? 0 : answer;
}

int main() {
    // Test case: nums array and corresponding costs
    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};

    // Output the minimum cost to make all elements equal
    cout << minCost(nums, cost) << endl;

    return 0;
}
