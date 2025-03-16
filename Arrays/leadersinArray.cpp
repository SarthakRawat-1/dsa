// Problem Statement :- https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

// Brute Force :- Use nested for loops, outer for loop for selecting an element (starts from first element) and inner for loop checks if there is any element to the right that is greater than the element currently traversed by the outer loop. We start by initializing the outer loop pointer to the start element and setting it as the current leader. If any element traversed is found greater than the element currently set as a leader, it will not go to the ans array and we increment the outer loop pointer by 1 and set the next element as the current leader. If we don’t find any other element to the right greater than the current element, then we push the current element to the ans array stating that is it the leader element.

// Optimal Solution :- Start from the last element because we only want to check the elements on the right side.
// First, we'll start the traversal from the right. Then, we move toward the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
// If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.
// Else, we proceed with the further elements on the left. This method prints the leaders in the reverse direction of their occurrences. If we are concerned about the order, we can use an extra array or a string to order.

#include<bits/stdc++.h>
using namespace std;

// Function to find leaders in an array.
// A leader is an element which is greater than all elements to its right.
vector<int> printLeaders(int arr[], int n) {

    // Vector to store the leaders.
    vector<int> ans;
  
    // The last element of the array is always a leader.
    // Initialize max to the last element and push it into the ans vector.
    int max = arr[n - 1];
    ans.push_back(arr[n-1]);

    // Traverse the array from the second last element to the first.
    // Compare each element with the current max (rightmost leader).
    for (int i = n - 2; i >= 0; i--) {
        // If the current element is greater than the max,
        // it is a leader, so push it into the ans vector.
        if (arr[i] > max) {
            ans.push_back(arr[i]);
            max = arr[i];  // Update max to the current leader.
        }
    }
  
    // Return the vector containing the leaders.
    return ans;
}

int main() {

    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeaders(arr,n);
  
    // Print the leaders in the correct order.
    // The ans vector stores leaders from right to left,
    // so we print them in reverse to maintain the correct order.
    for(int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";   
    }
  
    cout << endl;  
    return 0;
}
