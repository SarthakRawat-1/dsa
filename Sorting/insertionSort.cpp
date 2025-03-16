// Insertion sort builds the final sorted array one item at a time. It is much like sorting playing cards in your hands: you pick up one card and insert it into the correct position among the cards already sorted.
// The algorithm starts with an empty sorted portion and an unsorted portion. Initially, the sorted portion contains just the first element, and the unsorted portion contains the rest.
// The algorithm picks each element from the unsorted portion (starting from the second element) and inserts it into its correct position within the sorted portion. For each element to be inserted, it is compared with the elements in the sorted portion to find the appropriate position.
// Basically the element from unsorted position is moved forward in the sorted position till it encounters number that are bigger than it. Once it encounters a number lesser than itself, it stops there. And hence it also becomes a part of sorted portion.
// You can also think of this as :- As each element is compared with the elements in the sorted portion, if the current element is smaller than the element being compared to, the larger elements are shifted to the right to make room for the new element. Once the correct position is found, the element is inserted into that position.
// This process is repeated for each element until the entire array is sorted.

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    
    // Outer loop picks one element from the unsorted portion (starting from the second element) and tries to insert it into the correct position within the sorted portion of the array.
    for (int i = 1; i < n; i++) {

        // Inner Loop to compare the unsorted element with the elements in the sorted portion. Initially we take unsorted element as second element of array. It is compared with first element, which happens be to only element in sorted position now. If the first element is bigger, then this second element will be swapped with that.
        // After that we have two elements in the sorted position now, so the unsorted element to compare is now the third element of array. This goes on and on.
        for (int j = i; j > 0; j--) { // j > 0 and not j >= 0 because when j = 0, then j - 1 will be -1 which is not a valid index.
            // Since sorted portion lies on the left, we have to compare the element from unsorted portion, with elements from the sorted portion one by one, which all lie on it's left initally.
            if (arr[j] < arr[j - 1]) {
                // Swap the elements, if the unsorted element is smaller than the element being compared to.
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                // If the unsorted element is not smaller than the element being compared to in the sorted portion, we can stop the loop as if it's not smaller than that element, so it for sure won't be smaller than the elements lying to the left of it.
                // This breaks the inner loop, so we can start comapring our next unsorted element.
                break;
            }
        }
    }
    
    cout << "After Using insertion sort: " << "\n";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9, -1, -23};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);

    return 0;
}