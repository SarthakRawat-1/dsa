// A Circular Linked List is a variation of a linked list in which :- The last node of the list points back to the first node (or head) instead of pointing to NULL. It forms a circular chain-like structure where the nodes are connected in a loop.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to insert a node at the end of a circular linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself
    } else {
        Node* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = head; // Make it circular
    }
}

// Function to display the circular linked list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Loop until we return to the head
    cout << endl;
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    cout << "Circular Linked List: ";
    display(head);

    return 0;
}
