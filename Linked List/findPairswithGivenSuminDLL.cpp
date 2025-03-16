// Problem Statement :- https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-pairs-with-given-sum-in-doubly-linked-list

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
    int arr[] = {5, 5, 4, 4, 4, 3, 3, 3, 3, 3, 2, 1};

    head = insertAtBeginning(arr, 0, 12, head);



    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
