// Let's say you have only one element initially, 1. top will be pointing to this. Now when we push 3 to Stack, a new node is created in Linked List and next of 1 points to 3. top will now point to 3. Onv, we will need head pointer to point to the first element in Linked List (and Stack). In a similar way, 5 and then 6 can be pushed.
// Now when we want to pop an element from this Stack, 6 should be popped. Hence, in our Linked List node containing 6 should be deleted and top should point back to 5 (which we can do with help of another pointer which will traverse the Linked List). But this traversing method can take quite a lot time, so we will use Doubly Linked List.
// But there's an even better way (which uses Singly Linked List and it won't even need head). So, we had 1 initially and top points to 1. Now 3 we will insert at the beginning such that 3 is now the first element and it's next points to 1. top will point to 3 now. Similarly, add new nodes for 5 and 6. top points to 6 after these operations.
// If we are asked to pop, we already have the index of 5 stored in next of 6. So move top there and delete 6 (use a temp pointer to delete that node).

// For size operation, we will keep track of it during push and pop operations (to avoid traversing the Linked List for this specific operation). 
// For peek operation, we will just return data of node pointed to by the top pointer.

#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the Stack (implemented using Singly Linked List)
class Node {
    public :

    int data; // stores the value of the node
    Node* next; // stores the pointer to the next node in the Linked List

    // Constructor to initialize a node with a given value
    Node (int value) {
        data = value;     // set the data for the node
        next = NULL;      // initially, the next pointer is set to NULL
    }
};

// Stack class that uses a Singly Linked List for its internal implementation
class Stack {
    Node* top; // pointer to the top element of the Stack (the most recent element added)
    int size;  // variable to track the number of elements in the Stack

    public :

    // Constructor to initialize the Stack
    Stack() { 
        top = NULL;  // initially, there are no elements in the Stack, so top is NULL
        size = 0;    // initialize size to 0
    }

    // Function to push an element onto the Stack
    void push(int value) {
        Node* temp = new Node(value); // create a new node with the given value

        // We need not check for Stack Overflow condition here as Linked List can create new nodes and allocate memory for it dynamically.
        // Stack Overflow can occur here only when we create too many nodes and Heap memory also becomes Full.
        // If this would have happened, then temp would store NULL. So just print Stack Overflow.

        if (temp == NULL) { // if no more memory is available for new node creation
            cout << "Stack Overflow\n" << endl;
        } else {
            // The new node's next pointer will point to the current top node
            temp -> next = top;
            // Now, top will point to the new node (the recently added node becomes the new top)
            top = temp;
            // Increment the size of the Stack
            size++;
            cout << "Pushed " << value << endl;
        }
    }

    // Function to pop the top element from the Stack
    void pop() {
        // In this case, if top is NULL, it means that Stack is empty. So handle that case
        if (top == NULL){
            cout << "Stack Underflow" << endl; // Stack is empty, cannot pop any element
        } else {
            Node* temp = top; // temporary pointer to hold the current top node
            cout << "Popped " << top -> data << endl; // print the value of the top element
            // Move the top pointer to the next node (effectively removing the current top)
            top = top -> next;
            // Delete the old top node to free memory
            delete temp;
            // Decrement the size of the Stack
            size--;
        }
    }

    // Function to get the top element of the Stack without removing it (peek operation)
    int peek() {
        // If Stack is empty, return -1
        if (top == NULL) {
            cout << "Stack is Empty" << endl;
            return -1; // no element to return
        } else {
            // Return the data of the top node
            return top -> data;
        }
    }

    // Function to check if the Stack is empty
    bool isEmpty() {
        return top == NULL; // if top is NULL, the Stack is empty
    }

    // Function to get the current size of the Stack
    int isSize() {
        return size; // return the size of the Stack
    }
};

int main() {
    Stack S;

    S.push(6);
    S.push(5);
    S.push(3);
    S.push(1);

    S.pop();

    cout << "Size of Stack is :- " << S.isSize() << endl;
    cout << "Top of Stack is :- " << S.peek() << endl;
    cout << "Is Stack Empty :- " << S.isEmpty() << endl;

    return 0;
}