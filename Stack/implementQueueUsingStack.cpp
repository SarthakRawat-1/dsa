// Problem Statement :- https://leetcode.com/problems/implement-queue-using-stacks/description/

// The main problem is popping the element, as from Queue, the element which was added first will be popped first, but for Stack, the element which was added last will be popped first.
// So, we can use two stacks. When we are asked to pop an element from Queue, we will pop all element from stack (can even print/return the last popped element from Stack which should be the first popped element from Queue) and store all these elements in other Stack.
// Eg :- {13, 15, 16, 17} Pushing into Stack is pretty much same as Queue. Now when we pop from Queue 12 will be removed. But as we are using Stack to implement so first, 17 will be popped (store this in other stack), then 16 (after 17 store this in other stack) and so on. So, our other stack looks like :- {17, 16, 15, 13} Now pop from thisStack, this will remove 13, and we are left with :- {17, 16, 15}
// Now let's say we are asked to push 20. In this case, we will push elements in first Stack (which became empty after popping all elements from it). So, Stack 1 is now :- {20} After this we can also push 18 and it becomes :- {20, 18} Now let's say we want to do pop operation. for this, pop from Stack 2 which holds :- {17, 16, 15} From here, 15 will be popped. Stack 2 becomes :- {17, 16}
// Hence, Stack 1 is being used for Push operations and Stack 2 is being used for Pop operations.

// Now let's say our Stack 2 is empty but Stack 1 still has elements. If we want to do pop operation in this case, we can do what we did in the beginning. Pop all elements from Stack 1 and store them in Stack 2, then just use pop operation on Stack 2 normally. Do this, whenever Stack 2 becomes empty.

// When both Stacks will be empty, we will have an empty Queue.

// For peek operation, it is basically peekFront. We know our front element in Queue will be present in Stack 2. It will actually be the top of Stack 2. 

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> st1, st2; // Two stacks to simulate the queue

public:
    // Check if the queue is empty
    bool empty() {
        // The queue is empty only if both stacks are empty
        return st1.empty() && st2.empty();
    }

    // Push element 'x' to the back of the queue
    void push(int x) {
        // We always push new elements to st1
        st1.push(x);
    }

    // Pop the element from the front of the queue and return it
    int pop() {
        // If the queue is empty, return 0 or handle the error
        if (empty()) {
            return 0; // Assuming 0 is returned for an empty queue
        }

        // If st2 is not empty, the front element is at the top of st2
        if (!st2.empty()) {
            int element = st2.top(); // Get the top element from st2 (front of queue)
            st2.pop(); // Remove it from st2
            return element; // Return the popped element
        } else {
            // If st2 is empty, we need to transfer elements from st1 to st2
            // This reverses the order and simulates FIFO behavior
            while (!st1.empty()) {
                st2.push(st1.top()); // Move top element of st1 to st2
                st1.pop(); // Remove it from st1
            }

            // After transferring, the front of the queue is now at the top of st2
            int element = st2.top(); // Get the top element from st2 (front of queue)
            st2.pop(); // Remove it from st2
            return element; // Return the popped element
        }
    }

    // Get the front element of the queue without removing it
    int peek() {
        // If the queue is empty, return 0 or handle the error
        if (empty()) {
            return 0; // Assuming 0 is returned for an empty queue
        }

        // If st2 is not empty, the front element is at the top of st2
        if (!st2.empty()) {
            return st2.top(); // Return the top element of st2 (front of queue)
        } else {
            // If st2 is empty, we need to transfer elements from st1 to st2
            // This reverses the order and simulates FIFO behavior
            while (!st1.empty()) {
                st2.push(st1.top()); // Move top element of st1 to st2
                st1.pop(); // Remove it from st1
            }

            // After transferring, the front of the queue is now at the top of st2
            return st2.top(); // Return the top element of st2 (front of queue)
        }
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Should print 1
    cout << "Popped element: " << q.pop() << endl; // Should pop 1
    cout << "Front element: " << q.peek() << endl; // Should print 2
    cout << "Popped element: " << q.pop() << endl; // Should pop 2
    cout << "Front element: " << q.peek() << endl; // Should print 3
    cout << "Popped element: " << q.pop() << endl; // Should pop 3

    if (q.empty()) {
        cout << "Queue is empty now." << endl; // Should print that the queue is empty
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
