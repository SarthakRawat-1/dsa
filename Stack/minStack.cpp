// Problem Statement :- https://leetcode.com/problems/min-stack/description/

// We will take two stacks, one normal stack and other stack which holds minimum element.
// If we get a new element, insert it into the normal stack and check if it is less than the top element of the min stack or not. If yes, then we will push the element into min stack. 
// If we want to pop an element from the stack, we will check if it is equal to the top element of the min stack or not. If yes, then we will pop that element from min stack and normal stack both.

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    // Declare two stacks: 'st' for all elements, 'min' to store minimum elements
    stack<int> st, min;

    // Constructor: Initializes the MinStack object
    MinStack() {
        // No initialization needed since we are using STL stacks.
    }
    
    // Pushes an element 'val' onto the stack
    void push(int val) {
        // If 'min' stack is empty or 'val' is less than or equal to the current minimum,
        // push 'val' onto the 'min' stack to update the current minimum.
        if (min.empty() || val <= min.top()) {
            min.push(val);
        }

        // Always push 'val' onto the main stack 'st'
        st.push(val);
    }
    
    // Removes the top element from the stack
    void pop() {
        // If the top of 'st' is the current minimum, remove it from 'min' stack too.
        if (st.top() == min.top()) {
            min.pop();
        }

        // Remove the top element from the main stack
        st.pop();
    }
    
    // Returns the top element of the stack without removing it
    int top() {
        return st.top();
    }
    
    // Retrieves the minimum element in the stack
    int getMin() {
        return min.top();
    }
};
int main() {
    MinStack* obj = new MinStack();

    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Minimum element of the Stack is :- " << obj->getMin() << endl;
    obj->pop();
    cout << "Top element of the Stack is :- " << obj->top() << endl;
    cout << "Minimum element of the Stack is :- " << obj->getMin() << endl;

    return 0;
}