// The union of two arrays can be defined as the common and distinct elements in the two arrays. The common elements should only come once. 
// One approach is to make a set. Then store all elements of both the array into the set. Since, a set already stores only unique elements, so we don't need to care about that. Now just declare another vector and store all the elements of set in that vector. This can be done by the help of a for of loop especially range based for of loop.
// For how you can insert elements in set, you can check removeDuplicatesfromSortedArray.cpp
// Another approach would be to use a map which stores frequency of elements of both arrays. Now for this map, the key will be the element and value will be frequency. Now we can just push key to the Union vector. We can do this as if it's isnie the map it means it has atleast come once and all keys are unique in a map and keys represents the elements from both arrays.

// This is the code for the map approach.

#include <bits/stdc++.h>  
using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    // Declare a map to store the frequency of elements
    // The key represents the element, and the value is its frequency (how many times it appears)
    map<int, int> freq;

    // Vector to store the final union of the two arrays
    vector<int> Union;

    // Traverse through the first array (arr1) and count the frequency of each element
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;  // Increments the frequency of each element in the map

    // Traverse through the second array (arr2) and count the frequency of each element
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;  // Increments the frequency of each element in the map

    // Traverse the map and push the keys (unique elements) into the Union vector
    for (auto &it: freq)
        Union.push_back(it.first);  // 'it.first' refers to the key (unique element) in the map

    return Union;  // Return the vector containing the union of arr1 and arr2
}

int main() {
    int n = 10, m = 7;

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    vector<int> Union = FindUnion(arr1, arr2, n, m);

    // Output the result
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val: Union)
        cout << val << " ";  

    return 0;  
}

// A better approach is to use a two pointer approach. But this works only if both the arrays are sorted. The set and map solutions work even for unsorted arrays.
// Take two pointers let’s say i, j pointing to the 0th index of first and second array. Create an empty vector for storing the union of arr1 and arr2.
// Traverse both the arrays using these pointers and insert distinct elements found in the vector. While traversing we may encounter three cases.
// If arr1[ i ] == arr2[ j ] Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i. Insert this only if it's not present already in the array.
// If arr1[ i ]  < arr2[ j ] we need to insert arr1[ i ] in union. If last element in union vector is not equal to arr1[ i ], then insert in union else don’t insert. After checking Increment i.
// If arr1[ i ] > arr2[ j ] we need to insert arr2[ j ] in union. If the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j.
// After traversing one of the array completely. Continue traversing the other array, check for condition and insert in the union.

#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers to iterate through arr1 and arr2
    vector<int> Union; // this will store the union of arr1 and arr2

    // Process both arrays simultaneously until one of them is fully traversed
    while (i < n && j < m) {
        // Case 1 and Case 2: when arr1[i] is smaller or equal to arr2[j]
        if (arr1[i] <= arr2[j]) {
            // If Union is empty or the last element of Union is not equal to arr1[i], insert arr1[i]
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++; // Move to the next element in arr1
        } 
        // Case 3: when arr2[j] is smaller
        else {
            // If Union is empty or the last element of Union is not equal to arr2[j], insert arr2[j]
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++; // Move to the next element in arr2
        }
    }

    // If there are remaining elements in arr1, add them to Union
    while (i < n) {
        // Only add arr1[i] if it's not already the last element in Union
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }

    // If there are remaining elements in arr2, add them to Union
    while (j < m) {
        // Only add arr2[j] if it's not already the last element in Union
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }

    return Union; 
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 

    vector<int> Union = FindUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: " << endl;
    for (auto &val: Union)
        cout << val << " "; 

    return 0;
}


