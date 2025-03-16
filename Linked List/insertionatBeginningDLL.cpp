// If you want to insert a node at beginning of DLL, we will first create a node using a temp pointer.
// Initially both temp->prev and temp->next will be NULL, but when we have to insert it to the beginning, temp->next should contain head (which points to first element before insertion).
// After this, change the head->prev to temp from NULL. This indicates insertion of a new node. Then change head node to point to temp as head always points to first element in a Linked List.

// If head is NULL i.e. Linked List doesn't exist, in that case, simply create a node and store it's address in head pointer. It's prev and next pointer will be NULL.

#include <bits/stdc++.h>
using namespace std;

// Definition for a node in a doubly linked list.
class Node {
    public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the list
    Node *prev;     // Pointer to the previous node in the list

    // Constructor to initialize a new node with a given value
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Recursive function to insert nodes at the beginning of the doubly linked list
Node* insertAtBeginning(int arr[], int index, int size, Node* head) {
    // Base case: If index reaches size, return the head as the recursion ends
    if (index == size) {
        return head;
    }

    // Create a new node with the current element of the array
    Node* temp = new Node(arr[index]);

    // Insert the new node at the beginning
    temp->next = head; // New node's next pointer should point to the current head
    if (head != NULL) {
        head->prev = temp; // Update head's previous pointer if head is not NULL
    }

    // Update head to the new node
    head = temp;

    // Recursive call for the next element in the array
    return insertAtBeginning(arr, index + 1, size, head);
}

int main() {
    // Initialize the head pointer to NULL, representing an empty doubly linked list
    Node* head = NULL;

    // Array of elements to be inserted at the beginning of the doubly linked list
    int arr[] = {1, 2, 3, 4, 5};

    // Iterative insertion at the beginning of DLL
    for (int i = 0; i < 5; i++) {
        // Check if the list is currently empty
        if (head == NULL) {
            // If list is empty, create the first node
            head = new Node(arr[i]);
        } else {
            // Create a new node for insertion at beginning
            Node* temp = new Node(arr[i]);
            temp->next = head;   // New node points to current head
            head->prev = temp;   // Current head points back to new node
            head = temp;         // Update head to the new node
        }
    }

    // Clear the list and re-create it using the recursive approach
    head = NULL;
    head = insertAtBeginning(arr, 0, 5, head);

    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
