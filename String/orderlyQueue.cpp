// Problem Statement :- https://leetcode.com/problems/orderly-queue/description/

// Take any string, for eg :- "baaca" If we are given freedom to choose any two characters and swap them. With this, we can sort any string.

// Consider eg :- "ceabd" and k = 2, now try to use the logic given above. Say, we want to swap c and e. We can do this even with this k = 2 condition. 
// For this, put e to the end, we get "cabde", then send c to end, we get "abdec", now send a to end, we get "bdeca", now send b to end, we get "decab", and finally we send d to end, we got "ecabd" and we have swapped e and c successfully.
// What this means is that even with this k boundation. We can swap any two characters in the string. And if we can swap any two characters in the string, we know that we can sort any string.
// We also know that sorted string is lexicographically the smallest and hence, our output will always be the sorted string of the given string.

// But this is not true for k = 1, as we only have one option , send the first char to the end (no other choice exists). In this case, try all possible permutations obtained from this and find the lexicographically smallest one.

#include <bits/stdc++.h>
using namespace std;

string orderlyQueue(string s, int k) {
    // Case 1: If k > 1, we have enough flexibility to sort the string.
    // We can freely swap any two characters by rearranging through repeated operations.
    // Thus, we can simply sort the string to get the lexicographically smallest result.
    if(k > 1) {
        sort(begin(s), end(s));  // Sort `s` in ascending order
        return s;                 // Return the sorted string as it is the smallest lexicographical order
    }
    
    // Case 2: When k = 1, we are restricted to only one operation:
    // Moving the first character to the end. This limitation means we can only create rotations of `s`.
    // We need to find the smallest lexicographical rotation among all possible rotations.
    
    string result = s;  // Initialize `result` as `s` itself for comparison
    for(int i = 1; i < s.length(); i++) {  // Iterate through possible rotations
        // Create a rotated version of `s` by moving the substring starting from index `i` to the beginning
        // and appending the initial part of the string from index `0` to `i-1`.
        string temp = s.substr(i) + s.substr(0, i);
        
        // Compare and store the lexicographically smallest rotation found so far
        result = min(result, temp);
    }
    
    // After checking all rotations, `result` contains the lexicographically smallest rotation.
    return result;
}

int main() {
    string s = "baaca";
    int k = 3;

    cout << orderlyQueue(s, k) << endl;

    return 0;
}