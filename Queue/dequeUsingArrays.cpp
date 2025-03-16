// Implementing Deque using Arrays also require two pointers, front and rear. The front pointer points to the first element of the deque, and the rear pointer points to the last element of the deque.
// We will use Circular Array to implement Deque. 
// How we change front and rear pointers upon pushing and popping is pretty much the same as in dequeUsingLinkedList.cpp and circularQueueUsingArrays.cpp.
// Edge Case :- What if front is at 0 index and there is space left in the array in the last index. In this case if you are pushing in front, use front = (front - 1 + size) % size This will cover the negative index case, that we will get when we don't add size. This works for other cases as well.
// Simialrly, if rear is at 0 index and there is space left in the array in the last index, and you want to pop an element from back, use rear = (rear - 1 + size) % size

#include <bits/stdc++.h>
using namespace std;

// Class to represent a Deque using a circular array
class Deque {
    int front, rear, size; // front and rear pointers, and size of the deque
    int *arr; // pointer to dynamically allocate memory for the array

public:
    // Constructor to initialize the Deque with a given size
    Deque(int n) {
        size = n;
        arr = new int[size]; // dynamically allocate memory for the array
        front = rear = -1; // initially, both front and rear are set to -1 (Deque is empty)
    }

    // Function to check if the Deque is empty
    bool isEmpty() {
        return front == -1; // Deque is empty if front is -1
    }

    // Function to check if the Deque is full
    bool isFull() {
        return (rear + 1) % size == front; // Deque is full when front and rear meet circularly
    }

    // Function to push an element at the front of the Deque
    void push_front(int x) {
        // If Deque is empty, initialize front and rear to 0
        if (isEmpty()) {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " in front of Deque" << endl;
            return;
        }
        // If Deque is full, we can't push more elements
        else if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }
        // Otherwise, decrement front (circularly) and insert element
        else {
            front = (front - 1 + size) % size; // calculate new front circularly
            arr[front] = x; // insert element at the new front position
            cout << "Pushed " << x << " in front of Deque" << endl;
            return;
        }
    }

    // Function to push an element at the back of the Deque
    void push_back(int x) {
        // If Deque is empty, initialize front and rear to 0
        if (isEmpty()) {
            front = rear = 0;
            arr[0] = x;
            cout << "Pushed " << x << " in back of Deque" << endl;
            return;
        }
        // If Deque is full, we can't push more elements
        else if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }
        // Otherwise, increment rear (circularly) and insert element
        else {
            rear = (rear + 1) % size; // You can do (rear + 1 + size) % size as well, but there is no specific need for this as even if rear = end index, rear + 1 will become size of array and size % size = 0, which is first index.
            arr[rear] = x; // insert element at the new rear position
            cout << "Pushed " << x << " in back of Deque" << endl;
            return;
        }
    }

    // Function to pop an element from the front of the Deque
    void pop_front() {
        // If Deque is empty, there are no elements to pop
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        // If front and rear are the same, Deque has only one element
        else if (front == rear) {
            cout << "Popped " << arr[front] << " from front of Deque" << endl;
            front = rear = -1; // reset front and rear to indicate Deque is empty
            return;
        }
        // Otherwise, increment front (circularly) to remove element from front
        else {
            cout << "Popped " << arr[front] << " from front of Deque" << endl;
            front = (front + 1) % size; // calculate new front circularly
            return;
        }
    }

    // Function to pop an element from the back of the Deque
    void pop_back() {
        // If Deque is empty, there are no elements to pop
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }
        // If front and rear are the same, Deque has only one element
        else if (front == rear) {
            cout << "Popped " << arr[rear] << " from back of Deque" << endl;
            front = rear = -1; // reset front and rear to indicate Deque is empty
            return;
        }
        // Otherwise, decrement rear (circularly) to remove element from rear
        else {
            cout << "Popped " << arr[rear] << " from back of Deque" << endl;
            rear = (rear - 1 + size) % size; // calculate new rear circularly
            return;
        }
    }

    // Function to get the element at the front of the Deque
    int start() {
        if (isEmpty()) {
            return -1; // return -1 if Deque is empty
        } else {
            return arr[front]; // return front element
        }
    }

    // Function to get the element at the rear of the Deque
    int end() {
        if (isEmpty()) {
            return -1; // return -1 if Deque is empty
        } else {
            return arr[rear]; // return rear element
        }
    }

    // Function to display the elements in the Deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Elements in the Deque: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " "; // print each element in the Deque
            i = (i + 1) % size; // move to the next element circularly
        }
        cout << arr[rear] << endl; // print the last element
    }
};

int main() {
    Deque D(5);

    D.push_back(5);
    D.push_front(8);

    D.pop_front();

    D.push_front(5);
    D.push_back(15);

    D.push_back(10);

    D.pop_back();
    
    cout << "First element in Dequeue is :- " << D.start() << endl;
    cout << "Last element in Dequeue is :- " << D.end() << endl;
}

