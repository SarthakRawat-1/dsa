// Problem Statement :- https://leetcode.com/problems/delete-node-in-a-linked-list/description/

// In the node to be deleted, enter the value (data) of the next node, in the value (data) of the current node. Then move node to node->next. Do the same for this node as well. When you reach the last node, it's next will contain NULL. This we can safely delete now.
// But we will also use a prev pointer to move to the second last node. This we will use to set next of second last node to NULL. 

#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
class ListNode {
public:
    int val;             // Value of the node (data)
    ListNode* next;      // Pointer to the next node in the list

    // Constructor to initialize a new node
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Solution class that contains the deleteNode function to delete a node in a linked list.
class Solution {
public:
    // Function to delete the given node from the linked list
    // This function does not receive the head of the list, only the node to be deleted.
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;  // Pointer to keep track of the previous node

        // Traverse the list until we reach the last node
        while (node != NULL && node->next != NULL) { // Checking node != NULL ensures that we don't accidentally try to access memory from a NULL node, which would cause a segmentation fault. This is not required for this problem statement however, as it's given in the question that node to be deleted won't be the last node.
            // Copy the value of the next node into the current node
            node->val = node->next->val;

            // Move the prev pointer to the current node
            prev = node;

            // Move the node pointer to the next node
            node = node->next;
        }

        // At the end of the loop, 'node' is pointing to the last node.
        // We need to remove this last node from the list.
        prev->next = NULL;  // Set the 'next' of the second last node to NULL

        // Delete the last node to free memory
        delete node;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original Linked List: ";
    printList(head);  

    Solution sol;
    sol.deleteNode(head->next);  

    cout << "Linked List after deletion: ";
    printList(head);  

    return 0;
}

