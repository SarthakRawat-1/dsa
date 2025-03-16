#include <bits/stdc++.h>
using namespace std;

// Function to reverse the elements of an array using a stack
void reverseArray(vector<char> &s, int n) {
    // Declare a stack to store the characters
    stack <char> S;

    // Push all characters from the array into the stack
    // The stack follows LIFO (Last In, First Out) order
    // So, the last element pushed into the stack will be the first to come out
    for (int i = 0; i < n; i++) {
        S.push(s[i]);  // Push each character of the vector 's' into the stack
    }

    // Initialize an index 'i' to track the position in the array 's'
    int i = 0;

    // Pop characters from the stack and place them back in the array 's'
    // This reverses the original order of the elements
    while (!S.empty()) {
        s[i] = S.top();  // Get the top element from the stack
        S.pop();         // Remove the top element from the stack
        i++;             // Move to the next position in the array
    }
}

int main() {
    vector<char> s = {'H', 'e', 'l', 'l', 'o'};

    reverseArray(s, s.size());

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
}