// Problem Statement :- https://www.geeksforgeeks.org/problems/string-manipulation3706/0

// This is a lot similar to makeArrayBeautiful.cpp

#include <bits/stdc++.h>
using namespace std;

// Function to remove consecutive same strings and return the size of the resulting stack
int removeConsecutiveSame(vector <string> v) {
    // Stack to store strings while checking for consecutive duplicates
    stack <string> s;

    // Iterate over the vector of strings
    for (int i = 0; i < v.size(); i++) {
        // If stack is empty, push the current string
        if (s.empty()) {
            s.push(v[i]);
        } 
        // If the top string of the stack is the same as the current string, pop the top element (remove the consecutive pair)
        else if (s.top() == v[i]) {
            s.pop();
        } 
        // If the top string is different from the current string, push the current string onto the stack
        else {
            s.push(v[i]);
        }
    }

    // The size of the stack represents the number of non-consecutive elements left after removal
    return s.size();
}

int main() {
    vector <string> str = {"ab", "ac", "da", "da", "ac", "ab", "ea"};

    cout << removeConsecutiveSame(str);
}