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

// Recursive function to insert nodes at the beginning of the doubly linked list.
Node* insertAtBeginning(int arr[], int index, int size, Node* head) {
    if (index == size) {
        return head;
    }

    Node* temp = new Node(arr[index]);

    temp->next = head; 
    if (head != NULL) {
        head->prev = temp; 
    }

    head = temp;

    return insertAtBeginning(arr, index + 1, size, head);
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 3, 4, 5};

    head = insertAtBeginning(arr, 0, 5, head);

    int pos = 3; // Position to delete in the list (1-based index)

    if (pos == 1) {
        // Code to delete node from the beginning of the doubly linked list
        if (head != NULL) { // Ensure the list is not empty
            if (head->next == NULL) { // If there's only one node
                delete head;  // Delete the head node
                head = NULL;  // Set head to NULL as the list is now empty
            } else {
                // If there are multiple nodes in the list
                Node* temp = head;       // Temporary pointer to current head
                head = head->next;       // Move head to the next node
                delete temp;             // Delete the original head
                head->prev = NULL;       // Update new head's prev pointer to NULL
            }
        }
    } else {
        // Code to delete a node at a specified position (not the head)
        Node* curr = head; // Start from the head of the list

        // Traverse to the node at the specified position
        while (--pos) {
            curr = curr->next;
        }

        // If the node to delete is the last node
        if (curr->next == NULL) {
            curr->prev->next = NULL; // Update the second-last node's next pointer
            delete curr;             // Delete the last node
        } else {
            // If the node to delete is in the middle of the list
            curr->prev->next = curr->next; // Link previous node to the next node
            curr->next->prev = curr->prev; // Link next node back to the previous node
            delete curr;                   // Delete the node at specified position
        }
    }


    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
