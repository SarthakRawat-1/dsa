// Problem Statement :- https://leetcode.com/problems/next-permutation/description/

/// Example to understand next permutation :- 
// Input array :- {1,3,2} 
// All possible permutations in lexicographical order (dictionary order) :- {{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}}
// Output array :- {2,1,3} because the enxt permutation just after {1,3,2} is {2,1,3}

// Brute Force Approach :- Find all possible permutations of elements present (see Recursion directory) and store them and then Search input from all possible permutations. Print the next permutation present right after it.

// Other way is to use the inbuilt next_permutation function in C++ STL.

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main() {
//     int arr[] = {1,3,2};
    
//     next_permutation(arr,arr+3);//using in-built function of C++
    
//     cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
//     return 0;
// }


// There isn't a better way to solve this, so now we will see the implementation of the STL function next_permutation
// Let's say you have this :- arr[] = {2, 1, 5, 4, 3, 0, 0}
// Before this let's take a look at Eng Dictionary. Say, you have three words :- raj, rax, rbx. We know raj will appear before both and rax will appear before rax.
// This happens because in both words ra is same, which comes before rb. So we have a long prefix match, then the difference appears. With rbx, only r is common, so we have a shorter prefix match here.
// Now consider our arr, we can see that if we try to make long prefix match by matching all elements aside from the last element (if we match all elements we will get the same number again, which we don't want), we will get {2,1,5,4,3,0} now one element is left which is 0, but we can't rearrange this in any way as it is only a single element.
// Now we try to match everything barring the last two elements. We got this prefix match :- {2,1,5,4,3} Now we have two elements i.e. {0, 0} left, but again if we rearrange we wills till only get {0, 0} so there's no change.
// Now we make the prefix match :- {2,1,5,4} and we have {3,0,0} elements left. We can rearrange this like :- {0,3,0} or {0,0,3} but in both cases, our permutation becomes smaller lexicographically instead of getting bigger. So, this also fails.
// Now prefix match is reduced to :- {2,1,5} and we have {4,3,0,0} elements left. Try rearranging this, and you will notice that no combination makes the permutation greater.
// Prefix match is now :- {2,1} and we have {5,4,3,0,0} elements left. Again, no rearrangement makes the permutation greater.
// We can observe the pattern why we are not getting any combination to make the permutation greater. This is because in {5,4,3,0,0} 5 is greater than 4 which is greater than 3 which is greater than 0
// Prefix match is now only the first element :- {2} and we have {1,5,4,3,0,0} elements left. Now we can observe that 1 is lesser than 5 (and 4 and 3 also). So now, there exists a combination for which the permutation becomes greater, so greater permutation will come at combination :- {2,5,4,3,1,0,0}
// But this is not the next permutation because there also exists {2,4,5,3,1,0,0} which is also greater than the given permutation but lesser than what we found in previous step, which is what we need. Because we want to find the enxt permutation, greater than original permutation but right after that.
// We had prefix match :- {2} rest of the elements we can permute. But we do know that right after {2} we can't have zero because it will mean the permutaion has become smaller. We also can't have one right after {2} because we have already checked for {2, 1} there are no possible permutations for a greater number.
// Hence, we have to get a number greater than {1} on second position. In our case, the best option will be {3} because it is greater than one but less than four or five, the other contenders.
// But now, we can think of making an algorithm :- Why was {2,1,5} not possible as prefix match? because from the rest of elements {4,3,0,0} we needed someone greater than 4 to replace it but it was not present!
// Now by adjusting prefix match we have to find an element such that it is smaller than atleast one other number present in the leftover element array (array aside from prefix match). This is what we refer to as a breakpoint.
// We can find this by using a loop with i and i + 1 and when a[i] < a[i + 1] we have got the breakpoint. In our eg :- i will be 1 as arr[i] = 1 and arr[i + 1] = arr[2] = 5
// Now, we only check i and i + 1 because think abt it, for eg :- You might have the confusion that :- {1, 0, 4, 3, 2} here 1 is greater than 4 but not 0. But observe, 0 is smaller than 4, so for this case, breakpoint is 0 and not 1! Hence, the breakpoint will appear as soon as the next element after it is greater than it.
// Now we have observed that everything after breakpoint, is in descending order. So, to find an element to replace {1} (which in our case the best option is {3}), we will start from the last in {5,4,3,0,0}, iterate over it till you find the first element greater than {1}
// Now, that we have filled {2,3} the rest of the elements {5,4,1,0,0} we have to find appropriate combination for this. We know that {2,3} is greater than {2,1}, so now our next priority is to arrange {5,4,1,0,0} such taht it becomes smallest as possible. So place it like {0,0,1,4,5} which is actually a sorted order!
// What if we there is no breakpoint? Consider {5,4,3,2,1} In this case (descending order), there is no breakpoint. But observe {1,2,3,4,5} there is a breakpoint here at {4,5} because 4 is lesser than 5. So we can have {1,2,3,5,4} as next permutation. Hence, last index to have a breakpoint is n - 2

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // Get the size of the array

    // Step 1: Find the break point
    // A break point is defined as the first index `i` from the back of the array where A[i] < A[i + 1].
    // This is the point where the sequence stops being in descending order from right to left.
    int ind = -1; // Initialize the break point to -1, assuming no break point exists
    for (int i = n - 2; i >= 0; i--) { // Traverse the array backwards from the second last element
        if (A[i] < A[i + 1]) {
            // We have found the break point where A[i] is smaller than A[i + 1]
            ind = i; 
            break;
        }
    }

    // If no break point is found, the array is in descending order.
    // This means the given permutation is the largest possible permutation, and
    // the next permutation is the smallest permutation (i.e., sorted in ascending order).
    if (ind == -1) {
        // Reverse the entire array to return the smallest permutation
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element on the right of the break point
    // We need to find the smallest number greater than A[ind] from the right side of the array.
    for (int i = n - 1; i > ind; i--) { // Start from the last element and move towards the break point
        if (A[i] > A[ind]) {
            // Swap the next greater element with A[ind] to create a valid next permutation
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: Reverse the part of the array after the break point
    // Reversing the right half ensures we get the smallest lexicographical order after swapping.
    reverse(A.begin() + ind + 1, A.end());

    // Return the modified array which now represents the next greater permutation
    return A;
}

int main()
{
    // Input array for which we want to find the next permutation
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};

    // Get the next greater permutation
    vector<int> ans = nextGreaterPermutation(A);

    // Output the result
    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " "; // Print each element of the modified array
    }
    cout << "]\n"; // Newline after printing the array
    return 0;
}


