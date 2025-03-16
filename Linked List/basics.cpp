// A Linked List is a data structure in which elements, called nodes, are arranged in a linear sequence, but they are not stored in contiguous memory locations like arrays.
// Each node contains two parts :- Data: The value or information that the node holds. Pointer/Reference: A link or reference to the next node in the sequence.
// Linked lists allow dynamic memory allocation, meaning the size of the list can grow or shrink during runtime, and insertion or deletion of elements is more efficient compared to arrays.
// There are two types of linked lists: Singly Linked List and Doubly Linked List.
// In Singly Linked List each node contains only one pointer to the next node. Traversal is only possible in one direction, from the head (first node) to the last node. 

#include <iostream>
using namespace std;

// We can use classes to create Linked lists.
class NODE {
    public:
    int data; // The data in the node can be stored in this variable
    NODE *next; // This is a pointer/reference to the next Node in the sequence so obv pointer type will also be NODE

    // With this defined we don't need to write the initialization code in our int main() block
    NODE(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    // Now we can just create a Node by creating an object of the class.
    // NODE A1;
    // A1.data = 4;
    // A1.next = NULL; // Null pointer declared as reference to other Node, implying Linked List ends here.

    // But this is a static way of creating a node which is not preferred as we don't know how many nodes we may need, so make nodes dynamically.

    // NODE *HEAD; // HEAD is a pointer to an object of type NODE
    // HEAD = new NODE; // This will create a new node and allocate memory for it. The location of the memory is stored in the pointer HEAD.
    // HEAD->data = 4; // We can access and modify the data stored in the node using the pointer.
    // HEAD->next = NULL;
    // This is a better way to intialize a node. But it would be best if we just use a constructor to do this instead.

    // With constructor defined, we can just use
    NODE *HEAD;
    HEAD = new NODE(4);
}