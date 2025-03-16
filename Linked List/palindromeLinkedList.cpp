// Problem Statement :- https://leetcode.com/problems/palindrome-linked-list/description/

// A simple way to do this is to traverse the Linked List and store it's data in a vector or array. After that, just find of the array or vector is a palindrome or not.

// Better Approach :- Break the Linked List into 2 equal parts from the middle. Reverse the second half. Then using pointers compare corresponding nodes of both halves.
// If number of nodes are odd, then also do the same (it doesn't matter in which half the middle node is going but still, it will go in the second half always). If any one of the pointer becomes NULL while traversing, it is a palindrome. We need not compare the extra middle node (which has become the last node when we reversed. The other half will exhuast before this, if it indeed is a palindrome).

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
    bool isPalindrome(ListNode* head) {
        // Edge case: If the list has only one node, it is a palindrome
        if (head->next == NULL) {
            return true;
        }

        // Step 1: Count the number of nodes to find the midpoint
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Divide the count by 2 to reach the middle of the list
        count = count / 2;

        // Step 2: Traverse to the middle node and disconnect the first half from the second half
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }
        // Disconnect the two halves
        prev->next = NULL;

        // Step 3: Reverse the second half of the list
        ListNode* front;
        prev = NULL;
        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Step 4: Compare the two halves
        ListNode* head1 = head;   // Pointer to the start of the first half
        ListNode* head2 = prev;   // Pointer to the start of the reversed second half
        while (head1 && head2) {  // Traverse and compare corresponding nodes
            if (head1->val != head2->val) {
                return false;     // If values do not match, it's not a palindrome
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // If all corresponding nodes matched, the list is a palindrome
        return true;
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
    // Creating a linked list: 1 -> 2 -> 2 -> 1, which is a palindrome
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;

    // Print the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Check if the linked list is a palindrome
    bool result = solution.isPalindrome(head);

    // Output the result
    if (result) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}