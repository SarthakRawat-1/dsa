// Problem Statement :- https://leetcode.com/problems/delete-columns-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    // Get the number of strings in the vector `strs`
    int n = strs.size();
    
    // Get the length of each string (all strings are of the same length by problem constraints)
    int k = strs[0].length();
    
    // Initialize a counter to track the number of columns that need to be deleted
    int count = 0;
    
    // Iterate through each column in the strings (each position `i` across all strings)
    for(int i = 0; i < k; i++) {
        
        // Check each consecutive pair of strings to see if the characters in column `i` are sorted
        for(int j = 1; j < n; j++) {
            
            // If the current character in column `i` of string `j` is smaller than the character in the same column of the previous string,
            // it indicates that this column is not sorted in lexicographical order
            if(strs[j][i] < strs[j-1][i]) {
                
                // Increment the count of columns to delete and break out of this column’s check
                // as we already know it’s unsorted.
                count++;
                break;
            }
        }
    }
    
    // Return the total number of columns that need to be deleted to make each remaining column sorted
    return count;
}

int main() {
    vector <string> strs = {"cba","daf","ghi"};
    cout << minDeletionSize(strs) << endl;
    return 0;
}