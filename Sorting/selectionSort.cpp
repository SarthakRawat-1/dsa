// Selection sort is a simple comparison-based sorting algorithm that divides the input array into two parts: the sorted part and the unsorted part. Initially, the sorted part is empty, and the unsorted part contains all the elements. The algorithm repeatedly selects the smallest (or largest, depending on the sorting order) element from the unsorted part and moves it to the sorted part.
// Assume the entire array is unsorted. The algorithm starts at the first element and selects the smallest element in the unsorted portion. Once the smallest element is found, it is swapped with the element at the beginning of the unsorted portion.
// The boundary between the sorted and unsorted portions of the array shifts to the right by one. Now, the smallest element has been placed in its correct position in the sorted portion.
// The process repeats for the next unsorted element. This continues until the entire array is sorted.

#include <bits/stdc++.h>
using namespace std;

// Function to perform selection sort on the array. Takes array and size of array.
void selection_sort(int arr[], int n) {

    // Outer loop: This will go through each element of the array.
    // We don't need to go till the last element because it will already be sorted after the second last pass.
    for (int i = 0; i < n - 1; i++) {
        // Assume the smallest element is at the current position 'i'.
        int mini = i;

        // Inner loop: This searches for the smallest element in the unsorted part of the array.
        // Starts from 'i' and goes till the end of the array.
        for (int j = i; j < n; j++) {
            // If we find an element smaller than the current minimum, update 'mini' to this new index.
            if (arr[j] < arr[mini]) {
                mini = j;  // Update the index of the smallest element.
            }
        }

        // Swap the smallest found element with the first unsorted element (at index 'i').
        // This places the smallest element of the unsorted part at its correct position.
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }

    cout << "After selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << "\n";
}

int main() {
    int arr[] = {13, 46, 5, 9, 80, 2};
    
    // Calculate the size of the array.
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Selection Sort :- \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << "\n";

    selection_sort(arr, n);

    return 0;
}
