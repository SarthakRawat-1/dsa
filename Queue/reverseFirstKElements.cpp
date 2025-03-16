// Problem Statement :- https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions

// We can pop first k elements from Queue and store them in a Stack. 
// One way to do is to store the rest of the elements of Queue in an array and pop them. Then we can pop elements from Stack and store them back in Queue, and after that store the elements from Array into Queue.
// But a better way is to count the number of elements left in Queue after k elements were removed. Then push the elements from Stack into the Queue. Then start popping and pushing elements from Queue back to Queue such that all numbers that were left after k elements will come behind them.  

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the first 'k' elements of the queue
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> S;  // Stack to reverse the first 'k' elements

    // Step 1: Push the first 'k' elements from the queue into the stack
    for (int i = 0; i < k; i++) {
        S.push(q.front()); // Push the front element of the queue onto the stack
        q.pop();           // Pop the front element from the queue
    }

    // Step 2: Size of remaining elements in the queue after 'k' elements are removed
    int n = q.size(); // Store the number of elements left in the queue

    // Step 3: Push elements from the stack back into the queue
    // This will reverse the order of the first 'k' elements
    while (!S.empty()) {
        q.push(S.top()); // Push the top element of the stack into the queue
        S.pop();         // Pop the top element from the stack
    }

    // Step 4: Move the remaining 'n' elements (after the first 'k' were reversed)
    // to the back of the queue to maintain the original order of these elements
    while (n--) {
        q.push(q.front()); // Push the front element of the queue to the back
        q.pop();           // Pop the front element from the queue
    }

    // Return the modified queue
    return q;
}

int main() {
    queue <int> Q;

    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    Q.push(70); 

    int k = 3;

    Q = modifyQueue(Q, k);

    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }

    return 0;
}