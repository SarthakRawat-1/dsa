// Problem Statement :- https://leetcode.com/problems/string-matching-in-an-array/description/

// You can solve this using Brute Force or KMP Algorithm.

#include <bits/stdc++.h>
using namespace std;

// Optimized Approach :- Sort the array by the lengths of the words. For each word, check only the longer words for substring inclusion using std::string::find (or any efficient substring search method).
// Function to find all words that are substrings of other words in the list
vector<string> stringMatching(vector<string>& words) {
    int n = words.size(); // Number of words in the list

    // Vector to store pairs of word lengths and the corresponding words
    vector<pair<int, string>> vp;

    // Populate the vector with pairs of word size and the word itself
    for (int i = 0; i < n; i++) {
        vp.push_back({words[i].size(), words[i]});
    }

    // Sort the vector based on word lengths (ascending order)
    sort(vp.begin(), vp.end());

    // Vector to store the result - words that are substrings of other words
    vector<string> ans;

    // Iterate through the sorted vector to find substrings
    for (int i = 0; i < n; i++) {
        // Compare the current word with all larger words
        for (int j = n - 1; j > i; j--) {
            // Check if the current word is a substring of a larger word
            if (vp[j].second.find(vp[i].second) != string::npos) {
                ans.push_back(vp[i].second); // Add the word to the result
                break; // Move to the next word, as it is already found
            }
        }
    }

    return ans; // Return the list of substring words
}

int main() {
    vector<string> words = {"mass","as","hero","superhero"}; // Input array of words
    vector<string> result = stringMatching(words); // Find the words that are substrings of other words in the list
    for (auto x : result) cout << x << " "; // Print the result
    return 0;
}