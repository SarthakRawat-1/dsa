// Problem Statement :- https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/0

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element 'x' at the bottom of the stack 's'
stack <int> insertAtBottom(stack <int> s, int x) {
    // Temporary stack to hold elements as we reverse the stack
    stack <int> temp;

    // Step 1: Transfer all elements from the original stack 's' to the temporary stack 'temp'
    // This will reverse the order of the elements
    while(!s.empty()) {
        temp.push(s.top());  // Push the top element of 's' to 'temp'
        s.pop();             // Pop the top element from 's'
    } 

    // Step 2: Push the element 'x' into the now-empty original stack 's'
    // Since the stack is empty, this ensures 'x' is at the bottom
    s.push(x);

    // Step 3: Transfer all elements back from the temporary stack 'temp' to the original stack 's'
    // This restores the original order of the elements, with 'x' now at the bottom
    while(!temp.empty()) {
        s.push(temp.top());  // Push the top element of 'temp' back to 's'
        temp.pop();          // Pop the top element from 'temp'
    }

    // Return the modified stack with 'x' inserted at the bottom
    return s;
}

int main() {
    stack <int> s;

    s.push(1);
    s.push(2);  
    s.push(3);
    s.push(4);

    int x = 5;

    s = insertAtBottom(s, x);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}