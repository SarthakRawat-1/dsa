// Problem Statement :- https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

// Let's say we have {2, 3, 5, -4, 6, -2, -8, 9}
// There's no one adjacent to 2, there's 2 adjacent to 3 (same sign, so no need to destroy), 3 adjacent to 5, 5 adjacent to -4 (different signs, so we need to delete both in the result array), but here is a problem. How will we now know that neighbour of 6 is 3, not -4? We can use a neighbour data structure (initialized with only first element).
// Then starting from second element 3, it's neighbour is 2, same sign, so no need to destroy. Update the neighbour variable and append 3 in that such that it becomes {2, 3}. Then go to 5, check neighbour array last element it's 3, same sign. Update neighbour variable with {2, 3, 5}. Then comes -4, check neighbour variable's last element it's 5. Different signs, so pop 5 from neighbour variable and don't append -4 to it. Keep doing this till we reach the end of array (which we have to make beautiful).
// This neighbour data structure will be stack (you can choose vector as well) as it's easier to access and pop the last element in Stack (which is the top element of Stack).
// In the end, take an array of same size as that of Stack and start filling the array in reverse order with elements of Stack (using top()).

#include <bits/stdc++.h>
using namespace std;

// Function to make the array "beautiful" by removing adjacent elements with different signs
vector <int> makeBeautiful(vector <int> arr) {
    // Stack to store elements of the array while checking adjacent pairs
    stack <int> S;

    // Iterate over all elements of the input array
    for (int i = 0; i < arr.size(); i++) {
        // If stack is empty, push the current element (since it has no adjacent neighbor)
        if (S.empty()) {
            S.push(arr[i]);
        } 
        // If the current element is non-negative (positive or zero)
        else if (arr[i] >= 0) {
            // Check the top element of the stack (neighbor)
            // If the top element is also non-negative, there is no need to destroy, push the current element
            if (S.top() >= 0) {
                S.push(arr[i]);
            } 
            // If the top element is negative (opposite sign), pop the top element (destroy both)
            else {
                S.pop();
            }
        } 
        // If the current element is negative
        else {
            // Check the top element of the stack (neighbor)
            // If the top element is also negative, no need to destroy, push the current element
            if (S.top() < 0) {
                S.push(arr[i]);
            } 
            // If the top element is non-negative (opposite sign), pop the top element (destroy both)
            else {
                S.pop();
            }
        }
    }

    // Now we have the "beautiful" stack, we need to convert it into a result array
    vector <int> ans(S.size());  // Create a result vector of the same size as the stack
    int i = S.size() - 1;        // Start filling the result vector from the last index

    // Transfer elements from the stack to the result vector in reverse order
    while (!S.empty()) {
        ans[i] = S.top();  // Get the top element of the stack and store it in the result vector
        S.pop();           // Pop the top element from the stack
        i--;               // Decrease the index of the result array
    }

    // Return the result vector, which is now "beautiful"
    return ans;
}

int main() {
    vector <int> V = {2, 3, 5, -4, 6, -2, -8, 9};

    vector <int> ans = makeBeautiful(V);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}