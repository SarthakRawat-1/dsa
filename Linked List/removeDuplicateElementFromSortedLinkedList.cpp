// Problem Statement :- remove-duplicate-element-from-sorted-linked-list

// Brute Force Approach :- Traverse the LL. First node's data store it in an array, after that if data of node is not the same as the previous element in array, then store it in the array, else if it is a duplicate element, skip that. After that, create a new LL from the array (either make a new LL or change data in existing LL and delete the rest of nodes which are not required anymore).

// Better Approach :- Start traversing from first node using a curr pointer. For every node we will check if node previous to that holds the same data (for previous node, we will use a prev pointer). If not, then simply move to the next node (both curr and prev). If it is, then change prev->next to curr->next, delete curr and move curr to prev->next

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

NODE* CreateLinkedList(vector<int> v, int index, int size, NODE* prev ) {
    if (index==size) {
        return prev;
    }

    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = prev; 

    return CreateLinkedList(v, index+1, size, temp);;
}

NODE* removeDuplicates(NODE* head) {
    if (!head || !head->next) return head;

    NODE* curr = head->next, *prev = head;

    while (curr) {
        if (curr->data == prev->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = prev->next;
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    NODE *HEAD;
    HEAD = NULL;

    vector <int> v = {1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 5};

    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    HEAD = removeDuplicates(HEAD);

    NODE *temp = HEAD;
    while (temp != NULL) {
        cout << temp->data << " "; 
        temp = temp->next; 
    }

    return 0;
}
