// Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of consecutive 1's in the given binary array
    int findMaxConsecutiveOnes(vector<int> &nums) {
      int cnt = 0;    // Variable to count the current streak of consecutive 1's
      int maxi = 0;   // Variable to store the maximum streak of consecutive 1's

      // Loop through each element in the array
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) { // If the current element is 1
          cnt++;            // Increase the count of consecutive 1's
        } else {            // If the current element is 0
          cnt = 0;          // Reset the count of consecutive 1's
        }

        // Update maxi with the maximum streak found so far
        maxi = max(maxi, cnt);
      }

      // Return the longest streak of consecutive 1's
      return maxi;
    }
};

int main() {
  vector<int> nums = {1, 1, 0, 1, 1, 1}; 
  Solution obj; 
  int ans = obj.findMaxConsecutiveOnes(nums); 

  cout << "The maximum consecutive 1's are " << ans;

  return 0;
}
