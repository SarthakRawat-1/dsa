// Problem Statement :- https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Brute Force :- Find all substrings (You can find this using length, i.e. first find 1 length substring, then 2 length substrings and so on) and check which one of them has all unique characters. Longest of them will be our answer.
// Obv ans will atleast be 1 because a character is always unqiue.

#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a substring has all unique characters
bool allUnique(string s, int start, int end) {
    set<char> chars; // Use a set to track characters in the substring
    for (int i = start; i <= end; i++) {
        if (chars.count(s[i])) { // If character is already in the set, it's not unique
            return false;
        }
        chars.insert(s[i]);
    }
    return true;
}

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0; // Variable to store the maximum length of the substring

    // Loop over all possible substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // If the current substring has all unique characters
            if (allUnique(s, i, j)) {
                // Update maxLength if current substring is longer
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}


// Better Approach :- Say you have "ababc", a can be answer, ab can also be answer, aba can't be our answer. So now, we need not check for abab and ababa.
// Now, starting with b, b can be answer, ba can be answer, bab can't be answer. No need to check for babc.
// Continue this for later characters as well. Return the maximum length of the substring.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();  // Length of the string
    int maxLength = 0;   // Variable to store the maximum length

    // Loop to go through each character of the string as the starting point
    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;  // Set to keep track of characters in the current substring
        int currentLength = 0;     // Length of the current substring without repeating characters

        // Loop to extend the substring from the starting point
        for (int j = i; j < n; j++) {
            // If the character has already been seen, stop checking this substring
            if (seen.find(s[j]) != seen.end()) {
                break;
            }

            // Add the character to the set and increase the current substring length
            seen.insert(s[j]);
            currentLength++;

            // Update the maximum length if the current substring is longer
            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;  // Return the maximum length found
}

int main() {
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}


// Optimal Approach :- Consider :- "ababc", a can be answer, so maxlength is 1, ab can also be answer, so maxlength is 2, but aba can't be answer, so maxlength i.e. window remains 2, and we need not check for abab and ababc.
// But go to aba again, we have to remove one a from it. So now, start from ba (removed the first a). This can be answer, window is still 2. Now check bab, can't be answer window remains 2. We have to remove b. 
// Now we have ab (removed b from front), can be answer window remains 2. Now check for abc, can be answer, window updated to 3. Now string is exhausted. So window is 3 which will be maxlength.

// Consider eg :- "abcdecbeadf", a can be answer, till abcde, we can have our answer, window is 5. We have to remove c, remove the first c (which comes after ab). To remove this, we also have to remove ab. So remove all three, and we get dec, our window is now 3. decb, can also be answer (window becomes 4) but decbe can't. We have to remove e.
// Remove first e (i.e. remove de), now we have cbe, can be answer window reduces to 3. cbea can be answer, cbead and cbeadf can also be answer (window updates to 6). String is exhausted. Max value of window was 6, so that is the answer.

// Sliding window can be implemented using two pointers, first (indicates start of substring) and second (indicates end of substring). But how do we know if a character has come before or not? Use a hash table for that as we know we only have 256 characters in ASCII table.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // A boolean array to keep track of characters we've seen in the current window.
    // We use 256 because there are 256 ASCII characters in total.
    vector <bool> count(256, 0);

    // Two pointers, `first` and `second`, to represent the sliding window.
    // `first` indicates the start of the window, and `second` is the end of the window.
    int first = 0, second = 0;

    // Variable `len` keeps track of the length of the longest substring without repeating characters.
    int len = 0;

    // Iterate through the string using `second` as the end pointer of the sliding window.
    while (second < s.size()) {
        // If we encounter a character that is already in the current window (i.e., `count[s[second]]` is true),
        // we need to remove characters from the start (`first` pointer) to ensure the substring is valid
        while (count[s[second]]) {
            // Set the character at `first` pointer to false, meaning we are removing it from the window.
            count[s[first]] = 0;
            // Move the `first` pointer to the right to shrink the window.
            first++;
        }

        // Add the character at `second` pointer to the current window by marking it as seen.
        count[s[second]] = 1;

        // Update the maximum length (`len`) of the valid substring.
        // The length of the current valid window is `second - first + 1`.
        len = max(len, second - first + 1);

        // Move the `second` pointer to the right to explore the next character.
        second++;
    }

    // Return the maximum length of a substring without repeating characters.
    return len;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}

