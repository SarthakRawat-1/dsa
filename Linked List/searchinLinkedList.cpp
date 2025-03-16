// Problem Statement :- https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326

// To check if an element is present in the linked list, start with a temp pointer pointing to the head. This pointer will be used to traverse the list. During the traversal, check if the data on the current node matches the specified value val. If no match is found, move to the next node using the next pointer of the current node.
// At any moment, the data of the node matches with the val, stop, and return 1. If, during traversal, the temp reaches the end, it means that it has reached the last point, which is NULL, hence, returns false at the end.

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
    if (index==size) {
        return prev;
    }

    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = prev; 

    return CreateLinkedList(v, index+1, size, temp);;
}

// Function to check if a given element is present in the linked list
int checkifPresent(NODE* head, int desiredElement) {
    NODE* temp = head;

    // Traverse the linked list
    while (temp != NULL) {
        // Check if the current node's data is equal to the desired element
        if (temp->data == desiredElement)
            return 1;  // Return 1 if the element is found

        // Move to the next node
        temp = temp->next;
    }

    return 0;  // Return 0 if the element is not found in the linked list
}

int main() {
    NODE *HEAD;

    HEAD = NULL;
    vector<int> v = {1, 2, 3, 4, 5};
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    // To display created Linked List
    // NODE *temp = HEAD; 
    
    // while (temp != NULL) {
    //     cout << temp->data << " "; 
    //     temp = temp->next; 
    // }

    // Check if the element is present in the linked list
    int desiredElement = 2;
    int result = checkifPresent(HEAD, desiredElement);
    if (result == 1) {
        cout << "Element " << desiredElement << " is present in the linked list." << endl;
    } else {
        cout << "Element " << desiredElement << " is not present in the linked list." << endl;
    }

}
