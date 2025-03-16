// Problem Statement :- https://leetcode.com/problems/longest-palindrome/description/

// It is quite easy to solve since we only have to return length of the longest palindrome.
// If a letter appears even times we will count all of it's occurences in the length. This is because even times means one half can be put in front and one half in back.
// If a letter appears odd number of times, we will select odd - 1 letters from that and add to the length. This is because we need that even number of times.
// Lastly, if any letter appears odd number of times, we will just increase one in the length. This is because one of those can be added in the middle. Eg :- aaabb, a appears odd number of times and b appears even number of times so length = 2 + (3 - 2) = 4, but as one of the element i.e. a appears odd number of times we can take length to be 5 because, the rest a can be isnerted in middle like :- ababa
// Of course, since only one element can be inserted in the middle, no matter how many letters we have with odd occurences. We can only add one of them in the middle.
// In our problem statement, the string can contain both uppercase and lowercase letters, so we will treat both of them differently when counting for their number of occurences because 'A' is not equal to 'a'. We can do so by creating two arrays of length 26. One to store count of lowercase letters and other to store count of uppercase letters.

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    // Step 1: Create two arrays of size 26 to store the count of lowercase and uppercase letters
    int lowercase[26] = {0}; // To store counts of 'a' to 'z'
    int uppercase[26] = {0}; // To store counts of 'A' to 'Z'

    // Step 2: Traverse through the string and count occurrences of each letter
    for (char c : s) {
        if (islower(c)) {
            // If character is lowercase, increment the corresponding index in lowercase array
            lowercase[c - 'a']++;
        } else {
            // If character is uppercase, increment the corresponding index in uppercase array
            uppercase[c - 'A']++;
        }
    }

    // Step 3: Initialize variables to track the palindrome length and whether an odd count exists
    int palindromeLength = 0; 
    bool oddCountFound = false;

    // Step 4: Calculate the length of the longest palindrome by processing the counts of lowercase letters
    for (int i = 0; i < 26; i++) {
        if (lowercase[i] % 2 == 0) {
            // If the count is even, add all occurrences to the palindrome length
            palindromeLength += lowercase[i];
        } else {
            // If the count is odd, add the largest even number (count - 1) to the length
            palindromeLength += lowercase[i] - 1;
            // Mark that we found an odd count, meaning one letter can be placed in the middle
            oddCountFound = true;
        }
    }

    // Step 5: Do the same for uppercase letters
    for (int i = 0; i < 26; i++) {
        if (uppercase[i] % 2 == 0) {
            // If the count is even, add all occurrences to the palindrome length
            palindromeLength += uppercase[i];
        } else {
            // If the count is odd, add the largest even number (count - 1) to the length
            palindromeLength += uppercase[i] - 1;
            // Mark that we found an odd count
            oddCountFound = true;
        }
    }

    // Step 6: If there was at least one odd count, add 1 to the length for the middle character
    if (oddCountFound) {
        palindromeLength += 1;
    }

    // Step 7: Return the calculated palindrome length
    return palindromeLength;
}

int main() {
    // Example 1: Input "abccccdd", output should be 7
    string s1 = "abccccdd";
    cout << "Longest palindrome length for \"" << s1 << "\" is: " << longestPalindrome(s1) << endl;

    // Example 2: Input "a", output should be 1
    string s2 = "a";
    cout << "Longest palindrome length for \"" << s2 << "\" is: " << longestPalindrome(s2) << endl;

    return 0;
}
