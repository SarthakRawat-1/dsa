// Problem Statement :- https://leetcode.com/problems/valid-anagram/description/

// First approach is to sort both strings and then you can directly compare if they are equal or not.
// Second approach is to use hashmap and then compare the count of each character in both strings. You need not use a map, you can even use an array of 26 size, as it is given that string only contains lowercase letters.

// Follow up :- What if the inputs contain Unicode characters? How would you adapt your solution to such a case? 
// To solve this, use an array of size 128, as Unicode chaarcters come in the range of 128. Or just use a map.

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        vector <int> count(26, 0); // Size 26 for each alphabet letter, intialized each with 0

        for (char &ch : s) { // Loop to store the count of each character in string s, in the count array
            count[ch - 'a']++; // ch - 'a' gives the index of the character in the array (0 for 'a', 1 for 'b', etc.)
        } 

        for (char &ch : t) { // Loop to decrease the count of elements present in string t, in the count array. 
            count[ch - 'a']--;
        }

        // If the strings were anagram, all the elements in the count array will be 0 at the end. 
        bool allZeros = all_of(count.begin(), count.end(), [](int i) { return i == 0; });

        return allZeros;
}

int main() {
    string s = "badc";
    string t = "baba";

    cout << isAnagram(s, t) << endl;
}