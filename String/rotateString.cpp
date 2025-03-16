// Problem Statement :- https://leetcode.com/problems/rotate-string/description/

// If the lengths of s and goal are different, it's impossible for s to become goal through any number of shifts. So, return false
// String Concatenation Trick :- If you concatenate s with itself (s + s), it will contain all possible shifts of s as its substrings. For example, if s = "abcde", then s + s = "abcdeabcde" contains every possible shift of s within the string.
// After concatenating s with itself, just check if goal is a substring of the concatenated string s + s. If it is, then s can be shifted to become goal

#include <iostream>
#include <string>
using namespace std;

// Function to check if 'goal' can be obtained by shifting 's'
bool canBeShifted(string s, string goal) {
    // Step 1: Check if lengths of s and goal are the same
    if (s.length() != goal.length()) {
        return false; // If lengths differ, it's not possible to shift to make them equal
    }
    
    // Step 2: Concatenate s with itself
    string doubled_s = s + s; // If s = "abcde", doubled_s = "abcdeabcde"
    
    // Step 3: Perform manual substring search to check if goal exists in doubled_s
    int m = doubled_s.length();
    int n = goal.length();
    
    // This loop iterates over doubled_s to check if goal exists as a substring in it. The index i is the starting position of the substring we're going to check.
    // The loop runs from i = 0 to i = m - n inclusive. This is because we want to ensure that we only look at substrings of length n (which is the same as the length of goal) and stop once we’ve checked all possible starting positions.
    // Eg :- Example: If doubled_s = "abcdeabcde" and goal = "cdeab", we only want to check starting positions up to index 5, because from index 6 onward, we can't fit a 5-character substring.
    for (int i = 0; i <= m - n; i++) {
        bool match = true; // Assume it's a match until proven otherwise

        // For each possible starting position i, we check if the substring starting at i in doubled_s matches goal.
        
        // Check if the substring from doubled_s[i] matches goal
        // j is used to compare characters between doubled_s and goal
        for (int j = 0; j < n; j++) {
            if (doubled_s[i + j] != goal[j]) { // doubled_s[i + j]: Refers to the character in doubled_s at the current position i offset by j, goal[j] refers to the character at the jth position of goal.
                match = false; // If at any point, the characters at i + j and j don't match, we set match = false and break out of the inner loop (because there's no point in continuing to check if one character is already wrong).
                break; // Mismatch found, break out of the inner loop
            }
        }
        
        // If a match was found, return true
        if (match) {
            return true;
        }
    }

    // You can also use STL functions to match substring instead of manual search.
    // if (doubled_s.find(goal) != string::npos) {
    //    return true; // If found, return true
    // }
    
    // If no match was found after checking all possible positions, return false
    return false;
}

int main() {
    string s1 = "abcde";
    string goal1 = "cdeab";
    cout << "Test Case 1 - Expected: true, Output: " << canBeShifted(s1, goal1) << endl;

    string s2 = "abcde";
    string goal2 = "abced";
    cout << "Test Case 2 - Expected: false, Output: " << canBeShifted(s2, goal2) << endl;

    return 0;
}

// This approach utilizes a Brute Force or Manual Approach to match substrings. A better approach to achieve the same is KMP Algorithm. 