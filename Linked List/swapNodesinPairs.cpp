// Problem Statement :- https://leetcode.com/problems/swap-nodes-in-pairs/description/

// Let's say you have a LL :- A->B->C->D
// We can say, head = A, head->next = B, head->next->next = C and if we are at A, then we know that we have to swap it with it's next node. Rest of the LL we will swap later.
// After swapping, A->next should now point to D (because C and D should also be swapped).
// In short, we can say :- A->next i.e. head->next = solve(head->next->next); where solve will be the swapped version of further LL starting from C.
// And B->next should now point to A i.e. head->next->next = head, but we can't directly write this as we haev changed the head->next above. So we can store that in a new variable temp, temp = head->next;
// Now finally as B is starting node of LL now, we should return that. In our case, temp will represent that.

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
    ListNode* swapPairs(ListNode* head) {
        // Base case: If the list is empty or has only one node, no swapping is needed.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Store the second node (the one that will become the new head after swapping).
        ListNode* temp = head->next;

        // Recursively swap the rest of the list starting from the third node.
        // The result of this recursive call will be the new next node for the current head.
        head->next = swapPairs(head->next->next);

        // Make the second node point to the first node, effectively swapping them.
        temp->next = head;

        // Return the new head of the swapped pair, which is the second node.
        return temp;
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
    // Create a sample linked list: 1 -> 3 -> 2 -> 5 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);

    cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    // Swap pairs in the linked list
    ListNode* newHead = solution.swapPairs(head);

    cout << "Linked List after swapping pairs: ";
    printList(newHead);

    return 0;
}