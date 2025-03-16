// Problem Statement :- https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=problem-list-v2&envId=linked-list

// This is quite similar to flatteningLinkedList.cpp
// We will follow the same approach of breaking down into mergeTwoSortedList.cpp

// Other method to solve this is using Merge Sort.
// Refer lecture for that.

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

    // Method 1 :- You can use the same approach as flatteningLinkedList.cpp
    // But this divide and conquer approach implements that in a better way
    // In flatteningLinkedList.cpp we were doing L1 merge L2 = R1, then R1 merge L3 = R2, then R2 merge L4 etc. which can be tedious as R3, R4 etc. can grow a lot in size.
    // In this, we are doing L1 merge L3 = R1, then L2 merge L4 = R2, then R1 merge R2 = R3 etc. which is a lot more efficient.
    // Merge two sorted linked lists.
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to simplify edge cases.
        ListNode* tail = &dummy; // Pointer to the last node of the merged list.

        // Merge the two lists while both have nodes remaining.
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1; // Attach the smaller node.
                l1 = l1->next;   // Move to the next node in l1.
            } else {
                tail->next = l2; // Attach the smaller node.
                l2 = l2->next;   // Move to the next node in l2.
            }
            tail = tail->next; // Advance the tail pointer.
        }

        // Attach any remaining nodes from either list.
        tail->next = l1 ? l1 : l2;

        return dummy.next; // Return the merged list starting after the dummy node.
    }

    // Merge k sorted linked lists using divide-and-conquer.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // Handle edge case of empty input.
        int n = lists.size(); // Number of linked lists.

        // Continuously merge lists in pairs until one list remains.
        while (n > 1) {
            int k = (n + 1) / 2; // Number of pairs.
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]); // Merge pairs.
            }
            n = k; // Reduce the size of the problem.
        }

        return lists[0]; // Return the final merged list.
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

    vector<ListNode*> lists = { head, head->next, head->next->next, head->next->next->next, head->next->next->next->next };
    ListNode* mergedList = solution.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(mergedList);

    return 0;
}