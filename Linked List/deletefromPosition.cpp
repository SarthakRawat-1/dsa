#include <iostream>
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

// Function to delete Node at a given position using Recursion
NODE* deleteNode(NODE* curr, int x) { // Again we have took a cur pointer to point to the element to be deleted
    // Base Case. We know that for xth node to be deleted, we have to move x - 1 times. Since, we have not decreased the x in our main() fucntion, our Base case checks for x == 1 not x == 0. At this, curr pointer is pointing to node to be deleted.
    if (x == 1) {
        NODE* temp = curr->next; // We need to store this, because once the node is deleted, we have to update next pointer of the node jsut before the node which was deleted.
        delete curr; // Now just delete the node
        return temp; 
    }

    // Recursive Case
    curr->next = deleteNode(curr->next, x - 1); // Call the fucntion again but this time move to the next element, by decreasing x by 1 and setting curr pointer to it's next pointer
    // Set the returned value to the next pointer of curr to update the next pointer of node just before the node which was deleted. This id one by using the help of Base case.
    // We have to ensure that this won't update next pointer of any other node.  

    // Now we need to return something, such that the curr->next doesn't change for any other node aside from the one which was just before teh deleted one.
    // So for every other case, we can just return curr
    return curr;
};

int main() {
    NODE* HEAD = NULL;
    int arr[] = {2, 4, 6, 1, 7};

    HEAD = CreateLinkedList(arr, 0, 5);

    // Edge Case :- It could be that the HEAD pointer is NULL meaning empty Linked List. We already know how to resolve this.
    // Edge Case :- What if we want to delete the first node? In this case, our code logic directly won't work as x = 1 so x-- becomes 0. Which means loop will never be executed and prev remains as NULL. So prev->next becomes invalid. To resolve this, just add an if statement before the main logic and inside it we can implement the same logic that we used in deletefromBeginning.cpp

    // Deleting Node at a particular position
    // Let's say we want to delete the third node
    int x = 3;

    if (x == 1) { // If we have to delete the first node
        NODE* temp = HEAD; // temp pointer will point to the first node
        HEAD = HEAD->next; // Change the HEAD pointer to point to the second node
        delete temp; // Delete the first node
    } else {
        // First, we need to reach the node to be deleted, so for that we will define a curr pointer initializing it to HEAD. Now we need to move x - 1 times.
        NODE* curr = HEAD;
        x--;

        // But we can't directly delete the node because the node just before the one which is deleted, in our case second node, has to point to the next node now, which was fourth node, but now is third node after deletion.
        // For this, we will use another pointer, say prev. This prev pointer will be used to move to the node just before the node to be deleted, in our case second node. Then using this pointer, we can assign next pointer of second node to next pointer of curr pointer, because curr pointer stores the address of third node, and it's next pointer will store address to fourth node.
        // After this, using curr pointer we can delete the third node.
        NODE* prev = NULL;

        while (x--) { // Till curr pointer not moves to the desired node
            prev = curr; // prev now points to element pointed by curr
            curr = curr->next; // Move curr to point to the next element.
        }

        prev->next = curr->next; // Assign next pointer of second node to next pointer of third node.
        delete curr; // Delete the third node.
    }

    while (HEAD) {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }
}

// Delete Node at a given position using Recursion.
// Don't use int main() function from the above code. Rest all fucntions are required.

int main() {
    NODE* HEAD = NULL;
    int arr[] = {2, 4, 6, 1, 7};

    HEAD = CreateLinkedList(arr, 0, 5);

    int x = 3;

    NODE* curr = HEAD;

    deleteNode(curr, x);

    while (HEAD) {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }
}