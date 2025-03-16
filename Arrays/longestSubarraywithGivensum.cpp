// Problem Statement: Given an array and a sum k (positive or negative), we need to print the length of the longest subarray that sums to k.

// A terrible way to solve this is to generate all possible subarrays and calculate their sums. If the sum is equal to k, we will consider its length. Among all such subarrays, we will consider the maximum length by comparing all the lengths.
// To understand this approach more in detail, or even how to generate every subarray, check this out on A2Z Sheet.
// There's another approach which optimizes this and uses only two for loops instead of three for loops. For this too, check A2Z sheet.

// A better approach is to use Hashing. Let's say you have an array. Now we have something to point to a particular element. Now we can calculate Prefix sum which is sum of all elements before this particular element and as well as this particular element. Now, we need to find out how many subarrays will have this particular element as their last index. Once is just the particular element istself. One can be this element, with the element before it. Another one is this particular element and two elements before it and so on.
// Now if we assume that there does exists a subarray which sum is k and last index is the particular element. 
// For simiplicity, assume we had an array of some number of elements and our paarticular element is 6th element i.e. index 5. We found a subarray, index 3 to index 5 whose sum is k. Now the prefix sum to 5 we say it's x. So, now we can infer that sum of elements from 0 index to 2 index will be x - k.
// Using this reasoning in the reverse, we will say that for this particular element, if anywhere previously, we got a sum of x - k, then the rest will be k

// Dry Run to Understand this better :- Take a hash map. Let's say we have this array :- {1, 2, 3, 1, 1, 1, 1, 4, 2, 3}, Let's say k = 3. This hash map will store the prefix sum at every index of array.
// Initially we are at first element, Intially sum is 0. As initially we have not found a subarray which has sum as k, so it's zero. As first element is 1 so sum is now 1. Now, next element is 2, so sum now becomes 3, which is equla to k, so the first two elements are a subarray whose sum is k. So their length we can record now in maxLen, which will be 2, the first element and the second element.
// Now when we come at second index, we have a 3 there, so prefix sum becomes 6. But we know that till first index we already got a 3 (we can find this in our code from the starting point index), so there is a subarray with sum k which happens to be just our 3rd element i.e element at index 2 (this we can find in our code by subtracting indexes of the x - k subarray and x subarray). So, length of that subarray is 1. But this is not greater than 2, so we don't change maxLen.
// Now we check element at index 3, which is 1, so now prefix sum becomes 7. Now for someone to be be equal to 3 i.e. k, someone from the start has to be 4 i.e. x - k, but this subarray we don't have from the start till index 3. So again, index is increased.
// Now element at index 4 is also 1, prefix sum becomes 8. Now for someone to be equal to 3 i.e. k, someone from the start has to be 5 i.e. x - k, but this subarray we don't have from the start till index 4. So again, index is increased.
// Element at index 5 is 1, prefix sum becomes 9. Now for someone to be equal to 3 i.e. k, someone from the start has to be 6 i.e. x - k, which we can see from our has map, does happen, sum 6 happens at index 2. S0, the remaining i.e. index 3 to index 5 will be k i.e. 3. This subarray length is 3, which is bigger than our previous maxLen, so update that.
// Do this for the rest of elements. Return maxLen at the end.

// The approach of using a prefix sum map ensures that we find the longest subarray with the target sum k from anywhere in the array, not just starting from the first index. 

