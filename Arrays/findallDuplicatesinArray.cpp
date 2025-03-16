// Problem Staement :- https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <bits/stdc++.h>
using namespace std;

// ------------------------ Approach 1 ------------------------
// Method 1: Using unordered_map to count frequencies.
// Time Complexity: O(n)
// Space Complexity: O(n) - extra space for the hash map.
vector<int> findDuplicatesMap(vector<int>& nums) {
    // Create an unordered_map to store the frequency of each element.
    unordered_map<int, int> um;
    
    // Iterate over the input vector and count occurrences.
    for (int i = 0; i < nums.size(); i++) {
        um[nums[i]]++;
    }

    // Prepare a vector to store the result (duplicates).
    vector<int> res;

    // Iterate over the map and add the element to the result if its frequency is greater than 1.
    for (auto i: um) {
        if (i.second > 1) {
            res.push_back(i.first);
        }
    }

    return res;
}

// ------------------------ Approach 2 ------------------------
// Method 2: In-place negation technique.
// If we have an array, which has elements from 1 to n, then we can use a specific pattern.
// Use the numbers as index to mark already visited elements.
// Let's say we have :- nums = {4, 3, 2, 7, 8, 2, 3, 1}, then first we have element 4. Size of array, n is 8. But 8 can't act as index.
// We can say that, n - 1 can act as index. First, we got 4, we got 4 - 1 = 3, as index. At 3 index, we have 7, which is not already visited, so we make it negative to mark it that we have visited it.
// Next, we got element 3, 3 - 1 = 2, so we mark index 2 negative. Next we come to element which has become -2. For index calculation, we need it to be positive, which means that we should find index using abs(element) - 1.
// When we get an index whose element is already marked as negative, then it means we have seen that element in abs(element) - 1 before.
// Time Complexity: O(n)
// Space Complexity: O(1) - uses only the output vector and modifies the input array.
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res; // Vector to store duplicates.
    
    // Loop through each number in the array.
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the index corresponding to the current number.
        // The absolute value is used because we may have already negated some numbers.
        int index = abs(nums[i]) - 1;
        
        // If the number at the calculated index is negative, 
        // it indicates that the number (index + 1) has been encountered before.
        if (nums[index] < 0)
            res.push_back(abs(nums[i]));  // Record this duplicate.
        else
            // Mark the number as seen by negating the number at the corresponding index.
            nums[index] = -nums[index];
    }
    return res;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = findDuplicates(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}