// Problem Statement :- https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Say you have :- {3, 1, 2, 4}, whichever subset has 1, it's min will always be 1 regardless of other elements.
// Eg :- {0, 3, 4, 5, 2, 3, 4, 1, 4} Consider 2, expand range on both sides till which 2 is minimum. Son, on left side range will go till 3, and on right it can go till 4.
// We got {3, 4, 5, 2, 3, 4} which index range is 1 to 6 (original arr idx). All subarr of this which include 2, will have minimum as 2.
// But how do we find such subarrays? Simply count no to the left of 2 and no to the right of 2. Add 1 separately to both and multiply. In our case :- (3 + 1) * (2 + 1)
// Do this for other elements too. For eg :- Let's consider 3 at idx 5. Can't expand on left and can expand only once on right, so we got {3, 4}.
// Then for this :- (0 + 1) * (1 + 1) = 2
// Btw instead of counting this again and again. We can make arr, which store idx of next smaller elements for each elements in both directions. Use -1 if u can't find.
// Using this we can easily multiply the corresponding no for same element (not even need to do +1), to get the no of subarrays for that element. Yeah just make sure we are storing idx, so we have to calc no on either side by ourselves.
// They will contribute :- no of subarrays * no itself

// Edge Case :- Say we have :- {2, 6, 2, 4, 2} we consider for mid 2
// We get the entire arr itself, so we have (2 + 1) * (2 + 1) = 9
// But then u go and find for first 2, we again get the entire arr and for this (0 + 1) * (4 + 1) = 5 But this will give rise to some duplicates.
// So to avoid duplicates 

#include <bits/stdc++.h>
using namespace std;

// Find "Nearest Smaller to Left" (NSL) for every element
// For each index i, NSL[i] gives the index of the closest element to the left
// which is strictly smaller than arr[i]. If no such element, set -1.
// Similar approach is used in Leetcode-84 (Largest Rectangle in Histogram).
vector<int> getNSL(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        // Pop until we find a smaller element
        while(!st.empty() && arr[st.top()] > arr[i])  // strictly less (<)
            st.pop();
        
        // If stack is empty → no smaller element exists
        result[i] = st.empty() ? -1 : st.top();
        
        // Push current index for future comparisons
        st.push(i);
    }
    return result;
}

// Find "Nearest Smaller to Right" (NSR) for every element
// For each index i, NSR[i] gives the index of the closest element to the right
// which is smaller or equal to arr[i]. If no such element, set n.
// We use <= here to prevent double-counting equal elements (important for duplicates).
vector<int> getNSR(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    
    for(int i = n - 1; i >= 0; i--) {
        // Pop until we find a strictly smaller or equal element
        while(!st.empty() && arr[st.top()] >= arr[i])  // non-strict (<=)
            st.pop();
        
        // If stack is empty → no smaller element exists
        result[i] = st.empty() ? n : st.top();
        
        // Push current index
        st.push(i);
    }
    return result;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    
    // Precompute nearest smaller indices
    vector<int> NSL = getNSL(arr, n); // nearest smaller to left
    vector<int> NSR = getNSR(arr, n); // nearest smaller to right
    
    long long sum = 0;
    int MOD = 1e9 + 7;

    for(int i = 0; i < n; i++) {
        // Distance to nearest smaller element on left
        long long d1 = i - NSL[i];
        
        // Distance to nearest smaller element on right
        long long d2 = NSR[i] - i;
        
        /*
            Explanation:
            - For arr[i], we have d1 choices for where the subarray can start (to the left),
              and d2 choices for where the subarray can end (to the right).
            - That means arr[i] is the minimum in (d1 * d2) subarrays.
            - So its contribution is arr[i] * (d1 * d2).
        */
        long long total_ways_for_i_min = d1 * d2;
        long long sum_i_in_total_ways  = arr[i] * total_ways_for_i_min;
        
        sum = (sum + sum_i_in_total_ways) % MOD;
    }
    return (int)sum;
}

int main() {

}