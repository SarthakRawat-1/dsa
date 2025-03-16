// Problem Statement :- Given an array of integers arr[] and an integer target. Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
// You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

// The brute force approach to solve this problem :- For each element of the given array, we will try to search for another element such that its sum is equal to the target. If such two numbers exist, we will return the indices.
// So in this approach, we need two for loops, one for selecting indices of array one by one. Then a nested for loop, to traverse through the remaining array for each of these indices to find the other number such that the sum is equal to the target.

// A better way to solve this is using Hash map. Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists. Thus we can trim down the time complexity of the problem. We will store the element along will its index in the HashMap. Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.
// First, we will select the element of the array one by one using a loop(say i).
// Then we will check if the other required element (i.e. target-arr[i]) exists in the hashMap.
// If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
// If it does exist, then we can just return indices of both.
// FInally if no such pair exists, we will return {-1, -1}
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;  // Hash map to store elements and their indices.
    
    // Loop through the array elements.
    for (int i = 0; i < n; i++) {
        int num = arr[i];          // Current element from the array.
        int moreNeeded = target - num;  // The other element required to meet the target sum.
        
        // Check if the other element required to form the target sum exists in the map.
        if (mpp.find(moreNeeded) != mpp.end()) {
            // If found, return the indices of the two elements.
            return {mpp[moreNeeded], i};
        }
        
        // Otherwise, store the current element and its index in the map.
        // This is done in case the current element will be needed in a future iteration.
        mpp[num] = i;
    }
    
    // If no such pair exists, return {-1, -1}.
    return {-1, -1};
}

int main() {
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};  
    int target = 14;                     

    vector<int> ans = twoSum(n, arr, target);
    
    cout << "This is the answer :- [" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}


// The optimized solution to this problem comes from the two pointer approach. In this approach, we will first sort the array and will try to choose the numbers in a greedy way.
// We will keep a left pointer at the first index and a right pointer at the last index.
// Now until left < right, we will check the sum of arr[left] and arr[right]. Not left <= right because at left = right, it is just one element, and we have to check for two elements so ignore this case.
// If the sum of these two is less than target sum, it means that we require a larger number, so we will increment the left pointer by 1, as array is sorted in ascending order.
// If the sum of these two is greater than target sum, it means that we require a smaller number, so we will decrement the right pointer by 1, as array is sorted in ascending order.
// If the sum of these two is equal to target sum, we will return the indices of the two elements.
// If left >= right, and we haven't found the two elements required, we can send {-1, -1}

#include <bits/stdc++.h>
using namespace std;

// Function to determine if there exists a pair in the array that sums up to the target.

vector<int> twoSum(int n, vector<int> &arr, int target) {
    // Here, we can't return correct indexes without keeping track of the original indices with the additional vector. This is because sorting an array changes the indices.
    // If we only used the original arr and then sorted it, and then used our algorithm on it and tried to return {left, right}, we are returning the indices from the sorted array, not the original array.
    // One way to get around this is to only take sorted array as inputs. But a better approach is what we have done i.e. maintain the original indices of the elements while still sorting the array. This can be done by pairing each element with its original index before sorting.

    // Step 1: Create a vector of pairs (element, index) to keep track of original indices.
    vector<pair<int, int>> arrWithIndices;
    for (int i = 0; i < n; i++) {
        arrWithIndices.push_back({arr[i], i});
    }

    // Step 2: Sort the array of pairs based on the element values.
    sort(arrWithIndices.begin(), arrWithIndices.end());

    // Step 3: Initialize two pointers.
    int left = 0;         // Left pointer starting at the beginning of the array.
    int right = n - 1;    // Right pointer starting at the end of the array.

    // Step 4: Traverse the array using the two-pointer approach.
    while (left < right) {
        int sum = arrWithIndices[left].first + arrWithIndices[right].first;

        // Step 5: If the sum matches the target, return the original indices of the elements.
        if (sum == target) {
            return {arrWithIndices[left].second, arrWithIndices[right].second};  // Return original indices.
        }
        // Step 6: If the sum is less than the target, move the left pointer to the right to increase the sum.
        else if (sum < target) {
            left++;
        }
        // Step 7: If the sum is greater than the target, move the right pointer to the left to decrease the sum.
        else {
            right--;
        }
    }

    // Step 8: If no pair is found, return array containing [-1, -1]
    return {-1, -1};
}

int main()
{
    int n = 5;  
    vector<int> arr = {2, 6, 5, 8, 11};  
    int target = 14;  

    vector<int> ans = twoSum(n, arr, target);

    cout << "Indices of elements that sum to the target: [" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}

// The two pointer appraoch is better than hash map solution only if the input array is already sorted and we don't have to sort.
// For unsorted array inputs, hash map approach is better