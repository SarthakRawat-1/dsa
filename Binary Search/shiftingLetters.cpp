// Problem Statement :- https://leetcode.com/problems/shifting-letters/description/

// Shifting Letters I
// We notice that for any input lets say, "abc",
// s = "abc", shifts = [3,5,9]
// Output: "rpl"
// After shifting the first 1 letters of s by 3, we have "dbc".
// After shifting the first 2 letters of s by 5, we have "igc".
// After shifting the first 3 letters of s by 9, we have "rpl", the answer.
// This is equivalent to shifting "abc" with shifts=[3+5+9 , 5+9 , 9 ] == [17 , 14 , 9]
// We observe that we have to maintain a reverse prefix sum of the shifts array and this will be equal to the number of shifts for each character.

// Shifting Letters II
// We will use Difference Array concept for this.
// 

#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    int cumulativeShift = 0; // This will store the cumulative shift from the end.
    
    // Traverse from the last character to the first.
    // This way, each character s[i] gets the sum of all shifts from i to n-1.
    for (int i = n - 1; i >= 0; i--) {
        // Update the cumulative shift with the current shift value.
        // Use modulo 26 since there are 26 letters in the alphabet.
        cumulativeShift = (cumulativeShift + shifts[i]) % 26;
        
        // Convert the character to a 0-indexed number ('a' -> 0, 'b' -> 1, ...),
        // add the cumulative shift, apply modulo 26 to wrap around,
        // then convert back to a character.
        s[i] = (char)(((s[i] - 'a' + cumulativeShift) % 26) + 'a');
    }
    
    return s;
}


