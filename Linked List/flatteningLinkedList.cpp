// Problem Statement :- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Break this down into simpler problems. We will try to convert this problem into mergeTwoSortedList.cpp
// As each of the sub LL are sorted. First, we will take two sub LL and merge them together. Then we can take this resultant LL and another sub LL and merge them together.
// Continue doing this till all the LL are merged.
// Remember that we have to connect nodes using bottom printer.

// We will take a root pointer as head  of the resultant LL (at each merge) and also the head of the final flattened LL.
// Initially we take head1, head2 and head3 pointers for the heads of three sub LL (side by side). Initially we, keep root at head1.
// We will merge if the next of root exists which guarantees that there are atleast two sub LL to merge.
// Before merging, we will make head1->next and head2->next NULL (as there is no need of next in merging). This iw hy we kept head3, to s till have access to rest of the LL.
// After merging, make root point to the head of the merged list (i.e. root is the head of merged list). Then we do root->next = head3, so our property of LL holds.
// Then, just repeat the above process.
// Finally, when root->next is NULL, return root.

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node in the linked list.
struct Node {
    int data;
    Node* next;   // Pointer to the next node in the same level.
    Node* bottom; // Pointer to the next node in the flattened list.

    Node(int val) { // Constructor for creating a new node.
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

// Function to merge two sorted linked lists.
Node* merge(Node* head1, Node* head2) {
    // Create a dummy node to simplify edge cases.
    Node* head = new Node(0);
    Node* tail = head; // Pointer to track the tail of the merged list.

    // Merge the two linked lists while both have nodes remaining.
    while (head1 && head2) {
        if (head1->data <= head2->data) { // Compare values to maintain sorted order.
            tail->bottom = head1;      // Attach the smaller node to the result list.
            head1 = head1->bottom;    // Move to the next node in the first list.
        } else {
            tail->bottom = head2;      // Attach the smaller node to the result list.
            head2 = head2->bottom;    // Move to the next node in the second list.
        }
        tail = tail->bottom;          // Move the tail pointer forward.
        tail->bottom = NULL;          // Ensure the bottom pointer is null.
    }

    // If any nodes are remaining in one of the lists, attach them.
    if (head1) {
        tail->bottom = head1;
    } else {
        tail->bottom = head2;
    }

    return head->bottom; // Return the head of the merged list (excluding dummy node).
}

// Function to flatten the linked list.
Node* flatten(Node* root) {
    // Pointers to track the heads of the sub-lists being merged.
    Node *head1, *head2, *head3;

    // Continue merging until there is only one flattened list remaining.
    while (root->next) {
        head1 = root;            // First sub-list to merge.
        head2 = root->next;      // Second sub-list to merge.
        head3 = root->next->next; // Remaining lists after the second sub-list.

        // Disconnect the 'next' pointers as they are not needed in merging.
        head1->next = NULL;
        head2->next = NULL;

        // Merge the two sub-lists and update root to point to the merged list.
        root = merge(head1, head2);

        // Restore the 'next' pointer for further merging.
        root->next = head3;
    }

    return root; // Return the head of the final flattened list.
}

// Function to print the flattened linked list.
void printList(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

// Helper function to insert nodes into the 'bottom' list.
Node* insertBottom(Node* head, int data) {
    if (!head) return new Node(data);
    Node* temp = head;
    while (temp->bottom) temp = temp->bottom;
    temp->bottom = new Node(data);
    return head;
}

// Main function to demonstrate the flattening process.
int main() {
    // Example linked list structure creation.
    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next = new Node(10);
    root->next->bottom = new Node(20);

    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten the list and print the result.
    root = flatten(root);
    printList(root);

    return 0;
}
