// Problem Statement :- https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

#include <bits/stdc++.h>
using namespace std;

// Instead of this function, we could have also used a Set.
bool isVowel(char &ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

// Function to determine if the two halves of the string `s` have the same number of vowels.
bool halvesAreAlike(string s) {
    // Calculate the length of the string `s`.
    int n = s.length();
        
    // Determine the midpoint of the string to divide it into two halves.
    int mid = n / 2;
    
    // Initialize pointers `i` and `j` to traverse the first and second halves of the string.
    int i = 0;     // Pointer for the first half (left half)
    int j = mid;   // Pointer for the second half (right half)
    
    // Initialize counters for vowels in each half.
    int countL = 0;  // Count of vowels in the left half
    int countR = 0;  // Count of vowels in the right half
    
    // Traverse each half of the string using `i` and `j`.
    // `i` iterates through the first half and `j` iterates through the second half.
    while (i < n / 2 && j < n) {
        // If the character at `i` in the left half is a vowel, increment `countL`.
        if (isVowel(s[i])) countL++;
        
        // If the character at `j` in the right half is a vowel, increment `countR`.
        if (isVowel(s[j])) countR++;
        
        // Move to the next character in both halves.
        i++;
        j++;
    }
    
    // Return true if the number of vowels in the left and right halves are equal.
    // This indicates that both halves are "alike" in terms of vowel counts.
    return countL == countR;
}

int main() {
    string s = "book";
    cout << halvesAreAlike(s) << endl;
    return 0;
}