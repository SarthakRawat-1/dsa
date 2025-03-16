// One method of reversing an array is to take a temp array of the same size. Then there will be variables to store the value of the last index of original array and the first index of the temp array
// Now, one by one elements will be copied from original array to temp array and variable storing index of last element of original array will be decreased by one and that storing first element of temp will be increased by one. This goes on and on till the whole array is copied in reverse order.
// However, this approach takes an extra array. There's better way to reverse an array.
// We can think of reversing the array as swapping the first and last elements of array. Then swapping the second first and second last element of the array. And so on.

#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};

    int start = 0, end = 5; // To index the corresponding elememts to be swapped.

    while (start < end) { // While start is less than end, this means that start has not crossed end so there's still elements left in array to swapped. Also, when start and end are equal both point to the same element, in that case also we don't have to swap.
        swap(arr[start], arr[end]);

        start++;
        end--;
    }

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
}