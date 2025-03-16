// Problem Statement :- https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list

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

Node* removeDuplicates(Node* head) {
    // Initialize a pointer to traverse the doubly linked list starting from the head.
    Node* temp = head;

    // Traverse the list until the current node is not NULL and the next node exists.
    while (temp != NULL && temp->next != NULL) {
        // Pointer to the next node in the list.
        Node* nextNode = temp->next;

        // Check if the current node's data matches the next node's data.
        while (nextNode != NULL && nextNode->data == temp->data) {
            // If a duplicate is found, save the duplicate node to delete it.
            Node* duplicate = nextNode;

            // Move the nextNode pointer forward to skip the duplicate node.
            nextNode = nextNode->next;

            // Free the memory occupied by the duplicate node.
            delete duplicate;
        }

        // Update the `next` pointer of the current node to point to the first non-duplicate node.
        temp->next = nextNode;

        // If the nextNode is not NULL, update its `prev` pointer to maintain the doubly linked list structure.
        if (nextNode != NULL) {
            nextNode->prev = temp;
        }

        // Move to the next node in the list for further processing.
        temp = temp->next;
    }

    // Return the updated head of the doubly linked list.
    return head;
}

int main() {
    // Initialize the head pointer to NULL, representing an empty doubly linked list
    Node* head = NULL;

    // Array of elements to be inserted at the beginning of the doubly linked list
    int arr[] = {5, 5, 4, 4, 4, 3, 3, 3, 3, 3, 2, 1};

    head = insertAtBeginning(arr, 0, 12, head);

    head = removeDuplicates(head);

    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
