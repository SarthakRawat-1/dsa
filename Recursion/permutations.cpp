// Problem Statement :- https://leetcode.com/problems/permutations/description/

// In total, we will have nums.size()! permutations.
// Let's say we had {1, 2, 3}. Output will have three number also, let's denote them by _, _, _
// The first number can be 1, 2 or 3. So, it is 1, _, _ or 2, _, _ or 3, _, _
// Consider second number for 2, _, _ it can be either 1 or 3 (as 2 has been utilized already). Let's say we put 3 there. We have 2, 3, _ now only 1 can come.
// We will need to know which elements are not written already in the number, so that we can put them in one of the available places. For this we will make a bool vector, same size as original vector. It will tell us if we have visited a particular number already or not

#include <bits/stdc++.h>
using namespace std;

// Helper function that recursively generates all permutations of the array.
void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited) {
    
    // Base case: If the current permutation (temp) is the same size as the input array,
    // it means we have a complete permutation to add to our results.
    if (temp.size() == arr.size()) {
        ans.push_back(temp);  // Add the completed permutation to the answer.
        return;
    }

    // Loop over each element in the array to explore possible choices.
    for (int i = 0; i < arr.size(); i++) {
        
        // If the element at index `i` has not been used in the current permutation (`temp`).
        if (!visited[i]) {
            
            // Mark the element as used by setting `visited[i]` to true.
            visited[i] = true;

            // Add the element to the current permutation `temp`.
            temp.push_back(arr[i]);

            // Recursive call to continue building the permutation with the chosen element included.
            solve(arr, ans, temp, visited);

            // Backtrack: Undo the choice by setting `visited[i]` to false.
            visited[i] = false;

            // Remove the last element added to `temp` to explore the next possibility in the loop.
            temp.pop_back();
        }
    }
}

// Main function that initiates the permutation generation.
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;     // Stores all possible permutations of `nums`.
    vector<int> temp;            // Temporary vector to store one permutation at a time.
    vector<bool> visited(nums.size(), false); // Tracks elements used in the current permutation.

    // Initiate the recursive helper function to start generating permutations.
    solve(nums, ans, temp, visited);

    // Return all generated permutations.
    return ans;
}

int main() {
    // Example input vector
    vector<int> nums = {1, 2, 3};

    // Generate all permutations of `nums`
    vector<vector<int>> ans = permute(nums);

    // Print each permutation in the result
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";  // Print each element in the permutation
        }
        cout << endl;  // New line for each permutation
    }
}


// How can we do it without temp and visited vectors i.e. extra space? 
// We know that as we go down the recursion tree i.e. adding elements to a specific position, we are fixing their position.
// The elements that are visited i.e. position fixed, will always come to the left of elements who have not yet been visited in the answer at each recursive step.
// We will do all the changes in the original nums vector by swapping.
// We will use a pointer to indicate element just after the elements that have been visited. To visit one more element i.e.e fixing position, we will have to swap the number at pointer with every other number after it (including the number at pointer itself) to get all possibilities for the next recursion tree stage.

#include <bits/stdc++.h>
using namespace std;

// Helper function that generates all permutations of the array in-place by swapping elements
void solve(vector<int> &arr, vector<vector<int>> &ans, int index) {

    // Base case: If `index` reaches the size of `arr`, it means we have a complete permutation
    // Add the current arrangement of `arr` to the result set
    if (index == arr.size()) {
        ans.push_back(arr);  // Store the current permutation
        return;
    }

    // Recursive case: Generate permutations by fixing each element at the `index` position
    for (int i = index; i < arr.size(); i++) {
        // Swap the current element at `i` with the element at `index`
        // This fixes the element at `index` in this branch of the recursive tree
        swap(arr[index], arr[i]);

        // Recursive call to generate all permutations from the next position (index + 1)
        solve(arr, ans, index + 1);

        // Backtrack by swapping back to the original arrangement
        // This allows exploration of different permutations in the next loop iteration
        swap(arr[index], arr[i]);
    }
}

// Main function that initiates the permutation generation
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;  // Stores all possible permutations of `nums`

    // Begin generating permutations from the start (index 0)
    solve(nums, ans, 0);

    // Return all generated permutations
    return ans;
}

int main() {
    // Example input vector
    vector<int> nums = {1, 2, 3};

    // Generate all permutations of `nums`
    vector<vector<int>> ans = permute(nums);

    // Print each permutation in the result
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";  // Print each element in the permutation
        }
        cout << endl;  // New line for each permutation
    }
}
