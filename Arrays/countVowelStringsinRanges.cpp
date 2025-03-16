// Problem Statement :- https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

// We can make a prefix sum kind of array. This time, the array will store the number of strings which satisfies the given condition upto that index.
// Then, for every query, say (1, 4), we will go to index 0 and index 4, and subtract the value of index 4 from index 0 to get the final answer for that query.

#include <bits/stdc++.h>
using namespace std;

// Function to check if a given character is a vowel
bool isVowel(char &ch) {
    // Check if the character is one of the lowercase vowels: 'a', 'e', 'i', 'o', 'u'
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true; // Return true if the character is a vowel
    return false;      // Otherwise, return false
}

// Function to process queries for vowel strings
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int Q = queries.size(); // Get the number of queries
    int N = words.size();   // Get the number of words in the input list

    // Result vector to store the output for each query
    vector<int> result(Q);

    // Prefix sum array to store cumulative counts of valid words
    vector<int> cumSum(N);
    int sum = 0; // Variable to maintain the cumulative sum

    // Process each word in the input list to compute the prefix sum - O(N)
    for(int i = 0; i < N; i++) {
        // Check if the current word starts and ends with a vowel
        if(isVowel(words[i][0]) && isVowel(words[i].back())) {
            sum++; // Increment the count if the condition is satisfied
        }
        // Update the prefix sum array
        cumSum[i] = sum;
    }

    // Process each query - O(Q)
    for(int i = 0; i < Q; i++) {
        int l = queries[i][0]; // Left index of the range
        int r = queries[i][1]; // Right index of the range

        // Compute the count of valid words in the range [l, r] using prefix sum
        result[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
    }

    // Return the final result containing the answers for all queries
    return result;
}

int main() {
    vector<string> words = {"aba","bcb","ece","aa","e"}; // Input list of words
    vector<vector<int>> queries = {{0,2},{2,3},{0,4}}; // Input queries
    vector<int> result = vowelStrings(words, queries); // Process the queries
    for(auto x : result) cout << x << " "; // Print the result

    return 0;
}