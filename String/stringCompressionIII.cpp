// Problem Statement :- https://leetcode.com/problems/string-compression-iii/description/

#include <bits/stdc++.h>
using namespace std;

// Function to compress a string by grouping identical characters
string compressedString(string word) {
    string comp = "";  // Stores the compressed string result

    int n = word.length(); // Length of the original string
    int i = 0; // Iterator to go through each character in the string

    // Loop through the characters in the input string
    while(i < n) {
        int count = 0;   // Count occurrences of the current character
        char ch = word[i]; // Current character to be compressed

        // Count occurrences of the same character up to 9 times, or until different character
        while(i < n && count < 9 && word[i] == ch) {
            count++; // Increment the count for consecutive identical characters
            i++; // Move to the next character
        }

        // Add the count followed by the character to the compressed result string
        comp += to_string(count) + ch;
    }

    return comp;  // Return the compressed string
}

int main() {
    // Test example (you can provide any string to see the compressed output)
    string word = "aaabbbccccc";
    cout << compressedString(word) << endl; // Should output "3a3b5c"
}
