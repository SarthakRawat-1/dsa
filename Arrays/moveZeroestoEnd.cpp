// One way to solve this is to suppose there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array. Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array. The last N-X places of the original array will be then filled with zero. Now, our task is completed.
// A better approach is using two pointers. We first take a pointer, and move it to the location where the first zero is, then we use the other pointer to traverse through array after that first zero. When we find a non zero element, we swap. After this, increment j to point to the next zero in the array. And so the process goes on and on till all zeroes are at end.

#include <bits/stdc++.h>
using namespace std;

// Function to move all zeros in the array to the end while maintaining the order of non-zero elements.
vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;  // Variable `j` is used as a pointer to track the first occurrence of zero in the array.
    
    // First loop to find the first zero element and set `j` as its index.
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {  // If the current element is zero,
            j = i;  // Set `j` to the index of this zero.
            break;  // Exit the loop as we have found the first zero.
        }
    }

    // If no zero is found, `j` will remain -1, meaning the array has no zeros.
    // In this case, we return the array as it is.
    if (j == -1) return a;

    // Now, we will move both pointers `i` and `j` to swap non-zero elements with zero elements.
    for (int i = j + 1; i < n; i++) {  // Start the loop from the element after `j`.
        if (a[i] != 0) {  // If the current element `a[i]` is not zero,
            swap(a[i], a[j]);  // Swap the current element with the element at index `j`.
            j++;  // Increment `j` to point to the next zero element in the array.
            // The reason why this simple statement ensures that j points to the next zero element in the array is because of the logic of our program.
            // Let's say that element right after the zero element is non zero, in this case after swapping and increasing j by one, the j again points to the zero, because it was swapped.
            // In case the element right after the zero element is also zero, then swapping will not happen with that zero but with a non zero element which might appear later. But after swapping, again as the next element was also zero, so j points to zero again.
        }
    }
    return a;  // Return the modified array where all zeros are shifted to the end.
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;  

    vector<int> ans = moveZeros(n, arr);

    
    for (auto &it : ans) {
        cout << it << " ";  
    }
    cout << '\n';  

    return 0;  
}
