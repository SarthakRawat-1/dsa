// Problem Statement :- https://www.geeksforgeeks.org/problems/queue-reversal/1

// One approach is to store all the elements of Queue in an Array and then from the back of array, start putting elements back into the Queue.

// A better approach is to use a Stack instead of an Array to store the elements. Then simply pop elements from Stack and add them back to Queue.

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the elements of a queue using a stack
queue<int> queueReversal(queue<int> Q) {
    // Create an empty stack to temporarily store the elements of the queue
    stack<int> S;

    // Step 1: Transfer all elements from the queue to the stack
    // While the queue is not empty, pop elements from the front of the queue and push them onto the stack
    while (!Q.empty()) {
        S.push(Q.front()); // Push the front element of the queue into the stack
        Q.pop();           // Remove the front element from the queue
    }

    // Step 2: Transfer all elements back from the stack to the queue
    // Since the stack is LIFO, popping elements from it will reverse their order
    while (!S.empty()) {
        Q.push(S.top());   // Push the top element of the stack into the queue
        S.pop();           // Remove the top element from the stack
    }

    // Return the reversed queue
    return Q;
}

int main() {
    queue <int> Q;

    Q.push(15);
    Q.push(25);
    Q.push(35);
    Q.push(45);
    Q.push(55);

    Q = queueReversal(Q);

    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }

    return 0;
}