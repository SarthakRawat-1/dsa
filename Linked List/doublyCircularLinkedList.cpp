#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Function to insert a node at the end of the doubly circular linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        // List is empty
        head = newNode;
        head->next = head; // Circular connection
        head->prev = head; // Circular connection
    } else {
        // Find the last node
        Node* tail = head->prev;

        // Update the new node's pointers
        newNode->next = head;   // New node points to head
        newNode->prev = tail;   // New node points to tail

        // Update existing nodes' pointers
        tail->next = newNode;   // Tail points to new node
        head->prev = newNode;   // Head's previous points to new node
    }
}

// Function to display the doubly circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Stop when we loop back to the head
    cout << endl;
}

// Function to display the list in reverse order
void displayReverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* tail = head->prev;
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != tail); // Stop when we loop back to the tail
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert elements into the list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Doubly Circular Linked List: ";
    display(head);

    cout << "Reverse Order: ";
    displayReverse(head);

    return 0;
}
