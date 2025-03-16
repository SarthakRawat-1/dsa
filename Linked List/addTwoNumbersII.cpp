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
        // Step 1: Reverse both input linked lists to simplify addition.
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        int sum = 0, carry = 0;  // Initialize variables for the sum and carry.
        ListNode* ans = new ListNode(); // Create a dummy node for the result.

        // Step 2: Iterate through both linked lists until all nodes are processed.
        while (l1 != NULL || l2 != NULL) {
            if (l1) { 
                sum += l1->val; // Add the value of the current node from l1.
                l1 = l1->next;  // Move to the next node in l1.
            }
            if (l2) {
                sum += l2->val; // Add the value of the current node from l2.
                l2 = l2->next;  // Move to the next node in l2.
            }

            // Step 3: Calculate the digit to store in the current node and the carry.
            ans->val = sum % 10; // Store the unit digit of the sum in the current node.
            carry = sum / 10;    // Compute the carry for the next iteration.

            // Step 4: Create a new node for the carry and link it to the current result.
            ListNode* newNode = new ListNode(carry); // Create a new node with the carry value.
            newNode->next = ans; // Point the new node to the current head of the result list.
            ans = newNode;       // Update the head of the result list to the new node.

            sum = carry; // Reset the sum to carry for the next iteration.
        }

        // Step 5: If there's no carry left, skip the dummy node and return the actual result.
        return carry == 0 ? ans->next : ans;
    }
};

//Approach-2 (Using Stack) - What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         // Stacks to store the values of the nodes in reverse order
//         stack<int> s1, s2;

//         // Traverse the first linked list and push values onto stack s1
//         while (l1 != NULL) {
//             s1.push(l1->val); // Push the current node's value onto the stack
//             l1 = l1->next;    // Move to the next node
//         }

//         // Traverse the second linked list and push values onto stack s2
//         while (l2 != NULL) {
//             s2.push(l2->val); // Push the current node's value onto the stack
//             l2 = l2->next;    // Move to the next node
//         }

//         int sum = 0, carry = 0;         // Initialize sum and carry variables
//         ListNode* ans = new ListNode(); // Create a dummy node for the result list

//         // Process the stacks until both are empty
//         while (!s1.empty() || !s2.empty()) {
//             if (!s1.empty()) {
//                 sum += s1.top(); // Add the top value from stack s1 to sum
//                 s1.pop();        // Remove the top element from stack s1
//             }
//             if (!s2.empty()) {
//                 sum += s2.top(); // Add the top value from stack s2 to sum
//                 s2.pop();        // Remove the top element from stack s2
//             }

//             // Calculate the value for the current digit and the carry
//             ans->val = sum % 10; // Extract the least significant digit
//             carry = sum / 10;    // Calculate the carry for the next iteration

//             // Create a new node for the carry and link it to the result list
//             ListNode* newNode = new ListNode(carry); // Node for the carry
//             newNode->next = ans; // Link the new node to the front of the list
//             ans = newNode;       // Update the head of the result list
//             sum = carry;         // Reset sum to carry for the next iteration
//         }

//         // If there's no carry left, skip the dummy node and return the result
//         return carry == 0 ? ans->next : ans;
//     }
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