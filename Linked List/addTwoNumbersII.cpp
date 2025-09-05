// Problem Statement :- https://leetcode.com/problems/add-two-numbers/description/
// Problem Statement :- https://leetcode.com/problems/add-two-numbers-ii/description/

// First we will reverse both Linked Lists. Then add the two reversed Linked Lists.
// To add the two reversed Linked Lists, we will add the corresponding nodes from both Linked Lists and store the sum in a new Linked List node. If there's a carry, we will store it in a variable.
// New nodes representing the sum of corresponding nodes will be added to the new Linked List in the beginning so that we don't have to reverse the Linked List in the end to get the final Linked List.

#include <bits/stdc++.h>
using namespace std;

// Definition for a singly-linked list node.
class ListNode {
public:
    int val;             // Value of the node (data)
    ListNode* next;      // Pointer to the next node in the list

    // Constructor to initialize a new node
    ListNode(int value = 0) {
        val = value;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        // Base case: If the list is empty or contains a single node, return the head.
        if (!head || !head->next) {
            return head;
        }

        // Recursive step: Reverse the rest of the list starting from the next node.
        ListNode* last = reverseLL(head->next);

        // Adjust pointers to reverse the current node.
        head->next->next = head; // Point the next node's next pointer back to the current node.
        head->next = NULL;       // Set the current node's next pointer to NULL to terminate the list.

        // Return the new head of the reversed list.
        return last;
    }

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Step 1: Reverse both lists so addition starts from least significant digit.
    l1 = reverseLL(l1);
    l2 = reverseLL(l2);

    int carry = 0;              // To store carry after each digit addition
    ListNode* ans = nullptr;    // Head of the result list (built in reverse)

    // Step 2: Process both lists until all digits and carry are consumed
    while (l1 || l2 || carry) {
        int sum = carry;        // Start with any leftover carry from previous step

        // Add l1's digit if available
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add l2's digit if available
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Step 3: Extract digit and new carry
        carry = sum / 10;       // Carry for next iteration
        int digit = sum % 10;   // Current digit to store in result

        // Step 4: Create new node for this digit
        // Prepend to the result (since we're building from least significant digit upward)
        ListNode* newNode = new ListNode(digit);
        newNode->next = ans;
        ans = newNode;
    }

    // Step 5: Return the head of the result list
    return ans;
}

};

//Approach-2 (Using Stack) - What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
// class Solution {
// public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Push all digits of l1 and l2 into stacks
        // This reverses the order so we can add from least significant digit
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;              // To store carry during addition
        ListNode* ans = nullptr;    // Head of the result list (will be built in correct order)

        // Step 2: Process until both stacks are empty AND no carry remains
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;        // Start with carry from previous step

            // Pop top value from s1 if available
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            // Pop top value from s2 if available
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Compute new carry and the digit for this place
            carry = sum / 10;       // Carry to propagate to next digit
            int digit = sum % 10;   // Current digit to store

            // Step 3: Create a new node with the digit
            // and insert it at the front of the result list
            ListNode* newNode = new ListNode(digit);
            newNode->next = ans;
            ans = newNode;
        }

        // Step 4: Return the head of the result list
        return ans;
    }
// };

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(5);

    Solution solution;

    ListNode* sumList = solution.addTwoNumbers(head1, head2);

    cout << "Sum of both Linked List :- " << endl;

    printList(sumList);

    return 0;
}