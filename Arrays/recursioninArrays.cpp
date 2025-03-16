#include <iostream>
using namespace std;

// Function to print an array using Recursion. Takes array, index of element and size of array as parameters
// One more way is to put index as the last element, and then call the function with that index in main function. Now everytime, we decrease the index in recursive function and when index becomes -1, we return. In this way, we don't need size of array as a parameter. 
void printArray(int arr[], int index, int n) {
    // Base case. If index of element is same as size of array, there are no more elements are left in array so return.
    if (index == n) {
        return;
    }

    // Prints the element
    cout << arr[index] << " ";

    // Calls the function again with incremented index
    printArray(arr, index + 1, n);

    // Now let's say you want to print the elements in reverse order, for that just move the recursive function call above the cout statement. 
}

// Function to take sum of elements of an array using Recursion. Takes array, index of element and size of array as parameters
int sumofElements(int arr[], int index, int n) {
    // Base case. If index of element is same as size of array, there are no more elements are left in array so send zero.
    if (index == n) {
        return 0;
    }

    // Returns the element and sum of the result of the function called again with incremented index.
    // This will help traversing the array elements. And at the end, after the last element is also accessed, it will just a return a zero from the base class.
    return arr[index] + sumofElements(arr, index + 1, n);
}

// Function to find minimum element of an array using Recursion. Takes array, index of element and size of array as parameters
int minElement(int arr[], int index, int n) {
    // Base case. If index is that of the last element of array, there are no more elements ahead of this, so just send this element, so it can be compared in the min function.
    if (index == n - 1) {
        return arr[index];
    }

    // We compare the current element at 'index' with the minimum element from the rest of the array. To get the minimum of the remaining elements, we recursively call minElement with the next index (index + 1).
    // The function returns the smallest element between arr[index] and the minimum of the remaining array elements.
    return min(arr[index], minElement(arr, index + 1, n));
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, 0, n);

    cout << endl << sumofElements(arr, 0, n) << endl;

    cout << minElement(arr, 0, n);

    return 0;
}