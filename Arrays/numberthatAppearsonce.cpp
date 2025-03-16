// Problem Statement :- Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// One appraoch to solve this problem is by running a loop (say i) to select the elements of the array one by one. For every element arr[i], we will perform a linear search using another loop (nested loop) and count its occurrence. If for any element the occurrence is 1, we will return it.

// A better way to solve this is using Hashing. We can simply hash the elements along with their occurrences in the form of (key, value) pair. Array hashing is not applicable if the array contains negatives or very large numbers. Hashing using map data structure can be used for that.
// For hash array solution :- In order to hash using an array, we need to first find the maximum element (say maxElement) to get the range of the hash array. The index of the hash array will represent the elements of the given array and the value stored in that index will be the number of occurrences. Now, the size of the array must be maxElement + 1 as we need to hash the maxElement itself.
// Now, using another loop we will store the elements of the array along with their frequency in the hash array. (i.e. hash[arr[i]]++)
// After that, using another loop we will iterate over the hash array, and try to find the element for which the frequency is 1, and finally, we will return that particular element.
// Please check missingNumber.cpp to see how hash array can be used.

// Now onto Hashing using map data structure. First, we will declare a map. Now, using a loop we will store the elements of the array along with their frequency in the map data structure. Using another loop we will iterate over the map, and try to find the element for which the frequency is 1, and finally, we will return that particular element.

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {

    // Step 1: Get the size of the input array.
    int n = arr.size();

    // Step 2: Declare a hashmap (std::map) to store the frequency of each element in the array.
    map<int, int> mpp;

    // Step 3: Loop through the array and populate the map with the frequency of each element.
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;  // Increment the count of arr[i] in the map.
    }

    // Step 4: Iterate through the map to find the element with a frequency of 1 (i.e., the single element).
    for (auto it : mpp) {
        if (it.second == 1)  // If the frequency of the element is 1.
            return it.first;  // Return the element with frequency 1.
    }

    // Step 5: If no single element is found (which shouldn't happen based on the problem constraints),
    // return -1 as a fallback. This line won't execute if the array has one element with a frequency of 1.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};

    int ans = getSingleElement(arr);

    cout << "The single element is: " << ans << endl;

    return 0;
}

// A more optimal solution involves using XOR operation which i am not covering here right now.