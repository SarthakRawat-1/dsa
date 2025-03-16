// Problem Statement :- https://leetcode.com/problems/sort-list/description/

// Brute Force Approach :- Convert the linked list into an array, sort the array, and then create a new linked list from the sorted array's values. 

// Optimal Appraoch :- Use Merge Sort Algorithm

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
    // Function to find the middle node of the linked list
    ListNode* findMiddle(ListNode* head) {
        // Base case: if the list is empty or has only one node,
        // the middle is the head itself
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize two pointers: slow moves one step at a time,
        // while fast moves two steps at a time
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Traverse the list until fast reaches the end or its next is NULL
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // Move slow by one step
            fast = fast->next->next; // Move fast by two steps
        }

        // Slow will now be pointing to the middle node
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the process of merging
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode; // Temp pointer to track the merged list

        // Traverse both lists until one of them becomes NULL
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                // If the current node in list1 is smaller or equal,
                // append it to the merged list
                temp->next = list1;
                list1 = list1->next; // Move to the next node in list1
            } else {
                // Otherwise, append the current node in list2
                temp->next = list2;
                list2 = list2->next; // Move to the next node in list2
            }
            temp = temp->next; // Advance the temp pointer
        }

        // Append the remaining nodes of list1 or list2
        if (list1 != NULL) {
            temp->next = list1; // Attach the rest of list1
        } else {
            temp->next = list2; // Attach the rest of list2
        }

        // Return the head of the merged list (next of dummyNode)
        return dummyNode->next;
    }

    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node,
        // it is already sorted
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Step 1: Find the middle of the linked list
        ListNode* middle = findMiddle(head);

        // Step 2: Divide the list into two halves
        ListNode* right = middle->next; // Start of the second half
        middle->next = NULL;            // Break the list into two halves
        ListNode* left = head;          // Start of the first half

        // Step 3: Recursively sort both halves
        left = sortList(left);   // Sort the first half
        right = sortList(right); // Sort the second half

        // Step 4: Merge the two sorted halves
        return mergeTwoSortedLists(left, right);
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
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);

    cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    head = solution.sortList(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}