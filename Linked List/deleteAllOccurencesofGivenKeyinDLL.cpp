// Problem Statement :- https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list

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

Node* deleteAllOccurrences(Node* head, int key) {
    // Pointer to traverse the doubly linked list.
    Node* temp = head;

    // Loop through the list to find and delete all nodes with the given key.
    while (temp != NULL) {
        // Check if the current node contains the target key.
        if (temp->data == key) {
            // If the node to be deleted is the head node.
            if (temp == head) {
                head = temp->next; // Move the head pointer to the next node.
            }

            // Save pointers to the next and previous nodes for reconnection.
            Node* nextNode = temp->next; // Next node in the list.
            Node* prevNode = temp->prev; // Previous node in the list.

            // If the next node exists, update its `prev` pointer to skip the current node.
            if (nextNode != NULL) {
                nextNode->prev = prevNode;
            }

            // If the previous node exists, update its `next` pointer to skip the current node.
            if (prevNode != NULL) {
                prevNode->next = nextNode;
            }

            // Free the memory of the current node.
            delete temp;

            // Move to the next node to continue the deletion process.
            temp = nextNode;
        } else {
            // If the current node does not contain the key, move to the next node.
            temp = temp->next;
        }
    }

    // Return the updated head pointer, which may be different if the head node was deleted.
    return head;
}

int main() {
    // Initialize the head pointer to NULL, representing an empty doubly linked list
    Node* head = NULL;

    // Array of elements to be inserted at the beginning of the doubly linked list
    int arr[] = {1, 2, 3, 4, 5, 3, 1, 2, 3};

    head = insertAtBeginning(arr, 0, 9, head);

    head = deleteAllOccurrences(head, 3);

    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
