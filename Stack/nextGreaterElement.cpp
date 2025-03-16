// Problem Statement :- https://www.geeksforgeeks.org/problems/next-greater-element/0

// Brute Force Approach is to use a loop to find the first greatest element to the right, for any element.

// Optimal Approach :-
// Let's say you have :- {8, 6, 4, 7, 4, 9, 10, 8, 12}
// First we put 8, then we take 6, as 6 is less than 8, so we put 6 with 8. Similarly, we put 4 with 8 and 6.
// Finally, when we take 7, 7 is greater than 4, so we remove 4 and 7 is 4's next greater element. Then for 6, 7 is greater than 6, so we remove 6 also and 7 becomes it's next greater element too.
// But as 7 is not greater than 8, we put 7 with 8. now, we have :- {8, 7}
// Similarly, now we will take 4, it's not greater than 9, so we put that. Then comes 9, which is greater than 4, 6 and 8. So 9 becomes next greater element for all of them. They are removed and now we only have 9.
// Continue this till last element (which has no element to it's right, so it's next greater element will be -1), we will get next greater element for all elements.
// This can be solved and simulated using a Stack.
// But if we directly store the element in Stack, we won't know the corresponding index of the element and hence we will not know where to put the next greater element in our answer array.
// Hence, instead of element itself, we will store it's index.

// Another Optimal Approach :-
// We will initialize an array with same size, all elements being -1.
// We will start from the back of given array. We get 12, we hold 12. It can be next greater element of someone. Then we get 8, as 12 is greater than 8, so second last element of our formed array is updated with 12. We will write 8 before 12 now.
// After this, we get 10, as 8 is smaller than 10, so we remove 8. But as 12 is greater than 10, so we get next greater element for 10 also (update value in array). Write 10 before 12 now. 
// Continue doing this for other elements.

#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
// Function to find the next greater elements for each element in the array
vector <long long> nextLargerElement(vector<long long> &arr, int n) {
    // Initialize result array with -1 for all elements
    vector <long long> ans(n, -1);

    // Stack to store indices of elements
    stack <int> st;

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is greater than element at index stored in stack
        while (!st.empty() && arr[st.top()] < arr[i]) {
            // If yes, update the result for the element at index stored in stack
            ans[st.top()] = arr[i];
            // Remove the index from stack as it's processed
            st.pop();
        }
        // Push current index into stack
        st.push(i);
    }
    
    // Return the result array
    return ans;
}

// Another Optimal Approach
vector <long long> nextLargerElement(vector<long long> &arr, int n) {
    // Initialize result array with -1 for all elements
    vector <long long> ans(n, -1);
    
    // Stack to store indices of elements
    stack <int> st;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Remove elements from the stack that are smaller than the current element
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if (!st.empty()) {
            ans[i] = arr[st.top()];
        }
        
        // Push the current index onto the stack
        st.push(i);
    }

    // Return the result array
    return ans;
}

int main() {
    vector <long long> arr = {8, 6, 4, 7, 4, 9, 10, 8, 12};
    vector <long long> ans = nextLargerElement(arr, arr.size());    

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}