// In this problem, we have to find second smallest and second largest element in the array but without recursion.

#include <bits/stdc++.h> 
using namespace std;

// Function to find the second smallest element in an array.
int secondSmallest(int arr[], int n)
{
    // If the array has fewer than 2 elements, it's not possible to find the second smallest element, so we return -1.
    if (n < 2)
        return -1;

    // `small` will hold the smallest element, initialized to the largest possible integer value (INT_MAX).
    int small = INT_MAX;

    // `second_small` will hold the second smallest element, also initialized to INT_MAX.
    int second_small = INT_MAX;

    // Loop through the entire array.
    for (int i = 0; i < n; i++) 
    {
        // If the current element is smaller than the current smallest (`small`),
        // update `second_small` to the value of `small` and then set `small` to the current element.
        if (arr[i] < small)
        {
            second_small = small; // Update second smallest
            small = arr[i];       // Update smallest
        }
        // If the current element is greater than the smallest but smaller than the second smallest,
        // update `second_small` to the current element. This ensures we capture the second smallest.
        else if (arr[i] < second_small && arr[i] != small) // != condition is also there to avoid counting the same element twice as both small and second_small
        {
            second_small = arr[i]; // Update second smallest
        }
    }
    
    // Return the second smallest element found.
    return second_small;     
}

// Function to find the second largest element in an array.
int secondLargest(int arr[], int n)
{
    // If the array has fewer than 2 elements, it's not possible to find the second largest element, so we return -1.
    if (n < 2)
        return -1;

    // `large` will hold the largest element, initialized to the smallest possible integer value (INT_MIN).
    int large = INT_MIN;

    // `second_large` will hold the second largest element, also initialized to INT_MIN.
    int second_large = INT_MIN;

    // Loop through the entire array.
    for (int i = 0; i < n; i++) 
    {
        // If the current element is larger than the current largest (`large`),
        // update `second_large` to the value of `large` and then set `large` to the current element.
        if (arr[i] > large) 
        {
            second_large = large;  // Update second largest
            large = arr[i];        // Update largest
        }
        // If the current element is smaller than `large` but greater than `second_large`,
        // update `second_large` to the current element. This ensures we capture the second largest.
        else if (arr[i] > second_large && arr[i] != large) // != condition is also there to avoid counting the same element twice as both large and second_large
        {
            second_large = arr[i]; // Update second largest
        }
    }

    // Return the second largest element found.
    return second_large;                
}

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};  

    int n = sizeof(arr) / sizeof(arr[0]);

    int sS = secondSmallest(arr, n);

    int sL = secondLargest(arr, n);

    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;

    return 0;
}
