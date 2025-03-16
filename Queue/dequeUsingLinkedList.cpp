// Stack and other Queues are actually implemented using Deques.

// A Deque or Double ended Queue is a data structure in which insertion and deletion can be performed at both ends, front and back.

// For first element, we will create a node, and front and rear pointer will point to this. Now, if it said that we have to push back another element in Queue, we will have to create a node and put it after the first node in Linked List using the help of rear pointer, and move rear pointer to this element now. Similarly, we can push back more element/node.
// Similarly, if we want to push front an element, we will have to create a node, before the first node, using the help of front pointer and move the front pointer to this element. We will also need a temp pointer to assign the previous front node address to next of new front node.
// If we want to pop back an element/node, we can delete it easily, but the problem comes in moving rear back by one node, after the last element is popped. This is why we don't use Singly Linked List to implement Deque. We use Doubly Linked List instead. In this way, we can move rear back by one node using the prev pointer of the last node. Then just delete next of rear.
// Similarly for pop front, move front to next node and delete the previous front node. 
// Obv in this case, we will have to take care of prev pointers as well for each node.
// If we only have one single element/node in Queue/LinkedList, and we are asked to pop front, we can't simply move front by one and delete it's prev because in this case, front will become NULL. Hence first, when we want to pop an element, we will first assign a temp pointer to the element to be popped. Then we will move front (it will become null, and in this case, we will have to make rear also NULL). Now delete the temp. 
// If we only have one single element/node in Queue/LinkedList, and we are asked to pop back, we will take temp pointer. Take rear one back (it becomes null, we have to make front also null). Now delete temp.

#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the Deque (Doubly Linked List Node)
class Node {
    public:

    int data;  // Stores the data value of the node
    Node *next, *prev;  // Pointers to the next and previous nodes in the deque

    // Constructor to initialize a new node with the given value
    Node(int value) {
        data = value;
        next = NULL;  // Initially, the new node's next and prev pointers are NULL
        prev = NULL;
    }
};

// Deque class using a doubly linked list structure
class Deque {
    Node *front, *rear;  // Pointers to the front and rear of the deque

    public:
    // Constructor to initialize an empty deque
    Deque() {
        front = NULL;  // Initially, both front and rear are NULL (empty deque)
        rear = NULL;
    }

    // Function to insert an element at the front of the deque
    void push_front(int x) {
        if (front == NULL) {  // If deque is empty, both front and rear point to the new node
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of Dequeue" << endl;
            return;
        } else {  // If deque has elements, insert the new node before the front
            Node *temp = new Node(x);
            temp->next = front;  // New node's next points to current front
            front->prev = temp;  // Current front's prev points to new node
            front = temp;  // Move front pointer to the new node
            cout << "Pushed " << x << " in front of Dequeue" << endl;
            return;
        }
    }

    // Function to insert an element at the back of the deque
    void push_back(int x) {
        if (front == NULL) {  // If deque is empty, both front and rear point to the new node
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back of Dequeue" << endl;
            return;
        } else {  // If deque has elements, insert the new node after the rear
            Node *temp = new Node(x);
            rear->next = temp;  // Rear node's next points to new node
            temp->prev = rear;  // New node's prev points to current rear
            rear = temp;  // Move rear pointer to the new node
            cout << "Pushed " << x << " in back of Dequeue" << endl;
            return;
        }
    }

    // Function to remove an element from the front of the deque
    void pop_front() {
        if (front == NULL) {  // If deque is empty, no elements to pop
            cout << "Dequeue Underflow" << endl;
            return;
        } else if (front == rear) {  // If deque has only one element
            Node *temp = front;  // Assign temp pointer to front node
            cout << "Popped element from the front of Dequeue :- " << temp->data << endl;
            front = rear = NULL;  // Set both front and rear to NULL after removing the last element
            delete temp;  // Delete the popped node
            return;
        } else {  // If deque has more than one element
            Node *temp = front;  // Assign temp pointer to front node
            cout << "Popped element from the front of Dequeue :- " << temp->data << endl;
            front = front->next;  // Move front pointer to the next node
            front->prev = NULL;  // Set the new front's prev pointer to NULL
            delete temp;  // Delete the old front node
            return;
        }

        // You can combine the else if and else statements into a single else statement :-
        // else {
        //     Node *temp = front;
        //     cout << "Popped element from the front of Dequeue :- " << temp->data << endl;
        //     front = front->next;
        //     delete temp;

        //     if (front) { // If front is not NULL, it means that we had more than one node/element
        //         front->prev = NULL;
        //     } else {
        //         rear = NULL;
        //     }

        //     return;
        // }
    }

    // Function to remove an element from the back of the deque
    void pop_back() {
        if (front == NULL) {  // If deque is empty, no elements to pop
            cout << "Dequeue Underflow" << endl;
            return;
        } else if (front == rear) {  // If deque has only one element
            Node *temp = front;  // Assign temp pointer to rear node (which is also the front)
            cout << "Popped element from the back of Dequeue :- " << temp->data << endl;
            front = rear = NULL;  // Set both front and rear to NULL after removing the last element
            delete temp;  // Delete the popped node
            return;
        } else {  // If deque has more than one element
            Node *temp = rear;  // Assign temp pointer to rear node
            cout << "Popped element from the back of Dequeue :- " << temp->data << endl;
            rear = rear->prev;  // Move rear pointer to the previous node
            rear->next = NULL;  // Set the new rear's next pointer to NULL
            delete temp;  // Delete the old rear node
            return;
        }

        // You can combine the else if and else statements into a single else statement :-
        // else {
        //     Node *temp = rear;
        //     cout << "Popped element from the back of Dequeue :- " << temp->data << endl;
        //     rear = rear->prev;
        //     delete temp;

        //     if (rear) { // If rear is not NULL, it means that we had more than one node/element
        //         rear->next = NULL;
        //     } else {
        //         front = NULL;
        //     }

        //     return;
        // }
    }

    // Function to get the data of the front element of the deque
    int start() {
        if (front == NULL) {  // If deque is empty, return -1
            return -1;
        } else {
            return front->data;  // Return the data of the front node
        }
    }

    // Function to get the data of the rear element of the deque
    int end() {
        if (front == NULL) {  // If deque is empty, return -1
            return -1;
        } else {
            return rear->data;  // Return the data of the rear node
        }
    }

    // Function to display the elements of the deque from front to back
    void display() {
        if (front == NULL) {  // If deque is empty, display a message
            cout << "Deque is empty" << endl;
            return;
        }
        Node *temp = front;  // Start from the front node
        cout << "Deque elements: ";
        while (temp != NULL) {  // Traverse the deque and print each element
            cout << temp->data << " ";  // Print the data of the current node
            temp = temp->next;  // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    Deque D;

    D.push_back(5);
    D.push_front(8);

    cout << "First element in Dequeue is :- " << D.start() << endl;

    D.pop_back();

    D.push_back(15);
    D.push_front(5);

    cout << "Last element in Dequeue is :- " << D.end() << endl;    

    D.pop_front();

    D.display();

    return 0;
}