#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    // Step 1: Get the size of the array
    int n = a.size(); // n is the size of the input array 'a'.

    // Step 2: Declare a map to store the prefix sum and corresponding index.
    // The map will store key-value pairs: prefix sum as the key and the index where that sum occurs as the value.
    map<long long, int> preSumMap;

    // Step 3: Initialize prefix sum and maximum length variables.
    long long sum = 0;  // sum will store the cumulative sum (prefix sum) as we iterate through the array.
    int maxLen = 0;     // maxLen will store the length of the longest subarray that sums to 'k'.

    // Step 4: Iterate through the array to calculate the prefix sum at each index.
    for (int i = 0; i < n; i++) {
        // Add the current element a[i] to the prefix sum.
        sum += a[i];

        // Step 5: If the current prefix sum equals 'k', update the maximum length.
        // This means that the subarray from index 0 to i has sum k.
        if (sum == k) {
            // The length of the subarray from index 0 to i is (i+1), so update maxLen.
            maxLen = max(maxLen, i + 1);
        }

        // Step 6: Calculate the sum of the remaining part, which is (sum - k).
        // This tells us if there is a subarray that when removed from the prefix sum, the remaining sum equals 'k'.
        long long rem = sum - k;

        // Step 7: If the remaining sum (rem = sum - k) is found in the map, 
        // it means that there is a subarray between preSumMap[rem] + 1 and i whose sum is equal to 'k'.
        if (preSumMap.find(rem) != preSumMap.end()) {
            // The length of that subarray is (i - preSumMap[rem]).
            int len = i - preSumMap[rem];
            // Update maxLen if the length of this subarray is greater than the previous maximum.
            maxLen = max(maxLen, len);
        }

        // Step 8: Finally, update the map if the current prefix sum has not been seen before.
        // We only insert the first occurrence of the prefix sum because we want to maximize the length of the subarray.
        // Inserting the earliest index ensures that the length (i - preSumMap[rem]) is maximized.
        // Eg :- Say you have {2, 0, 0, 3} and k = 3. Now prefix sum at every index is 2 aside from the last index where it is 5. Now, due to this, we can update prefix sum corresponding index value in our map.
        // Eg continued :- Intially prefix sum was 2 and index 0, this was stored in map. Then prefix sum 2 and index 1 which overwrites the previous value. Then prefix sum 2 and index 2, which overwrites the previous one. And finally, prefix sum 5 and index 3 makes a new entry. So, now when we try to find n - x for this, it will tell us that till index 2, we have sum n - x, which is true but not what we want as we want the maximum length. So what we want is to find the maximum length which means, the entry in our map for prefix sum 2 should never have been updated. this way, now we will find that subarray for n - k is just the first element. Subarray for k is from index 1 to index 3.
        // This is how we can ensure that our approach works even for zeros and negative numbers in the array.
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    // Step 9: Return the maximum length of the subarray whose sum is 'k'.
    return maxLen;
}

int main() {
    vector<int> a = {2, 3, 5, 1, 9};

    // Target sum 'k'.
    long long k = 10;

    int len = getLongestSubarray(a, k);

    // Print the result.
    cout << "The length of the longest subarray is: " << len << "\n";

    return 0;
}

// This is the optimal approach to solve this problem if array has both positives and negatives.
// But if array does not contain zero or negative numbers a better approach is using 2 pointers method.

// The thought process in this is that as you go right in the array, the sum will keep increasing and at one point, it'll become bigger than k. So in this case, we will try to trim down the subarray by removing initial elements i.e. leftmost elements

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray that sums to k
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // Get the size of the array

    int left = 0, right = 0; // Initialize two pointers for the sliding window
    long long sum = a[0]; // Start with the first element as the initial sum
    int maxLen = 0; // Variable to store the maximum length of the subarray

    // Loop until the right pointer crosses the last index
    while (right < n) {
        // Inner loop to reduce the subarray from the left
        // until the sum is less than or equal to k
        while (left <= right && sum > k) {
            sum -= a[left]; // Subtract the element at the left pointer from the sum
            left++; // Move the left pointer to the right
        }

        // Check if the current sum is equal to k
        if (sum == k) {
            // Update maxLen if the current subarray length is greater
            maxLen = max(maxLen, right - left + 1);
        }

        // Move the right pointer forward
        right++;
        // If the right pointer is still within bounds, add the new element to the sum
        if (right < n) sum += a[right];
    }

    // Return the maximum length found
    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9}; 
    long long k = 10; // Target sum
    int len = getLongestSubarray(a, k); 
    // Output the result
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
