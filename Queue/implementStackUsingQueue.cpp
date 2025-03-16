// Problem Statement :- https://leetcode.com/problems/implement-stack-using-queues/description/

// The main difference is in popping the element, as from the stack the element which was pushed last will be popped but from queue, the element which was pushed first will be popped first.
// So we will use two queues. 
// Say, you had :- {10, 13, 50} Now when we want to use pop operation, 50 should be deleted (for Stack) but as we are using a Queue, 10 will be deleted instead. So what we do is that we use pop operation on this Queue and pop 10 and 13 from it and store in another Queue. Now only 50 is left, just pop it and don't put it in 2nd Queue. 
// If we want to push 15 now, we will push it in 2nd Queue only. And our 2nd Queue is now :- {10, 13, 15} and 1st Queue is empty. Hence, we push elements to that Queue which already has elements.
// Now if we want to use pop operation again. We need to pop 15, as per Stack. So again, pop elements 10 and 13 from this Queue and store them in Queue 1. Then pop 15 from Queue 2. Hence, pop from that Queue which already has elements. Store the elements which will remain after popping in other Queue.

// Stack will be empty if both Queues are empty.

// The top element of Stack will be the element at back in that Queue which is filled with elements.

#include <bits/stdc++.h>
using namespace std;

class stackUsingQueue {
    queue<int> Q1; 
    queue<int> Q2; 

public:
    // Function to check if the stack is empty
    bool empty() {
        // Stack is empty if both queues are empty
        return Q1.empty() && Q2.empty();
    }

    // Function to push an element 'x' onto the stack
    void push(int x) {
        // Push to Q1 if it's empty (You can also push to Q2)
        if (empty()) {
            Q1.push(x); // If both queues are empty, push into Q1
        } else if (Q1.empty()) {
            Q2.push(x); // If Q1 is empty, push into Q2
        } else {
            Q1.push(x); // Otherwise, push into Q1
        }
    }

    // Function to pop the top element from the stack
    int pop() {
        // If both queues are empty, return 0 (assuming this for empty stack)
        if (empty()) {
            return 0;
        }

        // If Q1 is empty, we need to pop from Q2
        if (Q1.empty()) {
            // Move all elements except the last one from Q2 to Q1
            while (Q2.size() > 1) {
                Q1.push(Q2.front());
                Q2.pop();
            }

            // The last element in Q2 is the one to pop (LIFO behavior)
            int element = Q2.front(); // Get the last element
            Q2.pop(); // Remove it from Q2
            return element; // Return the popped element
        } else {
            // If Q2 is empty, we need to pop from Q1
            // Move all elements except the last one from Q1 to Q2
            while (Q1.size() > 1) {
                Q2.push(Q1.front());
                Q1.pop();
            }

            // The last element in Q1 is the one to pop
            int element = Q1.front(); // Get the last element
            Q1.pop(); // Remove it from Q1
            return element; // Return the popped element
        }
    }

    // Function to get the top element without popping it
    int top() {
        // If the stack is empty, return 0 (assuming this for empty stack)
        if (empty()) {
            return 0;
        }

        // The top element is the back of the non-empty queue
        if (Q1.empty()) {
            return Q2.back(); // Return the back element of Q2
        } else {
            return Q1.back(); // Return the back element of Q1
        }
    }
};

int main() {
    stackUsingQueue myStack;

    myStack.push(10);
    myStack.push(13);
    myStack.push(50);
    cout << "Top element: " << myStack.top() << endl; 

    cout << "Popped element: " << myStack.pop() << endl; 
    cout << "Top element: " << myStack.top() << endl; 

    myStack.push(15); 
    cout << "Top element: " << myStack.top() << endl; 

    cout << "Popped element: " << myStack.pop() << endl;
    cout << "Top element: " << myStack.top() << endl; 
    cout << "Popped element: " << myStack.pop() << endl; 

    if (myStack.empty()) {
        cout << "Stack is empty now." << endl; 
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
