// Problem Statement :- https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// Method 1 :- First we will detect if there is a loop present in LL or not. 
// Once we detect the loop using slow and fast pointers, we will move slow back to first node of LL (i.e. head) and let fast be where it is.
// Then increase both slow and fast by one step, till they come together i.e. become same. This will be the starting node of the loop.
// Then using this slow pointer, we will traverse the nodes in loop till we reach the last node in loop i.e. node just before first node. Then simply, turn it's next pointer to NULL to indicate that the link is broken.

// NOTE :- You might think that when we are finding the starting node of loop, we can also use a prev pointer with fast pointer to track the node just before fast pointer. When both slow and fast pointer, the prev pointer will point to the last node of loop, so we can just put prev->next to NULL.
// But this will not work for the case when loop starts from last node of LL to first node of LL

// Method 2 :- Here also we will first detect the loop using slow and fast pointers.
// Once we detect the loop, we will find the length of loop. Let's say slow is at the beginning node of loop.
// If fast pointer starts from slow and moves for the length of loop, it will arrive back at slow. We will use this to our advantage.
// After finding the length of loop, move slow pointer to head and move fast pointer to numebr of length of loop nodes ahead. Move both slow and fast one by one till they meet. They will meet at the beginning node of loop.
// Now you can use the same method as in Method 1 to break the loop.

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

// Method 1
void removeLoop(NODE *head) {
    // Initialize two pointers, `slow` and `fast`, to the head of the linked list.
    NODE *slow = head, *fast = head;

    // Step 1: Detect if a loop is present in the linked list using the slow and fast pointer technique.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;             // Move `slow` one step forward.
        fast = fast->next->next;       // Move `fast` two steps forward.

        // If `slow` and `fast` meet, there is a loop in the linked list.
        if (slow == fast) {
            break;
        }
    }

    // If `fast` reaches NULL or `fast->next` is NULL, there is no loop in the linked list.
    if (fast == NULL || fast->next == NULL) {
        return; // No loop detected, so return without modifying the linked list.
    }

    // Step 2: Find the starting node of the loop.
    slow = head;  // Move `slow` back to the head of the linked list.
    while (slow != fast) {
        slow = slow->next;   // Move `slow` one step forward.
        fast = fast->next;   // Move `fast` one step forward.

        // At the end of this loop, both `slow` and `fast` will meet at the starting node of the loop.
    }

    // Step 3: Traverse the loop to find the last node of the loop.
    while (slow->next != fast) {
        slow = slow->next; // Move `slow` one step forward until it reaches the last node in the loop.
    }

    // Step 4: Break the loop by setting the `next` pointer of the last node to NULL.
    slow->next = NULL; // This effectively removes the loop from the linked list.
}

// Method 2
void removeLoop(NODE *head) {
    // Initialize two pointers, `slow` and `fast`, both starting at the head of the linked list.
    NODE* slow = head;
    NODE* fast = head;

    // Step 1: Detect if a loop exists using the Floyd's Cycle Detection Algorithm.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move `slow` one step forward.
        fast = fast->next->next;  // Move `fast` two steps forward.

        // If `slow` and `fast` meet, a loop is detected.
        if (slow == fast) {
            break;
        }
    }

    // If no loop is detected (`fast` or `fast->next` reaches NULL), simply return.
    if (fast == NULL || fast->next == NULL) {
        return;
    }

    // Step 2: Calculate the length of the loop.
    slow = fast->next;  // Move `slow` one step ahead.
    int count = 1;      // Initialize the loop length counter.

    // Traverse the loop until `slow` meets `fast` again, counting the number of nodes.
    while (slow != fast) {
        count++;            // Increment the loop counter.
        slow = slow->next;  // Move `slow` to the next node.
    }

    // Step 3: Use the loop length to find the starting node of the loop.
    slow = head;           // Reset `slow` to the head of the linked list.
    fast = head;           // Reset `fast` to the head of the linked list.

    // Move the `fast` pointer `count` steps ahead in the list.
    while (count--) {
        fast = fast->next; // Move `fast` one step forward for `count` iterations.
    }

    // Move both `slow` and `fast` one step at a time until they meet.
    // When they meet, it is the starting node of the loop.
    while (slow != fast) {
        slow = slow->next; // Move `slow` one step forward.
        fast = fast->next; // Move `fast` one step forward.
    }

    // Step 4: Traverse the loop to find the last node.
    while (slow->next != fast) {
        slow = slow->next; // Move `slow` forward until it reaches the node just before `fast`.
    }

    // Break the loop by setting the `next` pointer of the last node to NULL.
    slow->next = NULL;
}

int main() {
    NODE *HEAD;

    vector <int> v = {1, 2, 3, 4, 5};

    HEAD = NULL;
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    HEAD->next->next->next->next->next = HEAD->next->next;

    removeLoop(HEAD);

    cout << "List after removing loop :- ";

    NODE *temp = HEAD;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}

