// Let's say initially we only have one element in our Queue, say 1. Then 2 is enqueued, so for this we will have to create a new node. Similarly, we can also add 5 and 6. Here, also we will have to maintain front and rear pointers. Initally both will be NULL.
// Elements which we want to enqueue will come after element pointed to by rear and once they are enqueued, rear will point to them. 
// When we dequeue an element, the front pointer which was pointing to the first node, the element at front will be deleted (using help of a temp pointer) and front will move to the next node. 

// To check if Queue is empty or not, jsut check if front points to NULL.

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;  // Variable to store the value of the node
    Node* next;  // Pointer to the next node in the queue

    // Constructor to initialize the node with a given value
    Node(int value) {
        data = value;
        next = NULL;  // By default, next is set to NULL (as it's the last node in the queue for now)
    }
};
    
class Queue {
    Node* front;  // Pointer to the front node (the node to be dequeued)
    Node* rear;   // Pointer to the rear node (the node where new elements will be enqueued)
    int size = 0;  // Variable to keep track of the size of the queue

    public:

    // Constructor to initialize the Queue
    Queue() {
        front = NULL;  // When queue is created, both front and rear pointers are set to NULL
        rear = NULL;
    }

    // Function to check if the queue is empty by verifying if the front is NULL
    bool isEmpty() {
        return front == NULL;
    }

    // Function to add (enqueue) an element into the queue
    void enqueue(int x) {
        // If the queue is empty, set both front and rear to the new node
        if (isEmpty()) {
            cout << "Pushed " << x << endl;
            front = new Node(x);  // Create a new node and make front point to it
            rear = front;  // As there's only one element, rear and front both point to the same node
            size++;  // Increase the size of the queue
        } else {
            cout << "Pushed " << x << endl;
            rear->next = new Node(x);  // Create a new node and link it to the rear node's next

            // As we are allocating memory dynamically, we don't get a Queue Overflow condition 
            // unless we use too much memory and the heap is full.
            // If the heap memory is full, rear->next will be NULL indicating that no more nodes can be added.

            if (rear->next == NULL) {  // Checking for a potential overflow
                cout << "Queue Overflow" << endl;
                return;
            }

            rear = rear->next;  // Move the rear pointer to the new node
            size++;  // Increment the size of the queue
        }
    }

    // Function to remove (dequeue) an element from the front of the queue
    void dequeue() {
        // If the queue is empty, there is nothing to dequeue
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
        } else {
            // Print the data of the front node which will be dequeued
            cout << "Popped element :- " << front->data << endl;
            Node* temp = front;  // Temporary pointer to store the front node to be deleted
            front = front->next;  // Move the front pointer to the next node
            delete temp;  // Delete the old front node to free memory
            size--;  // Decrease the size of the queue
        }
    }

    // Function to get the value at the front of the queue (peek)
    int peekFront() {
        // If the queue is empty, return -1 as there's no element to peek
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return front->data;  // Return the data stored in the front node
        }
    }

    // Function to get the value at the rear of the queue (peek)
    int peekRear() {
        // If the queue is empty, return -1 as there's no element at the rear
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return rear->data;  // Return the data stored in the rear node
        }
    }

    // Function to get the current size of the queue
    int queueSize() {
        return size;  // Return the size variable which tracks the number of elements in the queue
    }
};

int main() {
    Queue Q;

    Q.enqueue(10);
    Q.enqueue(20);  
    Q.enqueue(30);  
    Q.enqueue(40);  
    Q.enqueue(50);  
    Q.enqueue(60);  
    Q.enqueue(70);

    Q.dequeue();
    Q.dequeue();
    Q.dequeue();

    cout << "First element in Queue is :- " << Q.peekFront() << endl;
    cout << "Last element in Queue is :- " << Q.peekRear() << endl;
    cout << "The size of the Queue is :- " << Q.queueSize() << endl;
    cout << "Is the Queue empty? " << Q.isEmpty() << endl;

    return 0;
}