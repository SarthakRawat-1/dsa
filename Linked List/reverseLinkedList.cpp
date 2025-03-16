// Problem Statement :- https://leetcode.com/problems/reverse-linked-list/description/

// Brute Force Approach :- Use an additional data structure (vector or stack) to store the data of Linked List. 
// Then if we have used vector, we have to reverse the vector and then we can assign this data in existing Linked List (or create a new one using this). With Stack, we can just pop the data one by one. 
// This however only reverses the data.

// If we are asked to reverse the node itself i.e. both data and next pointer (and ofc head points to last node which has become the first node). We can use either Iterative appraoch or Recursive appraoch.

// Iterative Approach :- Take a curr pointer starting from the address of first node and prev pointer starting from NULL. For each element, it's curr->next will be updated to prev. After that we can update prev with curr.
// Before updating curr->next = prev we will also need a pointer (let's say future, initialized to NULL) to point to next element of curr so that after updating both curr->next and prev, we can move curr to the next element.

// Recursive Approach :- For any node, we know that we want it to point to the node previous to it. Here aslo we will need three pointers, curr, future and prev.

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

    // // Iterative Approach
    // ListNode* reverseList(ListNode* head) {
    //     // Initialize three pointers:
    //     // `curr` - points to the current node being processed
    //     // `prev` - points to the previous node in the reversed list
    //     // `future` - temporarily stores the next node to preserve the original list's structure
    //     ListNode *curr = head, *prev = NULL, *future = NULL;

    //     // Traverse the list until `curr` becomes NULL (end of the list)
    //     while (curr) {
    //         // Step 1: Store the next node of `curr` in `future` to keep track of the original next node
    //         future = curr->next;

    //         // Step 2: Reverse the `next` pointer of `curr` to point to `prev` (reversing the link direction)
    //         curr->next = prev;

    //         // Step 3: Move `prev` and `curr` one step forward in the list
    //         prev = curr;       // `prev` moves to the current node
    //         curr = future;     // `curr` moves to the next node in the original list
    //     }

    //     // After the loop, `prev` will be pointing to the new head of the reversed list
    //     head = prev;

    //     // Return the new head of the reversed list
    //     return head;
    // }


    // Recursive Approach

    // Recursive helper function to reverse the linked list
    ListNode* Reverse(ListNode *curr, ListNode *prev) {
        // Base case: if `curr` is NULL, we have reached the end of the list
        // At this point, `prev` will be the new head of the reversed list
        if (curr == NULL) {
            return prev;
        }

        // Step 1: Store the next node of `curr` in `future`
        // This is needed to move to the next node in the original list after reversing the link
        ListNode *future = curr->next;

        // Step 2: Reverse the link by making `curr->next` point to `prev`
        curr->next = prev;

        // Step 3: Recursively call `Reverse` with `future` as the new `curr` and `curr` as the new `prev`
        return Reverse(future, curr);
    }

    // Public function to initiate the recursive reversal
    ListNode* reverseListRecursive(ListNode* head) {
        // We start with `head` as `curr` and `NULL` as `prev`
        // `prev` will eventually point to the new head of the reversed list
        return Reverse(head, NULL);
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

    // ListNode* reversedHead = solution.reverseList(head);
    ListNode* reversedHeadRecursive = solution.reverseListRecursive(head);

    // cout << "Reversed Linked List: ";
    // printList(reversedHead);

    cout << "Reversed Linked List (Recursive): ";
    printList(reversedHeadRecursive);

    return 0;
}