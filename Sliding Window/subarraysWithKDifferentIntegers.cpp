// Problem Statement :- https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// Let's say you followed a typical sliding window approach and found a subarray satisfying the condition.
// Use map for elements and their freq.
// Eg :- (1, 2, 1) and k = 2. But it can be that subarrays of this can also satisy the constraint too. 
// Total no of subarrays ending at j = j - i + 1 Here, it is 3 => (2, 1), (1, 2, 1) and (1). But out of these (1) is nto valid, so we simply can't add j - i + 1 to result.
// Now think, if (1, 2, 1) has k distinct elements, then subarrays of this subarrays can atmost contain k distinct elements (i.e. k or less than k).
// But right now, we will still take j - i + 1. What it means is that from the start, find Subarrays with unqiue elements less than or equal to K. This we can find easily using map freq and doing j - i + 1.
// Ofc you have to do it for each subarray ending at j. 
// Ofc if size of map exceeds k, then shrink window from left, till we are back to k size.

// Then do this exact process and find for less than equal to k - 1.
// Then subtract ans for k - 1 from k.

// Btw there is question for Longest Substring with At Most K Distinct Characters, which is literally a subproblem of this.

#include <bits/stdc++.h>
using namespace std;

// Helper function: counts subarrays with at most 'k' distinct integers
int slidingWindow(vector<int> &nums, int k) {
    unordered_map<int, int> mp;  // frequency map of elements in current window

    int n = nums.size();
    int i = 0;   // left pointer of window
    int j = 0;   // right pointer of window
    int count = 0;  // total number of subarrays satisfying condition

    // Expand window with j
    while (j < n) {
        mp[nums[j]]++;   // include nums[j] in the window

        // If distinct elements exceed k, shrink window from left
        while (mp.size() > k) {
            mp[nums[i]]--;       // decrease freq of leftmost element
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);  // remove completely if freq becomes 0
            }
            i++;   // shrink from left
        }

        // All subarrays ending at j and starting from any index in [i, j] are valid
        // So, number of such subarrays = (j - i + 1)
        count += j - i + 1;

        j++;  // move right pointer
    }

    return count;
}

// Main function: counts subarrays with exactly k distinct integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    // Trick: exactly k = (at most k) - (at most k-1)
    return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
}

// Second Optimal Approach is One Pass Solution instead of Two Pass.
// Say you have :- A = [3, 1, 2, 1, 1, 2] and k = 2
// Let's say you have i at 4 and j at 5, you have [1, 2], this is the smallest possible valid subarr.
// But this can be expanded towards left till i = 1, on by one, this is the longest possible index till where it can be extended. i = 1 and j = 5 gives the longest subarr.
// So, we got new subarr [1, 1, 2], [2, 1, 2, 2] and [1, 2, 1, 1, 2], hence, 3 more subarrays which is i at lowest - i at longest. These are the extra subarr besides the shortest one.
// So, take three var this time, i, j and i_biggest (all initialized with 0). Map for freq tracking. Imp size < k, then move j. If mp size equal to k, this is valid subarr so add (i - i_biggest) + 1 to result.
// After this you can move j, but whenever map size = k, we try to shrink from left using i to find smallest valid subarr ending at that j. 
// int subarraysWithKDistinct(vector<int>& nums, int k) {
//     int n = nums.size();
    
//     unordered_map<int, int> mp;  // frequency map of elements in the current window
    
//     int i_chota  = 0;  // left pointer that shrinks duplicates (keeps window "minimal")
//     int j        = 0;  // right pointer, expands window
//     int i_bada   = 0;  // left pointer that resets when distinct count > k
    
//     int result   = 0;  // final answer
    
//     while (j < n) {
//         mp[nums[j]]++;  // include nums[j] into window
        
//         // Case 1: Too many distinct → shrink from left
//         while (mp.size() > k) {
//             mp[nums[i_chota]]--;         // decrease freq of nums[i_chota]
//             if (mp[nums[i_chota]] == 0) {
//                 mp.erase(nums[i_chota]); // remove if freq becomes 0
//             }
//             i_chota++;      // shrink window
//             i_bada = i_chota; // reset i_bada (since distinct count was broken)
//         }
        
//         // Case 2: Remove duplicates from left (to make window "tight/minimal")
//         // Example: if window = [1,2,1] and k=2, 
//         // we don't need the first 1, so shrink i_chota forward.
//         while (mp[nums[i_chota]] > 1) {
//             mp[nums[i_chota]]--;  // remove extra occurrence
//             i_chota++;
//         }
        
//         // Case 3: If window has exactly k distinct
//         // Then every subarray starting from [i_bada … i_chota] and ending at j is valid
//         if (mp.size() == k) {
//             result += i_chota - i_bada + 1;
//         }
        
//         j++; // expand window to the right
//     }
    
//     return result;
// }

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << subarraysWithKDistinct(nums, k) << endl;  
    // Expected output = 7
    // Explanation: The 7 subarrays are 
    // [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,3]
}