// Problem Statement :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Nth node from end will be (Total number of Nodes - N + 1) from beginning. This will be the node which we have to delete.
// And we already know how to delete a node from a position in Linked List.

#include <bits/stdc++.h>
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Initialize `count` to count the total number of nodes in the list
        int count = 0;
        ListNode* temp = head;

        // Traverse the list to find its length
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Calculate the position from the beginning (0-based index) of the node to be removed
        count = count - n;

        // Step 2: If `count` is 0, it means we need to remove the first node
        if (count == 0) {
            // Store the current head node in `temp` so we can delete it later
            temp = head;
            // Move `head` to the next node, effectively removing the first node
            head = head->next;
            
            // Delete the old head node to free up memory
            delete temp;

            // Return the updated head of the list
            return head;
        }

        // Step 3: Initialize two pointers for traversal
        // `prev` will point to the node just before the one we want to delete
        ListNode* prev = NULL;
        // `curr` will point to the node to be removed
        ListNode* curr = head;

        // Move `curr` to the node to be deleted, while `prev` follows it
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Step 4: Adjust the `next` pointer of `prev` to skip over `curr`
        prev->next = curr->next;

        // Delete the `curr` node to remove it from memory
        delete curr;

        // Return the modified head of the list
        return head;
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
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);


    Solution solution;

    cout << "Original Linked List: ";
    printList(head);

    int n = 1;
    head = solution.removeNthFromEnd(head, n);

    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}
