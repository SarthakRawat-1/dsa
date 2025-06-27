// Problem Statement :- https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-26

// If in an element, we have both letters same, then we can take it in our palindrome. If there are more than one element like this, then we can take only one of them (if the letters are different, like 'bb' and 'cc'), this is because, this will go in mid of palindrome. If both are same however (like 'aa' and 'aa'), then we can take both, as now they can be placed outside mid.
// If the element has both letters different, then we can take it in our palindrome, only if we have the reverse of it.

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> mp; // To store the frequency of each word
    int result = 0;

    // First pass: Try to form valid palindrome pairs
    for (string &word : words) {
        string reverseWord = word;
        swap(reverseWord[0], reverseWord[1]); // Get the reversed version of the word

        // Check if the reverse exists in the map
        if (mp[reverseWord] > 0) {
            // If yes, then we can form a palindrome pair (word + reverseWord), which adds 4 to the length
            result += 4;
            mp[reverseWord]--; // Use one instance of the reverse word
        } else {
            // Otherwise, store the current word for possible future matches
            mp[word]++;
        }
    }

    // Second pass: Check if there's a central word we can place in the middle of the palindrome
    for (auto &it : mp) {
        string word = it.first;
        int count = it.second;

        // If the word is like "aa", "bb", i.e., both letters are same and at least one occurrence exists
        if (word[0] == word[1] && count > 0) {
            result += 2; // We can place one such word in the center
            break; // Only one such central word is allowed
        }
    }

    return result;
}

int main() {
    vector<string> words = {"lc", "cl", "gg"};
    cout << longestPalindrome(words) << endl;
    return 0;
}