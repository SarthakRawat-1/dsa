// Problem Statement :- https://leetcode.com/problems/majority-element/description/

// A very simple way to solve this problem is to run a loop to select all elements one by one and then, for every element,  run another loop and count its occurrence in the given array. If any element occurs more than the floor of (N/2), we will simply return it.
// A better way to do this will be to use a Hashmap. Use a hashmap and store the key which will be the element of the array and the value which will be the number of times it occurs. Traverse the array and update the value of the key. After that, check if the value for any element/key is greater than the floor of N/2. If yes, return the key, otherwise iterate forward.

// An optimal approach to solve this would be using the Moore’s Voting Algorithm.
// If the array contains a majority element, its occurrence must be greater than the floor (N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 
// After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

// First we will intialize two variables :- Count for tracking the count of element, Element for which element we are counting.
// Intially count is zero and element is not intialized. Then we start iterating, now count is zero. Whenever count is zero, store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1. If they are different decrease the Count by 1.
// This Count doesn't signify the number of occurences of the Element though. It signifies something else.
// Eg :- Say you have {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5} Now intially count = 0 and Element unitialized. Start traversing, Element becomes 7 and count becomes 1, then continue traaversing, count becomes 2, then 1, then 2, then 1 and then 0 finally. Up till this part we have checked the portion {7, 7, 5, 7, 5, 1}. Now observe just this. In this the element 7 appears 3 times, the other elements also appear 3 times. So we can consider that if we only had this array, 7 will not be the majority element as 3 is not greater than N/2 i.e. 6/2
// Now after this Element will be changed to 5, as count was zero. Now after this count becomes 1. But as we move forward again it decreases to 0. This covers the portion :- {5, 7}
// After this again Element will be updated to 5, as the next element is 5. Now after this count becomes 1, then it increased to 2, then decreases to 1, then to 0. This covers the portion :- {5, 5, 7, 7}
// Now again Element will be updated to 5, as the next element is 5. Now after this, count continuosly updates to 4. After this, the iteration has an end. Our Element is 5.
// This element 5 will be the majority element, if there exists a majority element.
// For eg :- If the last portion was {1, 1, 1, 1} instead of {5, 5, 5, 5}, 1 would be stored in Element and complete iteration but it will not tbe the majority element. As we know, 1 appears only 5 times but length of array is 16. So Element has to appear more than 16/2 times to become majority.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    // size of the given array:
    int n = v.size();
    int cnt = 0; // count variable to track the "balance" of the element
    int el; // Element variable to store the candidate for majority element

    // Applying Moore's Voting Algorithm:
    for (int i = 0; i < n; i++) {
        // If the count is 0, we choose the current element as the candidate
        if (cnt == 0) {
            cnt = 1;     // Reset the count to 1 for the new candidate
            el = v[i];   // Set the current element as the candidate
        }
        // If the current element matches the candidate, increment the count
        else if (el == v[i]) cnt++;
        // If the current element is different from the candidate, decrement the count
        else cnt--;
    }

    // Now we need to check if the stored candidate element is actually the majority element:
    int cnt1 = 0;  // Counter for occurrences of the candidate element
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++; // Count how many times the candidate appears in the array
    }

    // If the candidate element occurs more than n/2 times, it's the majority element
    if (cnt1 > (n / 2)) return el;
    // If the candidate is not the majority element, return -1
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    int ans = majorityElement(arr);

    cout << "The majority element is: " << ans << endl;
    return 0;
}
