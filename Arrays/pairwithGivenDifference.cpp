// Problem Statement :- https://www.interviewbit.com/problems/pair-with-given-difference/

// This is basically the Two sum problem, but instead of sum there is difference.
// It's Brute force approach is the same as the Two sum problem.

// Better solution can be done by using Binary search. Btw this can also be used in Two sum problem. We need sorted array for this too.
// Let's say A and B are the two numbers whose difference is target i.e. A - B = target, now we can say A = target + B
// So let's say we have an array, say arr = {2, 3, 5, 10, 50, 80} First element is 2 and our target is 45, so now for 2 we have to find 47 in the rest of array. Thus, we can use Binary search in the rest of array to find 47.
// If 47 is not present, then go to other element which is 3, so now we need 48. Search for 48 usiing binary search in rest of the array.
// Continue doing this till you get the answer. 

// Optimized Solution can be given by sorting the array and then using two pointers approach.
// This problem can't be done by just simply pointing start to first element and end to last element. Think it like this :- You have {2, 3, 5, 10, 50, 80}, target = 45 Now if you do 80 - 2 it'll be 78. Move start and you get 80 - 3 = 77 and if you move end, you get 50 - 2 = 48 Both leads to decrease in the result as opposed to two sum problem, where moving start was increasing the sum and moving end was decreasing the sum.
// In this case, we need to put start at first element and end at second element. For this case, both start and end will be increased only. So in our eg :- Intially it's 3 - 2 = 1, we have to increase the sum as target is 45, so we increase the end to one more, hence now it's 5 - 2 = 3, still not enough, so increase once more 10 - 2 = 8, then 50 - 2 = 48, this is greater than target, we have to decrease it, so now keep end where it is, and increase start now, it becomes 50 - 3 = 47, still greater so again increase. 50 - 5 = 45, which is exactly what we wanted.

#include <bits/stdc++.h>
using namespace std;

// Function to find the pair of elements with the given target difference
void findPairWithDifference(vector<int>& arr, int target) {
    int n = arr.size();          // Size of the array
    int start = 0, end = 1;      // Initialize two pointers: start and end

    // Target is difference between the numbers, so make it positive
    if (target < 0) {
        target = target * (-1);
    }

    while (end < n) {
        // If the difference between the elements at 'end' and 'start' is equal to the target
        if (arr[end] - arr[start] == target) {
            // Output the result
            cout << arr[start] << " and " << arr[end] << " are the answer" << endl;
            return;  // Return after finding the pair
        }
        // If the difference is smaller than the target, move the 'end' pointer to increase the difference
        else if (arr[end] - arr[start] < target) {
            end++;
        }
        // If the difference is larger than the target, move the 'start' pointer to decrease the difference
        else {
            start++;
        }

        // Make sure that 'start' and 'end' don't point to the same element
        if (start == end) {
            end++;
        }
    }

    // If no pair is found, print a message
    cout << "No such pair found." << endl;
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 11};  

    int target = 3;  

    sort(arr.begin(), arr.end());

    findPairWithDifference(arr, target);

    return 0;
}
