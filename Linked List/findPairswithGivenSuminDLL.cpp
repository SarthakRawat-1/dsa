#include <bits/stdc++.h>
using namespace std;

// Definition for a node in a doubly linked list.
class Node {
    public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the list
    Node *prev;     // Pointer to the previous node in the list

    // Constructor to initialize a new node with a given value
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Recursive function to insert nodes at the beginning of the doubly linked list
Node* insertAtBeginning(int arr[], int index, int size, Node* head) {
    // Base case: If index reaches size, return the head as the recursion ends
    if (index == size) {
        return head;
    }

    // Create a new node with the current element of the array
    Node* temp = new Node(arr[index]);

    // Insert the new node at the beginning
    temp->next = head; // New node's next pointer should point to the current head
    if (head != NULL) {
        head->prev = temp; // Update head's previous pointer if head is not NULL
    }

    // Update head to the new node
    head = temp;

    // Recursive call for the next element in the array
    return insertAtBeginning(arr, index + 1, size, head);
}

/* ============================================================
   Solution Function: Find pairs with given sum in a sorted DLL
   ============================================================ */
vector<pair<int,int>> findPairsWithGivenSum(Node* head, int target) {
    vector<pair<int,int>> result;
    if (!head) return result; // Edge case: empty list

    // Step 1: Find the tail pointer (last node in DLL)
    Node* left = head;
    Node* right = head;
    while (right->next) {
        right = right->next;
    }

    // Step 2: Use two-pointer technique
    while (left && right && left->data < right->data) {
        int sum = left->data + right->data;

        if (sum == target) {
            // Found a valid pair
            result.push_back({left->data, right->data});
            // Move both pointers inward
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            // If sum is too small, move left forward to increase it
            left = left->next;
        }
        else {
            // If sum is too large, move right backward to decrease it
            right = right->prev;
        }
    }

    return result;
}


int main() {
    // Initialize the head pointer to NULL, representing an empty doubly linked list
    Node* head = NULL;

    // Array of elements to be inserted at the beginning of the doubly linked list
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5};

    head = insertAtBeginning(arr, 0, 12, head);

    // Target sum
    int target = 7;

    // Call the solution function
    vector<pair<int,int>> pairs = findPairsWithGivenSum(head, target);

    // Print the result
    cout << "Pairs with sum " << target << " are: ";
    for (auto &p : pairs) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
