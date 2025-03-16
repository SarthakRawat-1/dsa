// Problem Statement : https://www.geeksforgeeks.org/problems/find-length-of-loop/1

// This is a simple extension of linkedListCycle.cpp

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

// Function to count the number of nodes in a loop in the linked list
int countNodesinLoop(NODE* HEAD) {
    NODE* slow = HEAD;  // Slow pointer moves one step at a time
    NODE* fast = HEAD;  // Fast pointer moves two steps at a time

    // Step 1: Detect the presence of a loop using the Hare and Tortoise approach
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        // If slow and fast pointers meet, a loop is detected
        if (slow == fast) {
            break;
        }
    }

    // If no loop is detected, return 0
    if (fast == NULL || fast->next == NULL) {
        return 0;
    }

    // Step 2: Count the number of nodes in the loop
    int count = 1;        // Initialize count to 1 (slow is already at one node in the loop)
    slow = fast->next;    // Move slow pointer to the next node

    // Traverse the loop until slow reaches the meeting point again
    while (slow != fast) {
        count++;          // Increment count for each node in the loop
        slow = slow->next; // Move slow pointer to the next node
    }

    return count; // Return the total number of nodes in the loop
}

int main() {
    NODE* HEAD; // Pointer to the head of the linked list

    // Create a vector containing the data for the linked list
    vector<int> v = {1, 2, 3, 4, 5};

    // Initialize HEAD to NULL and create the linked list
    HEAD = NULL;
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    // Create a loop in the linked list for testing
    // Link the last node back to the second node (to create a loop)
    HEAD->next->next->next->next->next = HEAD->next;

    // Call the function to count the number of nodes in the loop
    int loopLength = countNodesinLoop(HEAD);

    // Print the result
    if (loopLength > 0) {
        cout << "The linked list has a loop with " << loopLength << " nodes." << endl;
    } else {
        cout << "The linked list does not have a loop." << endl;
    }

    return 0;
}