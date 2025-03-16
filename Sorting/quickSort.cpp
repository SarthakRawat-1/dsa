// Quick Sort involves partitioning an array into smaller subarrays around a "pivot" element, and then sorting these subarrays recursively.
// Select an element from the array to serve as the pivot. Different strategies for selecting a pivot include choosing the first, last, middle, or a random element in the array.
// Rearrange the array so that all elements smaller than the pivot are placed to its left and all elements greater than the pivot are placed to its right. The pivot itself is placed in its correct sorted position in the array.
// The array is now split into two subarrays: one on the left of the pivot and one on the right. Recursively apply Quick Sort to each subarray.
// The recursion terminates when a subarray has fewer than 2 elements, as an array with 0 or 1 element is already sorted.

#include <bits/stdc++.h>

using namespace std;

// Function to obtain the correct position of the pivot. Notice the vector is passed by reference.
//Now in this we are taking the pivot to be the last element of the array or subarray. Meaning for the array, last element is it's pivot and for the subarrays also each subarray's last element is their pivot.
int partition(vector<int> &arr, int start, int end) {
    // To get the correct index of pivot we will declare one more variable pos which intially will be at start.
    // Once we find an element smaller than the pivot, we will swap it with the element at pos. Then increase pos by 1. 
    // This way we can ensure that all elements smaller than pivot are placed to it's left.
    int pos = start;

    // We will comapre the pivot with every element in the subarray to know it's correct position. The first element we are comparing it with is the element at start index, which is the first element of array and subarray and it will compare till the end index.
    for (int i = start; i <= end; i++) {
        // Comparing the element at index i with our element at index end, which we have taken as pivot.
        if (arr[i] <= arr[end]) {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
            pos++;
            // Now the reason we are doing it like this, is because we just have to find the index where the pivot should be. Whether the elements before and after the pivot in it's correct position are also sorted or not, we don't care about that. We are only interested in finding the correct position of pivot.
            // Rest will be handled by our recursive function which will divide our array into subarrays and so on.
        }            
    }

    // The reason we are returning pos - 1 and not pos is because in the if condition we have used = sign which means that even for the pivot element, it will run because arr[end] == arr[end] is true, so pos will be increased by one more. 
    // We need this because inside the if statement is where we are actually making changing to our arrays, so we need to set our pivot to it's correct position there only.
    return pos - 1;
}

// Function to do the Quick Sort. Takes vector by reference, start index and end index. The start and end index are for indicating the start and end index of array and the sub array we will obtain by dividing about a pivot.
void quickSort(vector<int> &arr, int start, int end) {
    // Base Case. When start becomes greater than or equal to end. It means that array either has zero or one element in which case it is already sorted.
    if (start >= end) {
        return;
    }

    // First, we obtain the correct position of the pivot for the array and the subarray.
    // Hence, we used wrote another function for that. This function will return the current position of the pivot, basically return the position of the pivot after it is placed on the correct spot in the array. Correct spot means it's location will be same as if the array was already sorted.
    int pivot = partition(arr, start, end);

    // Dividing about the Pivot. This function is for the left side of the pivot.
    quickSort(arr, start, pivot - 1);

    // Dividing about the Pivot. This function is for the right side of the pivot.
    quickSort(arr, pivot + 1, end);
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}