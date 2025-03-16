// Insertion operation is used to add a Node to a Linked List
// Insertion can happen at the beginning or at the end or at a given position.
// Insertion at beginning involves changing the next pointer of the new node to point to the current head i.e. the first node in the linked list, the head node, and updating the head (this head is a variable) to the new node. In a linked list, the head is typically a pointer (or reference) to the first node. If the list is empty, the head points to NULL. The head variable itself is not part of the linked list.

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
NODE* CreateLinkedList(vector<int> v, int index, int size, NODE* prev ) {
    // Base Case. This will happen when index becomes equal to size meaning no more elements are left in the vector. Thus prev will be returned.
    // So now by returning prev in this, we are returning the address of the last node. We need this because this is where the HEAD pointer of our linked list will point to.
    if (index==size) {
        return prev;
    }
    // Please note that this is the actual value that the CreateLinkedList function will return when called. The other return statement is simply calling the same function again so this prev is being returned constantly from all the recursive calls of the function.

    // First, we have to create a node. It will have it's address. This address will be given to the next node being created. I have used prev keyword only for convienience becuase as we are adding a new node from beginning, it feels like a previous node.
    // Obv for the first node created, it's next pointer will be NULL. Hence, when we are calling the function in int main(), initial value of prev is NULL.

    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = prev; 
    
    // After this, it will create a new node but now prev value will be updated with the address of the node created before. This value will then be assigned to next pointer of the new node
    return CreateLinkedList(v, index+1, size, temp);;
}

int main() {
    NODE *HEAD;
    // HEAD = new NODE(4); // I am commenting this so that our if block can run for empty linked list in our array inseriton at beginning example.

    // Insertion at beginning of Linked List
    // This if statment will only execute if the Linked List is empty and will create a new NODE
    // if (HEAD == NULL) {
    //     HEAD = new NODE(28);
    // }
    // // This is the actual logic for inserting a new node at beginning.
    // else {
    //     NODE *temp;
    //     temp = new NODE(28);
    //     temp->next = HEAD; // Stores the address of the first node which was the head node before insertion of new node.
    //     HEAD = temp; // Updates the HEAD pointer to point to new node which is our head node now

    // }

    // Another example of Insertion at beggining can be understood by this.
    // We want to insert elements of an array as data in individual nodes in linked list.
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++) {
        if (HEAD == NULL) {
            HEAD = new NODE(v[i]);
        }
        else {
            NODE *temp; // By declaring this inside, we ensure that this will get destroyed once the new iteration of for loop starts. As there is no need of this because we are updating the HEAD variable with it's location.
            temp = new NODE(v[i]); // This however won't get deleted as we have created it dynamically. This is exactly what we want.
            temp->next = HEAD;
            HEAD = temp;
            // This ensures that the new node is inserted at the beginning of the list everytime the for loop runs.
        }
    }

    // Now if we want to print the linked list, we will have to traverse it.
    NODE *temp = HEAD; // We will use this variable to traverse the linked list. 
    // At temp = NULL, we will exit the loop because NULL pointer in next of a Node means it is is the last node and Linked list ends there.
    while (temp != NULL) {
        cout << temp->data << " "; // This will print the data in current node.
        temp = temp->next; // This will set temp pointer to point to the next node.
    }

    // Add node at beginning using Recursion. 
    // For convenience, I am making this part of code separate from other code present in the main() before this.
    NODE *HEAD;
    HEAD = NULL;
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);
}

