// Problem Statement :- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

// We will use Hare and Tortoise approach (also called Floyd’s cycle finding algorithm) to find the middle node.
// We will use two pointers here, fast and slow both initialized to head pointer.
// The idea is to move the 'slow' pointer one step at a time, i.e. slow = slow->next while moving the 'fast' pointer two steps at a time, i.e. fast = fast->next->next
// When 'fast' reaches the end of the list, 'slow' will be at the middle.

// But deletion also involves changing the next pointer of previous node to point to the next of the next node. So we will use one more pointer, prevSlow.

// If Linked List has only one Node (i.e. head->next == NULL) or Linked List is empty (i.e. head == NULL) then we will return NULL.

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

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or contains only one node, return NULL
        // because if there's only one node, after deleting it, the list becomes empty.
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        // Initialize pointers for the "slow and fast" two-pointer technique.
        // 'prevSlow' will keep track of the node before the 'slow' pointer, so we can link around the middle node when we find it.
        ListNode* prevSlow = NULL;  // This will store the node just before the middle node
        ListNode* slow = head;      // 'slow' pointer moves one step at a time
        ListNode* fast = head;      // 'fast' pointer moves two steps at a time

        // Traverse the list with the fast and slow pointers.
        // The fast pointer moves two steps, and the slow pointer moves one step.
        // When 'fast' reaches the end, 'slow' will be pointing to the middle node.
        while (fast != NULL && fast->next != NULL) {
            prevSlow = slow;           // Move 'prevSlow' to point to the current 'slow' node
            slow = slow->next;         // Move 'slow' one step ahead
            fast = fast->next->next;   // Move 'fast' two steps ahead
        }

        // Now, 'slow' points to the middle node, and 'prevSlow' points to the node just before it.
        // Skip the middle node by linking 'prevSlow' to the node after 'slow'.
        prevSlow->next = slow->next;

        // Delete the middle node (which 'slow' is pointing to).
        delete slow;

        // Return the head of the modified linked list, with the middle node removed.
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution sol;
    sol.deleteMiddle(head);  

    cout << "Linked List after deletion: ";
    printList(head);  

    return 0;
}