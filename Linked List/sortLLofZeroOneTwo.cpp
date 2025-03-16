// Problem Statement :- https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it

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

// Function to print the Linked List
void printList(NODE* head) {
    NODE* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Method 1 :- Count the number of 0's, 1's and 2's in the Linked List, then simply using this information, change the data of Nodes in Linked List.
NODE* segregate(NODE* head) {
    // Count occurrences of 0, 1, and 2
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    // Pointer to traverse the list
    NODE* curr = head;

    // First pass: Count the nodes
    while (curr) {
        if (curr->data == 0) {
            zeroCount++;
        } else if (curr->data == 1) {
            oneCount++;
        } else {
            twoCount++;
        }
        curr = curr->next;
    }

    // Reset pointer to the head of the list
    curr = head;

    // Second pass: Update the data in the nodes
    // Fill with 0's
    while (zeroCount--) {
        curr->data = 0;
        curr = curr->next;
    }

    // Fill with 1's
    while (oneCount--) {
        curr->data = 1;
        curr = curr->next;
    }

    // Fill with 2's
    while (twoCount--) {
        curr->data = 2;
        curr = curr->next;
    }

    // Return the updated list
    return head;
}

// Method 2 :- Make three separate Linked Lists for 0's, 1's and 2's (using three different head pointers) and merge these three Linked Lists.
NODE* segregate(NODE* head) {
     // Dummy heads and tails for separate lists of 0s, 1s, and 2s.
    NODE* zeroHead = new NODE(-1);
    NODE* oneHead = new NODE(-1);
    NODE* twoHead = new NODE(-1);

    // Pointers to maintain the end of the lists.
    NODE* zeroTail = zeroHead;
    NODE* oneTail = oneHead;
    NODE* twoTail = twoHead;

    // Traverse the original linked list.
    NODE* curr = head;

    while (curr) {
        if (curr->data == 0) {
            // Add to the 0s list
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        } else if (curr->data == 1) {
            // Add to the 1s list
            oneTail->next = curr;
            oneTail = oneTail->next;
        } else {
            // Add to the 2s list
            twoTail->next = curr;
            twoTail = twoTail->next;
        }

        curr = curr->next; // Move to the next node in the original list
    }

    // Connect the three lists together
    zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL; // Ensure the last node points to NULL

    // Update the head of the merged list to skip dummy node
    head = zeroHead->next;

    // Clean up dummy nodes to free memory
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main() {
    NODE *HEAD;

    vector <int> v = {0, 2, 1, 2, 0, 2, 1, 1, 0, 0, 2};

    HEAD = NULL;
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    cout << "Original List: ";
    printList(HEAD);

    HEAD = segregate(HEAD);

    cout << "Segregated List: ";
    printList(HEAD);

    return 0;
}