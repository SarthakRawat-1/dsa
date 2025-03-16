// Problem Statement :- https://leetcode.com/problems/middle-of-the-linked-list/description/

// Use the Hare and Tortoise approach i.e. fast (moves 2 step) and slow (moves 1 step) pointers.

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
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slow and fast, both pointing to the head of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        // The idea is to move the 'slow' pointer one step at a time,
        // while moving the 'fast' pointer two steps at a time.
        // When 'fast' reaches the end of the list, 'slow' will be at the middle.
        while (fast != NULL && fast->next != NULL) {
            // Move 'slow' one step forward (to the next node)
            slow = slow->next;
            
            // Move 'fast' two steps forward (skipping one node each time)
            fast = fast->next->next;
        }

        // When the loop ends, 'slow' will be pointing to the middle node of the linked list.
        // We return 'slow' as the result, which is the middle node.
        return slow;
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

    Solution solution;

    ListNode* middle = solution.middleNode(head);

    cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}