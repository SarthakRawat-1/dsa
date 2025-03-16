// One approach to solve this is using hash set because it only stores unique elements.
// Please note that it removes duplicate elements in place from the array, so the array is modified.
#include<bits/stdc++.h>  
using namespace std;    

// Function to remove duplicate elements from the array
int removeDuplicates(int arr[], int n) {
    set<int> set;  // A set automatically stores unique elements in sorted order.

    // Loop through the array and insert elements into the set.
    // Since a set only keeps unique elements, duplicates will be discarded.
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }

    // The size of the set represents the number of unique elements.
    int k = set.size();
    
    // Index to store unique elements back into the array.
    int j = 0;

    // Transfer unique elements from the set back to the array.
    for (int x : set) {
        arr[j++] = x;  // Assign each unique element to the array and increment the index 'j'.
    }

    // Return the count of unique elements.
    return k;
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to remove duplicates and get the number of unique elements.
    int k = removeDuplicates(arr, n);

    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";  
    }

    return 0;  
}

// Another approach of solving this would be using the two pointer approach.
// Please note that it removes duplicate elements in place from the array, so the array is modified.
// In this we will take a variable i as 0, then we use a for loop use a for loop by using a variable ‘j’ from 1 to length of the array. If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j]. This is because at this, we got a unique element. 
// After completion of the loop return i+1, i.e size of the array of unique elements.

#include<bits/stdc++.h>  
using namespace std;      

// Function to remove duplicates from a sorted array.
int removeDuplicates(int arr[], int n) {
    // Initialize a pointer 'i' which will track the index of the last unique element found.
    int i = 0;

    // Iterate through the array starting from the second element (index 1) using pointer 'j'.
    for (int j = 1; j < n; j++) {
        // If the element at 'j' is different from the element at 'i', it means it's a unique element.
        if (arr[i] != arr[j]) {
            i++;           // Increment 'i' to the next position where the unique element will be placed.
            arr[i] = arr[j]; // Place the unique element at this new position.
        }
    }

    // Return the number of unique elements, which is 'i + 1' (since 'i' is zero-based index).
    return i + 1;
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = removeDuplicates(arr, n);

    cout << "The array after removing duplicate elements is: " << endl;
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";  
    }

    return 0;  
}

