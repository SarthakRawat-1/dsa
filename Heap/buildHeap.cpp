// Converting a given array into a Max Heap
// 
// Two methods:
// 1) Heapify-Upwards (as in insertion.cpp or deletion.cpp)  
//    - Add elements one by one and bubble up to maintain heap property.
// 2) Heapify-Downwards (more efficient, O(n) time)  
//    - Build heap by fixing each subtree from the bottom up.

// We will start from n / 2 - 1 element as elements after that won't have any children.
// Then we will compare the parent element with it's children. We will swap it (depending on max or min heap). Then after swapping, it will again be compared and swapped (till it can) with it's new children.

#include <iostream>
using namespace std;

// "Heapify" ensures the subtree rooted at index i is a max-heap, assuming
// its children are already max-heaps.
// Parameters:
//    arr[] : array representing the heap
//    i     : current root index to heapify
//    n     : number of elements in arr
void Heapify(int arr[], int i, int n) {
    int largest = i;               // Initialize largest as root
    int left    = 2 * i + 1;       // left child index
    int right   = 2 * i + 2;       // right child index

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        Heapify(arr, largest, n);
    }
}

// Builds a max-heap from an unordered array in O(n) time
// We start from the last non-leaf node (n/2 - 1) and call Heapify
// on each node moving upwards to the root.
void BuildMaxHeap(int arr[], int n) {
    // Last non-leaf node is at index (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, i, n);
    }
}

// Utility to print the heap array
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example array
    int arr[] = {10, 20, 15, 12, 40, 25, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build the max heap
    BuildMaxHeap(arr, n);

    // Print resulting heap
    cout << "Max Heap array: ";
    printHeap(arr, n);

    return 0;
}
