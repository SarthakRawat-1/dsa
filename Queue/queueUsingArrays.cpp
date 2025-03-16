// Let's say we have an array of size, n = 6. 
// When they give us element 1 to store, we will store it at index 0, then an element after it say 2, will be stored at index 1 and so on, till, say 4.
// Now our array contains :- {1, 2, 3, 4} If we want to pop an element, it'll pop 1 from the array. Then if we want to pop one more element, 2 will be popped. Now we want to enqueue 5. So it'll be enqueued at end. Our array will look like :- {_, _, 3, 4, 5} where _ represents empty memory locations in array.
// The reason we have not enqueued 3 and 4 to lower indexes in the array, and we have let them be empty. Read further to understand why :-
// To implement this, we would need a front pointer and a rear pointer. Initially, when queue is empty, both front and rear will point to -1. 
// When one element is enqueued, both front and rear will point to index 0 now, Now if one more element comes, front will still point to index 0 but rear will now point to index 1.
// But how do we know, where to enqueue the element which is coming? rear pointer shows index of the last element. So when we want to add an element, simply put it in index rear + 1 and increase rear by 1 after that (or you can first increase rear and then store), so it points to the new last element.
// As long as there's atleast one element in the queue (and no element has been removed), front will point to zero index. 
// Once we dequeue an element, it will be removed from the front of array. So just increase the front pointer by one. The reason we need not delete that element is becasue when we will enqueue an elemenet later in that position, it will just be replaced.
// If during these operations, front ever becomes greater than rear, it will indicate that no element is present in the queue. In this case, set both to -1 again.
// Now, the reason why we are just changing the position of front pointer at dequeue and not pushing all elements left in lower index of the array, is because we want to minimze time complexity.

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear;
    int size;

    public :

    // Constructor to initialize the queue
    Queue (int n) {
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
        if (rear == size - 1) return true; // If rear is at the last index, the queue is full
        else return false;
        // Improvement: Can be simplified to return rear == size - 1;
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
            rear = rear + 1;
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
                front = front + 1; // Move front to the next position
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

    // Function to return the size of the queue (number of elements)
    int queueSize () {
        if (isEmpty()) {
            return 0; // If the queue is empty, size is 0
        } else {
            return rear - front + 1; // The number of elements is calculated as rear - front + 1
        }
    }

    ~Queue() {
        delete[] arr; // Free the dynamically allocated memory
    }

};


int main() {
    Queue Q(5);

    Q.enqueue(8);
    Q.enqueue(10);
    Q.enqueue(2);
    Q.enqueue(7);
    Q.enqueue(11);
    Q.dequeue();

    cout << "First element in Queue is :- " << Q.peekFront() << endl;
    cout << "Last element in Queue is :- " << Q.peekRear() << endl;
    cout << "The size of the Queue is :- " << Q.queueSize() << endl;
}