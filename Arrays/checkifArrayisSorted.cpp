// For a sorted array the previous of every element is smaller than or equal to its current element.

#include<bits/stdc++.h> 
using namespace std;    

// Function to check if an array is sorted in non-decreasing order
bool isSorted(int arr[], int n) {
    // Loop starts from the second element (index 1) and compares it with the previous element
    for (int i = 1; i < n; i++) {
        // If any element is smaller than the one before it, the array is not sorted
        if (arr[i] < arr[i - 1])
            return false; // The array is not sorted, so return false
    }
    
    // If no elements are out of order, the array is sorted, so return true
    return true;
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5}, n = 5;  

    printf("%s", isSorted(arr, n) ? "True" : "False"); 

    return 0; 
}
