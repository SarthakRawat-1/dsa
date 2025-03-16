// Problem Statement :- https://leetcode.com/problems/removing-stars-from-a-string/description/

// Very similar to backspaceStringCompare.cpp
// You can also do it with string. Keep storing characters in string. When you enounter a *, pop the last character of string and don't append * to string.
// You can do it with two pointer also. Place one pointer in start and iterate over the string. Use another pointer, j, in the array which stores result (same length as string). Now when i points to char, store that in array using j pointer. Move both by 1. If you encounter *, move j back by 1. Now using this array, we can use a for loop from 1 to j - 1, to form the resultant string.

#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    // Approach - 1

    stack <char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    string result = "";

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;


    // Approach - 2

    // string result = "";

    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == '*') {
    //         result.pop_back();
    //     } else {
    //         result.push_back(s[i]);
    //     }
    // }

    // return result;


    // Approach - 3

    // int n = s.length();

    // vector <char> temp(n);

    // int j = 0;

    // for (int i = 0; i < n; i++) {
    //     if (s[i] != '*') {
    //         temp[j] = s[i];
    //         j++;
    //     } else {
    //         j--;
    //     }
    // }

    // string result = "";

    // for (int i = 0; i < j; i++) {
    //     result.push_back(temp[i]);
    // }

    // return result;
}

int main() {
    string s = "erase*****";

    cout << removeStars(s);
}