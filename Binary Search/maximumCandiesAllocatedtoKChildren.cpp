// Problem Statement :- https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

// Brute Force :-
// We will first identify the maximum pile first. Then while going to each individual pile, if it's less than the max, we can't use it. If we can give, we will reduce the number of children to give.
// If we can't give the maximum, decrease it, and try to give maximum - 1. Continue doing this, till you can allocate candies to every child
// Eg :- candies = {5, 13, 3} and k = 3, for this too, the answer will be 5. Because 5 can be given from first pile. From second pile, 13 - 5 = 8 and again 8 - 5 = 3, so 2 children can be given from this pile.
// A shortcut way to distribute multiple child candies from the same pile (if it indeed has the required amount like above eg) is to simply divide i.e. 13/5 = 2

// Binary Search :-
// We can see that in Brute Force we are lineary trying on different answers (which are also sorted in decreasing order).
// We can use BS on answers.
// Taking example :- candies = {5, 8, 6} and k = 3. Maximum candy is 8 and Minimum candy is 1 obv because we can give everyone 1 candy the least allowed value.
// Now use Binary Search on this, and for this mid, find if this is a valid answer or not. If we can, then we will try with a higher value, so low = mid + 1.
// If we can't, it means that this is not a valid answer, so we will try with a lower value, so high = mid - 1

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/******************************************************************
* Approach-1 (Brute Force)
*
* Time Complexity : O(n * maxC), where maxC is the maximum candy value.
* Space Complexity: O(1)
*
* Detailed Explanation:
* 1. Compute the total number of candies and identify the maximum number
*    of candies in any single pile.
* 2. If the total candies are less than the required number of children (k),
*    return 0 since it's impossible to distribute at least one candy per child.
* 3. Loop from the maximum candy count down to 1. For each candidate value 'c':
*    - For each pile, compute how many children can receive exactly 'c' candies
*      (using integer division).
*    - Sum these values across all piles.
*    - If the sum is at least k, it means it’s possible to give 'c' candies to
*      k children, so return 'c' as the answer.
* 4. If no candidate value is valid, return 0.
******************************************************************/
int maximumCandiesBruteForce(vector<int>& candies, long long k) {
    int n = candies.size();
    int maxC = 0;   // To store the maximum candies in a single pile
    int total = 0;  // To store the total number of candies

    // Calculate total candies and maximum candies in a pile.
    for (int i = 0; i < n; i++) {
        total += candies[i];
        maxC = max(maxC, candies[i]);
    }

    // If there aren't enough candies to distribute at least one per child,
    // return 0.
    if (total < k) {
        return 0;
    }

    // Try each candidate value from maxC down to 1.
    for (int c = maxC; c >= 1; c--) {
        long long count = 0; // Total number of children who can get 'c' candies

        // For every pile, add the number of children that can be served 'c' candies.
        for (int i = 0; i < n; i++) {
            count += candies[i] / c;
        }
        
        // If enough children can be served 'c' candies, return 'c' as the answer.
        if (count >= k) {
            return c;
        }
    }

    return 0;
}

/******************************************************************
* Approach-2 (Binary Search on Answer)
*
* Time Complexity : O(n * log(maxC)), where maxC is the maximum candy value.
* Space Complexity: O(1)
*
* Detailed Explanation:
* 1. First, calculate the total candies and find the maximum number of candies
*    in any pile.
* 2. If the total is less than k, return 0 because distributing at least one candy
*    per child is impossible.
* 3. Apply binary search on the range of possible candies per child (from 1 to maxC):
*    - Calculate mid as the candidate number of candies to distribute.
*    - Use a helper function (canDistribute) to determine if it's possible to give
*      'mid' candies to at least k children.
*    - If it is possible, move the lower bound up to search for a higher valid candidate.
*    - Otherwise, reduce the upper bound.
* 4. The result holds the maximum number of candies per child that can be distributed.
******************************************************************/

// Helper function for binary search approach.
// Determines if it's possible to distribute 'mid' candies to at least k children.
bool canDistribute(vector<int>& candies, int mid, long long k) {
    int n = candies.size();
    // For each candy pile, reduce k by the number of children that can receive 'mid' candies.
    for (int i = 0; i < n; i++) {
        k -= candies[i] / mid;
        // If k is non-positive, it means we can satisfy the distribution requirement.
        if (k <= 0) {
            return true;
        }
    }
    return k <= 0;
}

// Binary search based function to determine the maximum candies per child.
int maximumCandiesBinarySearch(vector<int>& candies, long long k) {
    int n = candies.size();
    int maxC = 0;         // Maximum number of candies in any pile
    long long total = 0;    // Total number of candies

    // Calculate total candies and find the maximum candy value.
    for (int i = 0; i < n; i++) {
        total += candies[i];
        maxC = max(maxC, candies[i]);
    }

    // If there are insufficient candies to give at least one per child, return 0.
    if (total < k) {
        return 0;
    }

    int l = 1, r = maxC, result = 0;
    
    // Binary search for the highest possible candy count per child.
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // If it's possible to distribute 'mid' candies per child,
        // update result and search for a potentially higher value.
        if (canDistribute(candies, mid, k)) {
            result = mid;
            l = mid + 1;
        } else {
            // Otherwise, try a smaller value.
            r = mid - 1;
        }
    }

    return result;
}

int main() {
    // Example 1: Basic test case
    vector<int> candies1 = {2, 4, 6, 8, 10};
    long long k1 = 5;

    int result1 = maximumCandiesBinarySearch(candies1, k1);
    cout << "Result (Binary Search): " << result1 << endl;

    return 0;
}