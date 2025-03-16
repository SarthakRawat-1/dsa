// Problem Statement :- Given an array of integers, rotating array of elements by k elements either left or right.
// One way to solve this is using Reversal Algorithms.
// For rotatating elements to right :- Reverse the last k elements of the array. Reverse the first n-k elements of the array. Reverse the whole array.
// For rotatating elements to left :- Reverse the first k elements of the array. Reverse the last n-k elements of the array. Reverse the whole array.
// Since, I have already written program to reverse an array, I am not writing this Algorithm here.

// Another apporach is using a temporary array. This temporary array will be used to store the elements of the original array. These elements are those, which when the array is rotated, they will be rotated to positions that don't exist in array. So we store them in temp array.
// For left rotate, the intial k elements will be stored in temp array. For right rotate, the last k elements will be stored in temp array.
// Then rest of the elements in array, can be copied to their desired places in array. After that, elements from temp can be copied in the array.

// Now understand, say we have 7 elements in the array. And if it is asked to rotate the array 7 times (right or left doesn't matter), we can observe that rotating the array 7 times, will give the same array back. If we want to rotate the array 8 times, it will give the same result as if array was rotated 1 time. And so on. Hence, for any rotation number greater than size of array. It will always be same asif rotation was done by a number between 1 and number of elements in array.

// For Rotating Elements to Right. Copy the last k elements into the temp array. Shift n-k elements from the beginning by k position to the right. Copy the elements into the main array from the temp array.
#include <iostream>
using namespace std;

// Function to rotate an array to the right by 'k' positions
void Rotatetoright(int arr[], int n, int k)
{
    // If array is empty, return immediately
    if (n == 0)
        return;
    
    // Handle the case where 'k' is greater than array size:
    k = k % n; // Effective rotation is 'k' mod n (in case k > n)

    // If k is 0, no rotation is needed
    if (k == 0)  return;

    // Temporary array to store the last 'k' elements of the array
    int temp[k];
    
    // Copy the last 'k' elements from the original array to the temp array
    for (int i = n - k; i < n; i++)
    {
        temp[i - n + k] = arr[i];
    }
    
    // Shift the first 'n-k' elements to the right by 'k' positions
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    
    // Copy the 'k' elements from the temporary array back to the original array (front positions)
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int n = 7; // Size of the array
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Original array
    int k = 2; // Number of positions to rotate to the right
    
    Rotatetoright(arr, n, k);
    
    cout << "After Rotating the elements to right " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    
    return 0;
}

// For Rotating Elements to Left. Copy the first k elements into the temp array. Shift n-k elements from last by k position to the left. Copy the elements into the main array from the temp array.
#include <iostream>
using namespace std;

// Function to rotate an array to the left by 'k' positions
void Rotatetoleft(int arr[], int n, int k)
{
    // If array is empty, return immediately
    if (n == 0)
        return;

    // Handle the case where 'k' is greater than array size:
    k = k % n; // Effective rotation is 'k' mod n (in case k > n)

    // If k is 0, no rotation is needed
    if (k == 0)  return;

    // Temporary array to store the first 'k' elements of the array
    int temp[k];

    // Step 1: Copy the first 'k' elements from the original array into temp
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i]; // Store the first 'k' elements in temp
    }

    // Step 2: Shift the remaining elements (from index 'k' to 'n-1') to the left by 'k' positions
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k]; // Shift elements from index 'k' to 'n-1' to the left
    }

    // Step 3: Place the first 'k' elements stored in temp at the end of the array
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k]; // Copy temp array back to the last 'k' positions
    }
}

int main()
{
    int n = 7; // Size of the array
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Original array
    int k = 2; // Number of positions to rotate to the left

    Rotatetoleft(arr, n, k);

    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    
    return 0;
}



