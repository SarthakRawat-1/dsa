// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

// Brute Force Approach :- First, we traverse the DLL and store node data in a stack. Then, in a second pass, we assign elements from the stack to nodes, ensuring a reverse order replacement.

// Optimized Approach :- Follow the mentioned steps.
// 1. Initialize Pointers :- Set current to the head node and last to NULL. current will traverse the list, while last will temporarily hold the previous node during reversal.
// 2. Traverse and Reverse :- Loop through the list. For each node, Reverse the prev pointer to point to the next node (current->prev = current->next), Reverse the next pointer to point to the previous node (current->next = last), and Move current to the next node in the original sequence by setting it to the updated prev pointer (current = current->prev).
// 3. Update the Head: After traversal, last points to the new head of the reversed list. Update the head pointer to this node.
// This completes the reversal, with head now pointing to the first node of the reversed DLL.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with data, and references to the next and back nodes
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, without references to next and back nodes
    // Typically used to create a new node at the end of the list
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    
    // Initialize 'prev' to the head node
    Node* prev = head;            

    // Loop through the array starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array
        // Set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
        
        // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " ";  
        // Move to the next node
        head = head->next;         
    }
}

// Function to reverse a doubly linked list using an in-place link exchange method
Node* reverseDLL(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed; return the current head
        return head; 
    }
    
    // Initialize a pointer to the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to the previous node (original back pointer)
        prev = current->back; 
        
        // Swap the previous and next pointers to reverse the direction
        current->back = current->next; // Reverse the 'back' pointer
        current->next = prev;          // Reverse the 'next' pointer
        
        // Move to the next node in the original list (by using the new 'back' pointer)
        current = current->back; 
    }
    
    // The final node in the original list becomes the new head after reversal
    return prev->back;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4}; 
    Node* head = convertArr2DLL(arr); 
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head); 
    
    cout << endl << "Doubly Linked List After Reversing " << endl;
    head = reverseDLL(head); 
    print(head); 

    return 0;
}
