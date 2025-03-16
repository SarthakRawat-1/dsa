// Problem Statement :- https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

// The difference between two numbers is even if and only if both numbers have the same parity (both even or both odd).
// We want L (Left Sum) - R (Right Sum) to be even. This requires L and R to have the same parity.
// If S (Total Sum) is even, L and R must be both even or both odd (same parity). Their difference L - R will always be even. All partitions are valid (answer is n-1). 
// This is because the difference L − R can be rewritten as: L − R = (L + R) − 2R = S − 2R. Since S is even and 2R is always even (regardless of R), their difference S − 2R is also even. This holds for any partition because S is fixed, and 2R is always even.
// Thus, all n − 1 possible partitions will result in an even difference.
// If S (Total Sum) is odd, L and R have different parities (Because only Even + Odd can make Odd). Their difference L - R will always be odd. No valid partitions exist (answer is 0).

#include <vector>
#include <iostream>
using namespace std;

int countPartitions(vector<int>& nums) {
    int total_sum = 0;
    // Calculate the total sum of all elements in the array
    for (int num : nums) {
        total_sum += num;
    }
    // If the total sum is odd, no valid partitions exist
    if (total_sum % 2 != 0) {
        return 0;
    }
    // If the total sum is even, all possible partitions are valid
    return nums.size() - 1;
}

// Method 2 :- Using Prefix Sum
int countPartitions(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0; // Edge case (problem states n >= 2, but added for safety)

    // 1. Compute prefix sums
    vector<int> prefix(n);
    prefix[0] = nums[0]; // First element is just nums[0]
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + nums[i]; // Cumulative sum up to index i
    }

    // 2. Total sum is the last element of the prefix array
    int total_sum = prefix[n-1];

    // 3. Iterate through all possible partitions (i ranges from 0 to n-2)
    int valid_partitions = 0;
    for (int i = 0; i < n-1; ++i) {
        int left_sum = prefix[i]; // Sum of left subarray [0, i]
        int right_sum = total_sum - left_sum; // Sum of right subarray [i+1, n-1]

        // 4. Check if the difference (left_sum - right_sum) is even
        int difference = left_sum - right_sum;
        if (difference % 2 == 0) {
            valid_partitions++;
        }
    }

    return valid_partitions;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << countPartitions(nums) << endl;
    return 0;
}