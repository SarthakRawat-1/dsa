// Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until no more swaps are needed, which means the list is sorted.
// Bubble sort makes several passes over the array. In each pass, it compares adjacent elements and swaps them if they are in the wrong order (i.e., the left element is greater than the right element).
// With each pass, the largest unsorted element "bubbles" up to its correct position. After the first pass, the largest element will be placed at the end of the list. After the second pass, the second largest will be placed in the second last position, and so on.
// The algorithm continues making passes until no more swaps are needed, meaning the list is fully sorted.

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {

    // Outer loop: Start from the last element and move towards the first.
    // It determines how many passes we need to sort the array. We need number of elements - 1 passes to sort the array. This is because one by one largest element is placed to the end, and the first element will automatically be sorted once every other element is at their right palce.
    for (int i = n - 1; i > 0; i--) {
        bool swapped = false;  // To check if any swap is made in the current pass. This is used for efficiency purposes.
        
        // Inner loop: Compare adjacent elements up to index 'i'
        // Elements beyond 'i' are already sorted, so we don't need to check them.
        for (int j = 0; j <= i - 1; j++) {
            
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                
                // Swap the elements
                int temp = arr[j + 1];  
                arr[j + 1] = arr[j];    
                arr[j] = temp;       
                swapped = true;  // A swap has occurred   
            }

            
        }
        // If no swaps were made in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }

    cout << "After Using Bubble Sort: " << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {-1, -10, 13, 46, 24, 52, 20, 9, 99};
    
    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Using Bubble Sort: " << endl;
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);

    return 0;
}
