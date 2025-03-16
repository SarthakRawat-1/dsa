// One way to do this is using a while loop, till the Queue becomes empty. Start from element pointed to by front pointer and then dequeue this element. Keep increasing front pointer so that we traverse the entire Queue.

// But what if we want the elements of Queue to remain there? In this case also traverse the Queue using the while loop till Queue becomes empty, and store the elements in a different data structure (say, array) one by one and also print each element after it is stored (or you may it before storing) and after printing and storing, dequeue each element. After this, simply enqueue the elements of array into Queue. 

// But what if we want to achieve the same without using extra space for the data structure? We know size of Queue (queueSize), so we know the number of elements to print. So, first we print the element pointed to by front pointer. Now put this element at the end of queue (by enqueuing it), dequeue this element and decrease size by 1. Keep doing this till size becomes zero. 
// Here's a code which implements this using STL.

#include <iostream>
#include <queue>
using namespace std;

// Function to print elements of the queue and rotate them
// so that each element is dequeued and then enqueued back
void rotateAndPrintQueue(queue<int>& Q) {
    int n = Q.size(); // Get the size of the queue, i.e., the number of elements

    // We iterate 'n' times, printing and rotating elements
    while (n--) {
        // Output the element at the front of the queue
        cout << Q.front() << endl;

        // Enqueue the front element to the back, thereby rotating the queue
        Q.push(Q.front());

        // Dequeue (remove) the front element
        Q.pop();
    }
}

int main() {
    // Create a queue of integers
    queue<int> Q;

    // Enqueue elements to the queue
    Q.push(5);
    Q.push(15);
    Q.push(25);
    Q.push(35);
    Q.push(45);

    // Call the function to print and rotate the queue
    rotateAndPrintQueue(Q);

    return 0;
}


// Here's a code to do the same using Array implementation of Queue. 
// We have used Circular Queue instead of Linear Queue because in Linear Queue, elements can be displayed simply by using a for loop with variable going from front to rear and using this to print the elements. We don't even need queueSize for this. 

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

    void displayQueue () {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } 
        // Case when rear is greater than or equal to front
        // This means that the queue has not wrapped around and the rear is ahead of or at the same position as the front
        else if (rear >= front) { 
            // This means Circular Queue here, pretty much behaves like a Linear Queue, so just use the same method to print the Queue elements.
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << endl;
            }
        }
        // Case when rear < front (circular wrap-around case)
        // This happens when the queue has wrapped around to the beginning of the array
        else {
            // To print the elements in this case :-
            // 1. First print elements from 'front' to the end of the array

            for (int i = front; i <= size - 1; i++) {
                cout << arr[i] << endl;
            }

            // 2. Then, print the elements from the start of the array (index 0) to 'rear'

            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << endl;
            }
            
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

    Q.displayQueue();
}