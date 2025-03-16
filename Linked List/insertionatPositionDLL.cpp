#include <bits/stdc++.h>
using namespace std;

// Definition for a node in a doubly linked list.
class Node {
    public:
    int data;         // Data stored in the node
    Node *next;       // Pointer to the next node in the list
    Node *prev;       // Pointer to the previous node in the list

    // Constructor to initialize a new node with a given value
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Recursive function to create a DLL from an array by using Insertion at End
Node* createDLL(int arr[], int index, int size, Node* back) {
    // Base case: if index reaches size, we've added all nodes, so return NULL
    if (index == size) {
        return NULL;
    }

    // Create a new node with the current array element
    Node* temp = new Node(arr[index]);
    temp->prev = back;  // Set the previous pointer of the new node to 'back'

    // Recursively set the next pointer by creating the next node in the DLL
    temp->next = createDLL(arr, index + 1, size, temp);

    return temp; // Return the created node to connect the list
}

int main() {
    Node* head = NULL;  // Initialize head of the doubly linked list to NULL

    int arr[] = {1, 2, 3, 4, 5}; // Array to create the doubly linked list from

    // Create the DLL from the array using recursion
    head = createDLL(arr, 0, 5, NULL);

    int pos = 2;  // Position to insert a new node with value 5

    // Insert a node with value 5 at a specific position (beginning or middle)
    if (pos == 0) {  // Special case: insertion at the beginning
        if (head == NULL) { // If list is empty, create the first node
            head = new Node(5);
        } else { // Otherwise, insert at beginning
            Node* temp = new Node(5); // Create a new node
            temp->next = head;        // Set temp's next to the current head
            head->prev = temp;        // Set current head's prev to temp
            head = temp;              // Update head to the new node
        }
    } else {
        // Traverse to the node just before the specified position
        Node* curr = head;
        while (--pos) {
            curr = curr->next; // Move to the next node until reaching the position
        }

        // Check if inserting at the end of the list
        if (curr->next == NULL) {
            Node* temp = new Node(5); // Create the new node
            temp->prev = curr;        // Set temp's prev to the current last node
            curr->next = temp;        // Link current last node's next to temp
        } else {
            // Inserting in the middle of the list
            Node* temp = new Node(5);   // Create the new node
            temp->next = curr->next;    // Set temp's next to current node's next
            temp->prev = curr;          // Set temp's prev to current node
            curr->next = temp;          // Link current node's next to temp
            temp->next->prev = temp;    // Link temp's next node's prev to temp
        }
    }

    // To print the contents of the DLL
    Node* trav = head; // Traversal pointer starting from head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
