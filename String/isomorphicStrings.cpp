// Problem Statement :- https://leetcode.com/problems/isomorphic-strings/description/

// We will use map data structure for this.
// Let's say we have s = egg and t = add, at index 0 we have 'e' in string s and 'a' in string t. So, we map e with a. Then increase index by 1, now we have 'g' in string s and 'd' in string t, so we map g with d. Again, increasind index by 1, but this time g is already mapped with d, so we will just use that.
// For each character, we will first check if the character is already mapped or not.

// Consider another eg, s = foo and t = bar, at index 0, f will be mapped with b, then o will be mapped with a, but after that as there is another o, we have to map it with a, but last char in t is r so strings don't match.

// How to fulfill the condition, that no two characters may map to the same character? Consider s = xadc and t = baba, at index 0, we will map x with b, at index 1, we will map a with a, at index 2, we have d and we can't map it to b because we have already mapped x with b, same goes for last index, we can't map c with a now. But with just one map, how do we know that b in string t was already mapped to x in string s?? To rectify, we need another map, to find if the char in string t has been mapped before with some char in string s.

#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    // Create two maps: 
    // mp1 will map characters from string 's' to corresponding characters in string 't'.
    // mp2 will map characters from string 't' to corresponding characters in string 's'.
    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    int n = s.length(); // Length of string

    // Traverse through each character in both strings 's' and 't'.
    for (int i = 0; i < n; i++) {
        char ch1 = s[i]; // Get the current character from string 's'
        char ch2 = t[i]; // Get the current character from string 't'

        // Condition 1: If ch1 (from 's') is already mapped to some character in 't' but not ch2, return false.
        // This means that ch1 was already paired with a different character from 't' earlier.
        // Condition 2: If ch2 (from 't') is already mapped to some character in 's' but not ch1, return false.
        // This prevents two different characters in 's' from being mapped to the same character in 't'.
        if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
            return false;
        }

        mp1[ch1] = ch2; // Add the mapping from ch1 -> ch2 in the first map (mp1).
        mp2[ch2] = ch1; // Add the mapping from ch2 -> ch1 in the second map (mp2).
    }

    // If we went through all the characters and found no conflicts, the strings are isomorphic.
    return true;
}

int main() {
    string s = "badc";
    string t = "baba";

    cout << isIsomorphic(s, t) << endl;
}