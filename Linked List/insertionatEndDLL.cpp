#include <bits/stdc++.h>
using namespace std;

// Definition for a node in doubly linked list.
class Node {
    public:
    int data;          // Data stored in the node
    Node *next;        // Pointer to the next node in the list
    Node *prev;        // Pointer to the previous node in the list

    // Constructor to initialize a new node with given value.
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Recursive function to create a DLL from an array by using Insertion at End.
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
    
    return temp; // Return the created node
}

int main() {
    // Node* head = NULL;  // Head pointer for the doubly linked list
    // Node *tail = NULL;  // Tail pointer to keep track of the last element in the list

    // int arr[] = {1, 2, 3, 4, 5}; // Example array to create DLL nodes from
    
    // // Inserting Nodes at the end of DLL. For Recursive approach check out the function createDLL
    // for (int i = 0; i < 5; i++) {
    //     if (head == NULL) {
    //         // If head is NULL, create the first node and set both head and tail to it
    //         head = new Node(arr[i]);
    //         tail = head;
    //     } else {
    //         // Otherwise, insert a new node at the end
    //         Node* temp = new Node(arr[i]);
    //         tail->next = temp; // Link current tail's next to the new node
    //         temp->prev = tail; // Set new node's previous to current tail
    //         tail = temp;       // Update tail to the new node
    //     }
    // }

    // // To print the contents of DLL
    // Node* trav = head; // Use trav pointer to traverse the list from head
    // while(trav) {
    //     cout << trav->data << " "; // Print data of each node
    //     trav = trav->next;         // Move to the next node
    // }

    
    // Main function to use for recursive function
    Node* head = NULL; // Head pointer for the doubly linked list

    int arr[] = {1, 2, 3, 4, 5}; // Array to create the doubly linked list from

    // Create the DLL from the array using recursion
    head = createDLL(arr, 0, 5, NULL);

    // To print the contents of DLL
    Node* trav = head; // Traversal pointer starting from head
    while(trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
