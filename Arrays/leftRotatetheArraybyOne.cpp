// Left rotating an array by one position means shifting each element of the array one place to the left. The first element moves to the last position, and all other elements shift one place to the left.

#include<bits/stdc++.h>  
using namespace std;

// Function to perform a left rotation by one on the given array.
void solve(int arr[], int n) {
    // Step 1: Store the first element of the array in a temporary variable.
    int temp = arr[0];  // We store the value of arr[0] (first element) in 'temp' as it will be overwritten in the next step.

    // Step 2: Shift all elements of the array one position to the left.
    // We start from the first index (i = 0) and assign each element the value of the next element (arr[i+1]).
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // Move the element at index i+1 to index i.
    }

    // Step 3: Place the originally first element (stored in 'temp') at the last position of the array.
    arr[n - 1] = temp;  // Assign the value of 'temp' (initial first element) to the last index (n-1).

    // Step 4: Print the array after the rotation.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";  // Print each element of the rotated array.
    }
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    solve(arr, n);  

    return 0;  
}
