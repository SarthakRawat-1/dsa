// Problem Statement :- https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Problem Statement :- https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// Method 1 :- Find length of both prongs of the Linked List i.e. if we have a Linked List like :-
// 1->2->3->4->5->6->7     This is the first prong with length 7
//             ↑
//             9<-8       This is the second prong with length 5 (8->9->5->6->7)
// Once we find the length we can see that one prong has two extra nodes. So we will take two pointers curr1 and curr2 at start of both prongs (i.e. 1 and 8)
// We will now bring curr1 two nodes ahead. After this, we will move both curr1 and curr2 one by one till they meet at the same node. That same node will be our answer.

// Method 2 :- Pick one prong and using that reach the end of Linked List. In our above eg, it's 7
// Connect this to the head of one prong (for eg, 1 in above eg). This forms a loop. Now we can start from other prong (in our case, 8) and detect from where the loop is starting using slow and fast pointers. 
// We can't directly connect the end of Linked List to a prong because this will change the Linked List which is not allowed in our problem constraint. So we will use two pointers without modifying the lists to ensure the integrity of the data structures is preserved. Redirecting the pointers when they reach the end of their respective lists achieves the same result without creating a cycle. 

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
    // Method 1
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     // Initialize two pointers for traversing the two linked lists.
    //     ListNode* curr1 = headA; // Pointer for the first linked list.
    //     ListNode* curr2 = headB; // Pointer for the second linked list.

    //     // Initialize counters to store the lengths of the two linked lists.
    //     int count1 = 0, count2 = 0;

    //     // Step 1: Calculate the length of the first linked list.
    //     while (curr1) {
    //         count1++;            // Increment the counter for each node in list A.
    //         curr1 = curr1->next; // Move the pointer to the next node.
    //     }

    //     // Step 2: Calculate the length of the second linked list.
    //     while (curr2) {
    //         count2++;            // Increment the counter for each node in list B.
    //         curr2 = curr2->next; // Move the pointer to the next node.
    //     }

    //     // Reset the pointers to the heads of the respective linked lists.
    //     curr1 = headA; 
    //     curr2 = headB;

    //     // Step 3: Align the pointers at the same starting position.
    //     // If list A is longer, advance `curr1` to skip the extra nodes.
    //     while (count1 > count2) {
    //         count1--;            // Decrease the counter for list A.
    //         curr1 = curr1->next; // Move the pointer forward in list A.
    //     }

    //     // If list B is longer, advance `curr2` to skip the extra nodes.
    //     while (count2 > count1) {
    //         count2--;            // Decrease the counter for list B.
    //         curr2 = curr2->next; // Move the pointer forward in list B.
    //     }

    //     // Step 4: Traverse both lists together to find the intersection node.
    //     while (curr1 != curr2) { // Continue until the two pointers meet.
    //         curr1 = curr1->next; // Move the pointer in list A to the next node.
    //         curr2 = curr2->next; // Move the pointer in list B to the next node.
    //     }

    //     // If the pointers meet, they point to the intersection node.
    //     // If no intersection exists, both pointers will eventually become NULL.
    //     return curr1;
    // }

    // Method 2
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // If either list is empty, there can't be an intersection, return NULL.
        if (!headA || !headB) return NULL;

        // Initialize two pointers for traversing the lists.
        ListNode* curr1 = headA; // Pointer to traverse the first list.
        ListNode* curr2 = headB; // Pointer to traverse the second list.

        // Traverse both lists. The idea is that when one pointer reaches the end of its list,
        // it starts traversing the other list. This ensures both pointers traverse an equal number
        // of nodes (the sum of both list lengths). If there is an intersection, they will meet there.
        while (curr1 != curr2) {
            // Move `curr1` to the next node in list A, or to the head of list B if it reaches the end of list A.
            curr1 = curr1 ? curr1->next : headB;

            // Move `curr2` to the next node in list B, or to the head of list A if it reaches the end of list B.
            curr2 = curr2 ? curr2->next : headA;
        }

        // If the lists intersect, `curr1` and `curr2` will meet at the intersection node.
        // If they do not intersect, both will eventually reach the end (NULL) and exit the loop.
        return curr1; // Return the intersection node, or NULL if no intersection exists.
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
    ListNode* head1 = new ListNode(-1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(0);
    head2->next = new ListNode(2);
    head2->next->next = head1->next->next;

    Solution solution;

    ListNode* intersectionNode = solution.getIntersectionNode(head1, head2);    

    printList(intersectionNode);

    return 0;
}