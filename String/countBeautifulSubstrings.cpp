// Problem Statement :- https://leetcode.com/problems/count-beautiful-substrings-i/description/

// Due to relaxing constraints, we can just use a brute force approach. We will simply find all susbtrings and in all those check which substring satisfies the given conditions.

// Problem Statement :- https://leetcode.com/problems/count-beautiful-substrings-i/description/

#include <bits/stdc++.h>    
using namespace std;

// Helper function to check if a character is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to count beautiful substrings in the string 's' with a given condition 'k'
int beautifulSubstrings(string s, int k) {
    int n = s.length(); // Get the length of the string
    int count = 0; // Variable to store the count of beautiful substrings

    // Outer loop to start each substring from index 'i'
    for (int i = 0; i < n; i++) {
        int vowels = 0;     // Counts the number of vowels in the current substring
        int consonants = 0; // Counts the number of consonants in the current substring

        // Inner loop to extend the substring from index 'i' to 'j'
        for (int j = i; j < n; j++) {
            // Check if the character is a vowel or consonant and update counts accordingly
            if (isVowel(s[j])) {
                vowels++;
            } else {
                consonants++;
            }

            // Check the conditions for a "beautiful" substring:
            // 1. Equal number of vowels and consonants
            // 2. The product of vowels and consonants is divisible by k
            if (vowels == consonants && (vowels * consonants) % k == 0) {
                count++; // If both conditions are met, increment the count
            }
        }
    }
    
    return count; // Return the total count of beautiful substrings
}

int main() {
    string s = "aeiouxyz";
    int k = 2;
    cout << "Number of beautiful substrings: " << beautifulSubstrings(s, k) << endl;
}
