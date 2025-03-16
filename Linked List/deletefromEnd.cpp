// Deletion at end involves traversing the list to second last node and setting its next pointer to NULL.

// Just like in insertionatEnd.cpp, here also we won't use HEAD to traverse the linked list. We will use a temporary pointer, initialized to HEAD. Then we will move this temporary pointer to the point to the last node of Linked List, using the help of a while loop, with the condition that last node next pointer will be NULL. Now obv, we can just use delete keyword to delete the last node.
// But before that, we will have to set the next pointer of second last element to NULL. For this we will also use another pointer, let's call it prev. This will be initialized to NULL. Now whenever we store the next pointer in temporary pointer, before that we will have to store the temporary pointer in prev pointer. This will ensure that the temporary pointer always stays one node ahead at the end of loop iteration. So once, the end node is reacher, temporary pointer will become null (which means loop ends now), but prev pointer will store the next of second last node. 
// Edge Case :- It could be that the HEAD pointer is NULL meaning empty Linked List. So in this case, we don't have to do anything.
// Edge Case :- It could be that the Linked List has only one node. In this case, prev pointer will remain NULL even after deletion. Now, when we were changing the second last node next pointer to be NULL using the prev pointer, the next pointer of prev doesn't exist! Also in this case, HEAD pointer will still store the address of first node, which doesn't even exist now! This edge case we can handle by first checking the next pointer of HEAD, if it is NULL, then we can simply make a temporary pointer, initialize it to HEAD, set HEAD to NULL and then use delete keyword with temporary pointer to delete the Node. But if we don't even want that HEAD pointer as it doesn't store any valuable information now. We can simply just delete the HEAD pointer instead.

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

int main() {
    NODE* HEAD = NULL;
    int arr[] = {2, 4, 6, 1, 7};

    HEAD = CreateLinkedList(arr, 0, 5);

    // Delete a Node from end of Linked List

    if (HEAD != NULL) {
        if (HEAD->next == NULL) { // If there is only one node in Linked list
            // Method - 1 :- Deleting the only node using HEAD pointer
            // delete HEAD;
            // HEAD = NULL;

            // Method - 2 :- Deleting the only node using temporary pointer
            NODE* temp = HEAD;
            HEAD = NULL;
            delete temp;
        }
        else {
            NODE *curr = HEAD;
            NODE *prev = NULL;

            while (curr->next != NULL) { // Till curr pointer is not storing address of last element i.e. next pointer of curr is not NULL
                prev = curr; // prev now points to element pointed by curr
                curr = curr->next; // Move curr to point to the next element.
            }

            // Now we have reached last node with curr and prev is now pointing to second last node
            prev->next = NULL; // Set the next pointer of second last node to be NULL
            delete curr; // Delete the last node
        }
    }
    

    while (HEAD) {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }
}