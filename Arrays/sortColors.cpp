// Problem Statement :- https://leetcode.com/problems/sort-colors/description/

// One approach to solve this is by keeping the count of values. Since in this case there are only 3 distinct values in the array so it's easy to maintain the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values.
// Take 3 variables to maintain the count of 0, 1 and 2. Travel the array once and increment the corresponding counting variables. Let's consider count_0 = a, count_1 = b, count_2 = c
// In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {
    // Step 1: Initialize counters for 0's, 1's, and 2's
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    // Step 2: Count the occurrences of 0's, 1's, and 2's in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;  // Count the number of 0's
        else if (arr[i] == 1) cnt1++;  // Count the number of 1's
        else cnt2++;  // Count the number of 2's
    }

    // Step 3: Replace elements in the original array with 0's, 1's, and 2's

    // Replace the first 'cnt0' elements with 0's
    for (int i = 0; i < cnt0; i++) arr[i] = 0;

    // Replace the next 'cnt1' elements with 1's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1;

    // Replace the remaining elements with 2's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2;
}

int main() {
    int n = 6;  
    vector<int> arr = {0, 2, 1, 2, 0, 1};  

    // Step 5: Call the function to sort the array
    sortArray(arr, n);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;

    return 0;
}

// However there is a more optimal way to solve this problem. This problem is a variation of the popular Dutch National flag algorithm. 
// This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules. The rules are the following :-
// 1. arr[0….low-1] contains 0. [Extreme left part]
// 2. arr[low….mid-1] contains 1.
// 3. arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
// The middle part i.e. arr[mid….high] is the unsorted segment.
// So obv if the entire array is unsorted, then mid will point to the first element and high will point to the last element. low will also point to first element of array.
// Now, a[mid] can be 0, 1 or 2
// Now if a[mid] is 0, we know from rules, that the left portion of mid contains elements in sorted order. So 0 should come somewhere on the left. We swap zero with the element pointed by low. Becuase by defintion, low index is from where our 1 start. Eg :- {0, 0, 0, 1, 1, 0, 0, 2} In this our mid is at index 5. Now after swapping we got :- {0, 0, 0, 0, 1, 1, 0, 2} So now we can observe, we have a larger sorted portion now. Now mid will point to mid + 1 i.e. 6. Now we will also increase low, becuase low should only point to first 1 in our array.
// If a[mid] is 1, then by defintion, we know elements before mid are sorted, and element just before mid is 1. So we can just increase the mid to point to the next element and there is no need of swapping.
// If a[mid] is 2, then by defintion, we know elements starting from high + 1 contains 2. So, we will swap this 2 with place of element pointed by high which points to last unsorted element. Eg :- {0, 0, 1, 1, 2, 0, 2, 2, 2} So in this case mid is pointing to index 4 adn high is pointing to index 5. We swap both and we get :- {0, 0, 1, 1, 0, 2, 2, 2, 2} Now we can observe that arr[high+1….n-1] has become bigger. high now needs to be decreased, but mid will remain same. In this case now, mid and high will point to the same element. So now we know, even if both are equal, we have to consider that part as unsorted.

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {
    // Step 1: Initialize three pointers: 
    // 'low' for tracking 0's, 'mid' for current element, 'high' for tracking 2's
    int low = 0, mid = 0, high = n - 1;

    // Step 2: Traverse the array using the mid pointer until it crosses high
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Case 1: If current element (arr[mid]) is 0, swap it with the element at 'low' pointer
            swap(arr[low], arr[mid]);
            low++;  // Increment 'low' pointer to point to the next position
            mid++;  // Increment 'mid' to process the next element
        }
        else if (arr[mid] == 1) {
            // Case 2: If current element is 1, no need to swap, just move 'mid' pointer to the next element
            mid++;
        }
        else {
            // Case 3: If current element is 2, swap it with the element at 'high' pointer
            swap(arr[mid], arr[high]);
            high--;  // Decrement 'high' pointer to point to the next potential 2
            // Do not increment 'mid' because the swapped element from 'high' needs to be checked
        }
    }
}

int main() {
    int n = 6;  
    vector<int> arr = {0, 2, 1, 2, 0, 1};  

    sortArray(arr, n);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;

    return 0;
}
