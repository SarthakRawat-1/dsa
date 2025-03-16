// Problem Statement :- https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// Brute Force Approach 1 :- If an element appears twice, then either the element before or after it will be same as that element. But for single element, this condition will not be satisfied. So, just check the condition  arr[i] != arr[i-1] and arr[i] != arr[i+1] :- If this condition is true for any element, arr[i], we can conclude this is the single element.
// Edge Case 1 :- If n == 1 :- This means the array size is 1. If the array contains only one element, we will return that element only. 
// Edge Case 2 :- If i == 0 :- This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1]
// Edge Case 3 :- If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1]

// Optimal Approach :- Let's say you have 4 elements in an array and you are checking for i = 0. We have 3 elements (odd) on our right side, so once we check if element at i = 1 is equal to one at i = 0, then it is paired. So now, we only have 2 elements left, which must be equal to one other, otherwise we will have two elements which appear only once, which can't be our input as per the problem statement.
// But let's say we had 5 elements in array. And elements at index 0 and 1 are paired. 3 elements are left now (odd), so now we know that our single element will be present at one of these three indexes.
// With this knowledge, we can eliminate the half space, which we know can't have that element.
// This can be generalized for any index other than 0 and 1.
// Consider the eg where element at i is not equal to one at i + 1. After i there are odd number of elements left. In this case, the single element must be on the right side.

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize low and high pointers for binary search.
        int l = 0;
        int h = n - 1;
        
        // Binary search loop.
        while (l < h) {
            // Find the middle index.
            int mid = l + (h - l) / 2;

            // Check if the number of elements on the right side of mid is even.
            bool isEven = (h - mid) % 2 == 0;

            // Case 1: If nums[mid] is equal to nums[mid + 1], check the even/odd condition.
            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    // If the right half is even, move the low pointer to mid + 2 (skip both mid and mid + 1).
                    l = mid + 2;
                } else {
                    // If the right half is odd, move the high pointer to mid - 1 (since the single element must be in the left half).
                    h = mid - 1;
                }
            } 
            // Case 2: If nums[mid] is not equal to nums[mid + 1].
            else {
                if (isEven) {
                    // If the right half is even, the single element is in the left half, so move the high pointer to mid.
                    h = mid;
                } else {
                    // If the right half is odd, the single element is in the right half, so move the low pointer to mid + 1.
                    l = mid + 1;
                }
            }
        }
        
        // When the loop ends, the low pointer will be pointing to the single element.
        return nums[h];
}

int main() {
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4};
    cout << "Single element is " << singleNonDuplicate(nums1) << endl;

    vector<int> nums2 = {1, 1, 2, 2, 3};
    cout << "Single element is " << singleNonDuplicate(nums2) << endl;
}


// Another approach with slightly different logic.

#include <bits/stdc++.h>
using namespace std;

// Function to find the single non-duplicate element in a sorted array
int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); // Get the size of the array.

    // Edge cases:
    // Edge Case 1: If n == 1, return the only element since it is the single non-duplicate.
    if (n == 1) return arr[0];

    // Edge Case 2: If the first element is not equal to the second, return the first element.
    // This means the first element is the single element.
    if (arr[0] != arr[1]) return arr[0];

    // Edge Case 3: If the last element is not equal to the second last, return the last element.
    // This means the last element is the single element.
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    // Initialize binary search boundaries
    int low = 1, high = n - 2; // We check from index 1 to n-2 since edge cases are handled.

    // Binary search to find the single non-duplicate element
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index.

        // Check if arr[mid] is the single element
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid]; // If neither neighbor is equal, return the single element.
        }

        // The code onwards here is based on the logic that we can separate our array into two parts :-
        // Before the single element :- The elements are perfectly paired, meaning: If the index is even, it contains the first occurrence of a pair (e.g., arr[0], arr[2], arr[4],...). If the index is odd, it contains the second occurrence of the pair (e.g., arr[1], arr[3], arr[5],...).
        // After the single element :- The pairing pattern is shifted because of the presence of the single element. The odd/even pairing no longer holds: After the single element, even indices will contain the second occurrence of a pair, and odd indices will contain the first occurrence of a new pair.

        // Then why are we checking if mid is odd or even?
        // In the perfectly paired part (before the single element): If mid is even, the element at mid should be the first occurrence of a pair, and the element at mid + 1 should be its pair. If mid is odd, the element at mid should be the second occurrence of a pair, and the element at mid - 1 should be its pair.
        // By checking whether mid is odd or even, we can figure out if the current mid element is part of a correctly paired section: If mid is even and arr[mid] == arr[mid + 1], then this is a valid pair. If mid is odd and arr[mid] == arr[mid - 1], then this is also a valid pair.
        // If either of these conditions is true, we know that the single element lies in the right half of the array, because the left half (up to mid) is correctly paired.
        // If neither condition is true (i.e., arr[mid] is not equal to its expected pair), we know that the single element lies in the left half of the array, as the mismatch implies we've passed the single element.

        // Determine which half of the array to eliminate based on pairing:
        // If mid is odd and arr[mid] is equal to arr[mid - 1] OR
        // if mid is even and arr[mid] is equal to arr[mid + 1], 
        // we are in the left half of the array with the single element.
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // Eliminate the left half by adjusting the low boundary.
            low = mid + 1;
        }
        // If neither condition is true, we are in the right half.
        else {
            // Eliminate the right half by adjusting the high boundary.
            high = mid - 1;
        }
    }

    // Dummy return statement (should never be reached if the input follows the problem constraints).
    return -1; // Indicates no single element was found (shouldn't happen as per the problem statement).
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}; 

    int ans = singleNonDuplicate(arr); 
    cout << "The single element is: " << ans << "\n"; 

    return 0; 
}
