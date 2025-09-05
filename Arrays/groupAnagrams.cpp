// Problem Statement :- https://leetcode.com/problems/group-anagrams/description/

// If you sort the string (i.e. arrange characters) of two strings, and they are anagrams, after sorting they will form the same string.
// Eg :- ofr and for are both for after sorting.

// Other appraoch :- Vector representing alphabets. Pick first string. Fill the array with freq of corresponding char on that index.
// Then from that array, using the frequencies (non zero), make a string. Ofc this will give you the string in sorted fashion.
// Reset the vector representing alphabets, and continue process for further strings. When the string after making from vector representing alphabets match, they are anagrams.
// Ofc, here also we will use the same map. 
// We eliminated the need for sorting bringing down complexity from n x k log k to n * (k + 26)

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        string temp = strs[i];

        sort(begin(temp), end(temp));

        mp[temp].push_back(strs[i]);
    }

    for (auto &it : mp) {
        result.push_back(it.second);
    }

    return result;
}

// Without Sorting
string generate(string& word) {
    int arr[26] = {0};

    for (char &ch : word) {
        arr[ch - 'a']++;
    }

    string new_word = "";

    for (int i = 0; i < 26; i++) {
        int freq = arr[i];

        if (freq > 0) {
            new_word += string(freq, i + 'a');
        }
    }

    return new_word;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();

    unordered_map<string, vector<string>> mp;
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        string word = strs[i];

        string new_word = generate(word);

        mp[new_word].push_back(word);
    }

    for (auto &it : mp) {
        result.push_back(it.second);
    }

    return result;
}

int main() {

}