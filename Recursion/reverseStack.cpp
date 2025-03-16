// Problem Statement :- https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

#include <iostream>
#include <stack>
using namespace std;

/*
Approach:
This solution reverses a stack using recursion with O(N^2) time complexity and O(N) auxiliary space.
The algorithm works in two phases:

1. Recursive Unwinding:
   - Remove elements from the stack until it's empty
   - Maintain elements in the function call stack

2. Bottom Insertion:
   - Re-insert elements at the bottom of the stack using recursion
   - Each element from the call stack is inserted at the current bottom position

Key Operations:
- reverse(): Recursively empties the stack then rebuilds it in reverse order
- insertAtBottom(): Helper that ensures elements are inserted at the bottom
*/

class Solution {
public:
    void reverse(stack<int> &St) {
        // Base case: if stack is empty, return (unwinding complete)
        if (St.empty()) return;
        
        // Step 1: Remove top element and store in function call stack
        int top = St.top();
        St.pop();
        
        // Step 2: Recursively reverse remaining elements
        reverse(St);
        
        // Step 3: Insert the stored element at the bottom
        insertAtBottom(St, top);
    }

private:
    void insertAtBottom(stack<int> &St, int element) {
        // Base case: if stack is empty, simply push the element
        if (St.empty()) {
            St.push(element);
            return;
        }
        
        // Step 1: Remove current top element
        int top = St.top();
        St.pop();
        
        // Step 2: Recursively insert target element at new bottom
        insertAtBottom(St, element);
        
        // Step 3: Push back the original top element
        St.push(top);
    }
};

/* Helper function to print stack contents without modifying it */
void printStack(stack<int> s) {  // Pass by value to preserve original
    cout << "{";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << ",";
    }
    cout << "}";
}

int main() {
    Solution sol;
    
    // Test Case 1: Sample input from problem statement
    stack<int> test1;
    test1.push(3); test1.push(2); test1.push(1); test1.push(7); test1.push(6);
    cout << "Test 1 - Before: ";
    printStack(test1);
    sol.reverse(test1);
    cout << "\n         After:  ";
    printStack(test1); // Expected: {6,7,1,2,3}
    cout << "\n\n";
    
    return 0;
}