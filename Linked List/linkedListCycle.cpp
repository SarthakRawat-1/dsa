// Problem Statement :- https://leetcode.com/problems/linked-list-cycle/description/
// Problem Statement :- https://leetcode.com/problems/linked-list-cycle-ii/description/
// Problem Statement :- https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// Use the Hare and Tortoise approach. When both fast and slow pointer meets on the same node, we know there is a cycle.
// After this, we will use another pointer, say p (starting from head). We will increase p and slow both one by one. Wherever they meet, that will be the starting point of the cycle. So you can jsut return p (or slow).

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

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         // Edge case: If the list is empty or has only one node, there cannot be a cycle.
//         if (head == NULL || head->next == NULL) {
//             return NULL;
//         }

//         // Initialize two pointers: 'slow' will move one step at a time, and 'fast' will move two steps at a time.
//         ListNode* slow = head;
//         ListNode* fast = head;

//         // Loop until either the fast pointer reaches the end (i.e., no cycle) or the slow and fast pointers meet (indicating a cycle).
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;          // Move 'slow' one step.
//             fast = fast->next->next;    // Move 'fast' two steps.

//             // If 'slow' and 'fast' meet, a cycle is detected. Break the loop.
//             if (slow == fast) {
//                 break;
//             }
//         }

//         // If the 'slow' and 'fast' pointers do not meet, there is no cycle in the list.
//         if (slow != fast) {
//             return NULL;   // No cycle.
//         }

//         // To find the start of the cycle:
//         // Initialize a new pointer 'p' at the head of the list.
//         ListNode* p = head;

//         // Move 'p' and 'slow' one step at a time until they meet.
//         // The meeting point will be the starting node of the cycle.
//         while (p != slow) {
//             p = p->next;       // Move 'p' one step forward.
//             slow = slow->next; // Move 'slow' one step forward.
//         }

//         // Return the node where 'p' and 'slow' meet, which is the starting point of the cycle.
//         return p;
//     }
// };

// Method 2 :- Using Unordered Map
class Solution {
    public:
    // Function to detect a loop in a linked list
    bool detectLoop(ListNode* head) {
        // Initialize a pointer to traverse the linked list
        ListNode* curr = head;

        // Create an unordered_map (hash table) to store nodes as keys and a boolean value to track if a node has been visited
        unordered_map<ListNode*, bool> visited;

        // Traverse the linked list
        while (curr != NULL) {
            // Check if the current node is already present in the hash table
            // If it is, it means we've encountered this node before, indicating a loop
            if (visited[curr] == true) {
                return true; // Loop detected, return true
            }

            // Mark the current node as visited by adding it to the hash table
            visited[curr] = true;

            // Move to the next node in the linked list
            curr = curr->next;
        }

        // If we reach the end of the linked list (curr == NULL), there is no loop
        return false;
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
    // Create a linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle for testing (link the last node back to the second node)
    head->next->next->next->next = head->next; // -4 -> 2

    // Create an instance of Solution to use the detectCycle method
    Solution solution;

    // Detect cycle
    // ListNode* cycleStart = solution.detectCycle(head);
    bool cycleExists = solution.detectLoop(head);

    // Print result
    // if (cycleStart) {
    //     cout << "Cycle detected starting at node with value: " << cycleStart->val << endl;
    // } else {
    //     cout << "No cycle detected." << endl;
    // }

    if (cycleExists) {
        cout << "Loop detected." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Cleanup: free allocated memory (this would be more comprehensive in a real application)
    // Note: In practice, you might want to break the cycle before deleting to avoid memory leaks
    head->next->next->next->next = NULL; // Break the cycle for cleanup
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp; // Free each node
    }

    return 0;
}
