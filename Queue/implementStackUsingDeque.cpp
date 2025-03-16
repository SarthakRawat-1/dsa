// Stack follows LIFO.
// We'll use the push_back() and pop_back() operations of the deque to simulate the stack behavior.

#include <bits/stdc++.h>
using namespace std;

// Class to represent a Stack using Deque
class Stack {
    deque<int> dq; // Standard library deque container

    public:

    // Function to push an element onto the stack
    void push(int x) {
        dq.push_back(x); // Push to the back of deque (like adding to the top of the stack)
        cout << "Pushed " << x << " onto the stack" << endl;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (dq.empty()) {
            cout << "Stack Underflow: No elements to pop" << endl;
        } else {
            cout << "Popped " << dq.back() << " from the stack" << endl;
            dq.pop_back(); // Pop from the back of deque (like removing from the top of the stack)
        }
    }

    // Function to get the top element of the stack
    int top() {
        if (dq.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return dq.back(); // Return the last element in the deque
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return dq.empty(); // Check if deque is empty
    }

    // Function to return the current size of the stack
    int size() {
        return dq.size(); // Return the number of elements in the deque
    }

    // Function to display all elements of the stack
    void display() {
        if (dq.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Elements in stack: ";
        // Traverse deque from back to front to simulate stack display
        for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.display(); 

    cout << "Top element is: " << stk.top() << endl; 

    stk.pop(); 
    stk.display(); 

    cout << "Is stack empty? " << (stk.isEmpty() ? "Yes" : "No") << endl; 
    cout << "Current size of stack: " << stk.size() << endl; 

    return 0;
}
