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

// Our function to create a Linked list using recursion.
NODE* CreateLinkedList(vector<int> v, int index, int size, NODE* prev ) {
    if (index==size) {
        return prev;
    }
    
    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = prev; 
    
    return CreateLinkedList(v, index+1, size, temp);;
}

int main() {
    NODE *HEAD;
    HEAD = NULL;

    vector<int> v = {2, 4, 6, 8, 10};

    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    NODE *temp = HEAD; 
    
    while (temp != NULL) {
        cout << temp->data << " "; 
        temp = temp->next; 
    }
    // Output :- 10 8 6 4 2

    // Now we already have a Linked List created here. 


    // Inserting Node at a Particular position.
    // Let's say we want to insert a node after the third node which in our case is 6.
    int x = 3; 
    int value = 30; // Value to be inserted

    NODE *temp = HEAD;
    // Now temp is pointing to the first node. So it needs to move 2 times to reach the 3rd node.
    x--;

    while (x--) {
        temp = temp->next;
    }
    // Now temp is pointing to the 3rd node, which is 6 in our example.

    NODE *newNode = new NODE(value);
    // This order is extremely important, because we want to update next pointer in both previous node and the node to be isnerted.
    // If we first update the next pointer in previous node, we will not know the address of the node after the node to be inserted. This address needs to be stored in the node to be inserted next pointer and hence we need that. This address is present in next pointer of previous node before it is updated with reference of the new node to be inserted.
    newNode->next = temp->next;
    temp->next = newNode;
}