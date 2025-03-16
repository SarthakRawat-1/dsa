// Insertion at end involves traversing the list to the last node and setting its next pointer to the new node.

#include <iostream>
#include <vector>
using namespace std;


class NODE {
    public:
    int data; 
    NODE *next; 

    NODE(int value) {
        data = value;
        next = NULL;
    }
};

// Function to create Linked List using Recursion
NODE* CreateLinkedList(vector<int> v, int index, int size ) {
    // Base Case. This will happen when index becomes equal to size meaning no more elements are left in the vector. Thus NULL will be returned.
    // This NULL will be assigned to the next pointer of the last node only. Which is exactly what we want.
    if (index==size) {
        return NULL;
    }

    // First we will have to create a NODE, then we would need next pointer for that node. But as that next pointer points to the next node, which is not created yet, so we will have to create the next node first. This goes on and on.
    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = CreateLinkedList(v, index+1, size);

    // This logic will execute till index becomes equal to size. We need this because we have to create nodes for every element in the vector.

    // When the NULL is returned from Base class for the last node, then using Recursion, we will return the temp NODE pointer which will assign address of the NODE to the previous NODE next pointer..
    return temp;
}

int main() {
    NODE *HEAD;

    vector<int> v = {1, 2, 3, 4};

   for (int i = 0; i < v.size(); i++){
        if (HEAD == NULL) {
            HEAD = new NODE(v[i]);
        }
        else {
            NODE *tail = HEAD; // We will use this to traverse the Linked List. This however is not a good option as it means we will have to traverse the entire linked list when we want to insert a mew element.
            while (tail->next != NULL) {
                tail = tail->next;
                // This will traverse to the last node.
            }
            NODE *temp = new NODE(v[i]); // This will create the new node to be inserted at the end.
            tail->next = temp; // Setting the next pointer of the last node to the new node which is our last node now.

            // You can directly write this statement as a subsitution of above two statements of creating a node and setting the next pointer.
            // tail->next = new NODE(v[i]);
        }
   }

   // Better way to insert at end
   NODE *TAIL = NULL; // Declare this pointer to keep track of end of Linked List.

   for (int i = 0; i < v.size(); i++) {
        if (HEAD == NULL) {
            HEAD = new NODE(v[i]);
            TAIL = HEAD; // This means only one element present in Linked list. In that case, both Head and Tail points to the same element.
        }
        else {
            TAIL->next = new NODE(v[i]); // Now we can just create the new node and set the next pointer of previous last node to the new node address which will be our new last node.
            TAIL = TAIL->next; // Set Tail to point to the new last node.
        }
   }

   // Add node at end using Recursion.
   // For convenience, I am making this part of code separate from other code present in the main() before this.
   // NODE *HEAD;
   // Calling the function
    HEAD = CreateLinkedList(v, 0, v.size());
}