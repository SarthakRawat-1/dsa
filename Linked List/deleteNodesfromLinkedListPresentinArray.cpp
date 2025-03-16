// Problem Statement :- https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

// Store all the elements of array into an unordered set. Then traverse the Linked List using a curr pointer (starting from head), and when you encounter an element which is present in the set, we have to change the next pointer of the previous node.
// So we will beforehand check if the next node to the curr node needs to be deleted or not. In this case, if it needs to be deleted, we can just update curr->next to curr->next->next
// If the node need not be deleted, then simply move the curr node to curr->next
// If the first node also has to be deleted, then we will update head to head->next (Ofc if first, second, third nodes have to be deleted, then head will point to the fourth node).
// After this we can initialize the curr pointer with head.

// We can encounter a heap use after free error, with this approach.

// Hence, we use the help of curr pointer to delete the initial nodes. And here, curr pointer will point to the current node. We will use another pointer, prev, to access the previous node.

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
     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create an unordered_set from the 'nums' vector to store values that need to be removed from the linked list.
        unordered_set<int> st(begin(nums), end(nums));

        // Initialize two pointers: 'prev' (to track the previous node) and 'curr' (to traverse the list from the head).
        ListNode* prev = NULL;
        ListNode* curr = head;

        // This first while loop handles the case where the head node(s) need to be deleted
        // because their values exist in the 'st' set.
        while (curr != NULL && st.count(curr->val)) {
            head = curr->next;  // Move the head pointer to the next node.
            curr = head;        // Update the current node to the new head.
        }

        // The second while loop processes the remaining nodes of the list.
        // It checks whether a node's value exists in the 'st' set and deletes the node if necessary.
        while (curr != NULL) {
            int currVal = curr->val;  // Get the value of the current node.
            
            // If the current value is not found in the set, update 'prev' and move to the next node.
            if (!st.count(currVal)) {
                prev = curr;          // Move 'prev' to the current node.
                curr = curr->next;    // Move 'curr' to the next node.
            } else {
                // If the current node's value is in the set, remove the node by updating 'prev->next'.
                // Skip over the current node by pointing 'prev->next' to 'curr->next'.
                prev->next = curr->next;
                curr = curr->next;    // Move to the next node in the list.
            }
        }

        // Return the new head of the modified list.
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

    // Values to be removed: [2, -4]
    vector<int> nums = {2, -4};

    // Create an instance of Solution
    Solution solution;

    // Call the modifiedList function to modify the linked list
    ListNode* modifiedHead = solution.modifiedList(nums, head);

    // Print the modified linked list
    cout << "Modified Linked List: ";
    printList(modifiedHead);

    return 0;
}
