// Problem Statement :- https://leetcode.com/problems/merge-in-between-linked-lists/description/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // `left` will point to the node just before index `a` in `list1`.
        // `right` is used to traverse `list1` to find the node after index `b`.
        ListNode* left = NULL;
        ListNode* right = list1;

        // Step 1: Traverse `list1` to locate the nodes at positions `a-1` (left) and `b` (right).
        for (int i = 0; i <= b; i++) {
            if (i == a - 1) {
                // `left` is the node just before the range `[a, b]` to be removed.
                left = right;
            }
            // Move `right` to the next node.
            right = right->next;
        }

        // Step 2: Connect the `left` node to the head of `list2`.
        left->next = list2;

        // Step 3: Traverse `list2` to find its tail (last node).
        ListNode* temp = list2;
        while (temp && temp->next) {
            temp = temp->next;
        }

        // Step 4: Connect the tail of `list2` to the `right` node (node after `b` in `list1`).
        temp->next = right;

        // Step 5: Return the modified `list1` as the result.
        return list1;
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
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    Solution solution;

    ListNode* mergedList = solution.mergeInBetween(head1, 1, 2, head2);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}
