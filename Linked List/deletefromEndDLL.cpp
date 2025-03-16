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

    // Code to delete the node from the end of the doubly linked list
    if (head != NULL) { // Ensure list is not empty
        if (head->next == NULL) { // If there's only one node in the list
            delete head;  // Delete the head node
            head = NULL;  // Set head to NULL as the list is now empty
        } else {
            // If there are multiple nodes in the list
            Node* curr = head; // Temporary pointer to traverse to the end

            // Traverse to the last node
            while (curr->next) {
                curr = curr->next;
            }

            // Update the second-last node's next pointer to NULL, detaching the last node
            curr->prev->next = NULL;
            delete curr; // Delete the last node
        }
    }


    // To print the contents of the doubly linked list
    Node* trav = head; // Temporary pointer to traverse the list from the head
    while (trav) {
        cout << trav->data << " "; // Print the data of each node
        trav = trav->next;         // Move to the next node in the list
    }
}
