// The Floor of x is the largest element in the array which is smaller than or equal to x.
// The Ceiling of x is the smallest element in the array greater than or equal to x (basically Lower Bound).

#include<bits/stdc++.h>
using namespace std;

// Function to find the Floor of x in the array (largest element <= x)
int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1; // Initialize two pointers: low at start and high at the end of the array.
    int ans = -1; // Initialize ans to -1, meaning no floor is found if no suitable value is found.

    // Binary search to find the floor
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid index

        // Check if arr[mid] is less than or equal to x
        if (arr[mid] <= x) {
            ans = arr[mid]; // This could be the answer as it's <= x
            low = mid + 1;  // Move to the right half to check for a larger valid element
        }
        else {
            high = mid - 1; // If arr[mid] > x, discard the right half and search in the left
        }
    }
    return ans; // Return the largest element <= x (floor) or -1 if no such element exists
}

// Function to find the Ceil of x in the array (smallest element >= x)
int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1; // Initialize two pointers: low at start and high at the end of the array.
    int ans = -1; // Initialize ans to -1, meaning no ceil is found if no suitable value is found.

    // Binary search to find the ceil
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid index

        // Check if arr[mid] is greater than or equal to x
        if (arr[mid] >= x) {
            ans = arr[mid]; // This could be the answer as it's >= x
            high = mid - 1; // Move to the left half to check for a smaller valid element
        }
        else {
            low = mid + 1; // If arr[mid] < x, discard the left half and search in the right
        }
    }
    return ans; // Return the smallest element >= x (ceil) or -1 if no such element exists
}

// Function to get both the Floor and Ceil of x in the array
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int f = findFloor(arr, n, x); // Find the floor of x
    int c = findCeil(arr, n, x);  // Find the ceil of x
    return make_pair(f, c);       // Return both values as a pair (floor, ceil)
}


int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}
