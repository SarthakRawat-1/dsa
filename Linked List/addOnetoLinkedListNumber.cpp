// Problem Statement :- https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=add-1-to-a-number-represented-as-linked-list

// Reversing the linked list allows us to perform addition starting from the least significant digit (last node).
// Traverse the reversed list, add 1 to the first node, and handle the carry for subsequent nodes. If the carry remains after the last node, append a new node with the carry value.
// Reverse the list again to restore the original order.

#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;             // Value of the node
    ListNode* next;      // Pointer to the next node in the list

    // Constructor
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;

    while (current != NULL) {
        ListNode* nextNode = current->next; // Store the next node
        current->next = prev;              // Reverse the pointer
        prev = current;                    // Move prev to current
        current = nextNode;                // Move current to next node
    }

    return prev; // New head of the reversed list
}

// Function to add 1 to the number represented by the linked list
ListNode* addOne(ListNode* head) {
    if (head == NULL) {
        return new ListNode(1); // Handle edge case of empty list
    }

    // Step 1: Reverse the linked list
    head = reverseList(head);

    // Step 2: Add 1 to the reversed list
    ListNode* current = head;
    int carry = 1;

    while (current != NULL) {
        int sum = current->val + carry; // Add carry to the current value
        current->val = sum % 10;        // Update the node value
        carry = sum / 10;               // Update the carry

        // If there's no carry, break the loop early
        if (carry == 0) {
            break;
        }

        // Move to the next node
        if (current->next == NULL && carry > 0) {
            // If it's the last node and there's still a carry, add a new node
            current->next = new ListNode(carry);
            carry = 0;
        }
        current = current->next;
    }

    // Step 3: Reverse the list back to its original order
    return reverseList(head);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: 4->5->6
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(6);

    cout << "Original Linked List: ";
    printList(head);

    head = addOne(head);

    cout << "Linked List after adding 1: ";
    printList(head);

    return 0;
}
