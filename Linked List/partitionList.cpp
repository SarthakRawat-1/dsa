// Problem Statement :- https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=linked-list

// We will create two separate Linked Lists (using small and large as their head pointers) for nodes smaller and greater than x and then join them together.

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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes:
        // 'small' will be the head of the list containing nodes with values < x.
        // 'large' will be the head of the list containing nodes with values >= x.
        ListNode* small = new ListNode(0);  // Dummy node for the 'small' list.
        ListNode* large = new ListNode(0);  // Dummy node for the 'large' list.

        // Pointers to traverse and build the 'small' and 'large' lists.
        ListNode* smallP = small;  // Pointer to track the last node in the 'small' list.
        ListNode* largeP = large;  // Pointer to track the last node in the 'large' list.

        // Traverse the original list until the end.
        while (head != NULL) {
            // If the current node's value is less than x, add it to the 'small' list.
            if (head->val < x) {
                smallP->next = head;   // Connect the current node to the 'small' list.
                smallP = smallP->next; // Move the 'smallP' pointer forward.
            } 
            // If the current node's value is greater than or equal to x, add it to the 'large' list.
            else {
                largeP->next = head;   // Connect the current node to the 'large' list.
                largeP = largeP->next; // Move the 'largeP' pointer forward.
            }

            // Move to the next node in the original list.
            head = head->next;
        }

        // After traversing the list:
        // Connect the last node of the 'small' list to the head of the 'large' list.
        smallP->next = large->next;

        // Ensure the last node of the 'large' list points to NULL to terminate it.
        largeP->next = NULL;

        // The head of the partitioned list is the first real node after the dummy node 'small'.
        return small->next;
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
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);

    Solution solution;

    int x = 3;

    ListNode* partitionedList = solution.partition(head, x);    

    printList(partitionedList);

    return 0;
}