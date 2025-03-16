// Problem Statement :- https://leetcode.com/problems/reverse-words-in-a-string/description/

// Use a stack to push all the words in a stack. Now, all the words of the string are present in the stack, but in reverse order Pop elements of the stack one by one and add them to our answer variable. Remember to add a space between the words as well. 

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the words in a string
string reverseWords(string s) {
    // Add a space at the end of the string to handle the last word
    // This ensures the last word is pushed into the stack when we encounter a space
    s += " ";
    
    // Stack to store the words in reverse order
    stack<string> st;
    string str = "";  // Variable to accumulate characters of a word
    
    // Iterate through the string
    for (int i = 0; i < s.length(); i++) {
        // When a space is encountered, a word has ended
        if (s[i] == ' ') {
            // Push the word to the stack
            if (!str.empty()) { // To avoid pushing empty strings (from multiple spaces)
                st.push(str);
            }
            // Reset the str to start accumulating the next word
            str = "";
        } else {
            // Add the character to the current word
            str += s[i];
        }
    }

    // Variable to hold the final reversed sentence
    string ans = "";
    
    // Pop words from the stack and construct the reversed sentence
    while (!st.empty()) {
        // Append the word from the top of the stack to ans
        ans += st.top();
        st.pop();
        
        // Add a space after each word except the last one
        if (!st.empty()) {
            ans += " ";
        }
    }
    
    return ans;
}

int main() {
    string s = "Shogun the Great Lord";
    
    cout << "Before reversing words : " << endl;
    cout << s << endl;

    string reversed = reverseWords(s);
    
    cout << "After reversing words : " << endl;
    cout << reversed;
    
    return 0;
}
