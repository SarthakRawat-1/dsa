// Problem Statement :- https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

/*
Approach:
This solution sorts a stack using recursion with O(N^2) time complexity and O(N) auxiliary space.
The algorithm works in two phases:

1. Recursive Unwinding:
   - Remove elements from the stack until it's empty
   - Elements are removed in LIFO order (original stack order)

2. Sorted Insertion:
   - Re-insert elements back into the stack in sorted order
   - Always maintain the stack in descending order (largest at top)
   - Uses a helper function to find the correct position for each element

Key Operations:
- sort(): Recursively empties the stack then rebuilds it sorted
- insert(): Helper that ensures elements are inserted in correct order
*/

#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    // Main function to sort the stack
    void sort(stack<int> &s) {
        // Base case: if stack is empty, return
        if (s.empty()) {
            return;
        }
        // Remove the top element
        int top = s.top();
        s.pop();
        // Recursively sort the remaining stack
        sort(s);
        // Insert the removed element in sorted order
        insert(s, top);
    }

private:
    // Helper function to insert an element into the sorted stack
    void insert(stack<int> &s, int element) {
        // If stack is empty or current top is <= element, push the element
        if (s.empty() || s.top() <= element) {
            s.push(element);
        } else {
            // Remove the top element which is greater than the current element
            int top = s.top();
            s.pop();
            // Recursively insert the element into the remaining stack
            insert(s, element);
            // Push back the previously removed top element
            s.push(top);
        }
    }
};

// Test helper function
void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    Solution solver;
    
    // Test Case 1: Basic test
    stack<int> test1;
    test1.push(3);
    test1.push(2);
    test1.push(1);
    cout << "Test 1 Before: "; printStack(test1);
    solver.sort(test1);
    cout << "Test 1 After:  "; printStack(test1);
    cout << "Expected: 1 2 3\n\n";

    return 0;
}