// Problem Statement :- https://leetcode.com/problems/odd-even-linked-list/description/

// Take an odd pointer and an even pointer. They will aggregate odd and even nodes respectively and then we can connect them in the end.
// We will also use a evenStart pointer to store address of second node (first even node).
// To aggregate, start odd from first element and even from second element. Now, change odd->next to even->next, this will connect odd with the third node instead of second node. 
// After this, change even->next to even->next->next, this will connect even with the fourth node instead of third node.
// Now change odd = even->next so that odd will point to the third node and change even = even->next so that even will point to the fourth node.
// Continue doing this till all the nodes are traversed (checking if the value to be changed to becomes NULL for both).
// For connecting, jsut change odd->next (as it will point to last odd nodes) to evenStart.

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
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or contains only one node, no reordering is needed, so return the head.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize two pointers: 
        // 'odd' will traverse the nodes at odd indices,
        // 'even' will traverse the nodes at even indices.
        ListNode* odd = head;            // Start from the head node (1st node, which is odd).
        ListNode* even = head->next;      // Start from the second node (2nd node, which is even).
        ListNode* evenStart = even;       // Store the start of the even-indexed nodes to link later.

        // Traverse the list until there are no more even nodes left.
        // The loop will stop when 'even' or 'even->next' is NULL, meaning we've reached the end of the list.
        while (even != NULL && even->next != NULL) {
            // Link the current odd node to the next odd node (which is 'even->next').
            odd->next = even->next;

            // Link the current even node to the next even node (which is 'even->next->next').
            even->next = even->next->next;

            // Move the 'odd' pointer to the next odd node.
            odd = odd->next;

            // Move the 'even' pointer to the next even node.
            even = even->next;
        }

        // After reordering, link the last odd node to the first even node.
        // This connects the odd and even sublists together.
        odd->next = evenStart;

        // Return the head of the reordered list.
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
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Printing the original list
    cout << "Original list: ";
    printList(head);

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the oddEvenList function to reorder the linked list
    ListNode* reorderedHead = solution.oddEvenList(head);

    // Printing the reordered list (odd nodes first, followed by even nodes)
    cout << "Reordered list (odd nodes first, followed by even nodes): ";
    printList(reorderedHead);

    // Free allocated memory (to avoid memory leak)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
