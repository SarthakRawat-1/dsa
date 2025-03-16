// Problem Statement :- https://leetcode.com/problems/subarray-sum-equals-k/description/

// Brute Force Approach :- We will check the sum of every possible subarray and consider the count of subarrays whose sum is equal to k. Check out A2Z Sheet for this.

// Optimal Approach :- Consider the array :- [1, 4, 1, 2, 6] and k = 3
// Sum of first four elements = 8 and sum of first 2 elements = 5, with this we can deduce that the sum of elements in between (i.e. 3rd and 4th element) will be 3.
// To deduce this, we first find the sum of first n elements (4 in our case) and then check if anytime previous to this element, we are getting a prefix sum such that (prefix sum of n - prefix sum of that number) = k
// In our case :- 8 - 5 gives 3 which is equal to k.
// We will store prefix sum of all elements in a map with the count of occurences of that prefix sum.
// We are given k in question and we also will have prefix sum of the nth element which we are on. Furthermore, we will store prefix sum of previous elements in a map. So we have to find a prefix sum from map such that it is equal to (prefix sum of n - k).

// Consider :- [1, -1] and k = 0, for this we will get the map :- 1 -> 1 and 0 -> 1 and result = 0 but we know that 1 + -1 = 0, so there should be result = 1
// This is a corner case. Here's the catch to solve it.
// The prefix sum when the array has not even started yet is 0. Hence, when we reach -1 and we do 0 - 0 = 0, this 0 prefix sum we have seen once before which happens to be when array has not started. Hence, result should be increased by 1. 
// Hence, to cover such cases, we will initialize our map with 0 -> 1 (i.e. 0 has occured atleast 1 time for all arrays). In our eg :- 0 -> 2 will be stored in our map at last.
// Now let's say we had :- [1, -1, 0] and k = 0, till -1, we know that result = 1 and 0 -> 2 has been stored in our map.
// When we reach the third element i.e. 0 we have 0 - 0 = 0 and we have seen 0 not once but twice before, hence result is now increased by 2. In map, 0 -> 2 is updated to 0 -> 3.

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int result = 0; // Stores the total count of subarrays with sum equal to k
    int sum = 0;    // Running sum of elements as we iterate through the array
    map<int, int> mp; // Map to store the frequency of each running sum
    mp[0] = 1; // Initialize with sum 0 appearing once to handle cases where subarray itself equals k

    int n = nums.size(); // Size of the input array
    for(int i = 0; i < n; i++) {
        // Update the running sum with the current element
        sum += nums[i];

        // Check if there exists a prefix sum such that sum - k exists in the map
        // This indicates there is a subarray ending at the current index with sum equal to k
        if(mp.count(sum - k)) {
            result += mp[sum - k]; // Add the count of such prefix sums to the result
        }

        // Increment the count of the current sum in the map
        // This helps in tracking occurrences of each running sum up to the current index
        mp[sum]++;
    }

    // Return the total count of subarrays found with sum equal to k
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3}; 
    int k = 3; 
    int result = subarraySum(nums, k); 

    cout << "The number of subarrays with sum equal to " << k << " is: " << result << endl;

    return 0;
}
