// Merge Sort works by recursively splitting the array into smaller subarrays, sorting them, and then merging the sorted subarrays to produce a fully sorted array.
// First we recursively split the array into two halves until each subarray contains only one element (or zero elements, which is already sorted by definition).
// Sort each of the smaller arrays (since arrays of one element are trivially sorted, we don't need to do anything here).
// Merge the sorted subarrays back together to form a sorted array.

#include <bits/stdc++.h>

using namespace std;

// Function to merge two sorted halves of the array. Notice it takes vector by reference.
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary vector to store the merged result.

    // Pointers for the left and right halves of the array
    int left = low; // Start of the left half (from low to mid).
    int right = mid + 1; // Start of the right half (from mid + 1 to high).

    // Merge the two halves into the temp vector by comparing elements
    while (left <= mid && right <= high) { // The condition to check if we have exhausted the elements in either half.
        // If the left half element is smaller, append it to temp
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++; // Move the left pointer forward
        }
        // Else, append the right half element to temp
        else {
            temp.push_back(arr[right]);
            right++; // Move the right pointer forward
        }
    }

    // If there are remaining elements in the left half, append them to temp
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If there are remaining elements in the right half, append them to temp
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // These two work because, the while loop will not break until either left or right half is completely empty or exhausted. In that case, we can just append the rest of the elements present in other half to the temp vector, as they are also sorted.

    // Copy the merged elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low]; // Place elements from temp back into arr.
        // temp is a new vector that starts at index 0, whereas the elements in the original array that need to be replaced start at arr[low] and end at arr[high]
        // To map each element in temp back to the correct position in the original array, the expression temp[i - low] is used.
    }
}

// Recursive function to perform Merge Sort. This will be used to split the array in left and right half as well as calling merge to sort the array and merge the sorted arrays. Notice it takes vector by reference.
void mergeSort(vector<int> &arr, int low, int high) { // Initially low and high will point to first and last element of the array.

    if (low >= high) return; // Base case: if the array has one or zero elements, low will become equal to high or greater than that. As in this case, a single element or zero element is already sorted so jsut return.

    int mid = (low + high) / 2; // Find the middle index of the array. Better way is to use :- mid = low + (high - low) / 2

    mergeSort(arr, low, mid); // Recursively sort the left half of the array. We are calling mergeSort again with low now as low itself but high becomes mid.
    mergeSort(arr, mid + 1, high); // Recursively sort the right half of the array. We are calling mergeSort again with low now as mid + 1 and high remains high.
    merge(arr, low, mid, high); // Merge the two sorted halves together.
}


int main() {
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }

    cout << endl;

    mergeSort(arr, 0, n - 1);
    
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }

    cout << endl;

    return 0;
}