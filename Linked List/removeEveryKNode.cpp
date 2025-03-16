// Problem Statement :- https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

#include <iostream>
#include <vector>
using namespace std;

class NODE {
    public :
    int data;
    NODE *next;

    NODE(int value) {
        data = value;
        next = NULL;
    }
};

NODE* CreateLinkedList(int arr[], int index, int size) {
    if (index == size) return NULL;

    NODE* temp = new NODE(arr[index]);
    temp->next = CreateLinkedList(arr, index+1, size);
    return temp;
}

NODE* deleteK(NODE* head, int k) {
    // Initialize `curr` to start from the head of the linked list.
    NODE* curr = head;
    // `prev` pointer to keep track of the previous node.
    NODE* prev = NULL;

    // Initialize a counter to keep track of the current node position.
    int count = 1;

    // Special case: if `k` is 1, we need to remove every node, so we return NULL.
    if (k == 1) {
        return NULL;
    }

    // Traverse the list to remove every kth node.
    while (curr) {
        // Check if we are at the kth position
        if (count == k) {
            // Update the `next` pointer of the previous node to skip the kth node
            prev->next = curr->next;

            // Delete the kth node to free up memory
            delete curr;

            // Move `curr` to the next node after the deleted node
            curr = prev->next;

            // Reset the counter after deletion to start counting for the next kth node
            count = 1;
        } else {
            // Move `prev` to `curr` (current node becomes the previous one)
            prev = curr;

            // Move `curr` to the next node in the list
            curr = curr->next;

            // Increment the counter
            count++;
        }
    }

    // Return the head of the modified linked list
    return head;
}

int main() {
    NODE* HEAD = NULL;
    int arr[] = {2, 4, 6, 1, 7};

    HEAD = CreateLinkedList(arr, 0, 5);

    HEAD = deleteK(HEAD, 2);

    while (HEAD) {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }

    return 0;
}