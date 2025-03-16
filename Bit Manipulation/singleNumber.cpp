// Problem Statement :- https://leetcode.com/problems/single-number/description/

// We can solve this using the properties of XOR :-
// 1. Identity Property: x ^ 0 = x
// 2. Self-Inverse Property: x ^ x = 0
// 3. Commutative and Associative :- The order in which XOR operations are performed does not matter
// Hence, if we do XOR of all the elements in the array, then the element that appears only odd number of times (here 1) will be the only one left as the result.

#include <vector>
#include <iostream>
using namespace std;

// Function to find the single number using XOR
int singleNumber(vector<int>& nums) {
    int result = 0; // Initialize result to 0
    
    // XOR all elements in the array
    for (int num : nums) {
        result ^= num; // XOR each element with the result
    }
    
    // After the loop, all pairs will cancel out and only the single number will remain in result
    return result;
}

int main() {
    vector<int> nums1 = {2, 2, 1};
    cout << "The single number in nums1 is: " << singleNumber(nums1) << endl; // Output: 1

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "The single number in nums2 is: " << singleNumber(nums2) << endl; // Output: 4

    vector<int> nums3 = {1};
    cout << "The single number in nums3 is: " << singleNumber(nums3) << endl; // Output: 1

    return 0;
}
