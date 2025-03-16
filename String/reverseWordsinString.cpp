// Problem Statement :- https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the words in a given string
string result(string s) {
    int n = s.length(); // Get the length of the string
    string temp = "";   // Temporary string to hold the current word
    string ans = "";    // Result string to hold the reversed words

    // Iterate through the string from the beginning to the end
    for (int left = 0; left < n; left++) {
        // If the current character is not a space, add it to temp
        if (s[left] != ' ') {
            temp += s[left];
        } 
        // If a space is encountered and temp is not empty, it indicates the end of a word
        else if (s[left] == ' ' && !temp.empty()) {
            // Prepend the current word to ans with a space
            ans = temp + " " + ans; 
            temp = ""; // Reset temp for the next word
        }
    }
    
    // After the loop, check if there’s any remaining word in temp (it could happen if the string does not end with a space)
    if (!temp.empty()) {
        ans = temp + " " + ans; // Add the last word to the result
    }

    // Remove any trailing space if it exists
    if (!ans.empty() && ans.back() == ' ') {
        ans.pop_back();
    }
    
    return ans; // Return the final result with words reversed
}

int main() {
    string st = "  Shogun the Great Lord  "; // Input string with leading and trailing spaces
    cout << "Before reversing words: " << endl;
    cout << st << endl;  
    cout << "After reversing words: " << endl;
    cout << result(st);  
    return 0;
}
