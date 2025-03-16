// Queue follows FIFO.
// We'll use the push_back() and pop_front() operations of the deque to simulate the queue behavior.

#include <bits/stdc++.h>
using namespace std;

// Class to represent a Queue using Deque
class Queue {
    deque<int> dq; // Standard library deque container

    public:
    
    // Function to enqueue an element (insert at the back)
    void enqueue(int x) {
        dq.push_back(x); // Insert element at the back of deque
        cout << "Enqueued " << x << " into the queue" << endl;
    }

    // Function to dequeue an element (remove from the front)
    void dequeue() {
        if (dq.empty()) {
            cout << "Queue Underflow: No elements to dequeue" << endl;
        } else {
            cout << "Dequeued " << dq.front() << " from the queue" << endl;
            dq.pop_front(); // Remove element from the front of deque
        }
    }

    // Function to get the front element of the queue
    int front() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return dq.front(); // Return the first element in the deque
    }

    // Function to get the rear element of the queue
    int rear() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return dq.back(); // Return the last element in the deque
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return dq.empty(); // Check if deque is empty
    }

    // Function to return the current size of the queue
    int size() {
        return dq.size(); // Return the number of elements in the deque
    }

    // Function to display all elements of the queue
    void display() {
        if (dq.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Elements in queue: ";
        // Traverse deque from front to back to simulate queue display
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); 

    cout << "Front element is: " << q.front() << endl; 
    cout << "Rear element is: " << q.rear() << endl; 

    q.dequeue(); 
    q.display(); 

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 

    cout << "Current size of queue: " << q.size() << endl; 
    return 0;
}
