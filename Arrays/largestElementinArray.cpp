// One way to solve this is by sorting the array and then the largest element will be at last index.
// Here, i am going to write the approach using a max variable to solve this problem.

#include <bits/stdc++.h>
 
using namespace std;

// Function to find the largest element in the array.
// It takes an array `arr` and the size `n` of the array as input and returns the largest element.
int findLargestElement(int arr[], int n) {

    // This assumes the first element is the largest.
    int max = arr[0];

    // Loop through the entire array starting from the first element to the last.
    for (int i = 0; i < n; i++) {
        // If any element is larger than the current `max`, update `max` to that element.
        if (max < arr[i]) {
            max = arr[i]; // Update max to the new larger value
        }
    }
  
    // After the loop, `max` will hold the largest element in the array.
    return max;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int max = findLargestElement(arr1, n);
  cout << "The largest element in the array is: " << max << endl;

  return 0;
}


