// Problem Statement :- https://leetcode.com/problems/majority-element-ii/description/

// This is a variation/extension of majorityElement.cpp

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size(); // Get the size of the input array

    // Step 1: Initialize two potential majority elements and their counts
    // Majority elements are those that appear more than ⌊ n/3 ⌋ times, so at most, 
    // there can be two such elements in any array of size n.
    int maj1 = INT_MIN; // First potential majority element (initially an invalid value)
    int count1 = 0;     // Count for the first candidate

    int maj2 = INT_MIN; // Second potential majority element (initially an invalid value)
    int count2 = 0;     // Count for the second candidate

    // Step 2: First Pass - Identify two possible majority element candidates
    // We use the Boyer-Moore Voting Algorithm extension for the majority element.
    // The key idea is to find two candidates that might be the majority elements.
    for(int i = 0; i < n; i++) {
        if(nums[i] == maj1) {
            // If the current element matches maj1, increment count1
            count1++;
        } else if(nums[i] == maj2) {
            // If the current element matches maj2, increment count2
            count2++;
        } else if(count1 == 0) {
            // If count1 is zero, set nums[i] as the new maj1 candidate and set count1 to 1
            maj1 = nums[i];
            count1 = 1;
        } else if(count2 == 0) {
            // If count2 is zero, set nums[i] as the new maj2 candidate and set count2 to 1
            maj2 = nums[i];
            count2 = 1;
        } else {
            // If nums[i] does not match either maj1 or maj2 and both counts are non-zero,
            // decrement both counts (think of these as votes being canceled out)
            count1--;
            count2--;
        }
    }

    // After the first pass, maj1 and maj2 hold the two most likely candidates for the majority elements.
    // However, we need to verify if they actually appear more than ⌊ n/3 ⌋ times.

    // Step 3: Reset counts to verify the actual frequency of maj1 and maj2
    count1 = 0;
    count2 = 0;

    // Count occurrences of maj1 and maj2 in the array to confirm if they are indeed majority elements
    for(int num : nums) {
        if(num == maj1) {
            count1++;
        } else if(num == maj2) {
            count2++;
        }
    }

    // Step 4: Prepare the result based on the counts
    // We know that at most two elements can have a frequency greater than ⌊ n/3 ⌋, so our result can hold up to two elements.
    vector<int> result;
    if(count1 > n / 3) {
        // If maj1 occurs more than ⌊ n/3 ⌋ times, it's a majority element
        result.push_back(maj1);
    }
    if(count2 > n / 3) {
        // If maj2 occurs more than ⌊ n/3 ⌋ times, it's a majority element
        result.push_back(maj2);
    }

    return result; // Return the list of majority elements found
}

int main() {
    vector<int> nums = {3, 2, 3, 4, 4, 4, 5}; 
    vector<int> result = majorityElement(nums); 

    cout << "Elements that appear more than ⌊n/3⌋ times are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
