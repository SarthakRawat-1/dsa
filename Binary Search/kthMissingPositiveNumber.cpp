// Problem Statement :- https://leetcode.com/problems/kth-missing-positive-number/description/

// Brute Force :- Sequentially check each positive number, counting how many of them are missing from the input array. 
// We iterate through all positive numbers starting from 1. For each number, we check if it's present in the input array. If the number is missing, we increment a counter. Once the counter reaches k, we've found the Kth missing positive number.

// Optimal Approach :- Consider eg :- {2, 3, 4, 7, 11, 12}, now assume, all of the elements we needed, were there i.e., we had :- {1, 2, 3, 4, 5, 6}
// So now we can make out that till zeroth index, one number was missing (as it is 2 but it should have been 1), till second index, one number is missing (as 2, 3 and 4 are present in the array, so only 1 is missing), but till third index, we have 3 numbers missing (as 5 and 6 are not present in the array), till fourth index, we have 6 numbers missing (as 8, 9 and 10 are not present in the array) and till the last index, we have 6 numbers missing (12 is present so it is not missing). Hence, we got :- {1, 1, 1, 3, 6, 6}
// We can generate that array using :- arr[i] - i - 1 
// With our newly formed sequence, we can guess, where the Kth missing number would be. Let's say we had k = 5, so now it's obvious that in this :- {1, 1, 1, 3, 6, 6} it should be between 3 and 6 i.e. between 7 and 11, there is going to be our 5th missing positive integer. Which we can easilly find by adding one to 7 till we get our result or by subtracting one from 11 till we get our result.
// But how do we find the index of 7 or 11? Use the array {1, 1, 1, 3, 6, 6} and find if k = 5 was present in the array, where would it's correct position be if arr was sorted. Obv it would be :- {1, 1, 1, 3, 5, 6, 6}, with this we have got the index of 11. Now obv, here also we also want the first occurence of number greater than or equal to k.

#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    // 'start' and 'end' pointers for binary search
    int start = 0, end = arr.size() - 1;

    // Variable to store the potential answer index.
    // If no valid mid is found during the binary search, 'ans' defaults to arr.size()
    int ans = arr.size();

    // Binary search loop
    while (start <= end)  {
        // Calculate the middle index to split the search space.
        int mid = start + (end - start) / 2;

        // The number of missing elements before index 'mid' is calculated as:
        // arr[mid] - (mid + 1), because the number at index 'mid' should have been mid + 1
        // if there were no missing elements.
        // For example, if arr[mid] is 4 at index 2, and no elements were missing, 
        // the value should have been 3 at index 2.
        // Therefore, the number of missing elements before 'mid' is arr[mid] - (mid + 1).
        // Now, we check if the number of missing elements till 'mid' is greater than or equal to 'k'.
        if (arr[mid] - mid - 1 >= k) {
            // If the number of missing elements is >= k, 
            // the Kth missing positive number must be somewhere before or at 'mid'.
            // So, we record 'mid' as a potential answer and continue searching in the left half.
            ans = mid;
            end = mid - 1;  // Shrink the search space to the left half
        } else {
            // If the number of missing elements is less than 'k', 
            // the Kth missing positive number must be in the right half.
            // So, we adjust 'start' to search in the right half.
            start = mid + 1;
        }
    }       

    // Why do we return 'ans + k'?
    // 'ans' is the first index where the number of missing elements before 'mid' is >= k.
    // If we never find such an index, 'ans' remains as 'arr.size()'.
    // The value of 'ans' gives us an idea of where the Kth missing number would be.
    // If 'ans == arr.size()', it means that the Kth missing number lies beyond the last element of the array.
    // So we directly calculate it as if the entire array were filled with consecutive numbers.
    
    // The Kth missing number can be found by taking the index 'ans' (the first place where the missing number count is >= k)
    // and adding 'k'. This works because we are counting from 1 and shifting by 'k' missing numbers. The formula helps 
    // us get the correct Kth missing number even when we surpass all elements of the array.
    
    return ans + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11, 12};
    int k = 5;
    int ans = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << ans << endl;
    return 0;
}