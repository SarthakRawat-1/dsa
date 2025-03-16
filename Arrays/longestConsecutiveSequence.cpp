// Problem Statement :- https://leetcode.com/problems/longest-consecutive-sequence/description/

// Brute Force :- For each element in the array, we will try to find consecutive elements element + 1, element + 2, element + 3 and so on. Thus we will check for the length of the longest consecutive sequence we can build for every element. Among all the lengths we will consider the maximum one.

// #include <bits/stdc++.h>
// using namespace std;

// // Function to perform a linear search for a specific number 'num' in the array 'a'.
// // Returns true if 'num' is found, otherwise returns false.
// bool linearSearch(vector<int>& a, int num) {
//     int n = a.size(); // Get the size of the array.
    
//     // Iterate through the entire array to find the number 'num'.
//     for (int i = 0; i < n; i++) {
//         if (a[i] == num) // If the current element is equal to 'num', return true.
//             return true;
//     }
//     return false; // If 'num' is not found in the array, return false.
// }

// // Function to find the length of the longest consecutive sequence in the array.
// int longestSuccessiveElements(vector<int>& a) {
//     int n = a.size(); // Get the size of the array.
    
//     // Variable to keep track of the maximum length of consecutive sequence.
//     int longest = 1;
    
//     // Step 1: Iterate through each element of the array.
//     for (int i = 0; i < n; i++) {
//         // Pick an element 'x' from the array as the starting point of the sequence.
//         int x = a[i];
        
//         // Initialize a counter 'cnt' to track the length of the current consecutive sequence.
//         int cnt = 1;
        
//         // Step 2: Search for consecutive elements like x+1, x+2, etc. using the linear search function.
//         while (linearSearch(a, x + 1)) {
//             // If x+1 is found in the array, increment 'x' to the next consecutive number.
//             x += 1;
            
//             // Increment the sequence length counter 'cnt'.
//             cnt += 1;
//         }
        
//         // Step 3: After the inner loop completes, update 'longest' with the maximum sequence length encountered so far.
//         longest = max(longest, cnt);
//     }
    
//     // Step 4: Return the maximum length of consecutive sequence found.
//     return longest;
// }

// int main()
// {
//     // Example input array.
//     vector<int> a = {100, 200, 1, 2, 3, 4};

//     // Call the function to find the length of the longest consecutive sequence.
//     int ans = longestSuccessiveElements(a);

//     // Output the result.
//     cout << "The longest consecutive sequence is " << ans << "\n";
//     return 0;
// }


// Better Approach :- We can simply sort the array and run a for loop to find the longest consecutive sequence.

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the longest consecutive sequence in the array.
// int longestSuccessiveElements(vector<int>& a) {
//     int n = a.size(); // Size of the input array.
    
//     // If the array is empty, return 0 as there are no elements to form a sequence.
//     if (n == 0) return 0;

//     // Step 1: Sort the array to arrange elements in ascending order.
//     // Sorting helps in grouping consecutive numbers together.
//     sort(a.begin(), a.end());

//     // Step 2: Initialize variables to keep track of the sequence.
//     // 'lastSmaller' stores the last element included in the current sequence.
//     // It is initialized to INT_MIN (smallest possible value) to start fresh.
//     int lastSmaller = INT_MIN;
    
//     // 'cnt' keeps track of the length of the current sequence.
//     // Start with 0, as we haven't started counting any sequence yet.
//     int cnt = 0;
    
//     // 'longest' keeps track of the maximum length of the sequence encountered so far.
//     // Since the minimum possible sequence length is 1, initialize it to 1.
//     int longest = 1;

//     // Step 3: Iterate over the sorted array to find the longest consecutive sequence.
//     for (int i = 0; i < n; i++) {
//         // Case 1: Check if current element a[i] can be part of the current sequence.
//         // If a[i] is exactly 1 greater than 'lastSmaller', it means this is the next consecutive element.
//         if (a[i] - 1 == lastSmaller) {
//             cnt += 1; // Increment the sequence length.
//             lastSmaller = a[i]; // Update 'lastSmaller' to the current element.
//         }
//         // Case 2: If current element a[i] is equal to 'lastSmaller', we skip it.
//         // This ensures we avoid duplicates in the sequence.
//         else if (a[i] != lastSmaller) {
//             // If a[i] is neither consecutive nor duplicate, we start a new sequence.
//             cnt = 1; // Reset the sequence length to 1 for the new sequence.
//             lastSmaller = a[i]; // Update 'lastSmaller' to the new starting element.
//         }
//         // Update 'longest' to store the maximum sequence length encountered so far.
//         longest = max(longest, cnt);
//     }
    
//     // Step 4: Return the maximum sequence length found during the iteration.
//     return longest;
// }

// int main()
// {
//     vector<int> a = {100, 200, 1, 2, 3, 4};

//     int ans = longestSuccessiveElements(a);

//     cout << "The longest consecutive sequence is " << ans << "\n";
//     return 0;
// }


// Optimal Approach :- First, we will put all the array elements into the set data structure. If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set. If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements. Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.
// We will declare 2 variables, ‘cnt’ → (to store the length of the current sequence), ‘longest’ → (to store the maximum length).
// First, we will put all the array elements into the set data structure. For every element, x, that can be a starting number(i.e. x-1 does not exist in the set) we will do the following :-
// We will set the length of the current sequence(cnt) to 1. Then, again using the set, we will search for the consecutive elements such as x+1, x+2, and so on, and find the maximum possible length of the current sequence. This length will be stored in the variable ‘cnt’. After that, we will compare ‘cnt’ and ‘longest’ and update the variable ‘longest’ with the maximum value (i.e. longest = max(longest, cnt)). Finally, we will have the answer i.e. ‘longest’.

#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>& a) {
    int n = a.size();  // Get the size of the array
    if (n == 0) return 0;  // If the array is empty, return 0

    int longest = 1;  // Variable to store the maximum length of consecutive sequence
    unordered_set<int> st;  // Set to store the unique elements of the array

    // Step 1: Insert all elements from the array into the set
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);  // The set will automatically remove duplicates
    }

    // Step 2: Iterate through each element of the set
    for (auto it : st) {
        // Check if 'it' is the start of a sequence by verifying if 'it-1' does not exist in the set
        if (st.find(it - 1) == st.end()) {
            // 'it' is the starting number of a new sequence
            
            int cnt = 1;  // Initialize the length of the current sequence to 1
            int x = it;   // 'x' holds the current number in the sequence
            
            // Step 3: Find consecutive numbers starting from 'it'
            // Keep searching for x+1, x+2, ... until the next consecutive element is not found in the set
            while (st.find(x + 1) != st.end()) {
                x = x + 1;  // Move to the next consecutive number
                cnt = cnt + 1;  // Increment the length of the current sequence
            }
            
            // Step 4: Compare the length of the current sequence (cnt) with the longest found so far
            longest = max(longest, cnt);  // Update 'longest' with the maximum value
        }
    }
    
    return longest;  // Return the maximum length of consecutive sequence found
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};

    int ans = longestSuccessiveElements(a);

    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
