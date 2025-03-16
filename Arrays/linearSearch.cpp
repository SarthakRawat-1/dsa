// Linear Search is a simple search algorithm where we sequentially check each element of an array (or list) to see if it matches the target value. It starts from the first element and compares the target value with each element of the array one by one until a match is found or the end of the array is reached.

#include<bits/stdc++.h> 
using namespace std;

// Function to perform linear search in the given array 'arr' of size 'n'.
// It returns the index of the target element if found, otherwise returns -1.
int linearSearch(int arr[], int n, int target) {
    // Loop through each element in the array.
    for (int i = 0; i < n; i++) {
        // If the current element matches the target, return its index.
        if (arr[i] == target) {
            return i;  // Return the index where the element is found.
        }
    }
    // If we finish the loop and the element is not found, return -1.
    return -1;  // Element not found.
}

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);  

    int target = 70;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " is present at index " << result << endl;
    } else {
        cout << "Element " << target << " is not present in the array." << endl;
    }

    return 0;  
}
