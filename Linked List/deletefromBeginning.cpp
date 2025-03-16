// Deletion operation is used to delete a Node from a Linked List
// Deletion can happen at the beginning or at the end or at a given position.
// Deleting the first node in a Linked List involves changing HEAD pointer such that it points to the second node. And we can delete the first node now.

// First we have to create a temp pointer to point to first element , so it will take the value of HEAD pointer obv.
// Now, we can change the HEAD pointer to point to the second element, which can be achieved by storing HEAD->next in HEAD.
// Now using temp, we can simply delete the node by :- delete temp;
// Edge Cases :- It could be that the HEAD pointer is NULL meaning empty Linked List. So in this case, we don't have to do anything.
// There's one more Edge Case which i have described in detail in deletefromEnd.cpp

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

    // Delete a Node from Starting of Linked List

    if (HEAD != NULL) {
        NODE* temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    }

    while (HEAD) {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }
}