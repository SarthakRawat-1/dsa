// Problem Statement :- https://leetcode.com/problems/find-special-substring-of-length-k/description/

// Use sliding window approach
// Keep a frequency array denoting frequency of each character in string.
// 

#include <bits/stdc++.h>
using namespace std;

bool hasSpecialSubstring(string s, int k) {
    // Initialize the count of consecutive identical characters.
    // Start with 1 because the first character forms a sequence of length 1.
    int count = 1;
    
    // Loop through the string starting from the second character (index 1)
    // The 'count++' in the loop header automatically increases count each iteration,
    // assuming the current sequence continues unless we reset it.
    for (int i = 1; i < s.size(); i++, count++) {
        // Check if the current character is different from the previous one.
        if (s[i] != s[i-1]) {
            // At this point, a block of identical characters has just ended.
            // Check if the ended block's length is exactly equal to k.
            // If it is, the following conditions hold:
            //   - The block itself has length k.
            //   - The character immediately after the block (s[i]) is different.
            //   - The character before the block was either the start of the string or different,
            //     because a change was detected.
            if (count == k)
                return true;
            
            // Reset the count for the new block.
            // We set count to 0 because the loop's 'count++' will immediately increment it to 1,
            // correctly starting a new block with the current character.
            count = 0;
        }
    }
    
    // After the loop, we need to check the last block in the string.
    // If the final sequence of characters (at the end of s) has a length exactly k,
    // it qualifies as a valid substring since there's no following character to violate the condition.
    return (count == k);
}

int main() {
    string s = "aaabaaa";

    cout << hasSpecialSubstring(s, 3);
}