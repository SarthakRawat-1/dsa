// Consider a Linear Queue as explained in queueUsingArrays.cpp, of size 5 :- {1, 3, 4, 5, 8} We dequeued two elements from here, and now we are left with {_, _, 4, 5, 6} Now if we want to enqueue an element we can't do that as rear is pointing to last element.
// We want to implement Queue in such a way that in this case, those elements to be enqueue can come in those first two positions, which have been dequeued.
// For this we will implement Circular Queue.

// Circular Queue allows the last position to connect to the first position, forming a circle. When the queue reaches the end of the array, it wraps around to the beginning if space is available.
// Both the front and rear pointers move circularly within the array, ensuring that empty spaces left by dequeued elements can be reused.  

// In our eg, rear will circularly point to index 0 (after moving from index 4. Now, in this way, two elements can still be stored fot rear at index 0 and index 1.
// But how do we know when to stop? Simply check if rear + 1 = front. If it is, it means that the queue is full (as front points to the first element and rear points to the last).
// Edge Case :- What if we have front at index 0 and rear at last index (Queue is full). In this case, rear + 1 won't be zero, which means program will think that there is still space in Queue left which is false. To fix this, we can use mod operator. Just check if (rear + 1) % size = front (size is size of array, not queueSize).
// This mod operator trick we will also use to circularly move the front and rear pointers.

#include <bits/stdc++.h>
using namespace std;

class circularQueue {
    int *arr;
    int front, rear;
    int size;

    public :

    // Constructor to initialize the queue
    circularQueue (int n) {
        arr = new int[n]; // Dynamically allocate memory for the array
        front = -1; // Initially, both front and rear are -1, indicating an empty queue
        rear = -1;
        size = n; // Size of the queue is passed as an argument
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        if (front == -1) return true; // If front is -1, the queue is empty
        else return false;
        // Improvement: Can be simplified to return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        if ((rear + 1) % size == front) return true; // If rear is at the index just before front, the queue is full
        else return false;
        // Improvement: Can be simplified to return (rear + 1) % size == front
    }

    // Function to add an element to the queue (enqueue)
    void enqueue (int x) {
        if (isEmpty()) { 
            // If the queue is empty, set both front and rear to 0 and insert the element at index 0
            front = 0;
            rear = 0;
            arr[0] = x; // Enqueue the first element
            cout << "Enqueued element " << x << " is the first element in Queue." << endl;
            return;
        } else if (isFull()) {
            // If the queue is full, print an overflow message
            cout << "Queue Overflow" << endl;
            return;
        } else {
            // Otherwise, increment rear and insert the element at the new rear position
            rear = (rear + 1) % size;
            arr[rear] = x; // Enqueue at the new rear
            cout << "Enqueued element " << x << endl;
            return;
        }
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue () {
        if (isEmpty()) {
            // If the queue is empty, print an underflow message
            cout << "Queue Underflow" << endl;
            return;
        } else {
            // Special case: if front == rear, it means the queue has only one element
            if (front == rear) { 
                cout << "Dequeued the only element " << arr[front] << " from the Queue" << endl;
                front = -1; // Reset front and rear to -1, indicating the queue is empty
                rear = -1;
            } else {
                // Otherwise, simply move the front pointer to dequeue the element
                cout << "Dequeued the element " << arr[front] << " from the Queue" << endl;
                front = (front + 1) % size; // Move front to the next position
            }
            return;
        }
    }

    // Function to return the element at the front of the queue
    int peekFront () {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return INT16_MIN; // Return a special value to indicate empty queue
            // Improvement: Instead of returning, consider just printing the message. Use isEmpty function.
        } else {
            return arr[front]; // Return the front element
        }
    }

    // Function to return the element at the rear of the queue
    int peekRear () {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return INT16_MAX; // Return a special value to indicate empty queue
            // Improvement: Similar to peekFront, you can avoid returning this and just check beforehand.
        } else {
            return arr[rear]; // Return the rear element
        }
    }

    int queueSize() {
        // If the queue is empty, the size is obviously 0
        if (isEmpty()) {
            return 0;
        } 
        // Case when rear is greater than or equal to front
        // This means that the queue has not wrapped around and the rear is ahead of or at the same position as the front
        else if (rear >= front) {
            return rear - front + 1; // Size is simply the difference between rear and front, plus 1 (as indices are zero-based)
        } 
        // Case when rear < front (circular wrap-around case)
        // This happens when the queue has wrapped around to the beginning of the array
        else {
            // To calculate the size in this case:
            // 1. First count elements from 'front' to the end of the array, which is 'size - front'
            // 2. Then, add the number of elements from the start of the array (index 0) to 'rear', which is 'rear + 1'
            return (size - front) + (rear + 1);
        }
    }


    ~circularQueue() {
        delete[] arr; // Free the dynamically allocated memory
    }

};


int main() {
    circularQueue Q(5);

    Q.enqueue(8);
    Q.enqueue(10);
    Q.enqueue(2);
    Q.enqueue(7);
    Q.enqueue(11);
    Q.dequeue();
    Q.dequeue();
    Q.enqueue(34);
    Q.enqueue(45);

    cout << "First element in Queue is :- " << Q.peekFront() << endl;
    cout << "Last element in Queue is :- " << Q.peekRear() << endl;
    cout << "The size of the Queue is :- " << Q.queueSize() << endl;
}