// Problem Statement :- https://leetcode.com/problems/rotate-list/description/

// If we are asked to rotate a Linked List k times, we will have to first put a pointer (say curr) on the kth last element. Then we will have to break the link between this element (it will now become HEAD) and element just before it (this element will now point to NULL).
// After breaking the link, we can just change the next pointer of the last node (using a tail pointer to store HEAD in it's next). Then we will change HEAD pointer to point to kth last element.
// We can use :- k % size of Linked List to find the actual number of times we have to rotate.

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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: If the list is empty or has only one node, or k is zero, no rotation is needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Count the number of nodes in the linked list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: Compute the effective number of rotations needed by taking k modulo count
        k = k % count;

        // If k is 0 after modulus, the list does not need rotation
        if (k == 0) {
            return head;
        }

        // Step 3: Calculate the number of steps to reach the new head (count - k steps)
        count -= k;

        // Step 4: Initialize two pointers: `curr` to traverse the list, `prev` to keep track of the node before `curr`
        ListNode* curr = head;
        ListNode* prev = NULL;

        // Move `curr` to the (count - k)th node, which will be the last node of the rotated list
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Step 5: Break the link between `prev` and `curr`
        prev->next = NULL;

        // Step 6: Find the tail of the list starting from `curr` to link it back to the old head
        ListNode* tail = curr;
        while (tail->next) {
            tail = tail->next;
        }

        // Step 7: Connect the tail node to the original head
        tail->next = head;

        // Step 8: Update the head to the new starting node (`curr`)
        head = curr;

        // Return the new head of the rotated list
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
    head = solution.rotateRight(head, n);

    cout << "Linked List after rotating: ";
    printList(head);

    return 0;
}
