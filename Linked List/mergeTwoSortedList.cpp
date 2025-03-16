// Problem Statement :- https://leetcode.com/problems/merge-two-sorted-lists/description/

// Brute Force Approach :- Take two pointers to start traversing both the Linked Lists. Compare the data of both nodes and store the smaller one in a new Linked List. Move the pointer to next (only that pointer whose data we have used), again compare and add the smaller data to a new node.

// Better Approach :- Take two head pointers head1 and head2 to point to first node of both LL head pointer. Say you have LL :- 2->4->5->7 and 3->4->4->6->8->10
// As 2 is smaller than 3, we will break this node from the LL. For this we will use another pointer called head and this will now point to 2. head1 moves to next element and now points to 4.
// As 3 is smaller than 4, so break 3 from linked list. Now head2 points to 4.
// We are breaking by taking one more pointer called the tail pointer Initially, both head and tail will point to 2, but after we want to break 3 and add it here, we will say tail->next now points to 3 and tail moves to tail->next and after this tail->next becomes NULL.

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
    ListNode *mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the start of the new merged list.
        // This simplifies the logic by avoiding special cases for the head node.
        // Without it we would have to handle edge cases for initializing the head of the resulting linked list separately.
        // Without it, every time we add a node to the new list, we would need to check if it's the first node to set the head pointer explicitly.
        ListNode* head = new ListNode(0); 
        ListNode* tail = head; // Tail pointer to track the end of the merged list

        // Loop through both lists until one is exhausted
        while (list1 && list2) {
            // Compare the values of the current nodes from both lists
            if (list1->val <= list2->val) {
                // Attach the smaller node to the merged list
                tail->next = list1; 
                list1 = list1->next; // Move the pointer of list1 forward
            } else {
                // Attach the smaller node to the merged list
                tail->next = list2; 
                list2 = list2->next; // Move the pointer of list2 forward
            }
            // Move the tail pointer forward in the merged list
            tail = tail->next;
            tail->next = NULL; // Ensure the next pointer is set to NULL
        }

        // Attach the remaining nodes from the non-empty list (if any)
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Save the real head of the merged list (skipping the dummy node)
        tail = head;       // Temporary pointer to hold the dummy node
        head = head->next; // Move head to the actual start of the merged list
        delete tail;       // Delete the dummy node to free memory

        return head; // Return the head of the merged list
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
    ListNode* head1 = new ListNode(-1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(5);

    Solution solution;

    ListNode* mergedList = solution.mergeTwoLists(head1, head2);    

    printList(mergedList);

    return 0;
}