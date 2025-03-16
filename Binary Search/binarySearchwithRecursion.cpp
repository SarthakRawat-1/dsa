#include <bits/stdc++.h>
using namespace std;

// Binary Search using recursion. It takes the vector , the current search range (low to high), and the target value.
int binarySearch(vector<int>& nums, int low, int high, int target) {

    // Base case. If the low index exceeds the high index, it means the target isn't found and search space is exhausted. And hence, we return -1
    if (low > high) return -1; 

    // Calculate the middle index. (Note: This could potentially cause overflow for large arrays.)
    // A safer way is to use int mid = low + (high - low) / 2;
    int mid = (low + high) / 2;

    // Check if the middle element is the target. If yes, return the index.
    if (nums[mid] == target) return mid;

    // If the target is greater than the middle element, search in the right half of the array. So we set 'low' to mid + 1 in our Fucntion call.
    else if (target > nums[mid]) return binarySearch(nums, mid + 1, high, target);

    // Otherwise, search in the left half of the array. So we set 'high' to mid - 1 in our Function call.
    return binarySearch(nums, low, mid - 1, target);
}

int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}