// A Doubly Linked List (DLL) is a type of linked list where each node contains data and two pointers :- A next pointer that points to the next node in the list and a previous pointer that points to the previous node in the list.
// This structure allows traversal in both directions i.e. forward and backward.

#include <bits/stdc++.h>
using namespace std;

// Definition for a node in doubly linked list.
class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

