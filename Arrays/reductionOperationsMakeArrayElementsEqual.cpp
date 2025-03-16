// Problem Statement :- https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

// In problem statement it is given that if there are multiple elements with the largest value, pick the smallest i. However, as we are acounting only the number of operations, it doesn't matter if we pick the smallest i or not.
// We can sort the array. In this way, largest element will be at n - 1 index and second largest at n - 2 index, if both are not equal. If they are equal then find that index from the back, where the second largest becomes different.
// Then we can convert largest number to second largest number, and it will be 1 operation. Continue doing this for rest of the elements.
// Eg :- {1, 3, 5} Sorted order. We take an i pointer at last element. 5 is stored as largest number. Look at i - 1. 3 is stored as second largest number. 3 and 5 are different, so turn 5 into 3. Move i by left. Now 3 is largest num as i is on 3. Look at i - 1, it is 1, which is different than 3, so turn 3 to 1. 
// But now, we also have to make the 3 at last index into 1. So, we can say that when we are converting 3 at i into 1, we would have already converted all elements after it into 3. Now, we need to convert element at i and elements after that into 1 i.e. second largest element. Ofc, all of these require operations, so total (n - i) operations, where n is the size of array.

// If largest and second largest i.e. i and i - 1 elements are equal, move i to left by 1.

#include <bits/stdc++.h>
using namespace std;

int reductionOperations(vector<int>& nums) {
    // Sort the array to arrange elements in ascending order.
    sort(nums.begin(), nums.end());

    // Variable to store the total number of operations required
    int ans = 0;

    // 'n' stores the size of the array
    int n = nums.size();

    // Traverse the array from the end (largest element) to the start
    for (int i = n - 1; i >= 1; i--) {
        // If the current element is equal to the previous one, skip this iteration
        if (nums[i] == nums[i - 1]) {
            continue;
        } else {
            // If the current and previous elements are different,
            // add (n - i) to 'ans', as each difference represents a new "set" of operations
            // needed to reduce all elements from this index onward to the previous smaller value.
            ans += (n - i);
        }
    }

    // Return the total number of operations accumulated
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3};

    cout << reductionOperations(nums) << endl;

    return 0;
}